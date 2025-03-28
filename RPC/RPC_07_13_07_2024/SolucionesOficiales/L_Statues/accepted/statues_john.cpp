#include<iostream>
using namespace std;

const int MAXD = 50;

int grid[MAXD][MAXD];
int grid2[MAXD][MAXD];
int sizes[MAXD*MAXD];
int numSizes = 0;

void sort(int a[], int n)
{
    for(int i=1; i < n; i++) {
        int tmp = a[i];
        int j=i;
        while (j > 0 && a[j-1] > tmp) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = tmp;
    }
}

int place(int grid[][MAXD], int rows, int cols)
{
    int numDiags = rows+cols-1;
    int index = 0;								// index into sorted array
    int count = 0;
    for(int i=0; i<numDiags; i++) {
        int startRow = i < cols ? 0 : i-cols+1;
        int endRow = i < rows ? i : rows-1;
        int startCol = i < cols ? i : cols-1;
        int numVals = endRow-startRow+1;		// determine # of values in diagonal
        int c = startCol;
        for(int r = startRow; r <=  endRow; r++, c--) {
            if (grid[r][c] == -1)
                numVals--;
        }
        if (numVals == 0)
            continue;
        int low = sizes[index];					// range of values in this diagonal
        int high = sizes[index+numVals-1];
        c = startCol;
        for(int r = startRow; r <=  endRow; r++, c--) {
            int val = grid[r][c];
            if (val >= low && val <= high)
                count++;
        }
        index += numVals;

    }
    return count;
}

void rotate(int a[][MAXD], int b[][MAXD], int rows, int cols)
{
    for(int r=0; r<rows; r++)
        for(int c=0; c<cols; c++)
            b[c][rows-r-1] = a[r][c];
}


int main() {

    int rows, cols;
    cin >> rows >> cols;
    for(int i=0; i<rows; i++) {
        for(int j=0; j <cols; j++) {
            int val;
            cin >> val;
            grid[i][j] = val;
            if (val != -1)
                sizes[numSizes++] = val;
        }
    }
    sort(sizes, numSizes);
    int count = place(grid, rows, cols);
    int type = 0;								// used when generating test data
    rotate(grid, grid2, rows, cols);
    int val = place(grid2, cols, rows);
    if (val > count) {
        count = val;
        type = 1;
    }
    rotate(grid2, grid, cols, rows);
    val = place(grid, rows, cols);
    if (val > count) {
        count = val;
        type = 2;
    }
    rotate(grid, grid2, rows, cols);
    val = place(grid2, cols, rows);
    if (val > count) {
        count = val;
        type = 3;
    }
    cout << numSizes-count << endl;
//		System.out.println(type);
}
