#include <vector>
#include <string>

std::string to_string(const std::string& val)
{
	return val;
}

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
		maxSize = 128;
		currSize = 0;
	}
	~HashMap()
	{
	}
	void insert(K key, V value);

private:
	std::vector<Pair<K, V>> *data = new std::vector<Pair<K, V>>[128];
	size_t maxSize;
	size_t currSize;
	int hashCode(K);

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
	index = hash % maxSize;
	return index;
}
// TODO: implement the best hashCode to avoid chaning

template<typename K, typename V>
void HashMap<K, V>::insert(const K key, const V value)
{
	/*Pair<K, V> pair = new Pair<K, V>(key, value);*/
	Pair<K, V> pair = Pair<K, V>(key, value);
	int index = hashCode(key);
	std::vector<Pair<K, V>> vecPair = data[index];
	vecPair.push_back(pair);
	currSize++;
}
