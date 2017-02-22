#pragma once
#include "controller.h"
#include <assert.h>
class test
{
public:
	void testAdd()
	{
		controller tester;
		int sizeBefore = tester.getQuestions().size();
		tester.addQuestion(20,1,"TEST","YES");
		assert(tester.getQuestions().size() == sizeBefore + 1);
		tester.addQuestion(25, 1, "TEST", "YES");
		assert(tester.getQuestions().size() == sizeBefore + 2);
		try {
			tester.addQuestion(20, 1, "DUPLICATE ID", "NO");
			assert(false);
		}
		catch(QuestionException e){};
			
	}
	void testRemove()
	{
		controller tester;
		int sizeBefore = tester.getQuestions().size();
		tester.addQuestion(24, 1, "TEST", "YES");
		assert(tester.getQuestions().size() == sizeBefore + 1);
		tester.addQuestion(25, 1, "TEST", "YES");
		assert(tester.getQuestions().size() == sizeBefore + 2);
		tester.removeQuestion(25);
		assert(tester.getQuestions().size() == sizeBefore + 1);
		tester.removeQuestion(24);
		assert(tester.getQuestions().size() == sizeBefore);
		try {
			tester.removeQuestion(99999);
			assert(false);
		}
		catch (QuestionException e) {};
	}
	void testUpdate()
	{
		controller tester;
		Participant check;
		Participant* john = new Participant(0, "TESTJOHN");
		tester.getRepo().addParticipant(*john);
		tester.addPoints(10, "TESTJOHN");
		check = tester.getRepo().findParticipant("TESTJOHN");
		assert(check.getScore() == 10);
	}
	test()
	{
		this->testAdd();
		this->testRemove();
		this->testUpdate();
	}
};