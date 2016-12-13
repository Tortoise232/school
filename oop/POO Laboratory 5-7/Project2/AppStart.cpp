#include"domain.h"
#include "dynVector.h"
#include<stdio.h>
#include "repo.h"
#include "controller.h"
#include "UI.h"
#include<windows.h>
#include<assert.h>
#include"tests.h"
class E
{
public:
	E() { std::cout << "E{}"; }
	virtual ~E() { std::cout << "~E()"; }
};
class DE : public E
{
public:
	static int n;
	DE() { n++; }
};
int DE::n = 0;
int fct2(int x)
{
	if (x < 0)
	{
		throw E{};
		std::cout << "number less than	0" << std::endl;
	}
	else if (x == 0)
	{
		throw DE{};
		std::cout << "number equal to 0"<< std::endl;
	}
	return x % 10;
}
int main()
{
	int x;
	try
	{
		int res = 0;
		res = fct2(-5);
		std::cout << DE::n;
		res = fct2(0);
		std::cout << DE::n;
		res = fct2(25);
		std::cout << DE::n;
	}
	catch (E&)
	{
		std::cout << DE::n;
	}
	std::cin >> x;
	return 0;
}