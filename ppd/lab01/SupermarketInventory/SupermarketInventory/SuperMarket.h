#pragma once
#include <mutex>
#include <vector>
#include "Product.h"
class SuperMarket
{
private:
	std::vector<Product> products = std::vector<Product>();
	std::vector<int> amountOfSoldProducts;
	std::mutex mmmoneymutex;
	int money;
	int realMoney;
public:
	SuperMarket();
	SuperMarket(std::vector<Product> products);
	int getMoney();
	int getRealMoney();
	int getProductCost(int id);
	void addProduct(std::string productName, int price, int id);
	void sellProduct(int id, int quantity);
	void buyProduct(int id, int quantity);
	void sellOrder(std::vector <std::pair<int, int>> comanda);
	void buyOrder(std::vector <std::pair<int, int>> comanda);
	~SuperMarket();
};

