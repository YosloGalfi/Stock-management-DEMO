#pragma once

#include <string>
class Item
{
private:
	std::string name;
	std::string articleNumber;
	std::string location;
	int amount;

	// DirectX texture?
	// DirectX model?

public:
	Item();
	Item(std::string name, std::string articleNumber, std::string location, int amount);
	~Item();

	void SetName(const std::string name);
	void SetArticleNumber(const std::string articleNumber);
	void SetLocation(const std::string location);
	void SetAmount(const int number);

	const std::string GetName() const;
	const std::string GetArticleNumber() const ;
	const std::string GetLocation() const;
	const int GetAmount() const;
}; 
