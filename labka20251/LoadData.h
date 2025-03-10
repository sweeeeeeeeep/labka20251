#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

using product_data = std::map<std::string, std::string>;
class LoadData
{
public:
	virtual void open() = 0;
	virtual bool isOpenSucsess() const = 0;
	virtual std::vector<product_data> download() = 0;
	virtual void close() = 0;

	virtual std::vector<product_data> getData();
	virtual void erorrOpen() const;
	virtual void erorrFormat() const;


};

