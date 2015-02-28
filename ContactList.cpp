#include "ContactList.h"
#include <string>

using namespace std;

ContactList::ContactList()
{
    head = NULL;
}

ContactList::~ContactList()
{
    remove_all();
}

void ContactList::remove_all()
{
    if ( head == NULL)
    {
        return;
    }
    else
    {
        NodePtr delete_ptr = head;
    
        while( head != NULL )
        {
            delete_ptr = head;
            head = head->link;
            delete delete_ptr;
        }
        head = NULL;
        delete head;
    }
}

bool ContactList::add(string key, Contact value)
{
    if(head == NULL)
    {
        NodePtr new_node = new ContactNode(key, value);
        
        head = new_node;
        
        return true;
    }
    
    if( !contains(key) )
    {
        NodePtr new_node =  new ContactNode(key, value);
        
        NodePtr go_back = head;
        
        while(go_back->link != NULL)
        {
            go_back = go_back->link;
        }
        
        go_back->link = new_node;
        
        return true;
    }
    else
    {
        for(NodePtr search = head; search != NULL; search = search->link)
        {
            if(search->data.key == key)
            {
                search->data.value = value;
            }
        }
    }
    return false;
}


// Removes the pair with the specified key from the list. If such a
// pair exists, the function returns true; false otherwise.

bool ContactList::remove(string key)
{
    
	if ( !contains(key) )
    {
        return false;
    }
    
    if( head->data.key == key )
    {
        NodePtr old_head = head;
        head = head->link;
        delete old_head;
        return true;
    }
    
    else
    {
        NodePtr in_front = head;
        NodePtr behind = head;
        
        for (in_front = head->link; in_front != NULL; in_front = in_front->link)
        {
            if(in_front->link == NULL)
            {
                behind->link = NULL;
                delete in_front;
                return true;
            }
            if( in_front->data.key == key )
            {
                behind->link = in_front->link;
                delete in_front;
                return true;
            }
            behind = in_front;
        }
    }
    return false;
}


bool ContactList::contains(string key)
{
	if (head == NULL)
    {
        return false;
    }
    else
    {
        for(NodePtr search = head; search != NULL; search = search->link)
        {
            if( search->data.key == key )
            {
                return true;
            }
        }
    }
    return false;
}

Contact ContactList::get(string key)
{
	if( !contains(key))
    {
        throw KeyException();
    }
    else
    {
        for(NodePtr search = head; search != NULL; search = search->link)
        {
            if( search->data.key == key )
            {
                return search->data.value;
            }
        }
    }
    Contact emty;
    return emty;
}

// Adds all the contacts (i.e., values) of the list, whose key is
// prefixed by 'prefix', to the specified vector.

void ContactList::get_contacts(vector<Contact>& contacts)
{
    
}

// Adds all the contacts (i.e., values) of the list, whose key is
// prefixed by 'prefix', to the specified vector.
void ContactList::get_contacts_by_prefix(string prefix, vector<Contact>& contacts)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        for(NodePtr search = head; search != NULL; search = search->link)
        {
            if(search->data.key.substr(0, prefix.length()) == prefix)
            {
                contacts.push_back(search->data.value);
            }
        }
    }
}

// Returns a vector containing the StringContactPairs of this list.
vector<StringContactPair> ContactList::to_vector()
{
    vector<StringContactPair> skila;
    
    for(NodePtr all_Cont_pair = head; all_Cont_pair != NULL; all_Cont_pair = all_Cont_pair->link )
    {
        skila.push_back( all_Cont_pair->data );
    }
    
	return skila;
}

// OPTIONAL
// A friend function for writing the contents of the list to an output stream
ostream& operator <<(ostream& outs, const ContactList& lis)
{
    for(NodePtr all_nodes = lis.head; all_nodes != NULL; all_nodes = all_nodes->link)
    {
        outs << all_nodes->data.value << endl;
    }
    return outs;
}