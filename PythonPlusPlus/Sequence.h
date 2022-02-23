#pragma once
#include "Type.h"

class Sequence : public Type
{
public:
	Sequence(int type);

	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;
};

