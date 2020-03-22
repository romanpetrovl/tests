#include <iostream>

void PrintBin(int num)
{
	if (num) {
		PrintBin(num >> 1);
		std::cout << (num & 1);
	}
}

int main()
{
	int number = 5;
	PrintBin(5);
	std::cout << std::endl;

    system("pause");
    return 0;
}