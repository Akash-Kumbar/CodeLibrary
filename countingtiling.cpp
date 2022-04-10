#include <bits/stdc++.h>

using namespace std;

int ways_tile_floor(int N, int M)
{
   int arr[N + 1];
   arr[0] = 0;
   for (int i = 1; i <= N; i++)
   {
      if (i > M)
      {
         arr[i] = arr[i − 1] + arr[i − M];
      }
      else if (i < M || i == 1)
      {
         arr[i] = 1;
      }
      else 
      {
         arr[i] = 2;
      }
   }
   return arr[N];
}
int main(){
   int n = 3, m = 2;
   cout<<"Count the number of ways to tile the floor of size n x m using 1 x m size tiles are: "<<ways_tile_floor(n, m);
   return 0;
}
