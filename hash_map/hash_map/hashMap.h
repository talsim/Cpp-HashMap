#include <vector>
#include <string>
using namespace std;
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
	HashMap()
	{
		maxSize = data.max_size();
	}
	~HashMap()
	{
	}
	int hashCode(K);
private:
	std::vector<Pair<K,V>> data;
	size_t maxSize;
};

template <typename K, typename V>
int HashMap<K, V>::hashCode(K key)
{
	string keyToStr = "";
	keyToStr = to_string(key);
	int hash = 0;
	int index = 0;
	for (int i = 0; i < keyToStr.length(); i++) // change to ascii number
		hash = hash + (int)keyToStr[i];
	index = hash % maxSize;
	return index;
}
