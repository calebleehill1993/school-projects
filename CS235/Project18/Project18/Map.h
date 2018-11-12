#ifndef Map_h
#define Map_h

#include "MapInterface.h"
#include "Set.h"
// is map using functions from the set? slides 32 and 33 make it seem like that


template <typename K, typename V>
class Map : public MapInterface<K, V> {
private:
    //creating a pair that includes the key and the value data.
    struct Pair {
        Pair() {
            next = NULL;
        }
        Pair(K the_key){
            key = the_key;
            value = V();
            next = NULL;
        }
        ~Pair( ) {
        }
        K key;
        V value;
        Pair *next;
    };
    int map_size;
    const int MAX_SIZE = 31;
    Pair** the_keys;
    size_t front;
    K key;
    V value;
public:
    // dynamically allocates an array for the pairs to be hashed into
    Map() {
        the_keys = new Pair*[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; i++) {
            the_keys[i] = NULL;
        }
    }
    //deletes dynamilacally allocated memory
    ~Map() {
        for (int i = 0; i < MAX_SIZE; i++)
            if (the_keys[i] != NULL) {
                Pair *prevEntry = NULL;
                Pair *entry = the_keys[i];
                while (entry->next != NULL) {
                    prevEntry = entry;
                    entry = entry->next;
                }
            }
        delete[] the_keys;
    }
    
    typedef std::pair<const K, V> entryType;
    /** Read/write index access operator.
     If the key is not found, an entry is made for it.
     @return: Read and write access to the value mapped to the provided key. */
    virtual V& operator[](const K& new_key) {
        int index = HashValue(new_key);
        
        if (the_keys[index] == NULL) {
            the_keys[index] = new Pair(new_key);
            the_keys[index]->key = new_key;
        }
        else if (the_keys[index]->key == new_key) {
            return the_keys[index]->value;
        }
        else if ((the_keys[index]->next != NULL) && the_keys[index]->next->key == new_key) {
            return the_keys[index]->next->value;
        }
        else {
            Pair *entry = the_keys[index];
            while (entry->next != NULL) entry = entry->next;
            if (entry->key == key) entry->value = value;
            else
                entry->next = (new Pair(new_key));
        }
        return the_keys[index]->value;
    }
    
    /*takes the key and adds up the lexicographical numbers of each
     letter then takes the remainder of it divided by 29, a prime number*/
    int HashValue(K current_key) const {
        int hashing_value = 0;
        char value;
        for (int i = 0; i < current_key.size(); i++) {
            value = current_key.at(i);
            hashing_value = int(value) + hashing_value;
        }
        hashing_value = hashing_value % 29;
        return hashing_value;
    }
    
    
    /** erases all the elements in the map*/
    virtual size_t erase(const K& key) {
        int index = HashValue(key);
        if (the_keys[index] != NULL ) {
            Pair *prevEntry = NULL;
            Pair *entry = the_keys[index];
            while (entry->next != NULL && entry->key != key) {
                prevEntry = entry;
                entry = entry->next;
            }
            if (entry->key == key) {
                if (prevEntry == NULL) {
                    Pair *nextEntry = entry->next;
                    delete entry;
                    the_keys[index] = nextEntry;
                }
                else {
                    delete entry;
                }
            }
        }
        return 1;
    }
    
    /** Removes all items from the Map. */
    virtual void clear() {
        for (int i = 0; i < MAX_SIZE; i++) {
            the_keys[i]->key = "";
        }
        if (the_keys != NULL) {
           // delete the_keys;
        }
    }
    
    /** @return: number of Key-Value pairs stored in the Map. */
    virtual size_t size() const {
        return map_size;
    }
    
    /** @return: maximum number of Key-Value pairs that the Map can hold. */
    virtual size_t max_size() const {
        return MAX_SIZE;
    }
    
    /** @return: string representation of Key-Value pairs in Map. */
    virtual std::string toString() const {
        std::ostringstream outString;
        for (int i = 0; i < MAX_SIZE; ++i) {
            if (the_keys[i] != NULL ) {
                if (the_keys[i]->key.back() == ':') {
                   outString << the_keys[i]->key << " " << the_keys[i]->value << std::endl;
                }
                else {
                    outString << the_keys[i]->key << " " << the_keys[i]->value << std::endl;
                }
                if (the_keys[i]->next != NULL) {
                    outString << the_keys[i]->next->key << " " << the_keys[i]->next->value << std::endl;
                }
            }
        }
        return outString.str();
    }
};


#endif /* Map_h */
