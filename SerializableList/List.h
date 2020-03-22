#pragma once
#include<string>
struct ListNode {
    ListNode *      prev;
    ListNode *      next;
    ListNode *      rand; // указатель на произвольный элемент данного списка, либо NULL
    std::string     data;
};

class List {
public:
	List() { head = nullptr; tail = nullptr; count = 0; };
	~List() { clear(); };
    void Serialize(FILE * file);  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
    void Deserialize(FILE * file);  // загрузка из файла (файл открыт с помощью fopen(path, "rb"))

	void push_back(ListNode* newNode, bool bIsSetRandomPtr = false);
	void push_forward(ListNode* newNode, bool bIsSetRandomPtr = false);

	void printList();
	void clear();
private:
    ListNode *      head;
    ListNode *      tail;
    int       count;

	void SetRandomPointer(ListNode* node);
};