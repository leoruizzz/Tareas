// DoubleLinkedList.cpp

#include <iostream>
#include "DoubleLinkedList.hpp"

using namespace std;

void showMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Añadir elemento al inicio" << endl;
    cout << "2. Añadir elemento al final" << endl;
    cout << "3. Insertar antes de un valor" << endl;
    cout << "4. Eliminar un valor" << endl;
    cout << "5. Buscar un valor" << endl;
    cout << "6. Mostrar lista" << endl;
    cout << "7. Salir" << endl;
    cout << "Selecciona una opción: ";
}

int main() {
    DoubleLinkedList<int> myList;
    int choice, value, target;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Valor a añadir al inicio: ";
                cin >> value;
                myList.add_front(value);
                break;
            case 2:
                cout << "Valor a añadir al final: ";
                cin >> value;
                myList.add_back(value);
                break;
            case 3:
                cout << "Valor antes del cual insertar: ";
                cin >> target;
                cout << "Valor a insertar: ";
                cin >> value;
                try {
                    myList.insert_before(target, value);
                } catch (const out_of_range& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            case 4:
                cout << "Valor a eliminar: ";
                cin >> value;
                try {
                    myList.delete_value(value);
                } catch (const out_of_range& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            case 5:
                cout << "Valor a buscar: ";
                cin >> value;
                int index;
                index = myList.find(value);
                if (index != -1) {
                    cout << "Valor encontrado en posición: " << index << endl;
                } else {
                    cout << "Valor no encontrado." << endl;
                }
                break;
            case 6:
                cout << "Lista: ";
                myList.display();
                break;
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (choice != 7);

    return 0;
}

