/* 
 * Sample Scanner2: 
 * Description: Count the number of characters and the number of lines 
 *              from standard input
 * Usage: (1) $ flex sample2.lex
 *        (2) $ gcc lex.yy.c -lfl
 *        (3) $ ./a.out
 *            stdin> whatever you like
 *	      stdin> Ctrl-D
 * Questions: Is it ok if we do not indent the first line?
 *            What will happen if we remove the second rule?
 */

%{
/* need this for the call to atof() below */
#include <math.h>
%}

DIGIT    [0-9]
ID       [a-z][a-z0-9]*

%%

{DIGIT}+    {
             printf( "An integer: %s (%d)\n", yytext,
                     atoi( yytext ) );
             }

{DIGIT}+"."{DIGIT}*        {
             printf( "A float: %s (%g)\n", yytext,
                     atof( yytext ) );
             }

 if|else|while|break|for|return        {
             printf( "A keyword: %s\n", yytext );
             }

{ID}        printf( "An identifier: %s\n", yytext );

"("|")"|";"|"{"|"}"|"+"|"-"|"*"|"/"|"%"|">"|"<"|"=="|"="|","|";"   printf( "An operator: %s\n", yytext );

 "{"[\^{$\;$}}\n]*"}"     /* eat up one-line comments */

 [ \t\n]+          /* eat up whitespace */

 .           printf( "Unrecognized character: %s\n", yytext );

%%

 main( argc, argv )
 int argc;
 char **argv;
{
  ++argv, --argc;  /* skip over program name */
 if ( argc > 0 )
         yyin = fopen( argv[0], "r" );
 else
         yyin = stdin;

 yylex();
 return 1;
}
