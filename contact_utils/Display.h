#include "common_libraries.h"

#ifndef _DISPLAY_H
#define _DISPLAY_H

class Display {
public:
    static void write_in_book_file(Contact contact);

    static void write_in_favorite_file(Contact contact);

    static void rewrite_book_file();

    static void rewrite_favorite_file();

    static void display_all_contacts();

    static void display_favorite_contacts();
};

#endif //_DISPLAY_H
