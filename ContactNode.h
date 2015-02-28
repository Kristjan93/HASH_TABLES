#ifndef CONTACTNODE_H
#define CONTACTNODE_H

#include <iostream>
#include <string>
#include <vector>

#include "Contact.h"

struct StringContactPair
{
	StringContactPair();
	StringContactPair(string key, Contact value);

    string key;
    Contact value;
};

struct ContactNode
{
    ContactNode(string key, Contact value, ContactNode* link = NULL);
    ContactNode(StringContactPair data, ContactNode* link = NULL);

	StringContactPair data;
    ContactNode *link;
};

typedef ContactNode* NodePtr;

#endif
