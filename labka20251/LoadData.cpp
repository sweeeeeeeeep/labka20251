#include "LoadData.h"
#include <iostream>

std::vector<product_data> LoadData::getData()
{
	open();
	if (isOpenSucsess())
	{
		auto result = download();
		close();
		return result;
	}
	erorrOpen();
	return std::vector<product_data>();
}

void LoadData::erorrOpen() const
{
	std::cout << "Error open file" << std::endl;
}

void LoadData::erorrFormat() const
{
	std::cout << "Error format file" << std::endl;
}
