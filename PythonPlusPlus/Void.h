#pragma once
#include "Type.h"

class Void : public Type
{
public:
	Void(bool isTemp);
	~Void();

	void* getValue() const override;
	bool isPrintable() const override;
	std::string toString() const override;
};

