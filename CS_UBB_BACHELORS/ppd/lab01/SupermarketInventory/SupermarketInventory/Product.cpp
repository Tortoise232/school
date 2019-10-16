#include "stdafx.h"
#include "Product.h"


Product::Product()
{
}


Product::~Product()
{
}

int Product::getID() {
	return this->id;
}

int Product::getPrice()
{
	return this->price;
}

int Product::getQuantity()
{
	return this->quantity;
}

std::string Product::getName()
{
	return this->name;
}

std::mutex & Product::getMutex()
{
	return this->mut;
}

Product::Product(int id,int price, int quantity, std::string name) {
	this->id = id;
	this->price = price;
	this->quantity = quantity;
	this->name = name;
}

Product::Product(int id, int price, std::string name)
{
	this->id = id;
	this->price = price;
	this->name = name;
	this->quantity = 0;
}

void Product::addQuantity(int quantity) {
	this->mut.lock();
	this->quantity += quantity;
	this->mut.unlock();
}

bool Product::removeQuantity(int quantity) {
	this->mut.lock();
	if (this->quantity >= quantity) {
		this->quantity -= quantity;
		this->mut.unlock();
		return true;
	}
	this->mut.unlock();
	return false;	
}

const Product & Product::operator=(const Product & prod)
{
	return prod;
}

