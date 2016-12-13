%adica lista de la intregul A la integrul B;
%list(i,i,o,o).

list(E,E,Result,Result).
list(A,B,RL,Result):-
	A\=B,
	B1 is B - 1,
	list(A,B1,[B|RL],Result).
list(A,B,Result):-
	list(A,B,[],Result).

