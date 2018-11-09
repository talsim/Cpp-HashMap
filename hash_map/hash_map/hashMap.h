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
		curr_size = 0;
	}
	~HashMap()
	{
	}
	void insert(K key, V value);
	void display();

private:
	std::array<std::vector<std::pair<K, V>>, MAX_SIZE> data;
	size_t curr_size;
	int hashCode(K);
	bool is_last_pair();
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
bool HashMap<K, V>::is_last_pair()
{
	return false;
}

template<typename K, typename V>
void HashMap<K, V>::insert(const K key, const V value)
{
	data[hashCode(key)].push_back(std::make_pair(key, value));
	curr_size++;
}

// python style printing
template<typename K, typename V>
void HashMap<K, V>::display()
{
	std::cout << "{";
	for (int i = 0; i <	MAX_SIZE; i++)
	{
		for (int j = 0; j < data[i].size(); j++) // for on the pairs
			std::cout << data[i][j].first << ":" << data[i][j].second << ", ";
			if(is_last_pair())
				std::cout << "}" << std::endl;
	}
}