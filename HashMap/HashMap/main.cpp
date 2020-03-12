#include "HashMap.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	HashMap<string, int> obj;
	obj.insert("tal", 1000);
	obj.insert("eli", 900);
	obj.insert("mama", 800);
	obj.insert("hello", 700);
	cout << obj;
	obj.get("lol");
	return 0;
}

