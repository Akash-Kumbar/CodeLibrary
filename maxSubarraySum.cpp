#include<bits/stdc++.h>

using namespace std;

int maxSubArraySum(int [], int);
int maxOf2(int, int);

int main()
{
    int size, max;
    cin >> size;
    int arr[size];
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i];
    
    max = maxSubArraySum(arr, size);

    cout << max << "\n";

    return 0;
}

int maxSubArraySum(int arr[], int size)
{
    int best = INT16_MIN, sum = 0;
    for(int i = 0 ; i < size ; i++)
    {
        sum = max(arr[i], sum + arr[i]);
        best = max(best, sum);
    }

    return best;
}

int maxOf2(int x , int y)
{
    int max;
    if(x > y)
        max = x;
    else
        max = y;

    return max;
}