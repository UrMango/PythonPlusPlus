#pragma once
#include "Sequence.h"

class String : public Sequence
{
private:
	std::string _value = "";
public:
	String(std::string value);
	~String();

	bool isPrintable() const override;
	std::string toString() const override;
};

