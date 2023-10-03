// DoubleLinkedList.hpp
#pragma once

#include <iostream>
#include <stdexcept>  // Para usar std::out_of_range

template <typename T>
class DoubleLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoubleLinkedList() {
        Node* current = head;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = tail = nullptr;
    }

    void add_front(const T& data) {
        Node* newNode = new Node{data, head, nullptr};
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void add_back(const T& data) {
        Node* newNode = new Node{data, nullptr, tail};
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = tail;
        }
    }

    // Inserción antes del nodo con el valor targetData
    void insert_before(const T& targetData, const T& data) {
        Node* current = head;
        while (current != nullptr && current->data != targetData) {
            current = current->next;
        }

        if (current == nullptr) {
            throw std::out_of_range("Target not found for insertion");
        }

        Node* newNode = new Node{data, current, current->prev};
        if (current->prev != nullptr) {
            current->prev->next = newNode;
        } else {
            head = newNode;
        }
        current->prev = newNode;
    }

    void delete_value(const T& data) {
        Node* current = head;
        while (current != nullptr && current->data != data) {
            current = current->next;
        }

        if (current == nullptr) {
            throw std::out_of_range("Data not found for deletion");
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
    }

    int find(const T& data) const {
        int index = 0;
        for (Node* current = head; current != nullptr; current = current->next) {
            if (current->data == data) {
                return index;
            }
            ++index;
        }

        return -1; // Retorna -1 si no se encuentra el elemento
    }

    void display() const {
        for (Node* current = head; current != nullptr; current = current->next) {
            std::cout << current->data << " ";
        }
        std::cout << std::endl;
    }
};
