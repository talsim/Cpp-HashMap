#include <vector>
#include <string>
#include <array>

#define MAX_SIZE 32

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
		curr_size = 0;
	}
	~HashMap()
	{
	}
	void insert(K key, V value);
	bool contains(const K key);
	template <typename K, typename V> friend std::ostream& operator<<(std::ostream& os, const HashMap<K, V>& dt);

private:
	std::array<std::vector<std::pair<K, V>>, MAX_SIZE> data;
	size_t curr_size;
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
template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const HashMap<K, V>& dt)
{
	std::string storage_str = "";
	os << "{";
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < dt[i].size(); j++) // for on pairs
		{
			storage_str += to_string(dt[i][j].first);
			storage_str += ":";
			storage_str += to_string(dt[i][j].second);
			storage_str += ",";
		}
	}
	os << "}";
	return os;
}

template<typename K, typename V>
void HashMap<K, V>::insert(const K key, const V value)
{
	if (contains(key))
	{
		std::cout << "Error: key " << key << " already exists!" << std::endl;
		exit(0);
	}
	data[hashCode(key)].push_back(std::make_pair(key, value));
	curr_size++;
}

template<typename K, typename V>
bool HashMap<K, V>::contains(const K key)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < data[i].size(); j++)
			if (data[i][j].first == key)
				return true;
	}
	return false;
}

// python style printing
//void HashMap<K, V>::display()
//{
//	std::cout << "{";
//	for (int i = 0; i <	MAX_SIZE; i++)
//	{
//		for (int j = 0; j < data[i].size(); j++) // for on the pairs
//			std::cout << data[i][j].first << ":" << data[i][j].second << ", ";
//			if()
//				std::cout << "}" << std::endl;
//	}
//}