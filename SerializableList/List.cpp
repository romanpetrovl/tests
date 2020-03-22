#include "List.h"
#include <iostream>
#include <vector>
#include <map>

void List::push_back(ListNode* newNode, bool bIsSetRandomPtr)
{
	if (!head) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	count++;
	if (bIsSetRandomPtr) SetRandomPointer(tail);
}

void List::push_forward(ListNode* newNode, bool bIsSetRandomPtr)
{
	if (!head) {
		head = tail = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	count++;
	if (bIsSetRandomPtr) SetRandomPointer(head);
}

void List::Serialize(FILE * file)
{
	auto currentNode = head;
	while (currentNode) {
		fprintf(file, "%u %u\n%s\n", reinterpret_cast<std::uintptr_t>(currentNode)
								   , reinterpret_cast<std::uintptr_t>(currentNode->rand)
								   , currentNode->data.c_str());
		currentNode = currentNode->next;
	}
}

void List::Deserialize(FILE * file)
{
	std::map<std::uintptr_t, ListNode*> nodesMap;
	nodesMap[reinterpret_cast<std::uintptr_t>(nullptr)] = nullptr; //ключ nullptr

	std::uintptr_t keyNode, randKey;
	std::vector<std::uintptr_t> randKeysOrder;

	while (fscanf_s(file, "%u %u\n", &keyNode, &randKey) != EOF)
	{
		char bufferChar, buffer[256];
		int cursoreLineIndex = 0;

		while ((bufferChar = fgetc(file)) != '\n')
		{
			buffer[cursoreLineIndex] = bufferChar;
			cursoreLineIndex++;
		}

		buffer[cursoreLineIndex] = '\0';

		ListNode* newNode = new ListNode{ nullptr, nullptr, nullptr, buffer };
		push_back(newNode);
		nodesMap[keyNode] = tail;
		randKeysOrder.push_back(randKey);
	}

	auto currNode = head;
	int keyOrderIndex = 0;
	while (currNode != nullptr)
	{
		currNode->rand = nodesMap[randKeysOrder[keyOrderIndex]];
		currNode = currNode->next;
		keyOrderIndex++;
	}
}

void List::printList()
{
	auto currentNode = head;
	size_t i = 1;
	while (currentNode)
	{
		std::cout << i << ".	" << "Data:" << currentNode->data << std::endl;
		std::cout << "	" << "  RandomElementData:" << (currentNode->rand ? currentNode->rand->data : "NULL") << std::endl;
		std::cout << std::endl;
		currentNode = currentNode->next;
		i++;
	}
}

void List::SetRandomPointer(ListNode* node)
{
	int r = rand() % (count)+1;
	ListNode* currentNode = head;
	while (r--) currentNode = currentNode->next;
	node->rand = currentNode;
}

void List::clear()
{
	auto currentNode = head;
	while (currentNode)
	{
		ListNode* toDel = currentNode;
		currentNode = currentNode->next;
		delete toDel;
	}
	head = nullptr;
	tail = nullptr;
	count = 0;
}