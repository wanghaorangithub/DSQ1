#pragma once
#ifndef LIST
#define LIST
#include <iostream>

template<typename T>
class ArrayList {
private:
	int size = 0;
	T *head;
public:

	ArrayList(int size) :size(size), head(new T[size]) {};
	~ArrayList()
	{
		delete[]head;
	}
	bool deletetDataFromArrayList(int &position) {
		if (position < size) {
			for (int i = position; i + 1 < size; i++)
				head[i] = head[i + 1];
			size--;
			return true;
		}
		else
			return false;
	}
	int getSize() { return size; }
	bool set(T data, int &position) {
		if (position < size) {
			head[position] = data;
			return true;
		}
		else
			std::cout << "Over filled!" << std::endl;
		return false;
	}
	T get(int &position) {
		if (position < size) {
			return head[position];
		}
		else {
			std::cout << "Over filled!" << std::endl;
			return 0;
		}
	}

};
#endif // !LIST