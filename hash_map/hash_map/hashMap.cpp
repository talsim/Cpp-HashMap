#include "hashMap.h"
using namespace std;

template<typename K, typename V>
HashMap<K, V>::HashMap()
{
	maxSize = data.max_size;
}

template<typename K, typename V>
HashMap<K, V>::HashMap(K, V)
{
	this->data.key = K;
	this->data.value = V;
}


template<typename K, typename V>
HashMap<K, V>::~HashMap()
{
}

template<typename K, typename V>
size_t HashMap<K, V>::hashCode(K key) // gets a key of any type and return's its index
{
	key = to_string(key);
	int hash = 0;
	int index = 0;
	int str_size = 0;
	for (int i = 0; key != '\0'; i++) // find string size
		str_size++;
	for (int i = 0; i < str_size; i++) // change to ascii number
		hash = hash + (int)key[i];
	index = hash % maxSize;
	return index;
}
