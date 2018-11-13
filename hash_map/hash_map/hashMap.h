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
	size_t curr_size;
	void insert(K key, V value);
	bool contains(const K key);
	V get(K key);
	bool is_empty();
	size_t get_map_size();
	template <typename K, typename V> friend std::ostream& operator<<(std::ostream& os, const HashMap<K, V>& obj);

private:
	// TODO: implement the best hashCode to avoid chaning
	std::array<std::vector<std::pair<K, V>>, MAX_SIZE> data;
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

// python style printing
template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const HashMap<K, V>& obj)
{
	using namespace std;
	std::string storage_str = "";
	os << "{";
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < obj.data[i].size(); j++) // for on pairs
		{
			storage_str += to_string(obj.data[i][j].first);
			storage_str += ":";
			storage_str += to_string(obj.data[i][j].second);
			storage_str += ", ";
			//check if last
		}
	}
	os << storage_str;
	os << "}";
	os << std::endl;
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

template<typename K, typename V>
V HashMap<K, V>::get(K key)
{
	if (contains(key))
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			for (int j = 0; j < data[i].size(); j++)
				if (data[i][j].first == key)
					return data[i][j].second;
		}
	}
	std::cout << "Error: key not found!" << std::endl;
	exit(0);
}

template<typename K, typename V>
bool HashMap<K, V>::is_empty()
{
	return curr_size == 0;
}

template<typename K, typename V>
size_t HashMap<K, V>::get_map_size()
{
	return 32;
}
