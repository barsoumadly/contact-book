#include "common_libraries.h"
#include "Add.h"


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
    return contact;
}

void Add::add_contact() {
    vector<string> data = get_data();
    Contact contact = set_data(data);
    Contact_Book::contacts.push_back(contact);
    sorting_contacts(Contact_Book::contacts);
    Display::write_in_book_file(contact);
    cout << "Contact Saved" << endl;
    Display::rewrite_book_file();
}

void Add::sorting_contacts(vector<Contact> &contacts) {
    for (int times = 1; times <= contacts.size() - 1; ++times) {
        for (int i = 0; i <= contacts.size() - times - 1; ++i) {
            if (contacts[i].get_first_name() > contacts[i + 1].get_first_name()) {
                swap(contacts[i], contacts[i + 1]);
                int temp = contacts[i].get_contact_number();
                contacts[i].set_contact_number(contacts[i+1].get_contact_number());
                contacts[i+1].set_contact_number(temp);
            }else if(contacts[i].get_first_name() == contacts[i + 1].get_first_name()){
                if (contacts[i].get_last_name() == contacts[i + 1].get_last_name()){
                    int temp = contacts[i].get_contact_number();
                    contacts[i].set_contact_number(contacts[i+1].get_contact_number());
                    contacts[i+1].set_contact_number(temp);
                    swap(contacts[i], contacts[i + 1]);
                }
            }
        }
    }
}

void Add::add_contact_to_favorite() {
    int num = Search::search_by_contact_number();
    Contact_Book::number_of_favorites += 1;
    Contact_Book::contacts[num].set_favorites_number(Contact_Book::number_of_favorites);
    Contact_Book::favorites.push_back(Contact_Book::contacts[num]);
    sorting_contacts_in_favorites(Contact_Book::favorites);
    Display::write_in_favorite_file(Contact_Book::contacts[num]);
    cout << "Contact Added" << endl;
    Display::rewrite_favorite_file();
}

void Add::sorting_contacts_in_favorites(vector<Contact> &contacts) {
    for (int times = 1; times <= contacts.size() - 1; ++times) {
        for (int i = 0; i <= contacts.size() - times - 1; ++i) {
            if (contacts[i].get_first_name() > contacts[i + 1].get_first_name()) {
                swap(contacts[i], contacts[i + 1]);
                int temp = contacts[i].get_favorites_number();
                contacts[i].set_favorites_number(contacts[i+1].get_favorites_number());
                contacts[i+1].set_favorites_number(temp);
            }else if(contacts[i].get_first_name() == contacts[i + 1].get_first_name()){
                if (contacts[i].get_last_name() > contacts[i + 1].get_last_name()){
                    int temp = contacts[i].get_favorites_number();
                    contacts[i].set_favorites_number(contacts[i+1].get_favorites_number());
                    contacts[i+1].set_favorites_number(temp);
                    swap(contacts[i], contacts[i + 1]);
                }
            }
        }
    }
}

