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