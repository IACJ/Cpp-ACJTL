#pragma once
#include<algorithm>
using namespace std;

/** mini_qsort
*@param arr 要排序的数组
*@param l  要排序的左边界
*@param r 要排序的右边界
*/
void ACJ_qsort(int* arr, int l, int r) {
	//三行初始化
	int i = l;
	int j = r;
	int halfVal = arr[(l + r) / 2];
	//快排
	while (i<=j){
		while (arr[i] < halfVal) { i++; }
		while (arr[j] > halfVal) { j--; }
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	//递归
	if (i < r) { ACJ_qsort(arr, i, r); }
	if (j > l) { ACJ_qsort(arr, l, j); }
	//结束了，这个快排真是又短又好用……
}
