#include <string>
#include <iostream>


int main()
{


	std::string string;
	std::string substring;
	std::cin >> substring >> string;
	int length = string.length();	
	int sub_length = substring.length();
	
	int n = -1;
	int previous = 0;

	while(n < length)
	{
		n = string.find(substring, n + 1);
		if(n == -1)
		{
			for(int i(previous); i < length; ++i)
			{
				std::cout << string[i];
			}
			break;
		}
		
		for(int i(previous); i < n; ++i)
		{
			std::cout << string[i];
		}
		std::cout << substring;
		std::cout << "*";
		previous = n + sub_length;
	}
	std::cout << std::endl;

}



