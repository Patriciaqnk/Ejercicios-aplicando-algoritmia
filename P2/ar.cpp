#include<iostream>
#include<vector>
#define MAX 2147483647

using namespace std;

int main(){

    int nCasos;
    cin >> nCasos;
    cout << nCasos << endl;

    for(int i = 0;i < nCasos;i++){
        int M, A;

        cin >> M >> A;

        vector<vector<int>> matriz(M, vector<int>(A));
        vector<int> averiasPorMecanico(M, 0);       //Avería que resuelve cada mecanico
        vector<bool> averiasReparadas(A, false);    //Averias que han sido reparadas
        vector<int> mecanicoPorAveria(A, 0);        //Mecanicos que reparan cada avería concreta
        vector<bool> mecanicos(M, false);           //Mecanicos que han sido usados o no
        int reparaciones = 0;
        
        //Montamos la matriz y el array de averías por cada mecánico
        for(int j = 0;j < M;j++){
            for(int k = 0;k < A;k++){
                cin >> matriz[j][k];
                if(matriz[j][k] == 1) averiasPorMecanico[j]++;
            }
        }

        //Decisión voraz: Cada avería la repararará el mecánico que pueda reparar menos averías a parte de sobre la que se está iterando
        for(int j = 0;j < A;j++){
            int averiasMin = MAX;
            bool reparable = false;
            int mecanico = 0;
            for(int k = 0;k < M;k++){
                if(matriz[k][j] == 1 && !mecanicos[k]){
                    reparable = true;
                    if(averiasPorMecanico[k] < averiasMin){
                        averiasMin = averiasPorMecanico[k];
                        mecanico = k;
                    }
                }
            }
            //Si es reparable y el mecánico que se ha eledido está libre se le asigna la tarea
            if(reparable && !mecanicos[mecanico]){
                averiasReparadas[j] = true;
                mecanicoPorAveria[j] = mecanico+1;
                mecanicos[mecanico] = true;
                reparaciones++;
            }   
        }

        //Sacamos el resultados
        cout << reparaciones << endl;
        for(int j = 0;j < A;j++){
            cout << mecanicoPorAveria[j] << " ";
        }
        cout << endl;
    }

}