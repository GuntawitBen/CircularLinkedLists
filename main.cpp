#include <iostream>
using namespace std;
#include "linkedlist.h"

void instructions();

int main() {
   LinkedList l; // initially there are no nodes
   unsigned int choice; // user's choice
   int item; // value entered by the user
    instructions(); // display the menu
    cout << "? ";
    cin >> choice;

   // loop while user does not choose 3
 while (choice != 3) {

        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> item;
                l.insert(item); // insert item in list
                l.print(); // Print forward order
                break;
          
            case 2: // delete an element
                 if (!l.isEmpty()) {
                 cout << "Enter number to be deleted: ";
                 cin >> item;

                 if (l.deletes(item)) {
                 } 
                 else {
                  cout << item << " not found." << endl << endl;
                 }
                 l.print(); // Print forward order
                   
                 } 
                 else {
                 cout << "List is empty." << endl;
                 }
                 break;

          
            case 3:
                puts("End of run.");
                return 0;
          
            default:
                cout << "Invalid choice." << endl;
                break;
        }
       instructions();
        cout << "? ";
        cin >> choice;
    }
}

// display program instructions to the user
void instructions() {
   cout << endl << "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end." << endl;
}