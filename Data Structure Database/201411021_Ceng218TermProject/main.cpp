#include "List.h"

int main(void)
{
	List<string> l1;
	string str;

	l1.WriteTextFiles();
	l1.traverse();

	cout << "Enter a word: ";
	cin >> str;

	cout << "---" + str + "---" + "\n";
	cout<<l1.Search(str);


	getchar();
	getchar();
	return 0;
}
