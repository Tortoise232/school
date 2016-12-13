%divCom(elem,elem,Result).
%divCom(i,i,o,o).
%dvcList(i,o,o).
%YOU HAVE TO PROVIDE FIRST ELEM AS PARAM
dvcList([],Result,Result).
dvcList([H|T],RE,Result):-
	divCom(H,RE,RE),
	dvcList(T,RE,Result).

	


divCom(Result,Elem,Result):-
	Elem = 0 .
divCom(E1,E2,Result):-
	E1 >= E2,
	R is E1 mod E2,
	divCom(E2,R,Result).



