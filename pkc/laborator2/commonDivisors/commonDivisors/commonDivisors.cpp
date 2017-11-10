// commonDivisors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include "InfInt.h"
#define PRINT false
#define NUMBER_OF_RUNS 10
#define NUMBER_OF_DIGITS 50


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



InfInt gcdEuclidDivisionBIG(InfInt a, InfInt b) {
	while (a > 0 && b > 0 && a % b != 0) {
		a > b ? a %= b : b %= a;
	}
	return b > 0 ? b : a;
}

InfInt gcdEuclidDiffBIG(InfInt a, InfInt b) {
	while (a > 0 && b > 0 && a != b) {
		a > b ? a -= b : b -= a;
	}
	return b > 0 ? b : a;
}

InfInt gcdExtendedEuclidianBIG(InfInt a, InfInt b) {
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

InfInt gcdBinaryBIG(InfInt u, InfInt v)
{
	// simple cases (termination)
	if (u == v)
		return u;

	if (u == 0)
		return v;

	if (v == 0)
		return u;

	// look for factors of 2
	if (u % 2 == 0) // u is even
	{
		if (v % 2 ==  1) // v is odd
			return gcdBinaryBIG(u / 2, v);
		else // both u and v are even
			return gcdBinaryBIG(u /2, v /2) * 2;
	}

	if (v % 2 == 0) // u is odd, v is even
		return gcdBinaryBIG(u, v / 2);

	// reduce larger argument
	if (u > v)
		return gcdBinaryBIG((u - v) / 2, v);

	return gcdBinaryBIG((v - u) / 2, u);
}

void bigNumberComparison(int runs, int nrOfDigits) {
	for (int i = 0; i < runs; i++) {
		InfInt a = generateInfInt(nrOfDigits).c_str();
		InfInt b = generateInfInt(nrOfDigits).c_str();
		if (PRINT)
			std::cout << "a = " << a
			<< "; b = " << b
			<< "; divisor: \n"
			<< "EuclidDivisionBig: " << gcdEuclidDivisionBIG(a, b) << " \n"
			<< "EuclidDiffBig: " << gcdEuclidDiffBIG(a, b) << " \n"
			<< "ExtendedEuclidBig: " << gcdExtendedEuclidianBIG(a, b) << " \n";
	}
}



int runExtendedEuclidian(int runs, int nrOfDigits) {
	std::chrono::milliseconds timeStamp = getStamp();
	int generationTime = 0;
	for (int i = 0; i < runs; i++) {
		std::chrono::milliseconds generationAdjustement = getStamp();
		InfInt a = generateInfInt(nrOfDigits).c_str();
		InfInt b = generateInfInt(nrOfDigits).c_str();
		generationAdjustement = getStamp() - generationAdjustement;
		generationTime += generationAdjustement.count();
		gcdExtendedEuclidianBIG(a, b);
	}
	timeStamp = getStamp() - timeStamp;
	return timeStamp.count() - generationTime;
}

int runEuclidDivision(int runs, int nrOfDigits) {
	std::chrono::milliseconds timeStamp = getStamp();
	int generationTime = 0;
	for (int i = 0; i < runs; i++) {
		std::chrono::milliseconds generationAdjustement = getStamp();
		InfInt a = generateInfInt(nrOfDigits).c_str();
		InfInt b = generateInfInt(nrOfDigits).c_str();
		generationAdjustement = getStamp() - generationAdjustement;
		generationTime += generationAdjustement.count();
		gcdEuclidDivisionBIG(a, b);
	}
	timeStamp = getStamp() - timeStamp;
	return timeStamp.count() - generationTime;
}

int runBinary(int runs, int nrOfDigits) {
	std::chrono::milliseconds timeStamp = getStamp();
	int generationTime = 0;
	for (int i = 0; i < runs; i++) {
		std::chrono::milliseconds generationAdjustement = getStamp();
		InfInt a = generateInfInt(nrOfDigits).c_str();
		InfInt b = generateInfInt(nrOfDigits).c_str();
		generationAdjustement = getStamp() - generationAdjustement;
		generationTime += generationAdjustement.count();
		gcdBinaryBIG(a, b);
	}
	timeStamp = getStamp() - timeStamp;
	return timeStamp.count() - generationTime;
}


int main()
{
	std::cout << "Running on " << NUMBER_OF_RUNS << " iterations\n";
	for (int digit_count = 1; digit_count < 40; digit_count++){
		std::cout << "Running for " << digit_count << " digits: "
		<< " EE: " << runExtendedEuclidian(NUMBER_OF_RUNS, digit_count)
		<< " ED: " << runEuclidDivision(NUMBER_OF_RUNS, digit_count)
		<< " B: " << runBinary(NUMBER_OF_RUNS, digit_count) << "\n";
	}
	return 0;
}