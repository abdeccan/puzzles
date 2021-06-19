#include <iostream>
#include <map>

int main()
{
	try
	{
		std::map<int, char> mymap;
		std::map<int, char>::iterator iter = mymap.begin();

		mymap.insert(mymap.end(), std::make_pair<int, char>(0, 'A'));
		mymap.insert(mymap.end(), std::make_pair<int, char>(1, 'b'));
		mymap.insert(mymap.end(), std::make_pair<int, char>(2, 'c'));

		iter = mymap.find(6);
		//iter = mymap.erase(iter);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "hello world" << std::endl;
	return 0;
}