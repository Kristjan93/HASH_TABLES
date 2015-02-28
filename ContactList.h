#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
#include <vector>

#include "ContactNode.h"
#include "KeyException.h"

using namespace std;

class ContactList
{
    public:
        // Creates an empty list
        ContactList();
        ~ContactList();

		// If there exists a pair with the specified key in the list, the value
		// of that pair is updated with the specified value. Otherwise, the
		// (key, value) pair is added to the back of the list.
		// The function returns true if the (key, value) pair was added to the
		// list; false otherwise (i.e., if the key was present in the list).
        bool add(string key, Contact value);

		// Removes the pair with the specified key from the list. If such a
		// pair exists, the function returns true; false otherwise.
        bool remove(string key);

		// Returns true if and only is this list contains a pair with the
		// specified key.
        bool contains(string key);

		// Returns the contact associated with the specified key.
		// If the specified key is not in the list, KeyException is thrown.
        Contact get(string key);

		// Adds all the contacts (i.e., values) of the list to the specified
		// vector.
        void get_contacts(vector<Contact>& contacts);

		// Adds all the contacts (i.e., values) of the list, whose key is
		// prefixed by 'prefix', to the specified vector.
        void get_contacts_by_prefix(string prefix, vector<Contact>& contacts);

		// Returns a vector containing the StringContactPairs of this list.
		vector<StringContactPair> to_vector();

		// OPTIONAL
        // A friend function for writing the contents of the list to an output stream
        friend ostream& operator <<(ostream& outs, const ContactList& lis);
    
      void remove_all();

    private:
		// Pointer to the head of the list
        NodePtr head;

		// Deallocates the memory allocated for the linked list.
    
};

typedef ContactList* ListPtr;

#endif // INTLIST_H
