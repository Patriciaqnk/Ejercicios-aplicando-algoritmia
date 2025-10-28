#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

char randomChar() {
    char options[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    return options[rand() % 5]; //Número de caracteres distintos que queremos generar
}

int main(){
    int casos = 1;
    srand(time(0));

    cout << casos << endl;

    for(int i = 0; i < casos; i++){
        int longitudVector = 100000; //Número de caracteres que queremos que tenga el vector
        int longitudSecuencia = 100; //Longitud de la secuencia que buscamos
        char caracterABuscar = randomChar();    //Caracter que vamos a buscar

        cout << longitudVector <<  " " << longitudSecuencia << " " << caracterABuscar << endl;

        for(int j = 0; j < longitudVector; j++){
            cout << randomChar() << " ";
        }
        cout << endl;   //Sacamos el vector por salida estandar
    }
}