#include "common_libraries.h"
#include "Delete.h"


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
    int check;
    ofstream out_file{"../contact_book.txt"};
    int num = Search::search_by_contact_number();
    check = Search::search_by_phone(Contact_Book::contacts[num].get_phone_number());
    if (num == -1) {
        cout << "No Contacts Found" << endl;
        delete_contact_from_book();
    } else {
        new_contact_numbers(num + 1);
        Contact_Book::contacts.erase(Contact_Book::contacts.begin() + num);
        Display::rewrite_book_file();
        if (check != -1) {
            new_favorite_numbers(check + 1);
            Contact_Book::favorites.erase(Contact_Book::favorites.begin() + check);
            Display::rewrite_favorite_file();
        }
    }
}

void Delete::delete_contact_from_favorites() {
    ofstream out_file{"../favorite_contacts.txt"};
    int num = Search::search_by_favorite_number();
    if (num == -1) {
        cout << "Not Exist" << endl;
        delete_contact_from_favorites();
    } else {
        new_favorite_numbers(num + 1);
        Contact_Book::favorites.erase(Contact_Book::favorites.begin() + num);
        Display::rewrite_favorite_file();
    }
}

void Delete::new_contact_numbers(int num) {
    int counter = num;
    for (int i = num; i < Contact_Book::contacts.size(); ++i) {
        Contact_Book::contacts[i].set_contact_number(counter);
        Contact::number = counter;
        counter += 1;
    }
}


void Delete::new_favorite_numbers(int num) {
    int counter = num;
    for (int i = num; i < Contact_Book::favorites.size(); ++i) {
        Contact_Book::favorites[i].set_favorites_number(counter);
        Contact_Book::number_of_favorites = counter;
        counter += 1;
    }
}
