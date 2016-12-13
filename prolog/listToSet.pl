%belong(list,elem)
%listToSet(i,o,o)
%listToSet(List,Set,Result)

main([H|T],Result):-
	main([H|T],[],Result).

main([H|T],RL,Result):-
	listToSet([H|T],RL1),
	revert(RL1,Result).

listToSet([],Result,Result).
listToSet([H|T],Result):-
	listToSet([H|T],RL,Result).
listToSet([H|T],RL,Result):-
	notBelong(RL,H),
	listToSet(T,[H|RL],Result).
listToSet([H|T],RL,Result):-
	listToSet(T,RL,Result).

notBelong([],E).
notBelong([H|T],E):-
	H \= E,
	notBelong(T,E).

revert([],Result,Result).
revert([H|T],RL,Result):-
	revert(T,[H|RL],Result).
revert([H|T],Result):-
	revert([H|T],[],Result).
