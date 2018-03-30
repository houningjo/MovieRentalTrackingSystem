/**
 * File name: hashTable.cpp
 * Author name: Ning Hou, Erika Portilla
 * Course: CSS502
 * Date: 02/24/2018
 * Last Modified:
 * ---------------------------------------------------------------------------
 * The purpose of the hashTable class is to provide a template Hashtable. 
 * On one precondition: the type K should be able to % by an integer.
 * ---------------------------------------------------------------------------
 */

#pragma once
#include <iostream>
using namespace std;

/**
 * The HashNode structs a single node that holds key, value.
 */
template<class K, class V>
struct HashNode{
	K key;
	V value;
	HashNode* nextHashNode;
	HashNode(const K& k, const V& v){
        key = k;
	    value = v;
	    nextHashNode = nullptr;
    }

};

/**
 * HashTable class declaration 
 */
template<class K, class V>
class HashTable{
private:
	int tableSize = 0;
	HashNode<K,V>** table = nullptr;

public:
	/**
	 * Constructor. 
	 * @param size the size of the table
	 */
	HashTable(int size);

	/**
	 * Destructor
	 */
	~HashTable();

	/** Returns the index of the table. This hash method uses
	 * key vlaue % the size of the table.
	 * @precondition size cannot be 0
	 * @param k the key 
	 * @return int the index of the table
	 */
	int hash(const K& k) const;

	/** Inserts the v value at key k. The insert method will always insert
	 * the new HashNode at the head of the linked list. The HashTable ignores
	 * a duplicate insertion.
	 * @param k the key 
	 * @param v the value
	 */
	void insert(const K& k, const V& v);

	/** Returns true if the key k exists in this hashTable, false otherwise.
	 * @param k the key
	 * @return true if the key k exists in this hashTable, false otherwise
	 */
	bool exist(const K& k);

	/**
	 * Returns a pointer of value v at the location where holds the key k.
	 */
	V* findV(const K& k);

	/** Displays the value at the key k position.
	 * @param k the key
	 */
	void display(const K& k);
};

/**
 * HashTable class definition
 */

/**
 * Constructor. 
 * @param size the size of the table
 */
template<class K, class V>
HashTable<K, V>::HashTable(int size){
	tableSize = size;
	table = new HashNode<K,V>*[tableSize];

	// initial all array elements to nullptr
	for(int i = 0; i < tableSize; i++){
		table[i] = nullptr;
	}
}

/**
 * Destructor
 */
template<class K, class V>
HashTable<K, V>::~HashTable(){
    for (int i = 0; i < tableSize; i++){
	    HashNode<K, V>* cur = table[i];

	    while (cur != nullptr){
	        HashNode<K, V>* prev = cur;
	        cur = cur->nextHashNode;
	        delete prev;
	    }
	}
	delete[] table;
}

/** Returns the index of the table. This hash method uses
 * key vlaue % the size of the table.
 * @precondition: k must be a data type that can be used for % operation
 * @param k the key 
 * @return int the index of the table
 */
template<class K, class V>
int HashTable<K, V>::hash(const K& k) const{
	return k % tableSize;
}

/** Inserts the v value at key k. The insert method will always insert
 * the new HashNode at the head of the linked list. The HashTable ignores
 * a duplicate insertion.
 * @param k the key 
 * @param v the value
 */
template<class K, class V>
void HashTable<K, V>::insert(const K& k, const V& v){
	if(!exist(k)){

		// creates a new HashNode
		HashNode<K, V> *newNode = new HashNode<K, V>(k, v);

		int index = hash(k);
		HashNode<K, V>* cur = table[index];
	 	// insert it at head
	 	table[index] = newNode;
	 	newNode->nextHashNode = cur;
 	}

}

/** Returns true if the key k exists in this hashTable, false otherwise.
 * @param k the key
 * @return true if the key k exists in this hashTable, false otherwise
 */
template<class K, class V>
bool HashTable<K, V>::exist(const K& k){
	int index = hash(k);

	HashNode<K,V>* curr = table[index];

	while(curr != nullptr){
		if(curr->key == k){
			return true;
		}
		curr = curr->nextHashNode;
	}

    return false;
}

/**
 * Returns a pointer of value v at the location where holds the key k.
 */
template<class K, class V>
V* HashTable<K, V>::findV(const K& k){

	if(exist(k)){
		int index = hash(k);
		HashNode<K,V>* curr = table[index];
		while(curr != nullptr){
			if(curr->key == k){
				return &curr->value;
			}
			curr = curr->nextHashNode;
		}
	}
	return nullptr;
}

/** Displays the value at the key k position.
 * @param k the key
 */
template<class K, class V>
void HashTable<K, V>::display(const K& k){
	int index = hash(k);

	HashNode<K, V>* cur = table[index];
	while(cur != nullptr){
		if(cur->key == k){
			cout << cur->key << ": " << cur->value << endl;
		}
		cur = cur->nextHashNode;
	}

}

