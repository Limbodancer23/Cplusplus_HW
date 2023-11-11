#include <iostream>

/*
1)Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. Вызвать эту функцию из main.
2)Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0.
Выводить на экран массив до изменений и после.
3)Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.
4)* Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), при этом метод должен циклически сместить
все элементы массива на n позиций.
5)** Написать функцию, которой передается не пустой одномерный целочисленный массив, она должна вернуть истину если в массиве есть место,
в котором сумма левой и правой части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false, checkBalance ([10, || 1, 2, 3, 4]) → true.
Абстрактная граница показана символами ||, эти символы в массив не входят.*/

void printArr(int size, double* arr); //Прототип функции
void changeValues(int size, int* arr);
void fillArray(int size, int* arr);
void arrayOffset(int n, int size, int* arr);
void EqualityFinder(int size, int* arr);

int main()
{
	/*const int size = 10;
	double array[size];
	printArr(size, array);*/
	/*int myArr[]{ 1,0,1,0,1,0,0 };
	changeValues(_countof(myArr), myArr);*/

	/*int newArray[8];
	fillArray(_countof(newArray), newArray);*/


	//int arr[]{ 1,2,3,4,8,3,1 };
	//int n = 0;
	//std::cout << "Enter number: ";
	//std::cin >> n;
	//arrayOffset(n, _countof(arr), arr);

	int qeArr[]{ 2, 3, 2, 6, 1 };
	EqualityFinder(_countof(qeArr), qeArr);
}

void printArr(int size, double* arr) {
	srand(time(0));
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = (double)(rand() % 100) - 50;
		//static_cast<double>(rand() % 901 + 100) / 100.0;
		std::cout << arr[i] << " ";
	}
}

void print(int size, int* arr) {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void changeValues(int size, int* arr) {

	print(size, arr);

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = arr[i] == 1 ? 0 : 1;
	}

	print(size, arr);
}

void fillArray(int size, int* arr) {
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = i == 0 ? 1 : arr[i - 1] + 3;
	}
	print(size, arr);
}

//a = 4
//b = 8
//a = a + b = 12
//---------------------
//b = a - b = 4
//a = a - b = 8
// 1 2 3 4
// 




void arrayOffset(int n, int size, int* arr) {
	bool flag = false;

	print(size, arr);
	if (n > 0)
	{
		for (; n>0; n--)
		{
			for (size_t j = size - 1; j > 0; j--)
			{
				arr[j] = arr[j] + arr[j - 1];
				arr[j - 1] = arr[j] - arr[j - 1];
				arr[j] = arr[j] - arr[j - 1];
			}
		}
	}
	else
	{
		for (; n < 0; n++)
		{
			for (size_t j = 0; j < size - 1; j++)
			{
				arr[j] = arr[j] + arr[j + 1];
				arr[j + 1] = arr[j] - arr[j + 1];
				arr[j] = arr[j] - arr[j + 1];
			}
		}
	}

	print(size, arr);
}

void EqualityFinder(int size, int* arr) {

	int left = 0;
	int right = 0;
	bool flag = false;
	for (size_t i = 0; i < size; i++)
	{
		right = 0;
		left += arr[i];
		for (size_t j = i+1; j < size; j++)
		{
			right += arr[j];
		}
		if (left == right) flag = true;
	}
	if (flag)
	{
		std::cout << "True";
	}
	else
	{
		std::cout << "False";
	}

}

