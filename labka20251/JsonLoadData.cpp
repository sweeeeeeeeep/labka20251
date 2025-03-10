#include "JsonLoadData.h"

JsonLoadData::JsonLoadData(const std::string& FilePath) : FilePath(FilePath)
{
}


void JsonLoadData::open()
{
	file.open(FilePath);
}

bool JsonLoadData::isOpenSucsess() const
{
	return file.is_open();
}

std::vector<product_data> JsonLoadData::download()
{
	std::vector<product_data> data;
	nlohmann::json jsonData;
	file >> jsonData;

	for (auto& item : jsonData)
	{
		product_data product;
		for (auto it = item.begin(); it!=item.end(); ++it)
		{
			product[it.key()] = it.value();
		}
		data.push_back(product);
	}
	return data;
}

void JsonLoadData::close()
{
	if (file.is_open())
	{
		file.close();
	}
}
