#include<iostream>
#include<algorithm>
#include <ctime>
#include "AMergeSort.h"
using namespace std;

int main() {
	cout << "test1 begins --------------------------------------------" << endl;
	//随机生成一个数组
	cout << "随机生成数组 : ";
	srand((unsigned)time(0));
	int* arr = new int[10];
	for (int i = 0; i<10; i++) {
		arr[i] = rand() % 99;
		cout << arr[i] << " ";
	}
	cout << endl;

	//排序
	//sort(arr, arr + 10);
	
	int* temp = new int[10]; //辅助数组
	AMergeSort(arr, temp, 0, 9);

	//打印排序后的数组
	cout << "排序后的数组 : ";
	for (int i = 0; i<10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "test1 ends ---------------------------------------------" << endl;
}