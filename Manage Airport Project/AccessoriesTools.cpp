#include "AccessoriesTools.h"

AccessoriesTools::AccessoriesTools(AccessoriesTools* accessoriesTools)
	: accessoriesTools(accessoriesTools)
{
}

AccessoriesTools::~AccessoriesTools()
{
	delete accessoriesTools;
}

void AccessoriesTools::printAccessproes() const
{
	accessoriesTools->printAccessproes();
}
