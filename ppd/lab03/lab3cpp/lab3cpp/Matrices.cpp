// Matrices.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "ThreadPool.h"

#include<chrono>
#include<string>
#include<iostream>
#include<stdlib.h>
#include<thread>
#include<vector>

#define PRINT_MATRIX false
#define LIMIT 1000
#define MAXNR 1000
//lazy globals fam
int a[LIMIT][LIMIT];
int b[LIMIT][LIMIT];
int c[LIMIT][LIMIT];

void printMatrix() {
	if (!PRINT_MATRIX)
		return;
	std::cout << "MATRIX A: \n";
	for (int i = 0; i < LIMIT; i++) {
		for (int j = 0; j < LIMIT; j++)
			std::cout << a[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "MATRIX B: \n";
		for (int i = 0; i < LIMIT; i++) {
			for (int j = 0; j < LIMIT; j++)
				std::cout << b[i][j] << " ";
			std::cout << "\n";
		}

	std::cout << "MATRIX C: \n";
	for (int i = 0; i < LIMIT; i++) {
		for (int j = 0; j < LIMIT; j++)
			std::cout << c[i][j] << " ";
		std::cout << "\n";
	}

}

void sumLine(int line) {
	for (int i = 0; i < LIMIT; i++) {
		c[line][i] = a[line][i] + b[line][i];
	}
}



void threadingSum() {
	ThreadPool threadPool(LIMIT);
	for(int i = 0; i < LIMIT; i++){
		threadPool.enqueue(sumLine, i);
	}
}


void sequentialSum() {
	for (int i = 0; i < LIMIT; i++)
		for (int j = 0; j < LIMIT; j++)
			c[i][j] = a[i][j] + b[i][j];
}

void producLine(int row) {
	int sum;
	for (int column = 0; column < LIMIT; column++) {
		sum = 0;
		for (int i = 0; i < LIMIT; i++){
			sum += a[row][i] * b[i][column];
		c[row][column] = sum;
		}
	}
}


void threadingProduct() {
	ThreadPool threadPool(LIMIT);
	for(int i = 0; i < LIMIT; i ++){
		threadPool.enqueue(producLine, i);
		}
}

void threadingProductAsync() {
	for (int i = 0; i < LIMIT; i++) {
		std::async(producLine, i);
	}
}

void threadingSumAsync() {
	for (int i = 0; i < LIMIT; i++)
		std::async(sumLine, i);
}

void sequentialProduct() {
	for (int i = 0; i < LIMIT; i++)
		for (int j = 0; j < LIMIT; j++) {
			int sum = 0;
			for (int ii = 0; ii < LIMIT; ii++)
					sum += a[i][ii] * b[ii][j];
			c[i][j] = sum;
		}
}

std::chrono::milliseconds getStamp() {
	return std::chrono::duration_cast< std::chrono::milliseconds >(
		std::chrono::system_clock::now().time_since_epoch());
}


void fillMatrices() {
	for (int i = 0; i < LIMIT; i++)
		for (int j = 0; j < LIMIT; j++) {
			a[i][j] = rand() % MAXNR;
			b[i][j] = rand() % MAXNR;
		}
}

int main()
{
	fillMatrices();
	std::chrono::milliseconds timeStamp;

	timeStamp = getStamp();
	threadingSum();
	std::cout << "Thread pool sum: " << (getStamp() - timeStamp).count() << " milliseconds\n";

	printMatrix();

	timeStamp = getStamp();
	threadingSum();
	std::cout << "Async sum: " << (getStamp() - timeStamp).count() << " milliseconds\n";

	printMatrix();

	timeStamp = getStamp();
	sequentialSum();
	std::cout << "Sequential sum: " << (getStamp() - timeStamp).count() << " milliseconds\n";

	printMatrix();

	timeStamp = getStamp();
	threadingProduct();
	std::cout << "Thread pool product: " << (getStamp() - timeStamp).count() << " milliseconds\n";

	printMatrix();

	timeStamp = getStamp();
	threadingProduct();
	std::cout << "Async product: " << (getStamp() - timeStamp).count() << " milliseconds\n";

	printMatrix();

	timeStamp = getStamp();
	sequentialProduct();
	std::cout << "Sequential product: " << (getStamp() - timeStamp).count() << " milliseconds\n";

	printMatrix();



}

