#pragma once
#include <mutex>
#include <vector>
#include "Product.h"
class SuperMarket
{
private:
	std::vector<Product> products = std::vector<Product>();
	std::mutex& mmmoneymutex = std::mutex();
	int money;
public:
	SuperMarket();
	SuperMarket(std::vector<Product> products);
	void addProduct(std::string productName, int price, int id);
	void sellProduct(int id, int quantity);
	void buyProduct(int id, int quantity);
	void sellOrder(std::vector <std::pair<int, int>> comanda);
	void buyOrder(std::vector <std::pair<int, int>> comanda);
	~SuperMarket();
};

