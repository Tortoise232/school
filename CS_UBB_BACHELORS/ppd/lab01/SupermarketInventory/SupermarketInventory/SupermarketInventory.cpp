// SupermarketInventory.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <stdio.h>
#include "SuperMarket.h"
#include <stdlib.h>
#include <iostream>



#define BATCH_SIZE 10
#define NUMBER_OF_PRODUCTS 3
#define MAX_ORDER_SIZE 10
int main()
{
	int x = 0;
	SuperMarket myMarket;
	while (true) {
		std::vector<std::pair<int, int>> vectorOfSells, vectorOfBuys;
		for (int i = 0; i < BATCH_SIZE; i++) {
			vectorOfSells.push_back({ rand() % NUMBER_OF_PRODUCTS, rand() % MAX_ORDER_SIZE + 1 });
		}
		myMarket.sellOrder(vectorOfSells);
		std::cout << "My threading money: " << myMarket.getMoney() << "\n";
		std::cout << "My actual money: " << myMarket.getRealMoney() << "\n";
		std::cout << "Fuckupery: " << myMarket.getMoney() - myMarket.getRealMoney() << "\n";
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
    return 0;
}

