#include "List.h"



int main()
{
	List list;
	FILE* inFile;
	FILE* outFile;
	char path[] = "D:\\test\\file";

	for (int i = 0; i < 5; i++) {
		ListNode* newNode = new ListNode{ nullptr, nullptr, nullptr, std::to_string(i) };
		list.push_back(newNode, true);
	}

	list.printList();
	inFile = fopen(path, "wb");
	list.Serialize(inFile);
	fclose(inFile);
	list.clear();

	outFile = fopen(path, "rb");
	list.Deserialize(outFile);
	list.printList();
	fclose(outFile);



    system("pause");
    return 0;
}
