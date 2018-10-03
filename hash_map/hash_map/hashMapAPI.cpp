#include "hashMapAPI.h"

HashMap::HashMap()
{
	key = 0;
	value = 0;
	size = 0;
}

HashMap::HashMap(int key, int value)
{
	this->key = key;
	this->value = value;
	this->size = 1;
}

HashMap::~HashMap()
{
}
