
// https://chatgpt.com/share/67c8b1c1-771c-8013-a837-cc07faac5c82

#include <iostream>

// Template Node structure
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

// Template Linked List class
template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Insert at the beginning
    void insertAtHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Delete a node by value
    void deleteNode(T value) {
        if (!head) return;

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* temp = head;
        while (temp->next && temp->next->data != value)
            temp = temp->next;

        if (temp->next) {
            Node<T>* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Print the linked list
    void display() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // Destructor to free memory
    ~LinkedList() {
        Node<T>* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function to test the linked list
int main() {
    LinkedList<int> list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtTail(40);

    std::cout << "Linked List: ";
    list.display();

    list.deleteNode(20);
    std::cout << "After deleting 20: ";
    list.display();

    return 0;
}
