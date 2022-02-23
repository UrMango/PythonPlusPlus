#pragma once
#include "Type.h"
#include <iostream>
#include <string>

class Integer : public Type
{
private:
	int _value = 0;
public:
	Integer(int value, bool isTemp);
	~Integer();

	void* getValue() const override;
	bool isPrintable() const override;
	std::string toString() const override;
};

