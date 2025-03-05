// https://chatgpt.com/share/67c8aee8-71f8-8013-9a01-308dff78d8f7

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at a specific position (1-based index)
    void insertAtPosition(int val, int pos) {
        if (pos <= 1) {
            insertAtHead(val);
            return;
        }

        Node* temp = head;
        int count = 1;
        while (temp && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (!temp) {  // Insert at the end if position is out of range
            insertAtTail(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }

        temp->next = newNode;
    }

    // Delete from head
    void deleteFromHead() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    // Delete from tail
    void deleteFromTail() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    // Delete at a specific position (1-based index)
    void deleteAtPosition(int pos) {
        if (!head) return;
        if (pos <= 1) {
            deleteFromHead();
            return;
        }

        Node* temp = head;
        int count = 1;
        while (temp && count < pos) {
            temp = temp->next;
            count++;
        }

        if (!temp) return;  // Position out of range

        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;

        if (temp == tail) tail = temp->prev;
        if (temp == head) head = temp->next;

        delete temp;
    }

    // Display forward
    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Display backward
    void displayBackward() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

// Main function to test the doubly linked list
int main() {
    DoublyLinkedList dll;

    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);
    dll.insertAtPosition(25, 3);

    cout << "Forward Traversal: ";
    dll.displayForward();

    cout << "Backward Traversal: ";
    dll.displayBackward();

    dll.deleteFromHead();
    cout << "After Deleting Head: ";
    dll.displayForward();

    dll.deleteFromTail();
    cout << "After Deleting Tail: ";
    dll.displayForward();

    dll.deleteAtPosition(2);
    cout << "After Deleting at Position 2: ";
    dll.displayForward();

    return 0;
}
