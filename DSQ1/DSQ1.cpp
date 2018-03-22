// DSQ1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include "arraylist.h"

int main()
{
	int n = 0, s = 0, m = 0;
	int position = 0,result=0;
	std::cout << "please enter three number" << std::endl;
	std::cout << "n:";
	std::cin >> n;
	std::cout << "s:";
	std::cin >> s;
	std::cout << "m:";
	std::cin >> m;
	//initial arrayList
	ArrayList <int> *arrayList = new ArrayList<int>(n);
	for (int i = 1; i <= n; i++) {
		position = i - 1;
		arrayList->set(i, position);
	}
	//get result
	position = s;
	while (arrayList->getSize() > 0) {
		position = (position + m - 2) % arrayList->getSize();
		result = arrayList->get(position);
		std::cout << result << " ";
		arrayList->deletetDataFromArrayList(position);
		position++;
	}
	return 0;
}

