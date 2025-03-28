#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    vector<int> tree; // Vector para almacenar el árbol
    int n; // Número de elementos en el arreglo original

    // Constructor: inicializa el árbol de segmentos con un vector de datos
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(2 * n); // Resize para almacenar el árbol
        // Inicializar el árbol con los datos
        for (int i = 0; i < n; ++i) {
            tree[n + i] = data[i]; // Asignar valores a las hojas
        }
        build(); // Construir el árbol
    }

    // Función para construir el árbol de segmentos
    void build() {
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1]; // Suma de los hijos
        }
    }

    // Actualiza un valor en la posición pos
    void update(int pos, int value) {
        pos += n; // Mover al nodo hoja
        tree[pos] = value; // Actualiza el valor
        // Actualiza los nodos padres
        for (pos /= 2; pos > 0; pos /= 2) {
            tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
        }
    }

    // Consulta la suma en el rango [l, r]
    int query(int l, int r) {
        l += n; // Convertir a indexación de árbol
        r += n;
        int sum = 0;
        while (l <= r) {
            if (l % 2 == 1) sum += tree[l++]; // Si l es un hijo derecho, agregar y mover a la siguiente
            if (r % 2 == 0) sum += tree[r--]; // Si r es un hijo izquierdo, agregar y mover al anterior
            l /= 2; // Mover hacia arriba en el árbol
            r /= 2; // Mover hacia arriba en el árbol

        }
        return sum; // Retorna la suma total
    }
};

int main() {


    // Ejemplo de uso
    int n; // Número de elementos
    cout << "Ingrese el numero de elementos: ";
    cin >> n;
    vector<int> data(n);
    cout << "Ingrese los elementos:\n";
    for (int i = 0; i < n; ++i) {
        cin >> data[i]; // Leer los elementos
    }

    // Crear un árbol de segmentos
    SegmentTree segmentTree(data);

    // Ejemplo de consultas y actualizaciones
    int queryType;
    while (true) {
        cout << "Seleccione opcion:\n1. Consultar suma en rango\n2. Actualizar valor\n3. Salir\n";
        cin >> queryType;

        if (queryType == 1) {
            int l, r;
            cout << "Ingrese el rango [l, r]: ";
            cin >> l >> r;
            cout << "La suma en el rango [" << l << ", " << r << "] es: " << segmentTree.query(l, r) << "\n";
        } else if (queryType == 2) {
            int pos, value;
            cout << "Ingrese la posicion y el nuevo valor: ";
            cin >> pos >> value;
            segmentTree.update(pos, value);
            cout << "Valor actualizado.\n";
        } else {
            break; // Salir del bucle
        }
    }

    return 0;
}

