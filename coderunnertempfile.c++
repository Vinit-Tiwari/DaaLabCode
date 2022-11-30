#include <iostream>
using namespace std;
static int m, n;
static int c = 0;
static int count = 0;
void nextValue(int k);
void GraphColoring(int k);
int g[10][10];
int x[10];
int main()
{
    int i, j;
    int temp;
    cout << "Enter the Number of Nodes :- ";
    cin >> n;
    cout << "Enter 1 for EDGE and Enter 0 for NOEDGE :-" << endl;
    for (i = 1; i <= n; i++)
    {
        x[i] = 0;
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                g[i][j] = 0;
            else
            {
                cout << i << " -> " << j << ":- ";
                cin >> temp;
                g[i][j] = g[j][i] = temp;
            }
        }
    }
    cout << endl
         << "Possible Solutionns are :- " << endl;
    for (m = 1; m <= n; m++)
    {
        if (c == 1)
        {
            break;
        }
        GraphColoring(1);
    }
    cout << endl
         << "The Chromatic Number is " << (m - 1) << endl;
    cout << "The Total Number of Solutions are " << count;
}
void GraphColoring(int k)
{
    int i;
    while (1)
    {
        nextValue(k);
        if (x[k] == 0)
        {
            return;
        }
        if (k == n)
        {
            c = 1;
            for (i = 1; i <= n; i++)
            {
                cout << x[i];
            }
            count++;
            cout << endl;
        }
        else
        {
            GraphColoring(k + 1);
        }
    }
}
void nextValue(int k)
{
    int j;
    while (1)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
        {
            return;
        }

        for (j = 1; j <= n; j++)
        {
            if (g[k][j] == 1 && x[k] == x[j])
                break;
        }
        if (j == (n + 1))
        {
            return;
        }
    }
}
