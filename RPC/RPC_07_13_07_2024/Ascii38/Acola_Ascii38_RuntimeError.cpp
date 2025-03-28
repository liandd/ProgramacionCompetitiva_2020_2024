#include <bits/stdc++.h>
using namespace std;
#define TRUE 1
#define FALSE 0
struct node {
    int key;
    struct node* sig;
};
struct node* enqueue(struct node* tail, int element) {
    struct node* newNode;
    newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = element;
    if (tail == NULL) {
        newNode->sig = newNode;
        tail = newNode;
    } else {
        newNode->sig = tail->sig;
        tail->sig = newNode;
        tail = newNode;
    }
    return tail;
}
int dequeue(struct node** tail) {
    struct node* firstNode;
    int element;
    if (*tail == (*tail)->sig) {
        element = (*tail)->key;
        free(*tail);
        *tail = NULL;
    } else {
        firstNode = (*tail)->sig;
        element = firstNode->key;
        (*tail)->sig = firstNode->sig;
        free(firstNode);
    }
    return element;
}
int queueEmpty(struct node* tail) {
    if (tail == NULL)
        return TRUE;
    else
        return FALSE;
}
int calcular(int n) {
    if (n == 1) return 1;//salir
    unordered_map<int, int> comp;//guardar complejidades
    struct node* cola = NULL;//puntero a cola
    cola = enqueue(cola, 1);
    comp[1] = 1;//la de 1 es 1
    while (!queueEmpty(cola)) {
        int num_actual = dequeue(&cola);
        int actual_comp = comp[num_actual];
        int sig = num_actual + 1;//sumas
        if (sig <= n && (comp.find(sig) == comp.end() || comp[sig] > actual_comp + 1)) {
            comp[sig] = actual_comp + 1;
            cola = enqueue(cola, sig);
        }
        sig = num_actual * 2;//multiplcaciones
        if (sig <= n && (comp.find(sig) == comp.end() || comp[sig] > actual_comp + 1)) {
            comp[sig] = actual_comp + 1;
            cola = enqueue(cola, sig);
        }
        string actual = to_string(num_actual);//concatenar
        for (int i = 1; i <= num_actual; ++i) {
            string i_str = to_string(i);
            sig = stoi(actual + i_str);
            if (sig <= n && (comp.find(sig) == comp.end() || comp[sig] > actual_comp + 1)) {
                comp[sig] = actual_comp + 1;
                cola = enqueue(cola, sig);
            }
        }
    }
    return comp[n];
}
int main() {
    int n;
    cin>>n;
    cout<<calcular(n)<<"\n";
    return 0;
}
