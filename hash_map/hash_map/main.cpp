#include "hashMap.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	HashMap<string, int> obj;
	cout << obj.hashCode("test") << endl;
	return 0;
}

