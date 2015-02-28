#include "StringContactMap.h"
#include "Hash.h"

#include <algorithm>

using namespace std;

StringContactMap::StringContactMap(int initial_capacity)
{
    capacity = INITIAL_CAPACITY;
    count = 0;
    map = new ListPtr[INITIAL_CAPACITY];
    
    for(int i = 0; i < capacity; i++)
    {
        map[i] = new ContactList;
    }
}

StringContactMap::~StringContactMap()
{
    for(int i = 0; i < capacity; i++)
    {
        if(map[i] != NULL)
        {
            delete map[i];
        }
    }
    count = 0;
    delete [] map;
}

void StringContactMap::load_check()
{
    if( count / static_cast<double>(capacity) > 0.8)
    {
        rebuild();
    }
}

void StringContactMap::rebuild()
{
    int oldCapacity = capacity;
    
    capacity = capacity * 2;
    
    ListPtr *OldMap = map;
    
    //by til nýtt map med 2* staerra capacity
    map = new ListPtr[capacity];
    
    for(int i = 0; i < capacity; i++){
        map[i] = new ContactList;
    }
    
    //geng í gegnum gamla map'id
    for(int i = 0; i < oldCapacity; i++){
        
        vector<StringContactPair> temp;
        
        //set temp = ContactList'inn i OldMap i
        temp = OldMap[i]->to_vector();
        
        //geng svo i gegnum temp vectorinn
        for(unsigned int k = 0; k < temp.size(); k++){
            
            //nae i key
            Contact valueValue = temp[k].value;
            
            //nae i value
            string keyValue = temp[k].key;
            
            //hash'a uppa nytt med nyja capacity
            int hashValue = HASH_H::hash(keyValue) % capacity;
            
            //og adda svo i nyja map'id
            map[hashValue]->add(keyValue, valueValue);
        }
        temp.clear();
    }
    
    //eydi gamla mapinu
    for(int i = 0; i < oldCapacity; i++){
        delete OldMap[i];
    }
    
    delete []OldMap;
}

int StringContactMap::size() const
{
	return count;
}

bool StringContactMap::empty() const
{
	return count == 0;
}

// Returns a vector containing the contacts in this map (in no
// particular order).
vector<Contact> StringContactMap::all_contacts() const
{
    if( count == 0 )
    {
        return vector<Contact>();
    }
    else
    {
        vector<Contact> AllConInMap;
        
        for (int i = 0; i < capacity; i++)
        {
            if(map[i] != NULL)
            {
                map[i]->get_contacts(AllConInMap);
            }
        }
        return AllConInMap;
    }
}

void StringContactMap::add(string key, Contact value)
{
    load_check();
    
    unsigned int pos = HASH_H::hash(key) % capacity;
    
    if( !contains(key) )
    {
        count++;
    }
    
    map[pos]->add(key, value);
}


// Removes the entry with the specified key from the map.
// If no entry in the map has the specified key, this operation has no
// effect.
void StringContactMap::remove(string key)
{
    unsigned int pos = HASH_H::hash(key) % capacity;
    
    if( !contains(key) )
    {
        return;
    }
    else
    {
        if(contains(key))
        {
            count--;
        }
        map[pos]->remove(key);
    }
}

// Returns true if and only if there exists an entry in the map with
// the specified key.
bool StringContactMap::contains(string key) const
{
    if( count == 0 )
    {
        return false;
    }
    else
    {
        unsigned int pos = HASH_H::hash(key) % capacity;
        if (map[pos]->contains(key) )
        {
            return true;
        }
    }
    return false;
}

Contact StringContactMap::get(string key) const
{
    if( !contains(key) )
    {
        throw KeyException();
    }
    else
    {
        unsigned int pos = HASH_H::hash(key) % capacity;
        return map[pos]->get(key);
    }
}

// Returns a vector containing the contacts in this map, whose key is
// prefixed by 'prefix' (in no particular order).

// void ContactList::get_contacts_by_prefix(string prefix, vector<Contact>& contacts)

vector<Contact> StringContactMap::prefix_search(string prefix) const
{
    vector<Contact> all;
    
    for (int i = 0; i < capacity; i++)
    {
        if( map[i] != NULL )
        {
            map[i]->get_contacts_by_prefix(prefix, all);
        }
    }
    return all;
}

// Optionally implement.
ostream& operator <<(ostream& out, const StringContactMap& map)
{
	return out;
}
