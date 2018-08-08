#include <vector>
#include <iterator>
#include <iostream>
#include <cmath>
#include <string>
#include <utility>
#include <cstring>
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::iter_swap;
template <typename T>
void myReverse(T& input)
{
	typename T::iterator it;
	typename T::iterator et;
	for (it=input.begin(), et=input.end(); it< et; it++, et--)
	{
		iter_swap(it, et-1);
	}
	return;
}
template <typename T>
void showContents(T& input)
{
	typename T::iterator it;
	for (it=input.begin(); it != input.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	int x[] = {1, 2, 3, 4, 5};
	vector<int> MyVec(x, x+5);
	showContents(MyVec);
	myReverse(MyVec);
	showContents(MyVec);
	string str = "This is a C++ string";
	vector<char> data(str.begin(), str.end());
	showContents(data);
	myReverse(data);
	showContents(data);
	string MyString ("This is a C++ string container");
	showContents(MyString);
	myReverse(MyString);
	showContents(MyString);
	char Cstr[] = "This is a C string char array";
	vector<char> data1(Cstr, Cstr+(strlen(Cstr)));
	showContents(data1);
	myReverse(data1);
	showContents(data1);
	vector<string> fruit; // This is a string vector
	fruit.push_back("apple");
	fruit.push_back("banana");
	fruit.push_back("orange");
	fruit.push_back("strawberry");
	showContents((fruit));
	myReverse(fruit);
	showContents((fruit));
}
