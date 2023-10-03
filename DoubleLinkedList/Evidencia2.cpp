#include "DoubleLinkedList/DoubleLinkedList.hpp"
#include <iostream>
#include <fstream>
#include <string>


void loadData(DoubleLinkedList<std::string>& dataList, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo " << filename << " para lectura.\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        dataList.add_back(line);
    }

    inFile.close();
}


// 1. Ordenar por fecha y hora y generar output602-1.out
void option1(DoubleLinkedList<std::string>& dataList) {
    // Implementar lógica de ordenación por fecha y hora
    // NOTA: La implementación exacta dependerá de la estructura de tus datos.
    // ...

    // Generar archivo output602-1.out
    std::ofstream outFile1("output602-1.out");
    if (outFile1.is_open()) {
        // Escribir los datos ordenados en el archivo
        // ...
        outFile1.close();
    } else {
        std::cout << "No se pudo abrir el archivo output602-1.out para escritura.\n";
    }
}

// 2. Ordenar por IP, fecha y hora y generar output602-2.out
void option2(DoubleLinkedList<std::string>& dataList) {
    // Implementar lógica de ordenación por IP, fecha y hora
    // NOTA: La implementación exacta dependerá de la estructura de tus datos.
    // ...

    // Generar archivo output602-2.out
    std::ofstream outFile2("output602-2.out");
    if (outFile2.is_open()) {
        // Escribir los datos ordenados en el archivo
        // ...
        outFile2.close();
    } else {
        std::cout << "No se pudo abrir el archivo output602-2.out para escritura.\n";
    }
}

// 3. Búsqueda por rango de IPs
void option3(DoubleLinkedList<std::string>& dataList) {
    // Pedir al usuario un rango de IPs
    std::string ipStart, ipEnd;
    std::cout << "Ingrese la IP de inicio del rango: ";
    std::cin >> ipStart;
    std::cout << "Ingrese la IP de fin del rango: ";
    std::cin >> ipEnd;

    // Buscar todas las IPs que se encuentren en el rango solicitado
    // NOTA: La implementación exacta dependerá de la estructura de tus datos.
    // ...

    // Guardar los registros dentro de ese rango en una DoublyLinkedList
    DoubleLinkedList<std::string> ipRangeList;
    // ...

    // Generar archivo iprange602-a.out con los datos de la búsqueda en orden ascendente
    std::ofstream outFile3a("iprange602-a.out");
    if (outFile3a.is_open()) {
        // Escribir los datos en el archivo
        // ...
        outFile3a.close();
    } else {
        std::cout << "No se pudo abrir el archivo iprange602-a.out para escritura.\n";
    }

    // Generar archivo iprange602-d.out con los datos de la búsqueda en orden descendente
    std::ofstream outFile3b("iprange602-d.out");
    if (outFile3b.is_open()) {
        // Escribir los datos en el archivo
        // ...
        outFile3b.close();
    } else {
        std::cout << "No se pudo abrir el archivo iprange602-d.out para escritura.\n";
    }
    
    // 4. Mostrar sumatoria de datos
void option4(DoubleLinkedList<std::string>& dataList) {
    // Desplegar en pantalla la cantidad de IPs en el archivo por cada año y mes
    // NOTA: La implementación exacta dependerá de la estructura de tus datos.
    
    // Suponiendo que cada entrada en tu lista tiene la forma "IP Año Mes ...",
    // puedes usar un mapa para contar las ocurrencias de cada par Año-Mes.
    std::map<std::pair<int, int>, int> ipCountPerYearMonth;

    // Iterar a través de cada elemento en dataList y actualizar ipCountPerYearMonth
    // ...

    // Mostrar los resultados
    std::cout << "Cantidad de IPs por año y mes:\n";
    for (const auto& [yearMonth, count] : ipCountPerYearMonth) {
        const auto& [year, month] = yearMonth;
        std::cout << year << "-" << month << ": " << count << " IPs\n";
    }
}

int main() {
    DoubleLinkedList<std::string> dataList;

    // Cargar datos del archivo log608-2.txt en dataList
    loadData(dataList, "log608-2.txt");
    

    // Menú de opciones
    while (true) {
        std::cout << "Seleccione una opción:\n";
        std::cout << "1. Ordenar por fecha y hora y generar output602-1.out\n";
        std::cout << "2. Ordenar por IP, fecha y hora y generar output602-2.out\n";
        std::cout << "3. Búsqueda por rango de IPs\n";
        std::cout << "4. Mostrar sumatoria de datos\n";
        std::cout << "5. Salir\n";

        int option;
        std::cin >> option;

        switch (option) {
            case 1:
                option1(dataList);
                break;
            case 2:
                option2(dataList);
                break;
            case 3:
                option3(dataList);
                break;
            case 4:
                option4(dataList);
                break;
            case 5:
                return 0;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    return 0;
}