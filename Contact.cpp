#include "Contact.h"

int Contact::number = 0;

void Contact::set_first_name(string &firstName) {
    this->first_name = firstName;
}

string Contact::get_first_name() {
    return first_name;
}

void Contact::set_last_name(string &lastName) {
    this->last_name = lastName;
}

string Contact::get_last_name() {
    return last_name;
}

void Contact::set_phone_number(string &phoneNumber) {
    this->phone_number = phoneNumber;
}

string Contact::get_phone_number() {
    return phone_number;
}

void Contact::set_address(string &address) {
    this->home_address = address;
}

string Contact::get_address() {
    return home_address;
}

void Contact::set_email(string &email) {
    this->e_mail = email;
}

string Contact::get_email() {
    return e_mail;
}

void Contact::set_work(string &job) {
    this->work = job;
}

string Contact::get_work() {
    return work;
}

void Contact::set_contact_number(int num) {
    number += 1;
    this->contact_number = num;
}

int Contact::get_contact_number() const {
    return contact_number;
}

void Contact::set_favorites_number(int num) {
    this->favorites_number = num;
}

int Contact::get_favorites_number() const {
    return favorites_number;
}
