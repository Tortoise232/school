%removeOdd(i,o,o)
removeOdd([],Result,Result).
removeOdd([H|T],LR,Result):-
	E is (H mod 2),
	E = 0,
	removeOdd(T,[H|LR],Result).
removeOdd([H|T],LR,Result):-
	E is (H mod 2),
	E  = 1,
	removeOdd(T,LR,Result).

