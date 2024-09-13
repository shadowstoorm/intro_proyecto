#include <iostream>
#include <conio.h>  
#include <random> //para la generacion de numeros aleatorios

using namespace std;

void dado(int numero) {
    if (numero == 1) {
        cout << " ----- \n";
        cout << "|     |\n";
        cout << "|  *  |\n";
        cout << "|     |\n";
        cout << " ----- \n";
    } 
    if (numero == 2) {
        cout << " ----- \n";
        cout << "| *   |\n";
        cout << "|     |\n";
        cout << "|   * |\n";
        cout << " ----- \n";
    } 
    if (numero == 3) {
        cout << " ----- \n";
        cout << "| *   |\n";
        cout << "|  *  |\n";
        cout << "|   * |\n";
        cout << " ----- \n";
    } 
    if (numero == 4) {
        cout << " ----- \n";
        cout << "| * * |\n";
        cout << "|     |\n";
        cout << "| * * |\n";
        cout << " ----- \n";
    } 
    if (numero == 5) {
        cout << " ----- \n";
        cout << "| * * |\n";
        cout << "|  *  |\n";
        cout << "| * * |\n";
        cout << " ----- \n";
    } 
    if (numero == 6) {
        cout << " ----- \n";
        cout << "| * * |\n";
        cout << "| * * |\n";
        cout << "| * * |\n";
        cout << " ----- \n";
    }
}

int tirar_dados(int dados[5]) {
    for (int i = 0; i < 5; i++) {
        dados[i] = rand() % 6 + 1;
    }
}

bool verificar_barco(int dados[5]) {
    for (int i = 0; i < 5; i++) {
        if (dados[i] == 6) {
            return true;
        }
    }
    return false;
}

bool verificar_capitan(int dados[5]) {
    for (int i = 0; i < 5; i++) {
        if (dados[i] == 5) {
            return true;
        }
    }
    return false;
}

bool verificar_tripulacion(int dados[5]) {
    for (int i = 0; i < 5; i++) {
        if (dados[i] == 4) {
            return true;
        }
    }
    return false;
}

int main(){

//faltar implemtar la logica
//recuerden usar las funciones que les deje arriba

    _getch();
    return 0;
}

