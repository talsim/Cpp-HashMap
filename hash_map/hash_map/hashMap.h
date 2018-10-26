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
		maxSize = data.max_size();
	}
	~HashMap()
	{
	}
	
	void insert(Pair<K, V> pair);

private:
	std::vector<Pair<K,V>> data;
	size_t maxSize;
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
void HashMap<K, V>::insert(Pair<K,V> pair)
{
	// index = hashCode(key)
	// vector.push_in_index(index, value);
}
