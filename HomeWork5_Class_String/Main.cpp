# include <iostream>
#include"String.hpp"

void changing(char symbol, String &obj);

int main() {
	// ----------------- Создание исходных объетов тремя типами конструкторов по условию задачи ----------------
	std::cout << "\033[91mStep 1. Creating source objects.\033[0m" << std::endl << "Enter the length of the object 's2' -> ";
	int length;
	std::cin >> length;
		
	String s1; 
	String s2(length);		
	std::cout << "Enter the text to fill in the object 's3'. ";
	String s3(SetPointer());
	
	// ----------------- Вывод информации об исходных объектах -------------------
	std::cout << std::endl << "\033[91mStep 2. The information about source objects.\033[0m" << std::endl << "The following default objects were successfully created:\n\ns1 = ";
	s1.Print();
	std::cout << "\ns2 = ";
	s2.Print();
	std::cout << "\ns3 = ";
	s3.Print();

	// ----------------- Изменение объектов -------------------
	std::cout << std::endl << "\033[91mStep 3. Changing objects.\033[0m" << std::endl;
	char my_choice;
	std::cout << std::endl << "\033[93mWhat do you want to do with the object 's1'?\033[0m" << std::endl << "Press \033[91m'1'\033[0m to add" << std::endl << "Press \033[91m'2'\033[0m to overwrite" << std::endl << "Press \033[91many other key\033[0m if object 's1' suit you" << std::endl << "Your choice -> ";
	std::cin >> my_choice;	
	changing(my_choice, s1);	
	std::cout << std::endl << "\033[93mWhat do you want to do with the object 's2'?\033[0m" << std::endl << "Press \033[91m'1'\033[0m to add" << std::endl << "Press \033[91m'2'\033[0m to overwrite" << std::endl << "Press \033[91many other key\033[0m if object 's1' suit you" << std::endl << "Your choice -> ";
	std::cin >> my_choice;	
	changing(my_choice, s2);
	std::cout << std::endl << "\033[93mWhat do you want to do with the object 's3'?\033[0m" << std::endl << "Press \033[91m'1'\033[0m to add" << std::endl << "Press \033[91m'2'\033[0m to overwrite" << std::endl << "Press \033[91many other key\033[0m if object 's1' suit you" << std::endl << "Your choice -> ";
	std::cin >> my_choice;	
	changing(my_choice, s3);

	return 0;
}

void changing(char symbol, String& obj) {
	switch (symbol)	{
	case '1':
		obj.AddText();
		obj.Print();
		break;
	case '2':
		obj.Cleaning();
		obj.AddText();	
		obj.Print();
		break;
	default:
		obj.Print();
	}
}
