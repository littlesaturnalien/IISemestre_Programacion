/*Escriba un programa que capture las notas definitivas 
del primer corte de la asignatura "ESTRUCTURAS DE DATOS"

Menú
1. Presentar el nombre y nota más alta
2. Presentar el nombre y nota más baja
3. El promedio de las notas
4. Debe permitir editar cualquier nombre o nota
5. Mostrar las notas ordenadas de menor a mayor
*/

#include <iostream>
#define MAX 5
using namespace std;

typedef struct{
    char nombreCompleto[100];
    float notas;
} estudiantes;

estudiantes notasDefinitivas[MAX];

void menuPrincipal(int cant, double x);
void nombreONota(int cant, double x);
void mostrarEstudiantes(int cant);
void regresarAlMenuPrincipal(int cant, double x);

int main(){
    int cant;
    double x;

    cout << "Cuantos estudiantes del primer corte de la asignatura ESTRUCTURA DE DATOS deseas ingresar:" << endl;
    cin >> cant;

    system("cls");

    if (cant < MAX && cant > 0){
        for (int i = 0; i < cant; i++){
        cout << "Ingrese el nombre completo del estudiante # " << i+1 << ":" << endl;
        scanf(" %[^\n]", notasDefinitivas[i].nombreCompleto);
        cout << "Ingrese su nota del 1er Corte: " << endl;
        cin >> notasDefinitivas[i].notas;
        x = x + notasDefinitivas[i].notas;
        cout << endl;
        }
        system("pause");
        system("cls");
        menuPrincipal(cant, x);
    }
    else{
        cout << "Ha escrito un valor fuera del rango permitido." << endl;
        system("pause");
        system("cls");
        main();
    }
    return 0;
}

void menuPrincipal(int cant, double x){
    int temp, ejercicio;
    double notaAlta = -100, notaBaja = 100, promedio;

    cout << endl;
    cout << "----------ESTRUCTURA DE DATOS----------" << endl;
    cout << "      Notas definitivas - I Corte      " << endl;
    cout << endl;
    cout << "  1. Mostrar el nombre y la nota mas alta." << endl;
    cout << "  2. Mostrar el nombre y la nota mas baja." << endl;
    cout << "  3. El promedio de notas." << endl;
    cout << "  4. Editar notas o nombre de estudiante." << endl;
    cout << "  5. Mostrar las notas ordenadas de menor a mayor." << endl;
    cout << endl;
    cin >> ejercicio;

    switch (ejercicio)
    {
    case 1: //nota mas alta
        int pos;
        for (int i = 0; i < cant; i++){
            if (notasDefinitivas[i].notas > notaAlta){
                notaAlta = notasDefinitivas[i].notas;
            }
        }
        for (int i = 0; i < cant; i++){
            if (notaAlta == notasDefinitivas[i].notas){
                pos = i;
            }
        }
        cout << endl;
        cout << "----NOTA MAS ALTA----" << endl;
        cout << "Estudiante: " << notasDefinitivas[pos].nombreCompleto << endl;
        cout << "Nota: " << notaAlta << endl;
        system("pause");
        system("cls");
        regresarAlMenuPrincipal(cant, x);
        break;
    
    case 2: //nota mas baja
        for (int i = 0; i < cant; i++){
            if (notasDefinitivas[i].notas < notaBaja){
                notaBaja = notasDefinitivas[i].notas;
            }
        }
        for (int i = 0; i < cant; i++){
            if (notaBaja == notasDefinitivas[i].notas){
                pos = i;
            }
        }
        cout << endl;
        cout << "----NOTA MAS BAJA----" << endl;
        cout << "Estudiante: " << notasDefinitivas[pos].nombreCompleto << endl;
        cout << "Nota: " << notaBaja << endl;
        system("pause");
        system("cls");
        regresarAlMenuPrincipal(cant, x);
        break;

    case 3: //promedio
        promedio = x/cant;
        cout << endl;
        cout << "El promedio de notas es " << promedio << endl;
        system("pause");
        system("cls");
        regresarAlMenuPrincipal(cant, x);
        break;
    
    case 4: //editar el arreglo
        system("cls");
        nombreONota(cant, x);
        break;

    case 5:
        system("cls"); 
        cout << "Notas ordenadas: " << endl;
        for (int i = 0; i < cant; i++){
            for (int j = i+1; j < cant; j++){
                if (notasDefinitivas[i].notas > notasDefinitivas[j].notas){
                    temp = notasDefinitivas[j].notas;
                    notasDefinitivas[j].notas = notasDefinitivas[i].notas;
                    notasDefinitivas[i].notas = temp;
                }
            }
        }
        for (int i = 0; i < cant; i++){
            cout << notasDefinitivas[i].notas << endl;
        }
        system("pause");
        system("cls");
        regresarAlMenuPrincipal(cant, x);
        break;

    default:
        cout << "Has ingresado un numero invalido. Intente otra vez." << endl;
        system("pause");
        system("cls");
        menuPrincipal(cant, x);
        break;
    }
}

