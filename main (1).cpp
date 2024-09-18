#include <iostream>
#include <conio.h>  
#include <cstdlib>  // para rand() y srand() 
#include <ctime>    // para time() 
#include <string>   // para std::string

using namespace std;

void dado(int numero) {
    if (numero == 1) {
        cout<<endl;
        cout << " ----- \n";
        cout << "|     |\n";
        cout << "|  *  |\n";
        cout << "|     |\n";
        cout << " ----- \n";
    } 
    if (numero == 2) {
        cout<<endl;
        cout << " ----- \n";
        cout << "| *   |\n";
        cout << "|     |\n";
        cout << "|   * |\n";
        cout << " ----- \n";
    } 
    if (numero == 3) {
        cout<<endl;
        cout << " ----- \n";
        cout << "| *   |\n";
        cout << "|  *  |\n";
        cout << "|   * |\n";
        cout << " ----- \n";
    } 
    if (numero == 4) {
        cout<<endl;
        cout << " ----- \n";
        cout << "| * * |\n";
        cout << "|     |\n";
        cout << "| * * |\n";
        cout << " ----- \n";
    } 
    if (numero == 5) {
        cout<<endl;
        cout << " ----- \n";
        cout << "| * * |\n";
        cout << "|  *  |\n";
        cout << "| * * |\n";
        cout << " ----- \n";
    } 
    if (numero == 6) {
        cout<<endl;
        cout << " - - - -  \n";
        cout << "|  *  *  |\n";
        cout << "|  *  *  |\n";
        cout << "|  *  *  |\n";
        cout << " - - - -  \n";
    }
}

// Función para realizar la tirada de los 5 dados
void tirar_dados(int dados[5], bool guardados[5]) {
    for (int i = 0; i < 5; i++) {
        if (!guardados[i]) { 
            dados[i] = rand() % 6 + 1; // Generación de número aleatorio entre 1 y 6
        }
    }
}

// Verificación cuando salga el número 6, ya que es el barco
bool verificar_barco(int dados[5], bool guardados[5]) {
    for (int i = 0; i < 5; i++) {
        if (dados[i] == 6 && !guardados[i]) {
            guardados[i] = true; 
            return true;
        }
    }
    return false;
}

// Verificación cuando salga el número 5, ya que es el capitán
bool verificar_capitan(int dados[5], bool guardados[5]) {
    for (int i = 0; i < 5; i++) {
        if (dados[i] == 5 && !guardados[i]) {
            guardados[i] = true; 
            return true;
        }
    }
    return false;
}

// Verificación cuando salga el número 4, ya que es tripulación
bool verificar_tripulacion(int dados[5], bool guardados[5]) {
    for (int i = 0; i < 5; i++) {
        if (dados[i] == 4 && !guardados[i]) {
            guardados[i] = true; 
            return true;
        }
    }
    return false;
}

// Función para esperar dos segundos antes de cerrar el programa
void esperar_2_segundos() {
    for (long long i = 0; i < 1000000000; i++); 
}

// Menú principal
void menu() {
    cout << "======= Sea usted bienvenido a BCT (el juego del Barco, Capitan y Tripulacion) =======" << endl;
    cout << "Seleccione una opcion" << endl;
    cout << "1. Jugar partida" << endl;
    cout << "2. Como se gana?" << endl;
    cout << "3. Salir" << endl;
    cout << "======================================================================================" << endl;
}

void como_se_juega() {
    cout << "======= Como se juega =======" << endl;
    cout << "---> Lanza 5 dados." << endl;
    cout << "---> Si obtienes un 6, es el barco. Guardalo y lanza los otros." << endl;
    cout << "---> Si obtienes un 5, es el capitan. Solo puedes guardarlo si ya tienes el barco." << endl;
    cout << "---> Si obtienes un 4, es la tripulacion. Solo puedes guardarla si tienes el barco y el capitan." << endl;
    cout << "---> Gana quien consiga barco, capitan y tripulacion en menos tiradas." << endl;
    cout << "---> Regresar al menu" << endl;
    cout << "==================================================================================================" << endl;
}

void jugar_turno(string jugador, int& tiradas) {
    int dados[5];
    bool guardados[5] = {false}; 
    bool barco = false, capitan = false, tripulacion = false;
    
    while (!barco || !capitan || !tripulacion) {
        tiradas++;
        cout << jugador << " - Tirada " << tiradas << ": (presiona Enter para tirar los dados)";
        cin.get(); 

        tirar_dados(dados, guardados);
        cout << "Resultado de los dados: ";
        for (int i = 0; i < 5; i++) {
            cout << dados[i] << " ";
            dado(dados[i]); 
        }
        cout << endl;

        if (!barco) {
            barco = verificar_barco(dados, guardados);
            if (barco) {
                cout << "Has encontrado el barco!" << endl;
            } else {
                cout << "Aun no has conseguido el barco." << endl;
            }
        }

        if (barco && !capitan) {
            capitan = verificar_capitan(dados, guardados);
            if (capitan) {
                cout << "Capitan conseguido!" << endl;
            } else {
                cout << "Aun no has conseguido el capitan." << endl;
            }
        }

        if (barco && capitan && !tripulacion) {
            tripulacion = verificar_tripulacion(dados, guardados);
            if (tripulacion) {
                cout << "Tripulacion conseguida!" << endl;
            } else {
                cout << "Aun no has conseguido la tripulacion." << endl;
            }
        }
    }

    cout << jugador << " ha conseguido barco, capitan y tripulacion en " << tiradas << " tiradas!" << endl;
}

int main() {
    srand(time(0)); 

    int opcion;
    menu();
    cout << "-----> ";
    cin >> opcion;
    cin.ignore();

    if (opcion == 1) {
        // Reproducir música después de elegir "Jugar partida"
        int result = std::system("explorer C:\\Users\\hggym\\OneDrive\\Escritorio\\UPC\\Proyecto_intro\\intro_proyecto\\piratas_del_caribe.wav");

        if (result != 0) {
            cout << "Error: No se pudo reproducir el archivo de audio." << endl;
        }

        string jugador1, jugador2;
        cout << "Introduce el nombre del Jugador 1: ";
        getline(cin, jugador1);
        cout << "Introduce el nombre del Jugador 2: ";
        getline(cin, jugador2);

        int tiradas_jugador1 = 0, tiradas_jugador2 = 0;

        cout << "Iniciando partida..." << endl;
        jugar_turno(jugador1, tiradas_jugador1);
        jugar_turno(jugador2, tiradas_jugador2);

        if (tiradas_jugador1 < tiradas_jugador2) {
            cout << jugador1 << " gana la partida!" << endl;
        } else if (tiradas_jugador1 > tiradas_jugador2) {
            cout << jugador2 << " gana la partida!" << endl;
        } else {
            cout << "Es un empate!" << endl;
        }
    } else if (opcion == 2) {
        como_se_juega();
    } else if (opcion == 3) {
        cout << "Saliendo del juego..." << endl;
        esperar_2_segundos();
        exit(0);
    } else {
        cout << "Por favor selecciona una de las opciones validas :)" << endl;
    }

    _getch();
    return 0;
}

