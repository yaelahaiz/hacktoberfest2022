//caesar chiper with cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string text;
	int key;
	cout << "Enter a plaintext: ";
	getline(cin, text);
	cout << "Enter a key: ";
	cin >> key;
	string output = text;
	for (int i = 0; i < text.length(); i++)
	{
		if (isupper(text[i]))
			output[i] = char(int(text[i] + key - 65) % 26 + 65);
		else
			output[i] = char(int(text[i] + key - 97) % 26 + 97);
	}
	cout << "Caesar is: " << output << endl;
	return 0;
}
