#include <string>

#ifndef _CONTACT_H
#define _CONTACT_H
using namespace std;

class Contact {
private:
    string first_name;
    string last_name;
    string phone_number;
    string e_mail;
    string work;
    string home_address;
    int contact_number;
    int favorites_number;
public:
    static int number;

    void set_first_name(string &firstName);

    string get_first_name();

    void set_last_name(string &lastName);

    string get_last_name();

    void set_phone_number(string &phoneNumber);

    string get_phone_number();

    void set_address(string &address);

    string get_address();

    void set_email(string &email);

    string get_email();

    void set_work(string &job);

    string get_work();

    void set_contact_number(int num);

    int get_contact_number() const;

    void set_favorites_number(int num);

    int get_favorites_number() const;
};

#endif //_CONTACT_H
