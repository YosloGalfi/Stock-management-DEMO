#include "Item.h"

Item::Item()
{
	this->name = "";
	this->articleNumber = "";
	this->location = "";
	this->amount = 0;
}

Item::Item(std::string name, std::string articleNumber, std::string location, int amount)
{
	this->name = name;
	this->articleNumber = articleNumber;
	this->location = location;
	this->amount = amount;
}

Item::~Item()
{
}

void Item::SetName(const std::string name)
{
	this->name = name;
}

void Item::SetArticleNumber(const std::string articleNumber)
{
	this->articleNumber = articleNumber;
}

void Item::SetLocation(const std::string location)
{
	this->location = location;
}

void Item::SetAmount(const int number)
{
	this->amount = number;
}

const std::string Item::GetName() const
{
	return this->name;
}

const std::string Item::GetArticleNumber() const
{
	return this->articleNumber;
}

const std::string Item::GetLocation() const
{
	return this->location;
}

const int Item::GetAmount() const
{
	return this->amount;
}
