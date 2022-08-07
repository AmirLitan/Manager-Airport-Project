#include "AccessKey.h"

AccessKey::AccessKey(AccessoriesTools* accessoriesTools, bool hasKey)
	: AccessoriesTools(accessoriesTools), hasKey(hasKey)
{
}

void AccessKey::printAccessproes() const
{
	AccessoriesTools::printAccessproes();
	std::cout << ", has key " << std::endl;
}
