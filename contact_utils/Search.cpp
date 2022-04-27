#include <iostream>
#include <iomanip>
#include "Search.h"
#include "../Contact_Book.h"
#include "Display.h"

using namespace std;

void Search::search_list() {
    cout << setw(30) << "1- Search by First Name" << endl
         << setw(29) << "2- Search by Last Name" << endl
         << setw(32) << "3- Search by Phone Number" << endl
         << setw(34) << "4- Search by his/her E-mail" << endl
         << setw(31) << "5- Search by his/her Job" << endl
         << setw(35) << "6- Search by his/her Address" << endl;
    string choice = Contact_Book::choose_command();
    Search::perform_search_option(stoi(choice));
}

void Search::perform_search_option(int command) {
    switch (command) {
        case SEARCH_BY_FIRST_NAME:
            search_by_first_name();
            break;
        case SEARCH_BY_LAST_NAME:
            search_by_last_name();
            break;
        case SEARCH_BY_PHONE_NUMBER:
            search_by_phone_number();
            break;
        case SEARCH_BY_EMAIL:
            search_by_email();
            break;
        case SEARCH_BY_JOB:
            search_by_job();
            break;
        case SEARCH_BY_ADDRESS:
            search_by_address();
            break;
        default:
            cout << "Wrong Choice" << endl;
            break;
    }
}

string Search::get_data_for_search(const string &word) {
    cout << "Enter " << word << ": ";
    string line = " ";
    cin >> line;
    return line;
}

void Search::search_by_first_name() {
    string first_name = get_data_for_search("First Name");
    search_first_name(first_name);
}

void Search::search_first_name(const string &firstName) {
    string word1 = change_style_of_word(firstName);
    for (int i = 0; i < Contact_Book::contacts.size(); ++i) {
        string word2 = change_style_of_word(Contact_Book::contacts[i].get_first_name());
        if (word2.find(word1) < Contact_Book::contacts.size()) {
            display_search_result(i,Contact_Book::contacts);
        }
    }
}

void Search::search_by_last_name() {
    string last_name = get_data_for_search("Last Name");
    search_last_name(last_name);
}

void Search::search_last_name(const string &lastName) {
    string word1 = change_style_of_word(lastName);
    for (int i = 0; i < Contact_Book::contacts.size(); ++i) {
        string word2 = change_style_of_word(Contact_Book::contacts[i].get_last_name());
        if (word2.find(word1) < Contact_Book::contacts.size()) {
            display_search_result(i,Contact_Book::contacts);
        }
    }
}

void Search::search_by_phone_number() {
    string phone_number = get_data_for_search("Phone Number");
    search_phone_number(phone_number);
}

void Search::search_phone_number(const string &phoneNumber) {
    for (int i = 0; i < Contact_Book::contacts.size(); ++i) {
        if (Contact_Book::contacts[i].get_phone_number().find(phoneNumber) <
            Contact_Book::contacts.size()) {
            display_search_result(i,Contact_Book::contacts);
        }
    }
}

void Search::search_by_job() {
    string job = get_data_for_search("Job");
    search_work(job);
}

void Search::search_work(const string &work) {
    string word1 = change_style_of_word(work);
    for (int i = 0; i < Contact_Book::contacts.size(); ++i) {
        string word2 = change_style_of_word(Contact_Book::contacts[i].get_work());
        if (word2.find(word1) < Contact_Book::contacts.size()) {
            display_search_result(i,Contact_Book::contacts);
        }
    }
}

void Search::search_by_email() {
    string email = get_data_for_search("Email");
    search_email(email);
}

void Search::search_email(const string &email) {
    string word1 = change_style_of_word(email);
    for (int i = 0; i < Contact_Book::contacts.size(); ++i) {
        string word2 = change_style_of_word(Contact_Book::contacts[i].get_email());
        if (word2.find(word1) < Contact_Book::contacts.size()) {
            display_search_result(i,Contact_Book::contacts);
        }
    }
}

void Search::search_by_address() {
    string address = get_data_for_search("Address");
    search_address(address);
}

void Search::search_address(const string &address) {
    string word1 = change_style_of_word(address);
    for (int i = 0; i < Contact_Book::contacts.size(); ++i) {
        string word2 = change_style_of_word(Contact_Book::contacts[i].get_address());
        if (word2.find(word1) < Contact_Book::contacts.size()) {
            display_search_result(i ,Contact_Book::contacts);
        }
    }
}

int Search::search_by_contact_number() {
    string contact_number = Search::get_data_for_search("Contact Number");
    int num = search_contact_number(stoi(contact_number));
    return num;
}

int Search::search_contact_number(int num) {
    for (int i = 0; i < Contact_Book::contacts.size(); ++i) {
        if (Contact_Book::contacts[i].get_contact_number() == num) {
            Search::display_search_result(i , Contact_Book::contacts);
            return i;
        }
    }
    return -1;
}

int Search::search_by_favorite_number() {
    string contact_number = Search::get_data_for_search("Contact Number");
    int num = search_favorite_number(stoi(contact_number));
    return num;
}

int Search::search_favorite_number(int num) {
    for (int i = 0; i < Contact_Book::favorites.size(); ++i) {
        if (Contact_Book::favorites[i].get_favorites_number() == num) {
            Search::display_search_favorite_contact(i, Contact_Book::favorites);
            return i;
        }
    }
    return -1;
}

int Search::search_by_phone(const string &phone) {
    for (int i = 0; i < Contact_Book::favorites.size(); ++i) {
        if (Contact_Book::favorites[i].get_phone_number() == phone) {
            return i;
        }
    }
    return -1;
}

string Search::change_style_of_word(const string &word) {
    string temp;
    for (char i: word) {
        temp += to_string(tolower(i));
    }
    return temp;
}

void Search::display_search_result(int num, vector<Contact> contacts) {
    cout << setw(10) << "Contact " << contacts[num].get_contact_number() << endl
         << "First Name: " << contacts[num].get_first_name() << endl
         << "Last Name: " << contacts[num].get_last_name() << endl
         << "Phone Number: " << contacts[num].get_phone_number() << endl
         << "Email: " << contacts[num].get_email() << endl
         << "Job: " << contacts[num].get_work() << endl
         << "Address: " << contacts[num].get_address() << endl
         << "----------------------------------------------" << endl;
}
void Search::display_search_favorite_contact(int num, vector<Contact> contacts) {
    cout << setw(10) << "Contact " << contacts[num].get_favorites_number() << endl
         << "First Name: " << contacts[num].get_first_name() << endl
         << "Last Name: " << contacts[num].get_last_name() << endl
         << "Phone Number: " << contacts[num].get_phone_number() << endl
         << "Email: " << contacts[num].get_email() << endl
         << "Job: " << contacts[num].get_work() << endl
         << "Address: " << contacts[num].get_address() << endl
         << "----------------------------------------------" << endl;
}