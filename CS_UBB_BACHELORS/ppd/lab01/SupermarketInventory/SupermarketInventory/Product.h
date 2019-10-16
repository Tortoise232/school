#pragma once
#include <vector>
#include <assert.h>
#include<mutex>

class Product
{
private:
	int price;
	int quantity;
	int id;
	std::mutex& mut = std::mutex();
	std::string& name = std::string();
public:
	Product();
	Product(int id, int price, int quantity, std::string name);
	Product(int id, int price, std::string name);
	void addQuantity(int quantity);
	bool removeQuantity(int quantity);
	const Product& operator=(const Product& prod);
	~Product();
	int getID();
	int getPrice();
	int getQuantity();
	std::string getName();
	std::mutex& getMutex();
};

