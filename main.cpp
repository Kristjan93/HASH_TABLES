//
//  main.cpp
//  HASH_TABLES
//
//  Created by Kristjan Thorsteinsson on 18/03/14.
//  Copyright (c) 2014 Kristjan Thorsteinsson. All rights reserved.
//
#include "Contact.h"
#include "ContactList.h"
#include <iostream>
using namespace std;

int main()
{
    ContactList kp;
    ContactList karel;
    ContactList adg;
    
    Contact bla, bla2, bla3;
    
    bla.name = "kristjan";
    bla.phone = "7741140";
    bla.email = "krillinn@gmail.com";
    bla.address = "hellubakki 16";
    
    
    bla2.name = "arnthor";
    bla2.phone = "666";
    bla2.email = "faggi@gmail.com";
    bla2.address = "bbbb";
    
    bla3.name = "siggi";
    bla3.phone = "777";
    bla3.email = "mikillfaggi@gmail.com";
    bla3.address = "Hell";

    kp.add("hannkristjan", bla);
    kp.add("karel", bla2);
    kp.add("hannarnthor", bla3);

    vector<Contact> virka;
    
    kp.get_contacts_by_prefix("ha", virka);
    
    for (int i = 0; i < virka.size(); i++)
    {
        cout << virka[i] << endl;
    }
    
    
    return 0;
}

