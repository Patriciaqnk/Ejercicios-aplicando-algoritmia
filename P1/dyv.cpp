#include<iostream>
#include<vector>
using namespace std;

//La variable maximoGlobal sirve para actualizar la posición donde empieza la secuencia que buscamos y la variable posicionGlobal para almacenarla
int maximoGlobal;
int posicionGlobal;
vector<char> vectorGlobal;

int max_seq( int l, int r, char c) // Función SecuenciaMaxima
{   
    //Si l es igual a r devolvemos 1 o 0 según sea el caracter que buscamos o no
    if(l == r) return vectorGlobal[l] == c; 

    //Calculamos la mitad y hacemos una llamada recursiva a ambas mitades
    int mid = (l+r)/2;
    int l_max = max_seq( l, mid, c);
    int r_max = max_seq( mid+1, r, c);

    //Ahora lo que vamos a comprobar es si alguna secuencia pasa entre las dos mitades y por tanto no es reconocida completamente por las llamadas anteriores
    int cruce_max = 0;          //El tamaño de la subsecuencia que pasa por en medio
    int conteo_izq = 0;         //Los elementos que hay hasta mid
    int conteo_der = 0;         //Los elementos que hay desde mid+1
    int posInicial = mid;       //La posición inicial de esta hipotética subsecuencia
    if(vectorGlobal[mid] == c && vectorGlobal[mid+1] == c) {   //Esto solo se da en el caso de que el caracter mid y el mid+1 sean el caracter que buscamos   
        //Contamos los elementos que hay desde mid hasta l
        int i = mid;
        while(i>=l && vectorGlobal[i] == c)
        {
            conteo_izq++;
            posInicial = i;
            i--;

        }
        //Contamos los elementos que hay desde mid+1 hasta r
        int j = mid+1;
        while(j<=r && vectorGlobal[j] == c)
        {
            conteo_der++;
            j++;
        }
    }

    //El tamaño de esta subsecuencia es la suma de los dos conteos
    cruce_max = conteo_der + conteo_izq;

    //El maximo de las 3 subsecuencias calculadas es la que buscamos
    int maximo = max(cruce_max, max(l_max, r_max));
    
    //Según la subsecuencia mayor de las 3. Cambiamos la variable global maximo y la posicion inicial de la tesecuencia
    if(cruce_max == maximo && cruce_max > maximoGlobal){
        posicionGlobal = posInicial;
        maximoGlobal = cruce_max;
    }
    if(r_max == maximo && r_max > maximoGlobal){
        maximoGlobal = r_max;
        posicionGlobal = mid+1;
    }
    if(l_max == maximo && l_max > maximoGlobal){
        maximoGlobal = l_max;
        posicionGlobal = l;
    }

    //Devolvemos la subsecuencia más grande.
    return maximo;
}


int main()
{
    //Número de casos
    int b;

    cin >> b;

    for(int a = 0; a<b; a++)
    {
        int n, m;
        char c;

        //Leemos los datos de entrada
        cin >> n >> m >> c;
        vectorGlobal.resize(n); //Asignar tamaño al vector según la entrada

        for(int i = 0; i<n; i++)
        {
            cin >> vectorGlobal[i];
        }

        //Variables globales de donde se encuentra la mayor secuencia de caracteres consecutivos y su posición de inicio
        maximoGlobal = 0;
        posicionGlobal = 0;
        //Calculamos la máxima secuencia
        int maximo = max_seq( 0, n, c);
        //Si el máximo es mayor al tamaño de la subsecuencia que nos piden, hacemos que sea igual a m
        if(maximo > m) maximo = m;
        //Si la posición de inicio no es coherente por el tamaño de m, la ajustamos
        if(posicionGlobal + m > n){
            posicionGlobal = n - m;
        }
        //Imprimimos la salida.
        cout << "CASO " << a+1 << ": " << endl;
        /*cout << n << " " << m << " " << c << endl;
        for(int i = 0; i<n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;*/

        cout << "DyV: ";
        cout << "MAXIMO: " << maximo;
        if(maximoGlobal > 0) cout << " POSICIÓN: " << posicionGlobal+1;
        cout << endl;
        //cout << "Directo: ";
        //Hacemos el calculo de forma directa para comprobar que nuestro algoritmo de DyV funciona
        //directo(v, n, m, c);
        cout << endl;
    }

    return 0;

}
