#include <iostream>
#include <string>
#include "Myvector.hpp"

template<typename _Vector>
void printvector(_Vector vec,int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void test01()
{
	std::vector<int> v1;

	for (int i = 0; i < 61; i++)
	{
		v1.push_back(i);
	}
	v1.insert(3, 1231);
	//printvector(v1, v1.Size());
	for (int i = 0; i < 62; i++)
	{
		std::cout << v1[i] << " ";
	}

	std::cout << v1.back() << std::endl;

	v1.push_front(321);

	//printvector(v1, v1.Size());

}



int main()
{
	test01();


	std::system("pause");
	return 0;
}