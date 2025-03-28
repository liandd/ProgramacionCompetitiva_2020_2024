#include <bits/stdc++.h>
using namespace std;
//codigo post prueba arbol segmentado
struct SegmentTree {
    vector<int> tree;
    int n;
    //crear arbol
    SegmentTree(int n) : n(n) {
        tree.resize(2 * n, 1); 
        build();
    }
	//construye
    void build() {
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
    //reservar y marcar 0 valor a habitacion reservada
    void reserveRoom(int pos) {
        pos += n;  //nodo a hoja
        tree[pos] = 0; // se reserva
        for (pos /= 2; pos > 0; pos /= 2) { //actualizar padres
            tree[pos] = tree[pos * 2] + tree[pos * 2 + 1]; 
        }
    }//mirar disponibles de l a r
    int query(int l, int r) {
        l += n;  
        r += n;
        int sum = 0;
        while (l <= r) {
            if (l % 2 == 1) sum += tree[l++]; 
            if (r % 2 == 0) sum += tree[r--]; 
            l /= 2;
            r /= 2;
        }
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    SegmentTree segmentTree(n);
    while (t--) {
        char morcilla;
        cin >> morcilla;
        if (morcilla == 'R') {
           int room;
            cin >> room;
            segmentTree.reserveRoom(room - 1);  //indice en 0
        } else if (morcilla == 'A') {
            int start, end;
            cin >> start >> end;
            cout << segmentTree.query(start - 1, end - 1) << "\n";
        }
    }

    return 0;
}


