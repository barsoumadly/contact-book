#include "../comman_libraries.h"

using namespace std;

vector<string> Add::get_data() {
    vector<string> data;
    string first_name = " ", last_name = " ", phone_number = " ",
            email = " ", work = " ", address = " ";
    Contact contact;
    cout << "Enter First Name: ";
    cin >> first_name;
    data.push_back(first_name);
    cout << "Enter Last Name: ";
    cin >> last_name;
    data.push_back(last_name);
    cout << "Enter Phone Number: ";
    cin >> phone_number;
    data.push_back(phone_number);
    cout << "Enter Email: ";
    cin >> email;
    data.push_back(email);
    cout << "Enter Job: ";
    cin >> work;
    data.push_back(work);
    cout << "Enter Address: ";
    cin >> address;
    data.push_back(address);
    Contact::number += 1;
    data.push_back(to_string(Contact::number));
    return data;
}

Contact Add::set_data(vector<string> data) {
    Contact contact;
    contact.set_first_name(data[0]);
    contact.set_last_name(data[1]);
    contact.set_phone_number(data[2]);
    contact.set_email(data[3]);
    contact.set_work(data[4]);
    contact.set_address(data[5]);
    contact.set_contact_number(stoi(data[6]));
    Contact::number = stoi(data[6]);
    return contact;
}

void Add::add_contact() {
    vector<string> data = get_data();
    Contact contact = set_data(data);
    Contact_Book::contacts.push_back(contact);
    Display::write_in_book_file(contact);
    cout << "Contact Saved" << endl;
}


void Add::add_contact_to_favorite() {
    int num = Search::search_by_contact_number();
    Contact_Book::contacts[num].set_favorites_number(Contact_Book::number_of_favorites);
    Contact_Book::favorites.push_back(Contact_Book::contacts[num]);
    Display::write_in_favorite_file(Contact_Book::contacts[num]);
    Contact_Book::number_of_favorites += 1;
}

