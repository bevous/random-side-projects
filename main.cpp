#include <string> 
#include <iostream>
#include <fstream>
#include <set>


int main()
{
	while (true)
	{
		int size = 0;
		std::string str = "";
		std::cout << "enter the characters ";
		std::cin >> str;
		std::cout << "enter the size ";
		std::cin >> size;
		std::ifstream infile;
		infile.open("words.txt");
		std::string temp = "";
		bool letter_is_good = false;
		while(std::getline(infile,temp))
		{
			for (auto letter : str)
			{
				if(temp[0]==letter && temp.length()==size)
				{
					for (auto letter2 : temp)
					{
						letter_is_good=false;
						for (auto character : str)
						{
							
							if(!letter_is_good)
							{
								letter_is_good = letter2 == character;
							}
						}
						if(!letter_is_good)
						{
							break;
						}
					}
					if(letter_is_good)
					{
						std::set<char> characters;
						for (auto letter : temp)
						{
							characters.insert(letter);
						}
						if (characters.size() == temp.length()) {
							std::cout << temp << std::endl;
						}
					}
				}
			}
		}

		infile.close();

		std::cout << "done reading" << std::endl;
		getchar();
	}
}