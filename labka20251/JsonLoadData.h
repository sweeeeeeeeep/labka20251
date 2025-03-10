#pragma once
#include "LoadData.h"
#include <nlohmann/json.hpp>
#include <fstream>

class JsonLoadData :
    public LoadData
{
public:
	JsonLoadData(const std::string& FilePath);
    void open() override;
	bool isOpenSucsess() const override;
	std::vector<product_data> download() override;
	void close() override;
	
private:
	std::ifstream file;
	std::string FilePath;
};

