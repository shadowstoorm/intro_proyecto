#include <iostream>
#include <conio.h>  
#include <cstdlib>  // para rand()  
#include <ctime>    // para time() 
#include <string>   // para std::string para el jugador 1 y la computadora
#include <windows.h>

using namespace std;


// Función para cambiar el color del texto en la consola
void cambiar_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Función para restablecer el color predeterminado de la consola
void restaurar_color() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
}

void dado(int numero) {
    if (numero == 6) {
        cambiar_color(14);
    } else if (numero == 5) {
        cambiar_color(1);
    } else if (numero == 4) {
        cambiar_color(12);
    }

    if (numero == 1) {
        cout << endl;
        cout << " ----- \n";
        cout << "|     |\n";
        cout << "|  *  |\n";
        cout << "|     |\n";
        cout << " ----- \n";
    } else if (numero == 2) {
        cout << endl;
        cout << " ----- \n";
        cout << "| *   |\n";
        cout << "|     |\n";
        cout << "|   * |\n";
        cout << " ----- \n";
    } else if (numero == 3) {
        cout << endl;
        cout << " ----- \n";
        cout << "| *   |\n";
        cout << "|  *  |\n";
        cout << "|   * |\n";
        cout << " ----- \n";
    } else if (numero == 4) {
        cout << endl;
        cout << " ----- \n";
        cout << "| * * |\n";
        cout << "|     |\n";
        cout << "| * * |\n";
        cout << " ----- \n";
    } else if (numero == 5) {
        cout << endl;
        cout << " ----- \n";
        cout << "| * * |\n";
        cout << "|  *  |\n";
        cout << "| * * |\n";
        cout << " ----- \n";
    } else if (numero == 6) {
        cout << endl;
        cout << " ----- \n";
        cout << "| * * |\n";
        cout << "| * * |\n";
        cout << "| * * |\n";
        cout << " ----- \n";
    }
    restaurar_color();
}

// Realizar la tirada de los 5 dados
void tirar_dados(int dados[5], bool guardados[5]) {
    for (int i = 0; i < 5; i++) {
        if (!guardados[i]) { 
            dados[i] = rand() % 6 + 1; 
        }
    }
}

// Verificar si sacaste 6 para guardar el barco
bool verificar_barco(int dados[5], bool guardados[5]) {
    for (int i = 0; i < 5; i++) {
        if (dados[i] == 6 && !guardados[i]) {
            guardados[i] = true; 
            return true;
        }
    }
    return false;
}

// Verificar si sacaste 5 para guardar el capitán
bool verificar_capitan(int dados[5], bool guardados[5]) {
    for (int i = 0; i < 5; i++) {
        if (dados[i] == 5 && !guardados[i]) {
            guardados[i] = true; 
            return true;
        }
    }
    return false;
}

// Verificar si sacaste 4 para guardar la tripulación
bool verificar_tripulacion(int dados[5], bool guardados[5]) {
    for (int i = 0; i < 5; i++) {
        if (dados[i] == 4 && !guardados[i]) {
            guardados[i] = true;    
            return true;
        }
    }
    return false;
}

// Para a la hora de cerrar el programa espere dos segundos 
void esperar_2_segundos() {
    for (long long i = 0; i < 1000000000; i++); 
}

// El menú que aparece cuando abrimos el juego
void menu() {
    cout << "======= Sea usted bienvenido a BCT (el juego del Barco, Capitan y Tripulacion) =======" << endl;
    cout << "Seleccione una opcion" << endl;
    cout << "1. Jugar partida" << endl;
    cout << "2. Como se juega?" << endl;
    cout << "3. Salir" << endl;
    cout << "======================================================================================" << endl;
}

// Las reglas del juego 
void como_se_juega() {
    cout << "======= Como se juega =======" << endl;
    cout << "---> Lanza 5 dados." << endl;
    cout << "---> Si obtienes un 6, es el barco. Guardalo y lanza los otros." << endl;
    cout << "---> Si obtienes un 5, es el capitan. Solo puedes guardarlo si ya tienes el barco." << endl;
    cout << "---> Si obtienes un 4, es la tripulacion. Solo puedes guardarla si tienes el barco y el capitan." << endl;
    cout << "---> Gana quien consiga barco, capitan y tripulacion en menos tiradas." << endl;
    cout << "---> Regresar al menu" << endl;
    cout << "---->Creado por Ulrich Nieto,Thiago Arias,Lucio" << endl;
    cout << "==================================================================================================" << endl;
}

//Prototipo de funciones
void jugar_turno(string jugador, int& tiradas); 
void jugar_turno_computadora(string jugador, int& tiradas);

