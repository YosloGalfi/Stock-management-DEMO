#pragma once
#include "Item.h"
#include <vector>

class Crate
{
private:
	std::string name;
	std::string location;
	std::string articleNumber;
	std::vector<Item> items;
	
public:
	Crate();
	Crate(std::string name, std::string articleNumber, std::string location, int numberOfItems);
	~Crate();

	void SetName(const std::string name);
	void SetArticleNumber(const std::string articleNumber);
	void SetLocation(const std::string location);
	void AddItem(Item newItem);
	bool DeleteItem(std::string articleNumber);

	const std::string GetName() const;
	const std::string GetArticleNumber() const;
	const std::string GetLocation() const;
	const size_t GetItemCount() const;
	Item GetItem(std::string articleNumber);
	std::vector<Item> GetAllItems();
};