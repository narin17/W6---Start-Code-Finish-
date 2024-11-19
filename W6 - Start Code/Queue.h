#include "Node.h"
#include <string>

class Queue {
private:
    Node* head;     // Pointer to the front of the queue
    Node* tail;      // Pointer to the rear of the queue
    int length;      // Keeps track of the queue size
public:
    Queue() {       // Constructor
        // your code here
        head= tail = nullptr;
        length = 0;
    }
    ~Queue() {      // Destructor to free memory
        while (!isEmpty()) {
            dequeue();   // Deallocate all nodes
        }
    }

    // Enqueue an element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    // Dequeue the front element from the queue
    void dequeue() {
        // your code here
        if(isEmpty()){
            std::cout<<"Invalid"<<std::endl;
        }  
        
        Node* temp = head;
        head = head->next;

        if(head==nullptr){
            tail = nullptr;
        }
        // if(length == 1){
        //     head = tail;
        // }
        delete temp;
        length--;
    }
    // Peek the front element without removing it
    int peek() {
        // your code here
        if(isEmpty()){
            std::cout<<"Invalid"<<std::endl;
        } 
        else{
            return head->data;
        }
    }
    // Check if the queue is empty
    bool isEmpty() {
        // your code here
        if(head==nullptr){
            return true;
        }
        return false;
    }
    // Get the current length of the queue
    int size() {
        return length;
    }

    // Convert the queue to a string representation
    std::string toString() {
      // your code here
        std::string result = "[";
        Node* current = head;
        while (current != nullptr) {
            result += std::to_string(current->data);
            if (current->next != nullptr) {
                result += ", ";
            }
            current = current->next;
        }
        result += "]";
        return result;
    }

};
