#include <iostream>
#include <vector>
using namespace std;

// Solucion aproximada para cota superior
int voraz(int n, vector<vector<int>>& B) {
    int voa = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            voa = max(voa, B[i][j] + B[j][i]);
        }
    }
    return voa;
}

// Calculamos la suma de distancias
int valor(vector<int>& s, int m, vector<vector<int>>& B) {
    int total = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            total += B[s[i]][s[j]] + B[s[j]][s[i]];
        }
    }
    return total;
}

// Generar nivel
void generar(int nivel, vector<int>& s) {
    if (s[nivel] == -1) {
        if (nivel == 0) {
            s[nivel] = 0;
        } else {
            s[nivel] = s[nivel - 1] + 1;
        }
    } else {
        s[nivel]++;
    }    
}

// Verifica si merece la pena seguir explorando
bool criterio(int nivel, vector<int>& s, int m, int voa, vector<vector<int>>& B) {
    int parcial = valor(s, nivel + 1, B);
    int faltan = m - (nivel + 1);
    int estimado = parcial;
    for (int i = 0; i < faltan; ++i) {
        estimado += voa;  // Añadir el valor máximo posible para los pares faltantes
    }
    return estimado > voa;
}

// Verificar si la solucion es la definitiva
bool solucion(int nivel, int m) { 
    return nivel == m - 1;
}

// Comprobar si hay más hermanos
bool masHermanos(int nivel, vector<int>& s, int n, int m) {
    return s[nivel] < n - (m - 1 - nivel);
}

// Volver a una rama anterior
void retroceder(int& nivel, vector<int>& s) {
    s[nivel] = -1;
    nivel--;
}

void backtracking(int n, int m, vector<vector<int>>& B) {
    vector<int> s(m, -1);       // Solución parcial
    vector<int> soa(m, -1);     // Mejor solución encontrada
    int nivel = 0;              // Nivel actual
    int voa = voraz(n, B);      // Usamos voraz como cota inicial
    int bact = 0;
    while (nivel >= 0) {
        // Generar siguiente hermano
        generar(nivel, s);

        // Verificar si podemos continuar con la rama
        if (!masHermanos(nivel, s, n, m)) {
            retroceder(nivel, s);
            continue;
        }

        // Si completamos la solución
        if (solucion(nivel, m)) {
            bact = valor(s, m, B);
            if (bact > voa) {
                voa = bact;
                soa = s;
            }
        }
        // Verificar si merece la pena continuar con la rama
        if (criterio(nivel, s, m, voa, B)) {
            nivel++;    // Siguiente nivel
            s[nivel] = -1;
        } else {
            // Retroceder si no hay más hermanos por explorar
            while (nivel > 1 && !masHermanos(nivel, s, n, m)) {
                retroceder(nivel, s);
            }
            if (nivel == 0 && !masHermanos(nivel, s, n, m)) {
                nivel = -1;  // Terminar el backtracking
            }
        }
    }

    cout << voa << endl;
}

int main() {
    int T;
    cin >> T;

    for (int nCasos = 0; nCasos < T; nCasos++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> B(n, vector<int>(n));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                cin >> B[i][j];
            }
        }

        backtracking(n, m, B);
    }
    
    return 0;
}
