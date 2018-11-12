#ifndef SET_H
#define SET_H
#include <string>

#include "SetInterface.h"
#include "BST.h"
using namespace std;

template<class T>
class Set : public SetInterface<string> 
{
private:
	BST<T> *set = new BST<T>;
public:
	Set() {}
	~Set() {
		set->clearTree();
	}

	/** Inserts item into the set, if the container doesn't
	already contain an element with an equivalent value.
	@return: pair.first = pointer to item
	pair.second = true if successfully inserted, else false. */
	//virtual Pair<T*, bool> insert(const T& item) = 0;
	bool insert(const T& item) {
		set->addNode(item);
		return false;
	}

	/** @return: the number of elements removed from the Set. */
	size_t erase(const T& item) {
		set->removeNode(item);
		return 0;
	}

	/** Removes all items from the set. */
	void clear() {
		set->clearTree();
	}

	/** @return: the number of elements contained by the Set. */
	size_t size() const {
		string setVal;
		size_t numItems = 0;
		istringstream vals(toString());
		while (vals >> setVal) {
			if (setVal != "_") {
				numItems++;
			}
		}
		return numItems;
	}

	/** @return: return 1 if contains element equivalent to item, else 0. */
	size_t count(const T& item) const {
		string setVal;
		istringstream vals(toString());
		while (vals >> setVal) {
			if (setVal == item) {
				return 1;
			}
		}
		return 0;
	}

	/** @return: string representation of items in Set. */
	std::string toString() const {
		return set->toString();
	}

	/**Friend function that outputs the toString*/
	friend std::ostream& operator<< (std::ostream& os, const Set<T>& mySet) {
		os << mySet.toString();
		return os;
	};

};

#endif // !SET_H

