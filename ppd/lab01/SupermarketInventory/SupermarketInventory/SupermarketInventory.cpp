// SupermarketInventory.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include "stdafx.h"
#include "SuperMarket.h"

int main()
{
	int x = 0;
	SuperMarket myMarket;
	std::vector<std::pair<int, int>> vectorOfOrders;
	vectorOfOrders.push_back({ 0, 5 });
	vectorOfOrders.push_back({ 1, 14 });
	vectorOfOrders.push_back({ 0, 35 });
	vectorOfOrders.push_back({ 3, 20 });
	vectorOfOrders.push_back({ 0, 20 });
	vectorOfOrders.push_back({ 0, 40 });
	vectorOfOrders.push_back({ 3, 59 });
	myMarket.sellOrder(vectorOfOrders);
	scanf_s("%d", x);
    return 0;
}