// Menú de reintentar o salir
void menu_reintentar(string& jugador1, int& tiradas_jugador1, int& tiradas_computadora) {
    int opcion; 
    while (true) {
        cout << "====== Fin de la partida ======" << endl;
        cout << "1. Jugar de nuevo" << endl;
        cout << "2. Salir" << endl;
        cout << "===============================" << endl;
        cout << "-----> ";
        cin >> opcion;
        cin.ignore();  // Ignorar el salto de línea después de ingresar la opción

        if (opcion == 1) {
            // Reiniciar las tiradas
            tiradas_jugador1 = 0;
            tiradas_computadora = 0;

            // Volver a jugar la partida
            jugar_turno(jugador1, tiradas_jugador1);
            jugar_turno_computadora("Computadora", tiradas_computadora);

        if (tiradas_jugador1 < tiradas_computadora) {
            cout << jugador1 << " gana la partida!" << endl;
            menu_reintentar(jugador1, tiradas_jugador1, tiradas_computadora); 
       } else if (tiradas_jugador1 > tiradas_computadora) {
            cout << "Fuiste vencido por la maquina!" << endl;
            menu_reintentar(jugador1, tiradas_jugador1, tiradas_computadora); 
       } else {    
            cout << "Es un empate!" << endl;
            menu_reintentar(jugador1, tiradas_jugador1, tiradas_computadora);
            }

        } else if (opcion == 2) {
            cout << "Saliendo del juego..." << endl;
            esperar_2_segundos();  // Esperar unos segundos antes de salir
            exit(0); // Termina el programa
        } else {
            cout << "Por favor selecciona una de las opciones validas :)" << endl;
        }
    }
}

// Jugadas del jugador
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

        if (barco) {
            if (!capitan) {
                capitan = verificar_capitan(dados, guardados);
                if (capitan) {
                    cout << "Capitan conseguido!" << endl;
                } else {
                    cout << "Aun no has conseguido el capitan." << endl;
                }
            }
        }

        if (barco && capitan) {
            if (!tripulacion) {
                tripulacion = verificar_tripulacion(dados, guardados);
                if (tripulacion) {
                    cout << "Tripulacion conseguida!" << endl;
                } else {
                    cout << "Aun no has conseguido la tripulacion." << endl;
                }
            }
        }
    }

    cout << jugador << " ha conseguido barco, capitan y tripulacion en " << tiradas << " tiradas!" << endl;
}

// Jugadas del computadora 
void jugar_turno_computadora(string jugador, int& tiradas) {
    int dados[5];
    bool guardados[5] = {false}; 
    bool barco = false, capitan = false, tripulacion = false;
    
    while (!barco || !capitan || !tripulacion) {
        tiradas++;
        cout << jugador << " - Tirada " << tiradas << ": Computadora está lanzando los dados..." << endl;
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
                cout << "La computadora ha encontrado el barco!" << endl;
            }
        }

        if (barco) {
            if (!capitan) {
                capitan = verificar_capitan(dados, guardados);
                if (capitan) {
                    cout << "Capitan conseguido por la computadora!" << endl;
                }
            }
        }

        if (barco && capitan) {
            if (!tripulacion) {
                tripulacion = verificar_tripulacion(dados, guardados);
                if (tripulacion) {
                    cout << "Tripulacion conseguida por la computadora!" << endl;
                }
            }
        }
    }

    cout << jugador << " ha conseguido barco, capitan y tripulacion en " << tiradas << " tiradas!" << endl;
}

int main() {
    srand(time(0)); 

    int opcion;
    string jugador1;
    int tiradas_jugador1 = 0, tiradas_computadora = 0;
    
    do {
        menu();
        cout << "-----> ";
        cin >> opcion;
        cin.ignore();  // Ignorar el salto de línea después de ingresar la opción

        if (opcion == 1) {
            cout << "Introduce el nombre del Jugador 1: ";
            getline(cin, jugador1);  // Solicitar el nombre del jugador

            cout << "Iniciando partida contra la computadora..." << endl;
            jugar_turno(jugador1, tiradas_jugador1);
            jugar_turno_computadora("Computadora", tiradas_computadora);

            if (tiradas_jugador1 < tiradas_computadora) {
                cout << jugador1 << " gana la partida!" << endl;
            } else if (tiradas_jugador1 > tiradas_computadora) {
                cout << "Fuiste vencido por la maquina!" << endl;
                menu_reintentar(jugador1, tiradas_jugador1, tiradas_computadora); 
            } else {    
                cout << "Es un empate!" << endl;
            }
        } else if (opcion == 2) {
            como_se_juega();
        } else if (opcion == 3) {
            cout << "Saliendo del juego..." << endl;
            esperar_2_segundos();  
        } else {
            cout << "Por favor selecciona una de las opciones validas :)" << endl;
        }

    } while (opcion != 3); 

    return 0;  
}

