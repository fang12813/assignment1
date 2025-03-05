// CHAT GPT PROMPT: cpp linked list

// Here is an implementation of a **singly linked list** in C++:

// ### Features:
// - **Insertion** at the end of the list.
// - **Display** function to print the list.
// - **Deletion** of a node by value.
// - **Destructor** to free allocated memory.

// Let me know if you need a **doubly linked list** or other modifications! 🚀

// https://chatgpt.com/canvas/shared/67c8addd56e88191af1bb9f8f1f421e2

#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {
public:
    Node* head;
    
    LinkedList() : head(nullptr) {}
    
    // Insert a node at the end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
    
    // Delete a node by value
    void remove(int val) {
        if (!head) return;
        
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }
        
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
    
    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    
    std::cout << "Linked List: ";
    list.display();
    
    list.remove(2);
    std::cout << "After deleting 2: ";
    list.display();
    
    return 0;
}
