#include "Crate.h"
Crate::Crate()
{
	this->name = "";
	this->articleNumber = "";
	this->location = "";

}

Crate::Crate(std::string name, std::string articleNumber, std::string location, int numberOfItems)
{
	this->name = name;
	this->articleNumber = articleNumber;
	this->location = location;
	//this->items.resize(numberOfItems);
}

Crate::~Crate()
{
}

void Crate::SetName(const std::string name)
{
	this->name = name;
}

void Crate::SetArticleNumber(const std::string articleNumber)
{
	this->articleNumber = articleNumber;
}

void Crate::SetLocation(const std::string location)
{
	this->location = location;
}

void Crate::AddItem(Item newItem)
{
	this->items.push_back(newItem);
}

bool Crate::DeleteItem(std::string articleNumber)
{
	for (int i = 0; i < this->items.size(); i++)
	{
		if (this->items[i].GetArticleNumber() == articleNumber)
		{
			//this->items.
		}
	}
	return false;
}

const std::string Crate::GetName() const
{
	return this->name;
}

const std::string Crate::GetArticleNumber() const
{
	return this->articleNumber;
}

const std::string Crate::GetLocation() const
{
	return this->location;
}

const size_t Crate::GetItemCount() const
{
	return size_t();
}

Item Crate::GetItem(std::string articleNumber)
{
	return Item();
}

std::vector<Item> Crate::GetAllItems()
{
	return std::vector<Item>();
}
