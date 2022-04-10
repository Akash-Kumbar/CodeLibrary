#include <bits/stdc++.h>

using namespace std;

/* function that returns number of paths
to move from start-cell at (1,1) to cell at(m,n) 
in a 2D grid */

int uniquePath(int m,int n)
{
    /* if there exists only 1 row or 1 column in the grid
    number of paths/ways to reach cell(m,n) is unique */
    if(m == 1 || n == 1)
    return 1;
    
    /* since, only downwards and rightwards movements are allowed 
    number of paths to reach cell at (m,n) is sum of number of paths
    to reach cell at (m-1,n) and cell at (m,n-1) */
    return uniquePath(m-1,n) + uniquePath(m,n-1);
}
/* main function to implement above function */
int main() 
{
    /* grid of 3 x 3 */
    int m = 3,n = 3;
    
    cout<<"Number of unique path for grid of "<<m<<" x "<<n<<" = "<<uniquePath(m,n);
    return 0;
}