void nombreONota(int cant, double x){
    int opc, posicion;
    cout << "SELECCIONE QUE DESEA MODIFICAR:" << endl;
    cout << endl;
    cout << "  1. Nombre de estudiante." << endl;
    cout << "  2. Nota de estudiante." << endl;
    cout << endl;
    cin >> opc;

    switch(opc){
        case 1: 
            system("cls");
            mostrarEstudiantes(cant);
            cout << endl;
            cout << "Ingrese el # del estudiante que deseas modificar: " << endl;
            cin >> posicion;
            if (posicion <= cant){
                cout << "Edite el nombre del estudiante #" << posicion << ":" << endl;
                scanf(" %[^\n]", notasDefinitivas[posicion-1].nombreCompleto);
            }
            else{
                cout << "Ese numero no existe." << endl;
            }
            system("cls");
            cout << "Lista modificada: " << endl;
            cout << endl;
            mostrarEstudiantes(cant);
            system("pause");
            system("cls");
            regresarAlMenuPrincipal(cant, x);
            break;

        case 2:
            system("cls");
            mostrarEstudiantes(cant);
            cout << endl;
            cout << "Ingrese el # del estudiante que deseas modificar: " << endl;
            cin >> posicion;
            if (posicion <= cant){
                cout << "Escribe la nueva nota del estudiante #" << posicion << ":" << endl;
                cin >> notasDefinitivas[posicion-1].notas;
            }
            else{
                cout << "Ese numero no existe." << endl;
            }
            system("cls");
            cout << "Lista modificada: " << endl;
            cout << endl;
            mostrarEstudiantes(cant);
            system("pause");
            system("cls");
            regresarAlMenuPrincipal(cant, x);
            break;

        default: 
            cout << "Has ingresado un numero invalido. Intente otra vez." << endl;
            system("pause");
            system("cls");
            nombreONota(cant, x);
            break;
    }
}

void mostrarEstudiantes(int cant){
    for (int i = 0; i < cant; i++){
        cout << "Estudiante: " << notasDefinitivas[i].nombreCompleto << endl;
        cout << "Nota: " << notasDefinitivas[i].notas << endl;
        cout << endl;
    }
}

void regresarAlMenuPrincipal(int cant, double x){
    int xd;
    cout << "QUIERES REGRESAR AL MENU PRINCIPAL?" << endl;
    cout << endl;
    cout << "  1. SI" << endl;
    cout << "  O presione cualquier numero para salir del programa" << endl;
    cout << endl;
    cin >> xd;

    switch(xd){
        case 1: 
            system("cls");
            menuPrincipal(cant, x);
            break;

        default: 
            system("cls");
            cout << "HA SALIDO EXITOSAMENTE" << endl;
            break;
    }
}