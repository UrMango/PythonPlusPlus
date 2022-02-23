#pragma once
#include "Sequence.h"

class String : public Sequence
{
private:
	std::string _value = "";
public:
	String(std::string value, bool isTemp);
	~String();

	void* getValue() const override;
	bool isPrintable() const override;
	std::string toString() const override;
};

