
#include<iostream>
#include<vector>
using namespace std;

void directo(vector<char> v, int n, int m, char c){
    //Variables de maximo y posicion
    int posicion = 0;
    int maximo = 0;

    //Recorremos el vector de m en m elementos
    for(int i = 0; i<=n-m; i++)
    {   
        //Hayamos la mayor subsecuencia
        int actualsubsecuencia = 0;
        for(int j = i; j<i+m; j++)
        {
            if(v[j] == c)
            {
                actualsubsecuencia++;
            }
            else
            {
                actualsubsecuencia=0;
            }
            if(actualsubsecuencia>maximo)
            {
                maximo = actualsubsecuencia;
                posicion = i;
            }
        }
    }

    //Imprimimos la salida
    cout << "MAXIMO: " << maximo;
    if(maximo>0)
    cout << " POSICIÓN: " << posicion+1;
}
int main(){
    //Número de casos
    int b;

    cin >> b;
    for(int a = 0; a<b; a++)
    {
        int n, m;
        char c;

        //Leemos los datos de entrada
        cin >> n >> m >> c;

        vector<char> v(n);

        for(int i = 0; i<n; i++)
        {
            cin >> v[i];
        }

        cout << "CASO " << a+1 << ": " << endl;
        cout << "Directo: ";
        //Hacemos el calculo de forma directa para comprobar que nuestro algoritmo de DyV funciona
        
        directo(v, n, m, c);
        cout << endl;
        cout << endl;
    }
    
    return 0;
}