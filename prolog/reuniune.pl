%reuniune(i,i,o,o);
%reuniune(list,list,list,list);

reuniune([],[],Result,Result).
reuniune([],[H|T],RL,Result):- 
	reuniune([],T,[H|RL],Result).
reuniune([H|T],[H1|T1],RL,Result):-
	reuniune(T,[H1|T1],[H|RL],Result).

