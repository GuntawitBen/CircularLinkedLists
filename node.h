#include <iomanip>

class Node {
  private:
    int value;
    Node* nextPtr;
  public:
    Node(int x = 0);
    Node* getNext();
    int getValue();
    void setNext(Node* t);
    void print();
};

Node::Node(int x){
  value = x;
  nextPtr = NULL;
}

Node* Node::getNext(){
  return nextPtr;
}

int Node::getValue(){
  return value;
}

void Node::setNext(Node* t){
  nextPtr = t;
}

void Node::print(){
  cout << setw(3) << value;
}