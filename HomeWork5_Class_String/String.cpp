#include "String.hpp"

String::String() {
	this->length_ = 80;
	this->data_ = new char[length_];
	for (int i = 0; i < length_; ++i)
		data_[i] = '-';
}

String::String(int length) {
	this->length_ = length;
	this->data_ = new char[length_];
	for (int i = 0; i < length_; ++i)
		data_[i] = '-';
}

void String::Print() const {
	if (data_ == nullptr)
		std::cout << "\033[92m''\033[0m \033[90m{The object is empty!)\033[0m";
	else
		for (int i = 0; i < length_; ++i)
			std::cout << "\033[92m" << data_[i] << "\033[0m";
	std::cout << std::endl << "The length of object is \033[92m" << length_ << " \033[0m" << std::endl;
}

void String::Cleaning() {
	if (data_ == nullptr)
		return;
	delete[] data_;
	data_ = nullptr;
	length_ = 0;
}

void String::AddText() {	
	if (data_ == nullptr) { // Если в исходной строке ничего не было, то просто перенаправляем указатель на созданный массив символов 
		this->data_ = SetPointer();
		this->length_ = strlen(data_);
		return;
	}
	// Если в исходной строке был текст, то дополняем его
	char* pointer = SetPointer(); // Временный массив для хранения результата фукнции SetPointer()
	int size = strlen(pointer);
	char* tmp = new char[length_ + size]; // Создаём новый массив с актуализированныйм текстом
	for (int i = 0; i < length_ + size; ++i)
		if (i < length_)
			tmp[i] = data_[i];
		else
			tmp[i] = pointer[i - length_];
	this->length_ += size; // Новое значение размера массива
	delete[] data_; // Чистим память из под данных объекта
	this->data_ = tmp; // Перенаправляем указатель на новый массив
	delete[] pointer; // Чистим память из под временного массива
	pointer = nullptr;
}

char* SetPointer() {
	std::cout << "Enter the text -> ";
	char* tmp = new char[255]; // на время выделяем память с запасом под строку
	std::cin.ignore(); // Чистим консоль, чтобы коректно в слудеющем действии считать символ '\n' для прекращения ввода строки
	std::cin.getline(tmp, 255, '\n'); // считываем введённую строку символов из консоли	
	int size = strlen(tmp) + 1; // последний символ в строке оставляем под нуль-терминатор
	char* pointer = new char[size]; // выделяем новую память под размер введённой пользователем строки	
	for (int i = 0; i < size - 1; ++i)
		pointer[i] = tmp[i];
	pointer[size - 1] = '\0';
	delete[] tmp; // освобождаем память из под временного дин.массива символов
	return pointer;
}
