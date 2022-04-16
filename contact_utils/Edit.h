#include "common_libraries.h"

#ifndef _EDIT_H
#define _EDIT_H

class Edit {
public:
    enum Edit_List {
        EDIT_FIRST_NAME = 1, EDIT_LAST_NAME,
        EDIT_PHONE_NUMBER, EDIT_EMAIL,
        EDIT_JOB, EDIT_ADDRESS
    };

    static void edit_list();

    static void perform_edit_option(int command);

    static string get_data_for_edit(const string &word);

    static void edit_first_name();
    static void edit_last_name();
    static void edit_phone_number();
    static void edit_email();
    static void edit_job();
    static void edit_address();
};

#endif //_EDIT_H
