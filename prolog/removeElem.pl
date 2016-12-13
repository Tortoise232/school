%removeElem(i,e,o,o)

removeElem([],_,Result,Result).

removeElem([H|T],H,RL,Result):-
	removeElem(T,H,RL,Result).

removeElem([H|T],E,RL,Result):-
	H \= E,
	removeElem(T,E,[H|RL],Result).

