// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string x = "AGCCCTAAGGGCTACCTAGCTT";
//     string y = "GACAGCCTACAAGCGTTAGCTTG";
//     cout<<"\nGiven Strings are : "<<endl;
//     cout<<"1. "<<x<<endl;
//     cout<<"2. "<<y<<endl;
//     cout<<endl;
//     int m = x.size();
//     int n = y.size();
//     int dp[m + 1][n + 1];
//     for (int i=0; i<=m; i++)
//     {
//         for (int j=0; j<=n; j++)
//         {
//             if (i==0 || j==0){
//                 dp[i][j] = 0;
//             }
//             else if (x[i-1] == y[j-1]){
//                 dp[i][j] = dp[i-1][j-1] + 1;
//             }
//             else{
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//     }
//     int index = dp[m][n];
//     string similar;
//     for (int i = 0; i<index; i++)
//     {
//         similar += " ";
//     }
//     int i=m, j=n;
//     while (i>0 && j>0)
//     {
//         if (x[i-1] == y[j-1])
//         {
//             similar[index-1] = x[i-1];
//             i--;
//             j--;
//             index--;
//         }
//         else if (dp[i-1][j] > dp[i][j-1])
//             i--;
//         else
//             j--;
//     }
//     cout << "The longest common sequence is of length " << dp[m][n] << "\n\n";
//     cout << "The Common sequence is " << similar << "\n\n";
// }

#include <iostream>
#include<stack>
using namespace std;
int main(){
    cou
}