#pragma once
#ifndef LINKLIST
#define LINKLIST
#include <iostream>

template<typename T>
struct Node
{
	T data;
	Node<T>*next;
	Node(Node<T>*next = nullptr) { this->next = next; }
	Node(const T &data, Node<T> *next = nullptr) {
		this->data = data;
		this->next = next;
	}
};
template<typename T>
class LinkList
{
private:
	Node<T> *head;
		int size;
public:
	LinkList(int size) {
		this->size = size;
		head = new Node<T>;
		Node<T> *p = head;
		for(int i = 0;i<size;i++)
		{
			p->next = new Node<T>(nullptr);
			p = p->next;
		}
	}
	~LinkList() {
		Node<T>*tmp;
		while (head != nullptr) {
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	bool deletetDataFromLinkList(int &position) {
		if (position >= size) {
			return false;
		}
		else
		{
			Node<T> *tmp = head;
			Node<T> *m = nullptr, *q = nullptr;
			for (int i = 0; i < position; i++)
				tmp = tmp->next;
			m = tmp->next;
			if (m->next != nullptr) {
				q = m->next;
				tmp->next = q;
			}
			else
				tmp->next = nullptr;
			size--;
			delete m;
			return true;
		}
	}
	int getSize() {
		return size;
	}
	bool set(T data,int position){
		if (position < size) {
			Node<T> *tmp=head->next;
			for (int i = 0; i < position; i++)
				tmp = tmp->next;
			tmp->data = data;
			return true;
		}
		else
			std::cout << "Over filled!" << std::endl;
		return false;
	}
	T get(int position) {
		if (position < size) {
			Node<T> *tmp = head->next;
			for (int i = 0; i < position; i++)
				tmp = tmp->next;
			return tmp->data;
		}
		else {
			std::cout << "Over filled!" << std::endl;
			return 0;
		}
	}
};
#endif // !LINKLIST
