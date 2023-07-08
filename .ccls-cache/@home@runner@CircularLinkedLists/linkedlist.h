#include <iostream>
#include <iomanip>
using namespace std;
#include "node.h"

class LinkedList{
  private:
    Node* head;
    int size;
  public:
    LinkedList();
    ~LinkedList();
    void insert(int value);
    int deletes(int value);
    int isEmpty();
    void print();
};

LinkedList::LinkedList(){
  head = NULL;
  size = 0;
}

LinkedList::~LinkedList(){
  cout << "Deleting All Nodes" << endl;
  Node* temphead = head;
  for (int i = 0; i < size; i++){
    head = head->getNext();
    delete temphead;
    temphead = head;
  }
}

void LinkedList::insert(int value) {
    Node* newNode = new Node(value);

    if (isEmpty()) { // if linked list is empty
        head = newNode;
        newNode->setNext(newNode); // make it circular
    }
    else if (value <= head->getValue()) { // if new is smaller than head
        newNode->setNext(head); // next of new will be old head
        Node* current = head;
        while (current->getNext() != head) {
            current = current->getNext();
        }
        current->setNext(newNode); // make new node the last node
        head = newNode; // new becomes head
    }
    else {
        Node* current = head->getNext();
        Node* previous = head;
        while (current != head && current->getValue() < value) {
            previous = current;
            current = current->getNext();
        }
        previous->setNext(newNode);
        newNode->setNext(current);
    }

    ++size;
}

int LinkedList::deletes(int value) {
    if (isEmpty()) {
        cout << "The list is empty" << endl;
        return 0;
    }

    int count = 0;
    Node* current = head;
    Node* previous = nullptr;
    do {
        if (current->getValue() == value) {
            if (previous != nullptr) {
                previous->setNext(current->getNext());
                if (current == head) {
                    head = previous->getNext();
                }
                delete current;
                current = previous->getNext();
            }
            else {
                Node* temp = current;
                if (current->getNext() == current) { // Only one node in the list
                    head = nullptr;
                }
                else {
                    head = current->getNext();
                    Node* last = head;
                    while (last->getNext() != temp) {
                        last = last->getNext();
                    }
                    last->setNext(head);
                }
                current = head;
                delete temp;
            }
            --size;
            count++;
        }
        else {
            previous = current;
            current = current->getNext();
        }
    } while (current != head);

    return count;
}


int LinkedList::isEmpty(){
  return head == NULL; //return 1 if head == NULL, return 0 otherwise
}

void LinkedList::print() {
    if (isEmpty()) {
        cout << "The list is empty" << endl;
    }
    else {
        cout << "List: ";
        Node* current = head;
        do {
            current->print();
            cout << " -> ";
            current = current->getNext();
        } while (current != head);
        cout << current->getValue() << "..." << endl;
    }
}
