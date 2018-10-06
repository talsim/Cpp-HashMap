#include "hashMap.h"
using namespace std;

template<typename K, typename V>
HashMap<K, V>::HashMap()
{
	MaxSize = 0;
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
size_t HashMap<K, V>::hash(K key) // gets a key of any type and return's its index
{

}
