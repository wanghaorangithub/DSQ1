// DSQ1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include "arraylist.h"
#include "linklist.h"
void solveTheProblemWithArrayList(int n, int s, int m); 
void solveTheProblemWithLinkList(int n, int s, int m);
int main()
{
	int n = 0, s = 0, m = 0;
	std::cout << "please enter three number" << std::endl;
	std::cout << "n:";
	std::cin >> n;
	std::cout << "s:";
	std::cin >> s;
	std::cout << "m:";
	std::cin >> m;
	solveTheProblemWithArrayList(n, s, m);
	solveTheProblemWithLinkList(n, s, m);
	return 0;
}
void solveTheProblemWithArrayList(int n, int s, int m) {
	int position = 0, result = 0;
	//initial arrayList
	ArrayList <int> *arrayList = new ArrayList<int>(n);
	for (int i = 1; i <= n; i++) {
		position = i - 1;
		arrayList->set(i, position);
	}
	//get result
	position = s;
	std::cout << "the result in ArrayList is:";
	while (arrayList->getSize() > 0) {
		position = (position + m - 2) % arrayList->getSize();
		result = arrayList->get(position);
		std::cout << result << " ";
		arrayList->deletetDataFromArrayList(position);
		position++;
	}
	std::cout << std::endl;
	delete arrayList;
}
void solveTheProblemWithLinkList(int n, int s, int m) {
	int position = 0, result = 0;
	//initial linkList
	LinkList <int> *linkList = new LinkList<int>(n);
	for (int i = 1; i <= n; i++) {
		position = i - 1;
		linkList->set(i, position);
	}
	//get result
	position = s;
	std::cout << "the result in LinkList is:";
	while (linkList->getSize() > 0) {
		position = (position + m - 2) % linkList->getSize();
		result = linkList->get(position);
		std::cout <<  result << " ";
		linkList->deletetDataFromLinkList(position);
		position++;
	}
	std::cout << std::endl;
	delete linkList;
}