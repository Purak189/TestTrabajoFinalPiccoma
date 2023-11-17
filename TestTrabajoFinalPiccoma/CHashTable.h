#pragma once
#include "CCHashEntidad.h"

template<typename T>
class HashTable {
private:
	HashEntidad<T>** tabla;
	int numElementos;
	int TABLE_SIZE;
public:
	HashTable(int TABLE_SIZE = 128) {
		this->TABLE_SIZE = TABLE_SIZE;
		this->numElementos = 0;
		this->tabla = new HashEntidad<T> * [TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			tabla[i] = nullptr;
		}
	}
	~HashTable() {
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (tabla != nullptr)
			{
				delete tabla[i];
			}
		}
		delete[] tabla;
	}
	unsigned long hashFunction(std::string str) {
		unsigned long hash = 5381;
		for (char c : str) {
			hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
		}
		return hash % TABLE_SIZE;
	}
	void insertar(std::string key, T value) {
		int base, step, hash;
		//validar si la tabla esta llena
		if (numElementos == TABLE_SIZE) return;
		//funcion hash
		base = hashFunction(key);
		hash = base;
		step = 0;
		while (tabla[hash] != nullptr)
		{
			base = (hash + step) % TABLE_SIZE; step++;
		}
		//almacenar
		tabla[hash] = new HashEntidad<T>(key, value);
		numElementos++;
	}
	int size() { return TABLE_SIZE; }
	int sizeActual() { return numElementos; }
	int buscar(std::string key) {
		int step = 0;
		int i, base;
		i = base = hashFunction(key);
		while (true)
		{
			if (tabla[i] == nullptr)
			{
				return -1;
			}
			else if (tabla[i]->getKey() == key)
			{
				return i;
			}
			else
			{
				step++;
			}
			i = (base + step) % TABLE_SIZE;
		}
	}
};