#include<iostream>
#include<vector>
#include<fstream>
#include "sortDemo.h"
using namespace std;

//void fun(int length,int* a) {  //����һ��ָ��
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
	fun(dis, d);*/  //���Կ����ڴ��붯̬���������´���һ���������鳤�ȵ�һ��ָ��

	//	vector<int> a;
	//	auto it=a.begin();
	//	a.push_back(1); a.push_back(2);
	//
	////	for (auto i = a.begin(); i != a.end(); ++i) {  //�õ�������������
	////		cout << *i << " ";  //*i ���ǵ�����iָ���Ԫ��
	//////		*i *= 2;  //ÿ��Ԫ�ر�Ϊԭ����2��
	////	}
	//
	//	cout << *it << endl;


	return 0;
}