%even(list,parity,result).
even([],P):-
	P = 0.
even([H|T],P):-
	P = 1,
	even(T,0).
even([H|T],P):-
	P = 0,
	even(T,1).

even([H|T]):-
	even([H|T],0).
