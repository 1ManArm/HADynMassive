#include <iostream>
#include <cstdlib>
#include <ctime>

void fill_arr(int arr[], int size, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (max - min) + min;
}

template <typename T>
void show_arr(T arr[], int size) {
	std::cout << "[";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

void resize_arr(int*& arr, int size, int num) {
	if (num <= 0)
		return;
	int* tmp = new int[size + num] {};
	for (int i = 0; i < size; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}

int main() {
	setlocale(LC_ALL, "Russian");

	//Задание 1
	std::cout << "Задание 1.\n";
	int n1, m1;
	std::cout << "Длины массивов: ";
	std::cin >> n1 >> m1;
	int* A = new int[n1];
	int* B = new int[m1];
	fill_arr(A, n1, 10, 31);
	fill_arr(B, m1, 50, 71);
	std::cout << "Array A:\n";
	show_arr(A, n1);
	std::cout << "Array B:\n";
	show_arr(B, m1);
	int* C = new int[n1 + m1];
	for (int i = 0; i < n1; i++)
		C[i] = A[i];
	for (int i = n1; i < n1 + m1; i++)
		C[i] = B[i - n1];
	std::cout << "Array C:\n";
	show_arr(C, n1 + m1);
	delete[] A;
	delete[] B;

	//Задание 2.
	std::cout << "\n\nЗадание 2.\n";
	int size2, n2;
	std::cout << "Введите длину массива -> ";
	std::cin >> size2;
	int* arr2 = new int[size2];
	srand(time(nullptr));
	std::cout << "Массив:\n";
	for (int i = 0; i < size2; i++) {
		arr2[i] = rand() % 10 + 1;
		std::cout << arr2[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "Количество дополнительных элементов -> ";
	std::cin >> n2;
	resize_arr(arr2, size2, n2);
	size2 += n2;
	std::cout << "Итоговый массив:\n";
	for (int i = 0; i < size2; i++)
		std::cout << arr2[i] << ' ';
	std::cout << std::endl;

	return 0;
}