#include <algorithm>

#include "ContactManager.h"

void ContactManager::add(Contact contact)
{
	if(phone_map.contains(contact.phone)) {
		throw DuplicatePhoneException();
	}
	if(name_map.contains(contact.name)) {
		throw DuplicateNameException();
	}
    phone_map.add(contact.phone, contact);
    name_map.add(contact.name, contact);
}

void ContactManager::remove(string name)
{
    if(!name_map.contains(name)) {
        return;
    }
    Contact c = name_map.get(name);
    name_map.remove(c.name);
    phone_map.remove(c.phone);
}

void ContactManager::update_phone(string name, string new_number)
{
    if(!name_map.contains(name)) {
        throw ContactMissingException();
    }
    Contact c = name_map.get(name);
    string old_number = c.phone;
    c.phone = new_number;
    name_map.add(name, c);

    phone_map.remove(old_number);
    phone_map.add(c.phone, c);

}

void ContactManager::update_email(string name, string new_email)
{
    if(!name_map.contains(name)) {
        throw ContactMissingException();
    }
    Contact c = name_map.get(name);
    c.email = new_email;
    name_map.add(name, c);
    phone_map.add(c.phone, c);
}

bool ContactManager::name_exists(string name)
{
    return name_map.contains(name);
}

bool ContactManager::phone_exists(string phone)
{
    return phone_map.contains(phone);
}

Contact ContactManager::get_contact_by_name(string name)
{
    if(!name_exists(name)) {
        throw ContactMissingException();
    }
    return name_map.get(name);
}

Contact ContactManager::get_contact_by_phone(string phone)
{
    if(!phone_exists(phone)) {
        throw ContactMissingException();
    }
    return phone_map.get(phone);
}

vector<Contact> ContactManager::get_contacts_by_name_prefix(string name_prefix)
{
    return name_map.prefix_search(name_prefix);
}

vector<Contact> ContactManager::get_contacts_by_phone_prefix(string phone_prefix)
{
    return phone_map.prefix_search(phone_prefix);
}

ostream& operator<< (ostream& out, ContactManager& manager)
{
	vector<Contact> contacts = manager.name_map.all_contacts();
	sort(contacts.begin(), contacts.end(), compare_contacts_by_name);
    out << contacts << endl << endl;

	contacts = manager.phone_map.all_contacts();
	sort(contacts.begin(), contacts.end(), compare_contacts_by_phone);
    out << contacts << endl;
    return out;
}
