%min(i,o,o)
%min(list,min,result)
%elimMin(i,o,o)
%elimElem(i,i,o,o)



min([],Result,Result).

min([H|T],Elem,Result):-
	H < Elem,
	min(T,H,Result).

min([H|T],Elem,Result):-
	H > Elem,
	min(T,Elem,Result).

min([H|T],H,Result):-
	min(T,H,Result).

elimElem([],_,Result,Result).

elimElem([H|T],H,RL,Result):-
	elimElem(T,0,RL,Result).

elimElem([H|T],E,RL,Result):-
	H \= E,
	elimElem(T,E,[H|RL],Result).

elimMin([H|T],Result):-
	min([H|T],H,Min),
	elimElem([H|T],Min,[],Result).	
