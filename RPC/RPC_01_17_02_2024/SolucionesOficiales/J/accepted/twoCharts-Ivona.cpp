#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000005
#define MAXL MAXN*10
#define MAXW 105

struct treenode {
    int id,numch;
    struct treenode* child[MAXW];
};

char c;
int N,depth;

char readnextchar() {
    char c;
    c = getc(stdin);
    while (c==' ') c = getc(stdin);
    if (c==EOF || c=='\n') return '\n';
    return c;
}

char readnextcharnum() {
    char c;
    c = getc(stdin);
    while (c<'0' || c>'9') c = getc(stdin);
    return c;
}

/*
// This is embarrassing, I could not get the compare function to work...
int cmpfnc(const void *a, const void *b) {
    const struct nodetree *aa, *bb;
    aa = (struct nodetree*)a;
    bb = (struct nodetree*)b;
    if (aa->id < bb->id) return -1;
    if (aa->id > bb->id) return 1;

    return 0;
}
*/


struct treenode* processTree(int dd) {
    struct treenode* root;
    int id,k;

    N++;

    root = (struct treenode*)malloc(sizeof(struct treenode));

    // read id
    id = 0;
    c = readnextcharnum();   
    while (c>='0' && c<='9') {
        id = id*10 + c-'0';
        c = readnextchar();   
    }
    // printf("id = %d\n",id);
    root->id = id;

    // process the children
    k = 0;
    while (c=='(') {
        // starting a new child
        // printf("starting child %d\n",k);
        root->child[k] = processTree(dd+1);
        c = readnextchar();
        k++;
        if (dd > depth) depth = dd;
    }

    root->numch = k;
    // qsort(root->child, k, sizeof(struct treenode*), cmpfnc);

    // sort children - in quadratic time... should not matter for <=10 children
    int i,j,max,maxj;
    struct treenode* tmp;

    for (i=0; i<k; i++) {
        // maxj = index with the largest id
        max = -1;
        for (j=i; j<k; j++) {
            if (max < root->child[j]->id) {
                max = root->child[j]->id;
                maxj = j;
            }
        }
        // swap i with maxj
        tmp = root->child[maxj];
        root->child[maxj] = root->child[i];
        root->child[i] = tmp;
    }

    /*
    printf("children of %d: (",root->id);
    for (i=0; i<k; i++) {
        printf("%d ",root->child[i]->id);
    }
    printf(")\n");
    */

    return root;
}

int equivalentTrees(struct treenode* r1, struct treenode* r2) {
    int i,j,min;
    struct treenode* tmp;

    if (r1->id != r2->id) return 0;
    if (r1->numch != r2->numch) return 0;

    for (i=0; i<r1->numch; i++) {
        if (!equivalentTrees(r1->child[i],r2->child[i])) return 0;
    }

    return 1;
}

int main() {
    int i;
    struct treenode* root[2];

    // to check the number of depts, and the depth
    N = 0;
    depth = 0;
    
    // read and process input, sorting subtrees by the subtree root ID
    for (i=0; i<2; i++) {
        //readTree(i);
        //printf("%s\n",t[i]);
        root[i] = processTree(0);
    }

    // printf("N=%d, depth=%d\n",N/2,depth);

    if (equivalentTrees(root[0],root[1])) {
        printf("Yes\n");
        return 0;
    }
	
    printf("No\n");
    return 0;
}
