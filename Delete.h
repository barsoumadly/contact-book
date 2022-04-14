#ifndef _DELETE_H
#define _DELETE_H

class Delete {
public:
    enum Delete_List {
        DELETE_FROM_FAVORITES = 1, DELETE_FROM_BOOK
    };

    static void delete_list();

    static void perform_delete_option(int command);

    static void delete_contact_from_book();

    static void delete_contact_from_favorites();

    static void change_contact_number(int num);
};

#endif //_DELETE_H
