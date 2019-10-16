%intercalare(list,elem,pos,contor,list,rez).
%intercalare(i,i,i,i,o,o).

intercalare([],_,_,_,Result,Result).

intercalare([H|T],E,P,C,RL,Result):-
	P \= C,
	C1 is C + 1,
	intercalare(T,E,P,C1,[H|RL],Result).

intercalare([H|T],E,P,P,RL,Result):-
	C is P + 1,
	intercalare([H|T],E,P,C,[E|RL],Result).

