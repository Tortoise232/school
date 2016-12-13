%subst(list,elem,elem,list,list)
%subst(i,i,elem,o,o).

subst([],_,_,Result,Result).
subst([H|T],H,R,RL,Result):-
	subst(T,H,R,[R|RL],Result).
subst([H|T],E,R,RL,Result):-
	E \= H,
	subst(T,E,R,[H|RL],Result).
