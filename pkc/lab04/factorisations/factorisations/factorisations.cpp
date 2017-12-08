// factorisations.cpp : Defines the entry point for the console application.
//




#include "stdafx.h"
#include <chrono>
#include <string>
#include <vector>
#include "InfInt.h"
#include <assert.h>
#define NUMBER_OF_DIGITS 20
#define POLLARD_BOUND 7


InfInt gcd(InfInt a, InfInt b) {
	InfInt u, u1 = 0, u2 = 1;
	InfInt v, v1 = 1, v2 = 0;
	InfInt q, r, d = 1;
	while (b > 0) {
		q = a / b;
		r = a - q * b;
		u = u2 - q * u1;
		v = v2 - q * v1;
		a = b;
		b = r;
		u2 = u1;
		u1 = u;
		v2 = v1;
		v1 = v;
		d = a;
		u = u2;
		v = v2;
	}
	return d;
}

struct pair {
	pair(InfInt a, int b) { prime = a; power = b; };
	InfInt prime;
	int power;
};

InfInt  myPow(InfInt number, InfInt pow) {
	while (pow > 1) {
		number *= number;
		pow--;
	}
	return number;
}

int log(InfInt number, int base) {
	int result = 0;
	InfInt ibase = base;
	while (number > ibase) {
		ibase *= base;
		result++;
	}
	return result - 1;
}

bool prime(InfInt a) {
	for (InfInt i = 2; i < a / 2; i++)
		if (a % i == 0)
			return false;
	return true;
}

std::chrono::milliseconds getStamp() {
	return std::chrono::duration_cast< std::chrono::milliseconds >(
		std::chrono::system_clock::now().time_since_epoch());
}



std::string generateInfInt(int nrOfDigits) {
	std::string number = "";
	for (int i = 0; i < nrOfDigits; i++) {
		number += rand() % 10 + 48;
	}
	//std::cout << number << " ";
	return number;
}

std::vector<pair> simpleFactorisation(InfInt number) {
	std::vector<pair> result;
	while (number > 1) {
		InfInt i = 2;
		while (number % i != 0)
			i++;
		bool isInResult = false;
		int positionInResult;
		for (positionInResult = 0; positionInResult < result.size(); positionInResult ++) {
			if (result[positionInResult].prime == i) {
				isInResult = true;
				break;
			}
		}
		isInResult ? result[positionInResult].power++ : result.push_back(pair(i, 1));
		number /= i;
	}
	return result;
}

InfInt pollardpObtaink(InfInt number)
{
	InfInt result(1);
	for (int i = 2; i < POLLARD_BOUND; i++)
		if (prime(i))
			result *= log(number, i);
	assert(result > 1);
	assert(result < number);
	std::cout << result << " ";
	return result;
}

std::vector<pair> pollardpFactorisation(InfInt number) {
	std::vector<pair> result;
	while (number > 1) {
		for (int a = 2; number > a; a++) {
			InfInt gcdRes = gcd(myPow(number, pollardpObtaink(number)), number);
			std::cout << " gcd res: " << gcdRes << " ";
			if (gcdRes > 1) {
				std::cout << " inside gcdResValid ";
				number /= gcdRes;
				bool isInResult = false;
				int positionInResult;
				for (positionInResult = 0; positionInResult < result.size(); positionInResult++) {
					if (result[positionInResult].prime == gcdRes) {
						isInResult = true;
						break;
					}
				}
				isInResult ? result[positionInResult].power++ : result.push_back(pair(gcdRes, 1));
				break;
			}
		}
	}
	
	return result;
}

int main()
{
	InfInt test(4218410);
	std::vector<pair> result = pollardpFactorisation(test);
	for (pair res : result)
		std::cout << res.prime << "^" << res.power << " * ";
    return 0;
}

