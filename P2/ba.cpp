#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 100
#define INF 1000000000

int B[MAXN][MAXN];  // matriz de distancias
int voa = -INF;     // valor óptimo actual
int soa[MAXN];      // mejor solución encontrada
int m;              // tamaño del subconjunto

//Calculamos la suma de distancias
int valor(int s[]) {
    int total = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = i + 1; j <= m; ++j)
            total += B[s[i]][s[j]] + B[s[j]][s[i]];
    return total;
}

//Generar nivel
void generar(int nivel, int s[]) {
    if (s[nivel] == -1) {
        if(nivel == 1){
            s[nivel] = 0;
        }else{
            s[nivel] = s[nivel -1] +1;
        }
    } else {
        s[nivel]++;
    }
}

//Comprueba si el valor actual está dentro del rango de valores
bool criterio(int nivel, int s[], int n) {
    return s[nivel] < n;
}

// Verificar si la solucion es la definitiva
bool solucion(int nivel) {
    return nivel == m + 1;
}

// Comprobar si hay más hermanos
bool masHermanos(int nivel, int s[], int n) {
    return s[nivel] < n - (m - nivel);
}

// Volver a una rama anterior
void retroceder(int &nivel, int s[]) {
    s[nivel] = -1;
    nivel--;
}

void backtracking(int n) {
    int s[MAXN];    // Solución parcial
    memset(s, -1, sizeof(s));  //Inicialización a -1
    int nivel = 1;             // Nivel inicial  
    voa = -INF;                // Inicializamos el valor 

    while (nivel != 0) {
        // Generar siguiente hermano
        generar(nivel, s);
        //Si completamos la solución
        if (solucion(nivel)) {
            int bact = valor(s);
            if (bact > voa) {
                voa = bact;
                memcpy(soa, s, sizeof(int) * (m + 1));
            }
        }
        //Verificar si merece la pena seguir
        if (criterio(nivel, s, n)) {
            nivel++;
            s[nivel] = -1;
        } else {
            // Retroceder si no hay más hermanos por explorar
            while (!masHermanos(nivel, s, n) && nivel > 1)
                retroceder(nivel, s);
            if (nivel == 1 && !masHermanos(nivel, s, n))
                nivel = 0;  // Terminar el backtracking
        }
    }

    cout << voa << endl;
}

int main() {
    int T;
    cin >> T;

    for(int casos = 0; casos < T; casos++) {
        int n;
        cin >> n >> m;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> B[i][j];

        backtracking(n);
    }

    return 0;
}
