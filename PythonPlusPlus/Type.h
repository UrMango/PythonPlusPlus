#pragma once
#include <iostream>

class Type
{
private:
	bool _isTemp = false;
public:
	void setIsTemp(const bool isTemp);
	bool getIsTemp() const;
	
	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;
};
