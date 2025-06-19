#include <iostream>
#include "ArrayList.hpp"

int main()
{
	ArrayList list;
	LData data;

	list.Insert(11); list.Insert(11);
	list.Insert(22); list.Insert(22);
	list.Insert(33);

	std::cout << "현재 데이터의 수: " << list.Count() << "\n";
	
	if (list.First(data))
	{
		std::cout << data << " ";

		while (list.Next(data))
			std::cout << data << " ";
	}
	std::cout << "\n\n";

	if (list.First(data))
	{
		if (data == 22)
			list.Remove();

		while (list.Next(data))
		{
			if (data == 22)
				list.Remove();
		}
	}

	std::cout << "현재 데이터의 수: " << list.Count() << "\n";

	if (list.First(data))
	{
		std::cout << data << " ";

		while (list.Next(data))
			std::cout << data << " ";
	}
	std::cout << "\n\n";

	return 0;
}