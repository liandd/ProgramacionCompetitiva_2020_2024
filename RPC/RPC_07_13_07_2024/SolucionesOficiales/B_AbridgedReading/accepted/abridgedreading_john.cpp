#include<iostream>
#include<vector>
using namespace std;

class Tuple {
public:
  	int min1, min2;

	Tuple(int a, int b) : min1(a), min2(b) {}
};

class Node
{
public:
	vector<Node*> children;
	int value;
	bool hasParent = false;
};

int maxval  = 0;
const int MAXN = 1000;

Node* nodes[MAXN+1];

Tuple* process(Node* n)
{
    if (n->children.size() == 0) {
        return new Tuple(n->value, maxval);
    }
    else {
        Tuple* tmp = process(n->children[0]);
        int min1a = tmp->min1;
        int min1b = maxval;
        int min2 = tmp->min2;
        for(int i=1; i<n->children.size(); i++) {
            tmp = process(n->children[i]);
            if (tmp->min1 <= min1a) {
                min1b = min1a;
                min1a = tmp->min1;
            }
            else if (tmp->min1 < min1b)
                min1b = tmp->min1;
            if (tmp->min2 < min2)
                min2 = tmp->min2;
        }
        if (min1b != maxval && min1a + min1b < min2)
            min2 = min1a + min1b;
        return new Tuple(min1a+n->value, min2+n->value);
    }
}

int main() {

    int n, m;

    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        nodes[i] = new Node();
        cin >> nodes[i]->value;
        maxval += nodes[i]->value;
    }
    for(int i=0; i<m; i++) {
        int p, c;
        cin >> p >> c;
        nodes[p]->children.push_back(nodes[c]);
        nodes[c]->hasParent = true;
    }
    nodes[0] = new Node();
    for(int i=1; i<=n; i++) {
        if (!nodes[i]->hasParent)
            nodes[0]->children.push_back(nodes[i]);
    }
    Tuple* ans = process(nodes[0]);
    cout << ans->min2 << endl;
}
