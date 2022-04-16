#include "contact_utils/common_libraries.h"

using namespace std;

int Contact_Book::number_of_favorites = 1;

vector<Contact> Contact_Book::contacts;
vector<Contact> Contact_Book::favorites;

void Contact_Book::start() {
    Contact_Book contactBook;
    commands_list_header();
    while (true) {
        display_contact_book_interface();
    }
}

void Contact_Book::display_contact_book_interface() {
    while (true) {
        commands_list();
        string choice = choose_command();
        bool check = check_command();
        if (check) {
            if (choice == to_string(Option_List::QUIT)) {
                break;
            } else {
                perform_command(stoi(choice));
            }
        } else {
            display_contact_book_interface();
        }
    }
}

void Contact_Book::commands_list_header() {
    cout << setw(70) << endl;
    cout << "*** CONTACT BOOK ***" << endl;
}

void Contact_Book::commands_list() {
    cout << setw(30) << "Select one option below" << endl
         << setw(21) << "1- Add Contact" << endl
         << setw(28) << "2- Search For Contact" << endl
         << setw(22) << "3- Edit Contact" << endl
         << setw(34) << "4- Add Contact to Favorite " << endl
         << setw(30) << "5- Display all Contacts" << endl
         << setw(35) << "6- Display Favorite Contacts" << endl
         << setw(26) << "7- Delete a Contact" << endl
         << setw(14) << "8- Quit" << endl;
}

Contact_Book::Contact_Book() {
    string line1 = " ", line2;
    ifstream in_file1, in_file2;
    in_file1.open("../contact_book.txt", ios::in);
    in_file2.open("../favorite_contacts.txt", ios::in);
    while (!in_file1.eof()) {
        getline(in_file1, line1);
        if (line1 != " ") {
            vector<string> data1 = split_line(line1);
            Contact contact1 = Add::set_data(data1);
            Contact::number += 1;
            contacts.push_back(contact1);
        }
    }
    while (!in_file2.eof()) {
        getline(in_file2, line2);
        if (line2 != " ") {
            vector<string> data2 = split_line(line2);
            Contact contact2 = Add::set_data(data2);
            contact2.set_favorites_number(number_of_favorites);
            favorites.push_back(contact2);
        }
    }
}

vector<string> Contact_Book::split_line(string &line) {
    string temp;
    vector<string> data;
    for (char i: line) {
        if (i == ',') {
            data.push_back(temp);
            temp = "";
        } else {
            temp += i;
        }
    }
    data.push_back(temp);
    return data;
}

string Contact_Book::choose_command() {
    cout << "Enter Your Choice: ";
    string choice = " ";
    cin >> choice;
    return choice;
}

bool Contact_Book::check_command() {
    cout << setw(18) << "1- Continue" << endl
         << setw(16) << "2- Return" << endl;
    string check_condition = choose_command();
    if (check_condition == to_string(Check_List::CONTINUE)) {
        return true;
    } else {
        return false;
    }
}

void Contact_Book::perform_command(int command) {
    switch (command) {
        case ADD_CONTACT:
            Add::add_contact();
            break;
        case SEARCH_FOR_CONTACT:
            Search::search_list();
            break;
        case EDIT_CONTACT:
            Edit::edit_list();
            break;
        case ADD_TO_FAVORITE:
            Add::add_contact_to_favorite();
            break;
        case DISPLAY_CONTACTS:
            Display::display_all_contacts();
            break;
        case DISPLAY_FAVORITE_CONTACTS:
            Display::display_favorite_contacts();
            break;
        case DELETE_CONTACT:
            Delete::delete_list();
            break;
        default:
            cout << "Wrong Choice" << endl;
            break;
    }
    clear_console();
}

void Contact_Book::clear_console() {
    string line;
    getline(cin, line);
    cin.ignore();
    system("clear");
}

