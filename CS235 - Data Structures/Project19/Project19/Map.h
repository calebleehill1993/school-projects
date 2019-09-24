#ifndef  MAP_H
#define MAP_H
#include <math.h>

#include "MapInterface.h"
#include "Set.h"

using namespace std;

template<typename Key_Type, typename Value_Type>
class Map : public MapInterface<Key_Type, Value_Type>
{

public:
	static const int HashTableSize = 31;
	static const int BonusHashTableSize = 7;

	/**Map will utilize a pair of two values*/
	struct Pair {
		Key_Type key = NULL;
		Value_Type value = NULL;

		Pair(const Key_Type& x, const Value_Type& y) : key(x), value(y) {}

		~Pair() {}
	};


	Map() {
		vals = new Pair*[HashTableSize];
		for (int i = 0; i < HashTableSize; ++i) {
			vals[i] = nullptr;
		}
	}
	~Map() {
		for (int i = 0; i < HashTableSize; ++i) {
			delete vals[i];
		}
		delete vals;
	} 

	/** Read/write index access operator.
	If the key is not found, an entry is made for it.
	@return: Read and write access to the value mapped to the provided key. */
	virtual Value_Type& operator[](const Key_Type& key) {
		int hashCode = 0;
		bool passedThrough = false;
		for (int i = 0; i < HashTableSize; ++i) {
			if ((vals[i] != nullptr) && (vals[i]->key == key)) {
				return vals[i]->value;
			}
		}
		hashCode = create_hash(key) % HashTableSize;
		if (hashCode < 0) {
			hashCode = hashCode * (-1);
		}
		if (vals[hashCode] == nullptr) {
			vals[hashCode] = new Pair(key, " ");
			return vals[hashCode]->value;
		}
		else {
			// I am using linear probing here
			for (int i = hashCode; i < HashTableSize; ++i) {
				if (vals[i] == nullptr) {
					vals[i] = new Pair(key, " ");
					return vals[i]->value;
				}
				if (i == HashTableSize - 1) {
					passedThrough = true;
					i = 0;
				}
				if (i == hashCode && passedThrough == true) {
					break;
				}
			}
		}
	}


	/** @return: the number of elements removed from the Map. */
	virtual size_t erase(const Key_Type& key) {
		return 0;
	}

	/** Removes all items from the Map. */
	virtual void clear() {
		for (int i = 0; i < HashTableSize; ++i) {
			vals[i] = nullptr;
		}
	}

	/** @return: number of Key-Value pairs stored in the Map. */
	virtual size_t size() const {
		size_t numItems = 0;
		for (int i = 0; i < HashTableSize; ++i) {
			if (vals[i] != nullptr) {
				numItems++;
			}
		}
		return numItems;
	}

	/** @return: maximum number of Key-Value pairs that the Map can hold. */
	virtual size_t max_size() const {
		return HashTableSize;
	}

	/** @return: string representation of Key-Value pairs in Map. */
	virtual std::string toString() const {
		stringstream out;
		if (vals[0] == NULL) {
			out << vals[0]->key << ": " << vals[0] << endl;
		}
		for (int i = 1; i < HashTableSize; ++i) {
			if (vals[i] != nullptr) {
				out << vals[i]->key << ": " << vals[i]->value << endl;
			}
		}
		return out.str();
	}

	/**Friend function that outputs the toString*/
	friend std::ostream& operator<< (std::ostream& os, const Map<Key_Type, Value_Type>& myMap) 
	{
		os << myMap.toString();
		return os;
	};

	/**Creates a hash code based on the string*/
	int create_hash(string toHash) {
		int hashCode = 0;
		const int algorithmNum = 31;
		int stringLength = toHash.length();
		for (int i = 0; i < stringLength; ++i) {
			hashCode += ((int)toHash.at(i) * (int)pow(algorithmNum, stringLength - i - 1));
		}
		return hashCode;
	}

private:
	Pair** vals;
};


#endif // MAP_H
