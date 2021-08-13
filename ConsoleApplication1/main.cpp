#include<iostream>
#include<vector>
#include<fstream>
#include "sortDemo.h"
using namespace std;

//void fun(int length,int* a) {  //传入一个指针
//	cout << a[2] << endl;
//}

int main() {
	ifstream fin("input.txt");
	vector<int> d;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		register int tmp;
		cin >> tmp;
		d.push_back(tmp);
	}

	mergeSort(d, 0, n - 1);
	//merge(d, 0, (n - 1) / 2, n - 1);
	/*for (int start = 1; start < n; start++) {
		register int tmp = d[start], p;
		for (p = start - 1; d[p] > tmp && p >= 0; p--) {}
		d.insert(d.begin() + p + 1, tmp);
		d.erase(d.begin() + start + 1);
	}*/

	for (int i = 0; i < n; i++) {
		cout << d[i] << " ";
	}

	/*int dis = 50;
	int* d = new int[dis];
	fun(dis, d);*/  //可以考虑在传入动态数组的情况下传入一个衡量数组长度的一个指针

	//	vector<int> a;
	//	auto it=a.begin();
	//	a.push_back(1); a.push_back(2);
	//
	////	for (auto i = a.begin(); i != a.end(); ++i) {  //用迭代器遍历容器
	////		cout << *i << " ";  //*i 就是迭代器i指向的元素
	//////		*i *= 2;  //每个元素变为原来的2倍
	////	}
	//
	//	cout << *it << endl;


	return 0;
}