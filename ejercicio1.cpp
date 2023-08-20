/*Escriba un programa que capture las notas definitivas 
del primer corte de la asignatura "ESTRUCTURAS DE DATOS"

Menú
1. La nota más alta
2. La nota más baja
3. El promedio de las notas
4. Debe permitir editar cualquier nota
5. Mostrar las notas ordenadas de menor a mayor
*/

#include <iostream>
using namespace std;

int main(){
    int cant, temp, opc;
    double x, notaAlta = -100, notaBaja = 100, promedio;

    cout << "Cuantas notas del primer corte de la asignatura ESTRUCTURA DE DATOS desea ingresar:" << endl;
    cin >> cant;
    double notas[cant];

    system("cls");

    for (int i = 0; i < cant; i++){
        cout << "Ingresa la nota #" << i+1 << ":" << endl;
        cin >> notas[i];
        x = x + notas[i];
    }

    system("pause");
    system("cls");

    int ejercicio;
    cout << endl;
    cout << "----------ESTRUCTURA DE DATOS----------" << endl;
    cout << "      Notas definitivas - I Corte      " << endl;
    cout << endl;
    cout << "  1. La nota mas alta." << endl;
    cout << "  2. La nota mas baja." << endl;
    cout << "  3. El promedio de notas." << endl;
    cout << "  4. Editar notas." << endl;
    cout << "  5. Mostrar las notas ordenadas de menor a mayor." << endl;
    cout << endl;
    cin >> ejercicio;

    switch (ejercicio)
    {
    case 1: //nota mas alta
        for (int i = 0; i < cant; i++){
            if (notas[i] > notaAlta){
                notaAlta = notas[i];
            }
        }
        cout << endl;
        cout << "La nota mas alta ingresada es " << notaAlta << endl;
        break;
    
    case 2: //nota mas baja
        for (int i = 0; i < cant; i++){
            if (notas[i] < notaBaja){
                notaBaja = notas[i];
            }
        }
        cout << endl;
        cout << "La nota mas baja ingresada es " << notaBaja << endl;
        break;

    case 3: //promedio
        promedio = x/cant;
        cout << endl;
        cout << "El promedio de notas es " << promedio << endl;
        break;
    
    case 4: //editar el arreglo
        system("cls");
        cout << "Ingrese el # de nota que deseas modificar: " << endl;
        cin >> opc;
        if (opc <= cant){
            cout << "Nuevo valor en nota #" << opc << ":" << endl;
            cin >> notas[opc-1];
        }
        else{
            cout << "Esa posicion no existe." << endl;
        }
        cout << endl;
        cout << "Lista modificada: " << endl;
        for (int i = 0; i < cant; i++){
            cout << notas[i] << endl;
        }
        break;

    case 5:
        system("clear"); 
        cout << "Notas ordenadas: " << endl;
        for (int i = 0; i < cant; i++){
            for (int j = i+1; j < cant; j++){
                if (notas[i] > notas[j]){
                    temp = notas[j];
                    notas[j] = notas[i];
                    notas[i] = temp;
                }
            }
        }
        for (int i = 0; i < cant; i++){
            cout << notas[i] << endl;
        }
        break;

    default:
        cout << "Has ingresado un numero invalido. Intente otra vez." << endl;
        system("pause");
        system("cls");
        main();
        break;
    }

    return 0;
}