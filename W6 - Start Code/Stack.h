#include "Node.h"
#include <string.h>

class Stack {
private:
    Node* top;     // Pointer to the top of the stack
    int length;      // Keeps track of the stack size

public:
    Stack() {       // Constructor
        // your code here
        top = nullptr;
        length = 0;
    }

    ~Stack() {      // Destructor to free memory
        while (!isEmpty()) {
            pop();   // Deallocate all nodes
        }
    }

    // Push an element onto the stack
    void push(int value) {
       // your code here
       Node* newNode = new Node(value);
       newNode->next = top;
       top = newNode;
       length++;
    }

    // Pop the top element from the stack
    void pop() {
        // your code here
        if(isEmpty()){
            std::cout<<"Invalid"<<std::endl;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        length--;
    }

    // Peek the top element without removing it
    int peek() {
        // your code here
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
       // your code here
       if(top== nullptr){
        return true;
       }
       else{
        return false;
       }
    }

    // Get the current length of the stack
    int size() {
        return length;
    }
    // Convert the stack to a string representation
    std::string toString() {
       // your code here
        std::string result = "[";
        Node* current = top;
        while (current != nullptr) {
            result += std::to_string(current->data);
            if(current->next != nullptr){
                result += ", ";
            }
            current = current->next;
        }
        result += "]";
        return result;
    }
};
