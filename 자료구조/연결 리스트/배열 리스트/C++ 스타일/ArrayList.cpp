#include "ArrayList.hpp"

ArrayList::ArrayList() : numOfData(0), curPosition(-1) {}

void ArrayList::Insert(LData data)
{
	if (numOfData >= LIST_LEN)
	{
		std::cout << "저장이 불가능합니다." << std::endl;
		return;
	}

	arr[numOfData++] = data;
}

bool ArrayList::First(LData& data)
{
	if (numOfData == 0)
		return false;

	curPosition = 0;
	data = arr[0];
	return true;
}

bool ArrayList::Next(LData& data)
{
	if (curPosition >= numOfData - 1)
		return false;

	data = arr[++curPosition];
	return true;
}

LData ArrayList::Remove()
{
	int rpos = curPosition;
	LData rdata = arr[rpos];

	for (int i = rpos; i < numOfData - 1; ++i)
		arr[i] = arr[i + 1];

	numOfData--;
	curPosition--;
	return rdata;
}

int ArrayList::Count() const
{
	return numOfData;
}