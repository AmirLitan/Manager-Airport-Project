#pragma once

#include "AccessoriesTools.h"
#include <iostream>
class AccessKey : AccessoriesTools
{
private:
	bool hasKey;
public:
	AccessKey(AccessoriesTools* accessoriesTools, bool hasKey);

	virtual void printAccessproes() const;
};

