#pragma once
#include <string>

template<class T>
class HashEntidad {
private:
	std::string key;
	T value;
public:
	HashEntidad(std::string key, T value) {
		this->key = key;
		this->value = value;
	}
	~HashEntidad() {}
	std::string getKey() { return key; }
	T getValue() { return value; }
};