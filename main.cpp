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

//funcion para realizar la tirada de los 5 dados 
int tirar_dados(int dados[5]) {
    for (int i = 0; i < 5; i++) {
        dados[i] = rand() % 6 + 1;
    }
}

//verifacion cuando salga el numero 6 se guarde ya que es el barco 
bool verificar_barco(int dados[5]) {
    for (int i = 0; i < 5; i++) {
        if (dados[i] == 6) {
            return true;
        }
    }
    return false;
}

//verifacion cuando salga el numero 5 se guarde ya que es el capitan
bool verificar_capitan(int dados[5]) {
    for (int i = 0; i < 5; i++) {
        if (dados[i] == 5) {
            return true;
        }
    }
    return false;
}

//verifacion cuando salga el numero 4 se guarde ya que es tripulacion
bool verificar_tripulacion(int dados[5]) {
    for (int i = 0; i < 5; i++) {
        if (dados[i] == 4) {
            return true;
        }
    }
    return false;

}

void menu(){
    cout<<"======= Sea usted bienvenido a BCT(el juego del Barco,Capitan y Tripulacion)=======/n";
    cout<<"Seleccione una opcion";
    cout<<"Jugar partida/n";
    cout<<"2.Como se gana?/n";
    cout<<"3.Salir/n";
    cout<<"======================================================================================";
}

void como_se_juega(){
    cout<<"======= Como se juega=======/n";
    cout << "1. Lanza 5 dados.\n";
    cout << "2. Si obtienes un 6, es el barco. Guárdalo y lanza los otros.\n";
    cout << "3. Si obtienes un 5, es el capitán. Solo puedes guardarlo si ya tienes el barco.\n";
    cout << "4. Si obtienes un 4, es la tripulación. Solo puedes guardarla si tienes el barco y el capitán.\n";
    cout << "5. Gana quien consiga barco, capitán y tripulación en menos tiradas.\n";
    cout << "==================================================================================================\n\n";
}


int main(){
   

//implementar -Si conseguimos un 6 en la primera tirada lo guardamos y pasamos a realizar las otras.
//Si conseguimos un 6 y un 5 en una sola tirada, podemos guardar ambos y tratar de obtener la tripulación.
//Si conseguimos un 6 y un 4 solamente podremos guardar el 6, porque necesitamos tener un capitán antes de poder agregar gente a la tripulación.
//Si en una sola tirada sale: el 6 y el 5, podemos guardar los dos pero deben ir en orden por lo que si nos sale un 6 y un 4 solo podremos guardar el 6.
//Gana el que saque barco, capitan y tripulación en la menor cantidad de partidas

    _getch();
    return 0;
}

