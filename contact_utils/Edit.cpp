#include "common_libraries.h"
#include "Edit.h"


void Edit::edit_list() {
    cout << setw(30) << "1- Edit First Name" << endl
         << setw(29) << "2- Edit Last Name" << endl
         << setw(32) << "3- Edit Phone Number" << endl
         << setw(34) << "4- Edit his/her E-mail" << endl
         << setw(31) << "5- Edit his/her Job" << endl
         << setw(35) << "6- Edit his/her Address" << endl;
    string choice = Contact_Book::choose_command();
    Edit::perform_edit_option(stoi(choice));
}

void Edit::perform_edit_option(int command) {
    switch (command) {
        case EDIT_FIRST_NAME:
            edit_first_name();
            break;
        case EDIT_LAST_NAME:
            edit_last_name();
            break;
        case EDIT_PHONE_NUMBER:
            edit_phone_number();
            break;
        case EDIT_EMAIL:
            edit_email();
            break;
        case EDIT_JOB:
            edit_job();
            break;
        case EDIT_ADDRESS:
            edit_address();
            break;
        default:
            cout << "Wrong Choice" << endl;
            break;
    }
}

string Edit::get_data_for_edit(const string &word) {
    cout << "Enter " << word << ": ";
    string line = " ";
    cin >> line;
    return line;
}

void Edit::edit_first_name() {
    int num = Search::search_by_contact_number();
    string first_name = get_data_for_edit("New First Name");
    Contact_Book::contacts[num].set_first_name(first_name);
    int check = change_favorite_file(num);
    if (check != -1) {
        Contact_Book::favorites[check].set_first_name(first_name);
    }
    Search::display_search_result(num);
    cout << "Contact Saved" << endl;
    Display::rewrite_book_file();
    Display::rewrite_favorite_file();
}

void Edit::edit_last_name() {
    int num = Search::search_by_contact_number();
    string last_name = get_data_for_edit("New Last Name");
    Contact_Book::contacts[num].set_last_name(last_name);
    int check = change_favorite_file(num);
    if (check != -1) {
        Contact_Book::favorites[check].set_last_name(last_name);
    }
    Search::display_search_result(num);
    cout << "Contact Saved" << endl;
    Display::rewrite_book_file();
    Display::rewrite_favorite_file();
}

void Edit::edit_phone_number() {
    int num = Search::search_by_contact_number();
    string phone_number = get_data_for_edit("New Phone Number");
    Contact_Book::contacts[num].set_first_name(phone_number);
    int check = change_favorite_file(num);
    if (check != -1) {
        Contact_Book::favorites[check].set_phone_number(phone_number);
    }
    Search::display_search_result(num);
    cout << "Contact Saved" << endl;
    Display::rewrite_book_file();
    Display::rewrite_favorite_file();
}

void Edit::edit_email() {
    int num = Search::search_by_contact_number();
    string email = get_data_for_edit("New Email");
    Contact_Book::contacts[num].set_first_name(email);
    int check = change_favorite_file(num);
    if (check != -1) {
        Contact_Book::favorites[check].set_email(email);
    }
    Search::display_search_result(num);
    cout << "Contact Saved" << endl;
    Display::rewrite_book_file();
    Display::rewrite_favorite_file();
}

void Edit::edit_job() {
    int num = Search::search_by_contact_number();
    string job = get_data_for_edit("New Job");
    Contact_Book::contacts[num].set_first_name(job);
    int check = change_favorite_file(num);
    if (check != -1) {
        Contact_Book::favorites[check].set_work(job);
    }
    Search::display_search_result(num);
    cout << "Contact Saved" << endl;
    Display::rewrite_book_file();
    Display::rewrite_favorite_file();
}

void Edit::edit_address() {
    int num = Search::search_by_contact_number();
    string address = get_data_for_edit("New Address");
    Contact_Book::contacts[num].set_first_name(address);
    int check = change_favorite_file(num);
    if (check != -1) {
        Contact_Book::favorites[check].set_address(address);
    }
    Search::display_search_result(num);
    cout << "Contact Saved" << endl;
    Display::rewrite_book_file();
    Display::rewrite_favorite_file();
}

int Edit::change_favorite_file(int num) {
    int index = 0;
    for (int i = 0; i < Contact_Book::favorites.size(); ++i) {
        if (Contact_Book::favorites[i].get_phone_number() ==
            Contact_Book::contacts[num].get_phone_number()) {
            index = i;
            break;
        } else {
            index = -1;
        }
    }
    return index;
}
