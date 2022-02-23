#pragma once
#include <iostream>

enum Types {
	_Void,
	_Bool,
	_Int,
	_String
};

class Type
{
private:
	bool _isTemp = false;
public:
	int _type = -1;
	Type(int type);	

	void setIsTemp(const bool isTemp);
	bool getIsTemp() const;

	virtual void* getValue() const = 0;
	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;
};
