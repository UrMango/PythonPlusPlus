#pragma once
#include "Type.h"

class Boolean : public Type
{
private:
	bool _value = false;
public:
	Boolean(bool value, bool isTemp);
	~Boolean();

	bool isPrintable() const override;
	std::string toString() const override;
};

