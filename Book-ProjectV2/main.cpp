#include <iostream>
#include "library.h"

using namespace std;

int main() {
    library mylibrary(1);

    int choice;
    do {
        cout<<"\t\t\t\t\t*===========Ahmed Reda==========*"<<endl;
        cout<<"\t\t\t\t\t|\tBook Management\t\t|\n";
        cout<<"\t\t\t\t\t*===============================*"<<endl;
        cout << "\t\t\t\t\t|1. Add a Book\t\t\t|\n"
             << "\t\t\t\t\t|2. Delete a Book\t\t|\n"
             << "\t\t\t\t\t|3. Search for a Book\t\t|\n"
             << "\t\t\t\t\t|4. Display All Books\t\t|\n"
             << "\t\t\t\t\t|5. Save Books to File\t\t|\n"
             << "\t\t\t\t\t|6. Load Books from File\t|\n"
             << "\t\t\t\t\t|7. Update Book Details\t\t|\n"
             << "\t\t\t\t\t|0. Exit\t\t\t|\n";
        cout<<"\t\t\t\t\t*===============================*"<<endl;
        cout << "\t\t\t\t\tEnter your choice: ";
        cin >> choice;
        system("cls");
        switch (choice) {
            case 1:
                mylibrary.addbook();
                break;
            case 2:
                mylibrary.deletebook();
                break;
            case 3: {
                int id;
                cout << "enter book id to search: ";
                cin >> id;
                int index = mylibrary.search_by_id(id);
                if (index != -1) {
                    cout << "book found: ";
                    mylibrary.displayBookById(id);
                } else {
                    cout << "book not found!" << endl;
                }
                break;
            }
            case 4:
                mylibrary.display_all_books();
                break;
              case 5: {
                string filename;
                cout << "enter filename to save: ";
                cin >> filename;
                mylibrary.save_to_file(filename);
                break;
            }
            case 6: {
                string filename;
                cout << "enter filename to load: ";
                cin >> filename;
                mylibrary.load_from_file(filename);
                break;
            }
            case 7: {
                int id;
                std::cout << "Enter the ID of the book you want to update: ";
                std::cin >> id;
                mylibrary.updatebook(id);
                break;
            }

            case 0:
                cout << "exiting the program." << endl;
                break;
            default:
                cout << "invalid choice! please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
