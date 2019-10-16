#pragma once
class tests
{
public:
	void startTests()
	{
		this->testAdd();
		this->testRemove();
		this->testUpdate();
		this->testSort();
	}
	void testAdd();
	void testRemove();
	void testUpdate();
	void testSort();
};