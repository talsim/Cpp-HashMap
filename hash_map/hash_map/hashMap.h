#pragma once
#include <vector>
#include <string>
template <typename K, typename V>

class Pair
{
public:
	K key;
	V value;
	Pair(K key, V value) {
		this->key = key;
		this->value = value;
	}
};

template <typename K, typename V>
class HashMap
{
public:	
	HashMap();
	HashMap(K, V);
	~HashMap();
	size_t hashCode(K);
private:
	std::vector<Pair<K,V>> data;
	size_t maxSize;
};