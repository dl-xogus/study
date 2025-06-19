#pragma once

#include <iostream>
using LData = int;

class ArrayList
{
private:
	static const int LIST_LEN = 100;
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;

public:
	ArrayList();

	void Insert(LData data);
	bool First(LData& data);
	bool Next(LData& data);
	LData Remove();
	int Count() const;
};