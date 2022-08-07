#pragma once
#include "Accessories.h"

class AccessoriesTools : public Accessories
{
	AccessoriesTools* accessoriesTools;
public:
	AccessoriesTools(AccessoriesTools* accessoriesTools);
	~AccessoriesTools();

	virtual void printAccessproes() const override;
		
};

