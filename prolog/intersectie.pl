%notBelong(i,i)
%notBelong(List,Elem)
%resultList(i,i,o,o)
%resultList(ListA,ListB,ResultList,ResultList).

notBelong([],E).
notBelong([H|T],E):-
	H \= E,
	notBelong(T,E).

intersect([],[],Result,Result).
intersect([H|T],[H1|T1],Result):-
	intersect([H|T],[],[H1|T1],Result).
intersect([H|T],[],RL,Result):-
	notBelong(RL,H),
	intersect(T,[],[H|RL],Result).	
intersect([H|T],[],RL,Result):-
	intersect(T,[],RL,Result).

