class HashMap 
{
public:
	HashMap();
	HashMap(int, int);
	~HashMap();
private:
	int key;
	int value;
	int size;
};

/*
begin() - Returns an iterator to the first element in the map
end() - Returns an iterator to the last element in the map
size() - Returns the number of elements in the map
*/