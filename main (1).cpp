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
    cout<<"   ======= Sea usted bienvenido a BCT(el juego del Barco,Capitan y Tripulacion)======="<<endl;
    cout<<"Seleccione una opcion"<<endl;
    cout<<"1.Jugar partida"<<endl;
    cout<<"2.Como se gana?"<<endl;
    cout<<"3.Salir"<<endl;
    cout<<"======================================================================================"<<endl;
}

void como_se_juega(){
    cout<<"======= Como se juega=======/"<<endl;
    cout << "---> Lanza 5 dados."<<endl;
    cout << "---> Si obtienes un 6, es el barco. Guardalo y lanza los otros."<<endl;;
    cout << "---> Si obtienes un 5, es el capitan. Solo puedes guardarlo si ya tienes el barco."<<endl;;
    cout << "---> Si obtienes un 4, es la tripulacion. Solo puedes guardarla si tienes el barco y el capitan."<<endl;;
    cout << "---> Gana quien consiga barco, capitan y tripulación en menos tiradas."<<endl;;
    cout <<"---> Regresar al menu"<<endl;
    cout << "=================================================================================================="<<endl;;
}


int main(){
   
   int opcion;

    menu();
    
    cout << "----->";
    cin >> opcion;

    if (opcion == 2) {
        como_se_juega(); 
    } else if (opcion == 1) {
        cout << "Iniciando partida..."<<endl; //implementar logica del juego aqui


    } else if (opcion == 3) {
        cout << "Saliendo del juego..."<<endl;
    } else {
        cout << "Por facor selecciona una de las opciones validas :)"<<endl;
    }



    _getch();
    return 0;
}

