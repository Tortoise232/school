%listToSet(i,o,o)
%notBelong(i,i)
%countElem(lista,elem,contor, Result).


notBelong([],E).
notBelong([H|T],E):-
	H \= E,
	notBelong(T,E).

listToSet([],Result,Result).
listToSet([H|T],RL,Result):-
	notBelong(RL,H),
	listToSet(T,[H|RL],Result).
listToSet([H|T],RL,Result):-
	listToSet(T,RL,Result).

countElem([],Result,Result).
countElem([],E,C,Result):-
	countElem([],[E|C],Result).
countElem([H|T],H,C,Result):-
	C1 is C + 1,
	countElem(T,H,C1,Result).
countElem([H|T],E,C,Result):-
	H \= E,
	countElem(T,E,C,Result).


main([],Result,Result).
main(_,[],RL,Result):-
	main([],RL,Result).
main(List,[SetH|SetT],RL,Result):-
	countElem(List,SetH,0,ResCount),
	main(List,SetT,[ResCount|RL],Result).
main([H|T], RL,Result):-
	listToSet([H|T],_,Set),
	main([H|T],Set,RL,Result).
