#include <string>

#ifndef _SEARCH_H
#define _SEARCH_H
using namespace std;

class Search {
private:

    static void search_first_name(const string &firstName);

    static void search_last_name(const string &lastName);

    static void search_phone_number(const string &phoneNumber);

    static void search_work(const string &work);

    static void search_email(const string &email);

    static void search_address(const string &address);

    static int search_contact_number(int num);

    static string change_style_of_word(const string &word);

    static void display_search_result(int num);

public:
    enum Search_List {
        SEARCH_BY_FIRST_NAME = 1, SEARCH_BY_LAST_NAME,
        SEARCH_BY_PHONE_NUMBER, SEARCH_BY_EMAIL,
        SEARCH_BY_JOB, SEARCH_BY_ADDRESS
    };

    static void search_list();

    static void perform_search_option(int command);

    static string get_data_for_search(const string &word);

    static void search_by_first_name();

    static void search_by_last_name();

    static void search_by_phone_number();

    static void search_by_job();

    static void search_by_email();

    static void search_by_address();

    static int search_by_contact_number();
};


#endif //_SEARCH_H
