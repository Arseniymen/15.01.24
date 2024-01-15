//Вставити задане число N в масив цілих чисел arr[n] (n>10) після першого від’ємного елементу;
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void Fill_arr(int* arr, int n) {
	for (int i = 0; i < n;  i++)
		*(arr + i) = rand() % 51 - 20;
}
void Print_arr(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << *(arr + i) << " ";
}
int main()
{
	int k;
	cout << " Which task" << endl;
	cin >> k;
	switch (k) {
	case 1: {
		int n, j;
		int m = 15;
		srand(time(NULL));
		cout << "enter N" << endl;
		cin >> n;
		int* arr = new int[m + 1];
		cout << "array: " << endl;
		Fill_arr(arr, m);
		Print_arr(arr, m);
		int mas = -1;
		for (int i = 0; i < m; i++) {
			if (*(arr + i) < 0) {
				mas = i;
				break;
			}
		}
		if (mas != -1 && n > 10) {
			*(arr + m) = n;
			for (int i = m, j = m - 1; j > mas; --i, --j) {
				*(arr + i) = *(arr + j);
			}
			*(arr + mas + 1) = n;
			cout << endl << " NEW array: " << endl;
			Print_arr(arr, m + 1);
		}
		else {
			cout << endl << " Nema nigativnogo" << endl;

		}
		delete[] arr;
	}break;
	case 2: {
		int n = 15;
		srand(time(NULL));
		int* arr = new int[n];
		Fill_arr(arr, n);
		cout << "array: " << endl;
		Print_arr(arr, n);
		int mas = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (*(arr + i) == 0) {
				mas = i;
				break;
			}
		}
		if (mas != -1) {
			int* newarr = new int[n - 1];
			for (int i = 0; i < mas; i++) {
				*(newarr + i) = *(arr + i);
			}
			for (int i = mas; i < n - 1; i++) {
				*(newarr + i) = *(arr + i + 1);
			}
			cout << endl << "New array: " << endl;
			Print_arr(newarr, n - 1);
			delete[] newarr;
		}
		else {
			cout << endl << "Nema" << endl;
			delete[] arr;
			break;
		}
	}
		  return 0;
	}




