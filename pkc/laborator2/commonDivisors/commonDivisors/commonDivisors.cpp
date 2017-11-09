// commonDivisors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <limits.h>
#include <vector>

#define PRINT false
#define NUMBER_OF_RUNS 1000000

unsigned long gcdEuclidDivision(unsigned long a, unsigned long b) {
	while (a && b && a % b != 0) {
		a > b ? a %= b : b %= a;
	}
	return b > 0 ?  b : a;
}

unsigned long gcdEuclidDiff(unsigned long a, unsigned long b) {
	while (a && b && a != b) {
		a > b ? a -= b : b -= a;
	}
	return b > 0 ? b : a;
}

unsigned long gcdExtendedEuclidian(unsigned long a, unsigned long b) {
	unsigned long u, u1 = 0, u2 = 1;
	unsigned long v, v1 = 1, v2 = 0;
	unsigned long q, r, d = 1;
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

unsigned long _LongRand()
{

	unsigned char MyBytes[4];
	unsigned long MyNumber = 0;
	unsigned char * ptr = (unsigned char *)&MyNumber;

	MyBytes[0] = rand() % 256; //0-255
	MyBytes[1] = rand() % 256; //256 - 65535
	MyBytes[2] = rand() % 256; //65535 -
	MyBytes[3] = rand() % 256; //16777216

	memcpy(ptr + 0, &MyBytes[0], 1);
	memcpy(ptr + 1, &MyBytes[1], 1);
	memcpy(ptr + 2, &MyBytes[2], 1);
	memcpy(ptr + 3, &MyBytes[3], 1);

	return(MyNumber);
}

bool equalDigits(unsigned long a, unsigned long b) {
	int cntA = 0, cntB = 0;
	while (a || b) {
		bool breakNow = a ? !b ? true : false : b ? true : false;
		
		if (breakNow)
			return false;
		a /= 10;
		b /= 10;
	}
	return true;
}

std::vector<unsigned long> generateLongs() {
	std::vector<unsigned long> arrai;
	for (int i = 0; i < NUMBER_OF_RUNS; i++) {
		unsigned long nr = 0;
		while(!equalDigits(nr, std::numeric_limits<unsigned long>::max()))
			nr = _LongRand();
		arrai.push_back(nr);
	}
	return arrai;
}

std::chrono::milliseconds getStamp() {
	return std::chrono::duration_cast< std::chrono::milliseconds >(
		std::chrono::system_clock::now().time_since_epoch());
}

int runGCD(unsigned long(*function)(unsigned long, unsigned  long), std::vector<unsigned long> arrai) {
	std::chrono::milliseconds timeStamp = getStamp();
	for (int i = 0; i < NUMBER_OF_RUNS; i+= 2) {
		if (PRINT)
			std::cout << "a = " << arrai[i]
			<< "; b = " << arrai[i + 1]
			<< "; divisor: "
			<< function(arrai[i], arrai[i + 1]) << "\n";
		else
			function(arrai[i], arrai[i + 1]);
	}
	timeStamp = getStamp() - timeStamp;
	return timeStamp.count();
}

int main()
{
	std::vector<unsigned long> arrai = generateLongs();
	std::cout << "Extended Euclidian:";
	std::cout << runGCD(&gcdExtendedEuclidian, arrai) << "\n";
	std::cout << "Euclidian (Division):";
	std::cout << runGCD(&gcdEuclidDivision, arrai) << "\n";
	std::cout << "Euclidian (Difference):";
	std::cout << runGCD(&gcdEuclidDiff, arrai) << "\n";
	return 0;
}

