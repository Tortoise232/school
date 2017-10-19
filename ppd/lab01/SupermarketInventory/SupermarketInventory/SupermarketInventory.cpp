// SupermarketInventory.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include "stdafx.h"
#include "SuperMarket.h"
#include <stdlib.h>
int main()
{
	int x = 0;
	SuperMarket myMarket;
	while (true) {
		std::vector<std::pair<int, int>> vectorOfSells, vectorOfBuys;
		for (int i = 0; i < 4; i++) {
			vectorOfSells.push_back({ rand() % 4, rand() % 100 + 1 });
			vectorOfBuys.push_back({ rand() % 4, rand() % 100 + 1 });
		}
		myMarket.sellOrder(vectorOfSells);
		myMarket.buyOrder(vectorOfBuys);
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
    return 0;
}

