%max(i,o)
max([],Result,Result).
max([H|T],E,Result):-
	H <= E,
	max(T,E,Result).
max([H|T],E,Result) :-
	H > E,
	max(T,H,Result).
