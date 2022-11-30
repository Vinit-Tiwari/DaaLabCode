#include<bits/stdc++.h> 
using namespace std;
#define MAX 9999999
#define N 6
int main()
{
    int g[N][N] = {{0, 4, 0, 0, 0, 2},
                   {4, 0, 6, 0, 0, 3},
                   {0, 6, 0, 3, 0, 1},
                   {0, 0, 3, 0, 2, 0},
                   {0, 0, 0, 2, 0, 4},
                   {2, 3, 1, 0, 4, 0}};

    int Node_Selected[N] = {0, 0, 0, 0, 0, 0};
    int num_edge = 0;
    Node_Selected[0] = 1;
    int min_cost = 0;
    cout<<"-----------------"<<endl;
    cout << "Edge : Weight\n";
    while (num_edge < N - 1)
    {
        int min = MAX;
        int a = 0;
        int b = 0;
        for (int m = 0; m < N; ++m){
            if (Node_Selected[m]){
                for (int n = 0; n < N; n++){
                    if ((!Node_Selected[n]) && g[m][n]){
                        if (min > g[m][n]){
                            min = g[m][n];
                            a = m;
                            b = n;
                        }
                    }
                }
            }
        }
        cout << a << "-" << b << "  : " << g[a][b] << endl;
        min_cost += g[a][b];
        Node_Selected[b] = 1;
        num_edge += 1;
    }
    cout<<"-----------------"<<endl;
    return 0;
}
