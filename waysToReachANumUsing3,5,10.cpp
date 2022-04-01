#include<bits/stdc++.h>

using namespace std;

int main()
{
    int num, i;
    int ways[] = {3, 5, 10};
    int lenWays = sizeof(ways)/sizeof(ways[0]);
    sort(ways, ways+lenWays);

    cin >> num;
    int DP[num+1];
    DP[0] = 1;
    for(i = 1 ; i <= num ; i++)
        DP[i] = 0;

    for(auto x : ways)
    {
        for(i = x ; i <= num ; i++)
        {
            DP[i] = DP[i] + DP[i - x];
        }
    }
    for(auto x : DP)
    {
        cout << x << " ";
    }
    cout << "\n";

    cout << "number of ways to reach " << num << " is " << DP[num] << "\n";
    return 0;
}