#include<iostream>


void RemoveDubs(char* str)
{
	if (str == nullptr || strlen(str) <= 1) return;

	unsigned originCursor = 1, editableCursor = 1;

	do
	{
		if (str[originCursor - 1] != str[originCursor])
		{
			str[editableCursor++] = str[originCursor];
		}
	}

	while (str[originCursor++] != '\0');

}

int main()
{
	char str[] = "AAAA BBBB CCC D EEE DD";
	RemoveDubs(str);
	std::cout << str << std::endl;

	system("pause");

	return 0;
}





