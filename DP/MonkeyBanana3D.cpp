//DeShaw Interview
/*There are three buildings in a row named A, B and C. Each building contains N floors. Each of the floors in each of the building contains a certain number of bananas.

A monkey can collect all the bananas at each floor as you make your way up from the ground floor to the Nth floor of a building. It can also jump from the ith floor of a building to the (i+1)th floor of its adjacent buildings. But it can only do so K times as you make your way up to the top.

Given are 3 arrays A[], B[] and C[] each of size N. The number of bananas at the ith floor of each building is indicated by the respective arr[i] ( A[i] for building A, B[i] for building B and C[i] for building C). The maximum number of jumps that can be made is given as K.

Find the maximum number of bananas that can be collected starting from the ground floor to the Nth floor with no more than K jumps.*/
#include <bits/stdc++.h>
using namespace std;
int dp[3][10][5];
void initDp()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 5; k++)
                dp[i][j][k] = -1;
}
int getBananas(int* a, int* b, int* c, int i, int n, int k, int on)
{
    // on variable indicates currently monkey is on which building 0->a, 1->b, 2->c
    if (i == n)
        return 0; // Base Case
    if (dp[on][i][k] != -1)
        return dp[on][i][k];
    int cur;
    switch (on) {
    case 0:
        cur = a[i];
        break;
    case 1:
        cur = b[i];
        break;
    case 2:
        cur = c[i];
        break;
    }
    if (k == 0) {
        return dp[on][i][k] = cur + getBananas(a, b, c, i + 1, n, k, on); // No jumps available. Hence, getBananas from current building only.
    }
    switch (on) { // Jumps available. getBananas from current or adjacent building maximum possible.
    case 0:
        return dp[on][i][k] = cur + max(getBananas(a, b, c, i + 1, n, k - 1, 1), getBananas(a, b, c, i + 1, n, k, 0));
    case 1:
        return dp[on][i][k] = cur + max(getBananas(a, b, c, i + 1, n, k - 1, 0), max(getBananas(a, b, c, i + 1, n, k, 1), getBananas(a, b, c, i + 1, n, k - 1, 2)));
    case 2:
        return dp[on][i][k] = cur + max(getBananas(a, b, c, i + 1, n, k - 1, 1), getBananas(a, b, c, i + 1, n, k, 2));
    }
}
 
int main()
{
    // your code goes here
    int n = 5, k = 2;
    int a[n] = { 4, 5, 1, 2, 10 };
    int b[n] = { 9, 7, 3, 20, 16 };
    int c[n] = { 6, 12, 13, 9, 8 };
    initDp();
    cout << max(getBananas(a, b, c, 0, n, k, 0), max(getBananas(a, b, c, 0, n, k, 1), getBananas(a, b, c, 0, n, k, 2)));
    return 0;
}
