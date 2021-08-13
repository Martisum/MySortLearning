#pragma once
#include<iostream>
#include<vector>
using namespace std;

void InsertSort(vector<int>& data, int dis = 1) {
	if (dis >= data.size()) return;
	for (int start = dis; start < data.size(); start++) {
		register int tmp = data[start], p;
		//		for (p = start - 1; data[p] > tmp && p >= 0; p-=dis) {}
		p = start - dis;  //改写为while形式方便调试
		while (p >= 0 && data[p] > tmp) {
			data[p + dis] = data[p];
			p -= dis;
		}

		data[p + dis] = tmp;

		/*auto i = data.begin() + dis + p;  //迭代器运算的时候，从左至右不能越界！！！！！！
		cout << *i << endl;*/
		//
		/*data.insert(data.begin() + dis + p, tmp);
		data.erase(data.begin() + start + 1);*/

		//		swap(data[start], data[dis+p]);  //直接傻逼交换是不行的啊……

		//		//下面这些代码可以采用vector_swap函数进行交换
		//		if (p >= 0) {
		//			data.insert(data.begin() + p + 1, tmp);
		//			data.erase(data.begin() + start + 1);
		//		}
		//		else if (p + dis == 0) {
		//			data.insert(data.begin(), tmp);
		//			data.erase(data.begin() + 1);
		////			data.insert(data.begin() + start);
		//			data.erase(data.begin() + start + 1);
		//		}
	}
}

void ShellSort(vector<int>& data) {
	//生成数组g
	long long g = 1;
	int G[1001] = { 0 };
	register int cnt = 0;
	while (g < data.size()) {
		G[++cnt] = g;
		g = g * 3 + 1;
	}

	for (int i = cnt; i >= 1; i--) {
		InsertSort(data, G[i]);
	}
	return;
}

//void InsertSort(vector<int>& d, int dis = 1) {
//    if (d.size() == 1) return;
//    // for(int start=1;start<d.size();start++){
//    //     register int tmp=d[start],p=start-1;
//    //     while(d[p]>tmp&&p>0) p--;
//
//    // }
//
//    for (vector<int>::iterator start = d.begin() + 1;
//        start < d.end(); start++) {
//        register auto p = start - 1;
//        // register int tmp=*start;
//        while (*p > *start) p--;
//        d.insert(p + 1, *start);
//        d.erase(start + 1);
//    }
//    return;
//}

void merge(vector<int>& data, int l, int mid, int r) {
	//这里的data数组不是一个切出来的数组，它就是原数组！
	register int l_length = mid - l + 1, r_length = r - mid;
	vector<int> l_side, r_side;
	//vector<int>* l_side = new vector<int>[mid - l + 1];


	for (int i = 0; i < l_length; i++)
		l_side.push_back(data[l + i]);
	for (int i = 0; i < r_length; i++)  //这里还需要取到mid，比l_side多了一个元素
		r_side.push_back(data[mid + i + 1]);

	register int pl = 0, pr = 0, p = l;
	while (pl < l_side.size() && pr < r_side.size()) {
		if (l_side[pl] < r_side[pr])
			data[p] = l_side[pl++];
		else
			data[p] = r_side[pr++];

		p++;
	}

	while (pl < l_side.size()) {
		data[p] = l_side[pl];
		p++; pl++;
	}
	while (pr < r_side.size()) {
		data[p] = r_side[pr];
		p++; pr++;
	}

	return;
}

void mergeSort(vector<int>& data, int l, int r) {
	//至少有三个元素才可以mergeSort，两个元素就直接看出来了
	if (l  < r) {
		register int mid = (l + r) / 2;
		mergeSort(data, l, mid);
		mergeSort(data, mid + 1, r);
		merge(data, l, mid, r);
	}
	return;
}