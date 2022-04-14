#include "comman_libraries.h"

void Delete::delete_list() {
    cout << setw(39) << "1- Delete Contact from Favorites" << endl
         << setw(24) << "2- Delete Contact" << endl;
    string choice = Contact_Book::choose_command();
    perform_delete_option(stoi(choice));
}

void Delete::perform_delete_option(int command) {
    switch (command) {
        case DELETE_FROM_FAVORITES:
            Delete::delete_contact_from_favorites();
            break;
        case DELETE_FROM_BOOK:
            Delete::delete_contact_from_book();
            break;
        default:
            cout << "Wrong Choice" << endl;
            delete_list();
            break;
    }
}

void Delete::delete_contact_from_book() {
    ofstream out_file{"../contact_book.txt"};
    int num = Search::search_by_contact_number();
    if (num == -1) {
        cout << "Not Exist" << endl;
        delete_contact_from_book();
    } else {
        change_contact_number(num + 1);
        Contact_Book::contacts.erase(Contact_Book::contacts.begin() + num);
        Display::rewrite_book_file();
    }
}

void Delete::delete_contact_from_favorites() {
    ofstream out_file{"../favorite_contacts.txt"};
    int num = Search::search_by_contact_number();
    if (num == -1) {
        cout << "Not Exist" << endl;
        delete_contact_from_favorites();
    } else {
        Contact_Book::favorites.erase(Contact_Book::favorites.begin() + num);
        Display::rewrite_favorite_file();
    }
}

void Delete::change_contact_number(int num) {
    int counter = num;
    for (int i = num; i < Contact_Book::contacts.size(); ++i) {
        Contact_Book::contacts[i].set_contact_number(counter);
        Contact::number = counter;
        counter += 1;
    }
}