#include <vector>
#include <string>
#include <array>

#define MAX_SIZE 64

std::string to_string(const std::string& val)
{
	return val;
}

template <typename K, typename V>
class HashMap
{
public:
	HashMap()
	{
		currSize = 0;
	}
	~HashMap()
	{
	}
	void insert(K key, V value);

private:
	std::array<std::vector<std::pair<K, V>>, MAX_SIZE> data; 
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
	index = hash % MAX_SIZE;
	return index;
}
// TODO: implement the best hashCode to avoid chaning

template<typename K, typename V>
void HashMap<K, V>::insert(const K key, const V value)
{
	data[hashCode(key)].push_back(std::make_pair(key, value));
	currSize++;
}
