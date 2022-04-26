#include "common_libraries.h"

#ifndef _ADD_H
#define _ADD_H

class Add {
public:

    static vector<string> get_data();

    static Contact set_data(vector<string> data);

    static void add_contact();

    static void sorting_contacts(vector <Contact> &contacts);

    static void sorting_contacts_in_favorites(vector <Contact> &contacts);

    static void add_contact_to_favorite();

};

#endif //_ADD_H
