#include "contact_utils/common_libraries.h"

#ifndef _CONTACT_BOOK_H
#define _CONTACT_BOOK_H
using namespace std;

class Contact_Book {
private:
    enum Option_List {
        ADD_CONTACT = 1, SEARCH_FOR_CONTACT, EDIT_CONTACT,
        ADD_TO_FAVORITE, DISPLAY_CONTACTS,
        DISPLAY_FAVORITE_CONTACTS, DELETE_CONTACT, QUIT
    };

    enum Check_List {
        CONTINUE = 1
    };

    static void display_contact_book_interface();

    static void perform_command(int command);

    static void clear_console();

public:
    static vector<Contact> contacts;
    static vector<Contact> favorites;
    static int number_of_favorites;

    static void start();

    Contact_Book();

    static vector<string> split_line(string &line);

    static void commands_list_header();

    static void commands_list();

    static string choose_command();

    static bool check_command();
};

#endif // _CONTACT_BOOK_H
