#ifndef STRINGCONTACTMAP_H
#define STRINGCONTACTMAP_H

#include <iostream>
#include <string>
#include <vector>
#include "ContactList.h"
#include "KeyException.h"

// Default initial capacity of a StringContactMap.
const int INITIAL_CAPACITY = 100;

// Maximum load (i.e. [number of entries] / [number of buckets]) of a
// StringContactMap.
const double MAX_LOAD = 1.0;

class StringContactMap {

    public:
		// Creates an empty map with the specified initial capacity.
        StringContactMap(int initial_capacity = INITIAL_CAPACITY);

        ~StringContactMap();

        // Returns the number ef entries in this map.
        int size() const;

        // Returns true if and only if the map contains no entries.
        bool empty() const;

		// Returns a vector containing the contacts in this map (in no
		// particular order).
        vector<Contact> all_contacts() const;

        // Adds the specified key to the map associated with the specified
        // contact.
        // If there exists an entry in the map with the specified key, it
        // should be replaced with the specified value.
        void add(string key, Contact value);

        // Returns true if and only if there exists an entry in the map with
        // the specified key.
        bool contains(string key) const;

        // Returns the contact associated wih the specified key.
        // Throws KeyException if no such contact exists.
        Contact get(string key) const;

        // Removes the entry with the specified key from the map.
		// If no entry in the map has the specified key, this operation has no
		// effect.
        void remove(string key);

        // Returns a vector containing the contacts in this map, whose key is
        // prefixed by 'prefix' (in no particular order).
        vector<Contact> prefix_search(string prefix) const;

		// OPTIONAL
		// Prints the contacts of this map to the specified stream (in no
		// particular order).
        friend ostream& operator <<(ostream& out, const StringContactMap& map);

    private:
        ListPtr* map;
        int capacity;
        int count;

		void load_check();
		void rebuild();
};

#endif

