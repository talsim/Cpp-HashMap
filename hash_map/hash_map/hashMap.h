#include <string>

std::string to_string(const std::string& val)
{
	return val;
}

template <typename K, typename V>
class HashNode
{
public:
	K key;
	V value;

	HashNode()
	{
		key = 0;
		value = 0;
	}
	HashNode(K key, V value) {
		this->key = key;
		this->value = value;
	}
};

template <typename K, typename V>
class HashMap
{
private:
	HashNode<K, V> **arr;
	size_t mapSize;
	size_t currSize;
	HashNode<K, V> *dummy;
	int hashCode(K);

public:
	HashMap()
	{
		mapSize = 64;
		currSize = 0;
		arr = new HashNode<K, V>*[mapSize];
		for (int i = 0; i < mapSize; i++)
			arr[i] = NULL;
		//dummy = new HashNode<K, V>(-1, -1); initialize to something for search function to work
	}
	~HashMap()
	{
	}
	void insert(K key, V value);
};

template <typename K, typename V>
int HashMap<K, V>::hashCode(K key)
{
	using namespace std;
	string keyToStr = to_string(key);
	int hash = 0;
	int index = 0;
	for (auto c : keyToStr) // change to ascii number
		hash = hash + (int)c;
	index = hash % mapSize;
	return index;
}
// TODO: implement the best hashCode to avoid chaning

template<typename K, typename V>
void HashMap<K, V>::insert(const K key, const V value)
{
	HashNode<K, V> *newPair = new HashNode<K, V>(key, value);
	int index = hashCode(key);
	//push to arr
	currSize++;
}
