#include "../comman_libraries.h"

void Display::write_in_book_file(Contact contact) {
    ofstream out_file{"../contact_book.txt", ios::app};
    if (!Contact_Book::contacts.empty()) {
        out_file << endl;
    }
    out_file << contact.get_first_name() << ","
             << contact.get_last_name() << ","
             << contact.get_phone_number() << ","
             << contact.get_email() << ","
             << contact.get_work() << ","
             << contact.get_address() << ","
             << contact.get_contact_number();
}

void Display::rewrite_book_file() {
    for (auto &contact: Contact_Book::contacts) {
        ofstream out_file{"../contact_book.txt", ios::app};
        out_file << contact.get_first_name() << ","
                 << contact.get_last_name() << ","
                 << contact.get_phone_number() << ","
                 << contact.get_email() << ","
                 << contact.get_work() << ","
                 << contact.get_address() << ","
                 << contact.get_contact_number() << endl;
    }
}

void Display::write_in_favorite_file(Contact contact) {
    ofstream out_file{"../favorite_contacts.txt", ios::app};
    if (!Contact_Book::favorites.empty()) {
        out_file << endl;
    }
    out_file << contact.get_first_name() << ","
             << contact.get_last_name() << ","
             << contact.get_phone_number() << ","
             << contact.get_email() << ","
             << contact.get_work() << ","
             << contact.get_address() << ","
             << contact.get_favorites_number();
}

void Display::rewrite_favorite_file() {
    for (auto &favorite: Contact_Book::favorites) {
        ofstream out_file{"../favorite_contacts.txt", ios::app};
        out_file << favorite.get_first_name() << ","
                 << favorite.get_last_name() << ","
                 << favorite.get_phone_number() << ","
                 << favorite.get_email() << ","
                 << favorite.get_work() << ","
                 << favorite.get_address() << ","
                 << Contact_Book::number_of_favorites << endl;
    }
}

void Display::display_all_contacts() {
    for (auto &contact: Contact_Book::contacts) {
        cout << setw(10) << "Contact " << contact.get_contact_number() << endl
             << "First Name: " << contact.get_first_name() << endl
             << "Last Name: " << contact.get_last_name() << endl
             << "Phone Number: " << contact.get_phone_number() << endl
             << "Email: " << contact.get_email() << endl
             << "Job: " << contact.get_work() << endl
             << "Address: " << contact.get_address() << endl
             << "----------------------------------------------" << endl;
    }
}

void Display::display_favorite_contacts() {
    for (auto &favorite: Contact_Book::favorites) {
        cout << setw(10) << "Contact " << favorite.get_favorites_number() << endl
             << "First Name: " << favorite.get_first_name() << endl
             << "Last Name: " << favorite.get_last_name() << endl
             << "Phone Number: " << favorite.get_phone_number() << endl
             << "Email: " << favorite.get_email() << endl
             << "Job: " << favorite.get_work() << endl
             << "Address: " << favorite.get_address() << endl
             << "----------------------------------------------" << endl;
    }
}




