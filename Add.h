#include "comman_libraries.h"

#ifndef _ADD_H
#define _ADD_H

class Add {
public:

    static vector<string> get_data();

    static Contact set_data(vector<string> data);

    static void add_contact();

    static void add_contact_to_favorite();

};

#endif //_ADD_H
