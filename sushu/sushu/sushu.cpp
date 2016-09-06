#include<iostream>
#include<string>
using namespace std;
/*
------------------------------------------------------------------------------
	*  创建时间 : 2016/8/30
	*  创建人 : ACJ
	*  文件描述 : 素数类
	*  功能描述 : 1.用{"筛法"}找出并存储小于N的所有正素数
						2.快速判断一个小于N的正整数是否为素数
						3.用平凡方法判断一个正整数是否为素数
						4.将重要数据封装为只读。
						(当N<1024时，自动将N提高到1024）
------------------------------------------------------------------------------
*/
class Sushu {
private:
	bool* mark;      //筛法 的筛表
	int* members;  //已记录的素数数组
	int maxInt;        //该实例的最大整数
	int number;      //已记录的素数个数
	string errInfo;   //错误信息

public:
	Sushu(int max) ;                             //申请内存并调用筛法函数   (当N<1024时，自动将N提高到1024）
	static bool isSushu_single(int x) ;   //平凡方法判别素数 
	bool isSushu(int x) const;               //从已标记数组中判别素数
	void printAll(int n = 0 ) const;        //打印出所以小于n的素数  (当N<=1时,或当N>maxInt时，自动调整到maxInt）
	void showMembers() const;           //打印出所以小于n的素数  (当N<=1时,或当N>maxInt时，自动调整到maxInt）
	int length()const;                            //返回已记录素数的个数
	int* cpArr()const;                            //深复制素数数组

	
private:
	void shaifa();
	void append(int x);
};

/*申请内存并调用筛法函数*/
Sushu::Sushu(int max = 1024){
	//	(当N<1024时，自动将N提高到1024）
	if (max <= 1024) {
		maxInt = 1024;
	} else {
		maxInt = max;
	}
	//初始化各个数据
	mark = new bool[maxInt + 1];
	for (int i = 2; i <= maxInt; i++) {
		mark[i] = true;
	}
	members = new int[maxInt];
	number = 0;
	string errInfo = "";
	shaifa();
}
/*运行筛法*/
void Sushu::shaifa(){
	int p = 2;
	int half = int(floor(sqrt(maxInt)));

	while (p <= half) {
		append(p);
		for (int i = p; p*i <= maxInt; i++) {
			mark[p*i] = false;
		}
		p++;
		while (p <= half && mark[p] == false) {
			p++;	
		}
	}
	//将筛余下的数字压入数组
	while (p <= maxInt  && mark[p] == false) {
		p++;
	}
	while (p <= maxInt) {
		append(p);
		p++;
		while (p <= maxInt && mark[p] == false) {
			p++;
		}
	}
}

/*在数组中添加一个素数成员*/
void Sushu::append(int x){
	members[number] = x;
	number++;
}

/*判断是否为素数*/
bool Sushu::isSushu(int x) const{
	if (x < 0) {
		x = -x;
	}
	if (x <= 1) {
		return false;
	}
	if (x > maxInt) {
		return isSushu_single(x);
	}
	return mark[x];
}

/*打印出所以小于n的素数  (当N<=1时,或当N>maxInt时，自动调整到maxInt）*/
void Sushu::printAll(int n) const{
	if (n >= maxInt || n <=1) {
		n = maxInt;
	}

	cout << "不大于 " << n << " 的素数有：" << endl;
	for (int i = 2; i<= n ; i++) {
		if (mark[i]) {
			cout << i << '\t';
		}
	}
	cout << endl << endl;;
}

/*打印出已经记录的素数*/
void Sushu::showMembers() const {
	cout << "已经记录的素数有：" << endl;
	for (int i = 0; i < number; i++) {
			cout << members[i] << '\t';
	}
	cout << endl;
	cout << "共" << number << "个";
	cout << endl;
}
/*返回已记录素数个数*/
int Sushu::length() const
{
	return number;
}

/*深复制素数数组*/
int* Sushu::cpArr() const
{
	int* heap = new int[maxInt];
	for (int i = 0; i < number; i++) {
		heap[i] = members[i];
	}
	return heap;
}

/*平凡方法判别素数*/
bool Sushu::isSushu_single(int x){
	if (x < 0) {
		x = -x;
	}
	if (x <= 1) {
		return false;
	}

	int half = int (floor(sqrt(x)));

	for (int i = 2; i <= half; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	cout << "请输入一个正整数N (N>=2)" << endl;
	int x;
	if (!(cin >> x ) || x <= 2) {
	cout << "输入错误,程序将退出" << endl;
	system("pause");
	return 0;
	}

	Sushu* sushu = new Sushu(x);
	sushu->printAll(x);
	sushu->showMembers();

	system("pause");
	return 1;



	//该类更多用法如下


	/*
	------------------------------------------------------------------------------
	获取只读成员的值、深复制已记录的素数数组
	_____调用  Sushu::length() 函数____
	_____调用  Sushu::cpArr()   函数____
	cout << sushu->length() <<endl;
	int* arr = sushu->cpArr();
	for (int i = 0; i < sushu->length(); i++) {
		cout << arr [i] << ' ';
	}
	cout << endl;
	------------------------------------------------------------------------------
	*/

	/*
	------------------------------------------------------------------------------
	用筛法筛过的标记数组判别素数：  (当数字不在筛表里，自动改用平凡判别方法）
	_____调用  Sushu::isSushu 函数____
	int bar = 17;
	if (sushu->isSushu(bar)) {
	cout << "是素数" << endl;
	}
	else {
	cout << "不是素数" << endl;
	}
	------------------------------------------------------------------------------
	*/


	/*
	------------------------------------------------------------------------------
	用平凡方法判别素数：
	_____调用  Sushu::isSushu_single() 函数____
	int foo =0;
	if (Sushu::isSushu_single(foo)) {
		cout << "是素数" << endl;
	} else {
		cout << "不是素数" << endl;
	}
	------------------------------------------------------------------------------
	*/
}


