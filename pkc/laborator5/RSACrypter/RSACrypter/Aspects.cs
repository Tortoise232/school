
using System;
using System.Reflection;
using System.Text;
using PostSharp.Aspects;
using PostSharp.Serialization;
 
namespace PostSharpAspects
{
    public class Logger
    {
        static int indentation = 0;
        public static void WriteLine(string line)
        {
            for (int i = 0; i < indentation; i++)
                Console.Write(" ");
            Console.Write(line + "\n");
        }
        public static void Indent()
        {
            indentation++;
        }
        public static void Unindent()
        {
            indentation--;
        }
        
    }
    [PSerializable]
    [LinesOfCodeAvoided(6)]
    public sealed class LogMethodAttribute : OnMethodBoundaryAspect
    {
        /// <summary>
        ///   Method invoked before the target method is executed.
        /// </summary>
        /// <param name="args">Method execution context.</param>
        public override void OnEntry(MethodExecutionArgs args)
        {
            var stringBuilder = new StringBuilder();

            stringBuilder.Append("Entering ");
            AppendCallInformation(args, stringBuilder);
            Logger.WriteLine(stringBuilder.ToString());

            Logger.Indent();
        }


        /// <summary>
        ///   Method invoked after the target method has successfully completed.
        /// </summary>
        /// <param name="args">Method execution context.</param>
        public override void OnSuccess(MethodExecutionArgs args)
        {
            Logger.Unindent();

            var stringBuilder = new StringBuilder();

            stringBuilder.Append("Exiting ");
            AppendCallInformation(args, stringBuilder);

            if (!args.Method.IsConstructor && ((MethodInfo)args.Method).ReturnType != typeof(void))
            {
                stringBuilder.Append(" with return value ");
                stringBuilder.Append(args.ReturnValue);
            }

            Logger.WriteLine(stringBuilder.ToString());
        }

        /// <summary>
        ///   Method invoked when the target method has failed.
        /// </summary>
        /// <param name="args">Method execution context.</param>
        public override void OnException(MethodExecutionArgs args)
        {
            Logger.Unindent();

            var stringBuilder = new StringBuilder();

            stringBuilder.Append("Exiting ");
            AppendCallInformation(args, stringBuilder);

            if (!args.Method.IsConstructor && ((MethodInfo)args.Method).ReturnType != typeof(void))
            {
                stringBuilder.Append(" with exception ");
                stringBuilder.Append(args.Exception.GetType().Name);
            }

            Logger.WriteLine(stringBuilder.ToString());
        }

        private static void AppendCallInformation(MethodExecutionArgs args, StringBuilder stringBuilder)
        {
            var declaringType = args.Method.DeclaringType;
            Formatter.AppendTypeName(stringBuilder, declaringType);
            stringBuilder.Append('.');
            stringBuilder.Append(args.Method.Name);

            if (args.Method.IsGenericMethod)
            {
                var genericArguments = args.Method.GetGenericArguments();
                Formatter.AppendGenericArguments(stringBuilder, genericArguments);
            }

            var arguments = args.Arguments;

            Formatter.AppendArguments(stringBuilder, arguments);
        }
    }
    /// <summary>
    ///   Helps creating a string out of a method call context.
    /// </summary>
    internal static class Formatter
    {
        public static void AppendTypeName(StringBuilder stringBuilder, Type declaringType)
        {
            stringBuilder.Append(declaringType.FullName);
            if (declaringType.IsGenericType)
            {
                var genericArguments = declaringType.GetGenericArguments();
                AppendGenericArguments(stringBuilder, genericArguments);
            }
        }

        public static void AppendGenericArguments(StringBuilder stringBuilder, Type[] genericArguments)
        {
            stringBuilder.Append('<');
            for (var i = 0; i < genericArguments.Length; i++)
            {
                if (i > 0)
                    stringBuilder.Append(", ");

                stringBuilder.Append(genericArguments[i].Name);
            }
            stringBuilder.Append('>');
        }

        public static void AppendArguments(StringBuilder stringBuilder, Arguments arguments)
        {
            stringBuilder.Append('(');
            for (var i = 0; i < arguments.Count; i++)
            {
                if (i > 0)
                    stringBuilder.Append(", ");

                stringBuilder.Append(arguments[i]);
            }
            stringBuilder.Append(')');
        }
    }
}