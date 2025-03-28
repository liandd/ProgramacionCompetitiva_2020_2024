#include<iostream>
#include<stack>
using namespace std;

class StackElement
{
public:
    int height;
	int start;

	StackElement(int h, int s) : height(h), start(s) {}
};


int main() {

    stack<StackElement*> s;

    int n;
    cin >> n;
    int height;
    s.push(new StackElement(0, 0));
    long long bestArea = 0;
    int bestStart = 0, bestEnd = 0;
    StackElement* e = NULL;
    for(int i=1; i<=n; i++) {
        cin >> height;
        e = NULL;
        while (!s.empty() && height < s.top()->height) {
            e = s.top();
            s.pop();
//System.out.println(" pop " + e->height + "," + e->start);
            long long area = e->height*(long long)(i-e->start);
            if (area > bestArea) {
                bestArea = area;
                bestStart = e->start;
                bestEnd = i;
            }
            else if (area == bestArea && e->start < bestStart) {
                bestStart = e->start;
                bestEnd = i;
            }
        }
        if (e == NULL)
            s.push(new StackElement(height, i));
        else
            s.push(new StackElement(height, e->start));
//System.out.println("push " + s.peek().height + "," + s.peek().start);
    }
    while (s.size() > 1) {
        e = s.top();
        s.pop();
        long long area = e->height*(long long)(n+1-e->start);
        if (area >= bestArea) {
            bestArea = area;
            bestStart = e->start;
            bestEnd = n+1;
        }
    }
    cout << bestStart << " " << (bestEnd-1) << " " << bestArea << endl;

}
