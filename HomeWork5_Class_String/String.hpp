#pragma once
#include<iostream>

class String {
public:	
	// String():length_(80),data_(nullptr) {} // Конструктор по умолчанию, если мы не хотим выделять память под несуществующий объект	
	String(); // Прототип конструктора по умолчанию
	// String(int length):length_(length),data_(nullptr){} // Параметрический конструктор по переданной длине строки, если мы не хотим выделять память под несуществующий объект
	String(int length); // Прототип параметрического конструктора с указанием конкретной длины строки
	String(char* pointer):length_(strlen(pointer)),data_(pointer){} // Параметрический конструктор по переданной строке
	~String() { delete[] data_; };
	// Блок гэттэров
	//char* GetAdress()const { return data_; }
	//int GetLength()const { return length_; }
	//char GetSymbol(int i)const { return data_[i]; }
	// Блок сэттэров
	void SetData(char* pointer) { this->data_ = pointer; }	
	void Print()const; // Метод для вывода объекта на экран
	void Cleaning(); // Метод для чистки содержимого объекта
	void AddText(); // Метод для добавления текста в объект
private:
	char* data_; // Указатель на адрес памяти хранения первого элемента динамического массива символов
	int length_; // Длина массива символов (длина строки)
};

char* SetPointer(); // Прототип функции для определения указателя на массив символов, введённых пользователем