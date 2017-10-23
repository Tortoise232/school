#include "stdafx.h"
#include "SuperMarket.h"
#include <iostream>
#include <thread>

#define STARTING_SUM 100;
SuperMarket::SuperMarket()
{
	
	this->money = 1000000;
	this->addProduct("Mere", 10, 0);
	this->addProduct("Portocale", 16, 1);
	this->addProduct("Biciclete", 40, 2);
	this->buyProduct(0, 1000);
	this->buyProduct(1, 1000);
	this->buyProduct(2, 1000);

	this->money = STARTING_SUM;
	this->realMoney = this->money;
	this->amountOfSoldProducts = std::vector<int>(3);

}

int SuperMarket::getProductCost(int id) {
	for (auto product : this->products)
		if (product.getID() == id)
			return product.getPrice();
}

SuperMarket::SuperMarket(std::vector<Product> products)
{
	this->products = products;
}

int SuperMarket::getMoney()
{
	return this->money;
}

int SuperMarket::getRealMoney() {
	return this->realMoney;
}

void SuperMarket::addProduct(std::string name, int price, int id)
{
	this->products.push_back(Product(id, price, name)); 
}

void SuperMarket::sellProduct(int id, int quantity)
{
	for (int i = 0; i < products.size(); i ++) {
		if (products[i].getID() == id) {
			this->mmmoneymutex.lock();
			if (products[i].removeQuantity(quantity)) {//transaction went ok
				std::cout << "I just sold " << quantity << " of " << products[i].getID() << " for " << quantity * products[i].getPrice()  << "\n";
				money += quantity * products[i].getPrice();
			}
			else
				std::cout << "I couldn't sell " << quantity << " of " << products[i].getID() << "out of my total " << products[i].getQuantity()  << "\n";
			this->mmmoneymutex.unlock();
		}
	}
}

void SuperMarket::buyProduct(int id, int quantity)
{	
	for (int i = 0; i < products.size(); i++) {
		if (products[i].getID() == id) {
			this->mmmoneymutex.lock();
			if (money > quantity * products[i].getPrice()) {
				std::cout << " I just bought " << quantity << " of " << products[i].getID() << " for " << quantity * products[i].getPrice() << "(" << std::this_thread::get_id << ")" << "\n";
				products[i].addQuantity(quantity);
				money -= quantity * products[i].getPrice();
			}
			else
				std::cout << " I couldn't buy " << quantity << " of " << products[i].getID() <<  "(" << std::this_thread::get_id << ")" << " \n";
			this->mmmoneymutex.unlock();
		}
	}
}

void SuperMarket::sellOrder(std::vector <std::pair<int, int>> comanda)
{	

	for (auto pair : comanda) {
		if (this->products.at(pair.first).getQuantity() >= pair.second) {
			std::cout << "I just sequentially sold " << pair.second << " of " << pair.first << " for " << this->getProductCost(pair.first) * pair.second <<"\n";
			this->realMoney += this->getProductCost(pair.first) * pair.second;
		}
	}

	std::vector<std::thread> threadVector = std::vector<std::thread>();
	for (int i = 0; i < comanda.size(); i ++) {
		std::thread myThread(&SuperMarket::sellProduct,this, comanda[i].first, comanda[i].second);
		threadVector.push_back(move(myThread));
	}
	
	while (threadVector.size() > 0) {
		threadVector.back().join();
		threadVector.pop_back();
	}
}

void SuperMarket::buyOrder(std::vector <std::pair<int, int>> comanda) {
	for (auto item : comanda) {
		this->buyProduct(item.first, item.second);
	}
}


SuperMarket::~SuperMarket()
{

}
