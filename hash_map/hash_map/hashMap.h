#include <string>

std::string to_string(const std::string& val)
{
	return val;
}

template <typename K, typename V>
class HashPair
{
public:
	K key;
	V value;

	HashPair()
	{
		key = 0;
		value = 0;
	}
	HashPair(K key, V value) {
		this->key = key;
		this->value = value;
	}
};

template <typename K, typename V>
class HashMap
{
private:
	HashPair<K, V> **arr;
	size_t mapSize;
	size_t currSize;
	int hashCode(K);

public:
	HashMap()
	{
		mapSize = 64;
		currSize = 0;
		arr = new HashPair<K, V>*[mapSize];
		for (int i = 0; i < mapSize; i++)
			arr[i] = NULL;
	}
	~HashMap()
	{
	}
	void insert(K key, V value);
	void display();
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
	HashPair<K, V> *newPair = new HashPair<K, V>(key, value);
	int hashIndex = hashCode(key);
	while (arr[hashIndex] != NULL)
	{
		hashIndex++;
		hashIndex %= mapSize;
	}
	//if (currSize >= 1)
	//{
	//	while (arr[hashIndex]->key != key) // NULL
	//	{
	//		hashIndex++;
	//		hashIndex %= mapSize;
	//	}
	//}
	currSize++;
	arr[hashIndex] = newPair;
}

template<typename K, typename V>
void HashMap<K, V>::display()
{
	for (int i = 0; i < currSize; i++)
		std::cout << "key = " << arr[i]->key << std::endl << "value = " << arr[i]->value << std::endl << "----------------------------" << std::endl << "----------------------------" << std::endl;
}