#include <iostream>
#include "nodeDoubly.hpp"
#include <stdexcept>

using namespace std;

template <typename T>
class DoublylinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoublylinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoublylinkedList() { clear(); }

    int getSize() const { return size; }

    T& operator[](int index);  // para obtener elementos de forma no constante
    const T& operator[](int index) const;  // para obtener elementos de forma constante

    void addFirst(T data) {
        Node<T>* newNode = new Node<T>(data, head);
        if (head) head->prev = newNode;
        head = newNode;
        if (!tail) tail = newNode;
        ++size;
    }

    void addLast(T data) {
        Node<T>* newNode = new Node<T>(data, nullptr, tail);
        if (tail) tail->next = newNode;
        tail = newNode;
        if (!head) head = newNode;
        ++size;
    }

    void insert(int index, T data) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }
        Node<T>* newNode = new Node<T>(data);
        if (index == 0) {
            addFirst(data);
        } else if (index == size) {
            addLast(data);
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            ++size;
        }
    }

    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

     T getData(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    void updateData(T oldData, T newData) {
        Node<T>* current = head;
        while (current != nullptr && current->data != oldData) {
            current = current->next;
        }
        if (current != nullptr) {
            current->data = newData;
        }
    }

    int findData(T data) {
        Node<T>* current = head;
        int currentIndex = 0;
        while (current != nullptr){
            if (current -> data == data) {
                return currentIndex;
            }
            current = current->next;
            currentIndex++;
        }
        return -1;
    
    }
    void updateAt(int index, T newData) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->data = newData;
    }

    bool deleteData(T data) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while (current != nullptr && current->data != data) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) {
            return false; // Data not found
        }
        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = prev;
        } else {
            tail = prev;
        }
        delete current;
        --size;
        return true;
    }

    bool deleteAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        for (int i = 0; i < index; ++i) {
            prev = current;
            current = current->next;
        }
        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = prev;
        } else {
            tail = prev;
        }
        delete current;
        --size;
        return true;
    }

    void print() const {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

      bool isEmpty() const {
        return size == 0;
    }

    void sort() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* minNode = current;
            Node<T>* r = current->next;
            while (r != nullptr) {
                if (minNode->data > r->data)
                    minNode = r;

                r = r->next;
            }
            T x = current->data;
            current->data = minNode->data;
            minNode->data = x;
            current = current->next;
        }
    }

    

    void duplicate() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* newNode = new Node<T>(current->data, current->next, current);
            if (newNode->next != nullptr) {
                newNode->next->prev = newNode;
            }
            current->next = newNode;
            current = newNode->next;
            ++size;
        }
    }

    void removeDuplicates() {
        Node<T>* current = head;
        while (current != nullptr && current->next != nullptr) {
            Node<T>* temp = current;
            while (temp->next != nullptr) {
                if (current->data == temp->next->data) {
                    Node<T>* dup = temp->next;
                    temp->next = temp->next->next;
                    delete dup;
                    --size;
                } else {
                    temp = temp->next;
                }
            }
            current = current->next;
        }
    }
};
