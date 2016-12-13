%addPerechi(i,i,o,o)
%getAllPerechi(i,o,o)

addPerechi(_,[],ResultA,ResultA).
addPerechi(E,[H|T],L,ResultA):-
	addPerechi(E,T,[[E|H]|L],ResultA).

getAllPerechi([],Result,Result).
getAllPerechi([H|T],RL,Result):-
	addPerechi(H,T,RL,ResultA),
	getAllPerechi(T,ResultA,Result).

