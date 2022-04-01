#include<bits/stdc++.h>

using namespace std;

int main()
{
    int size = 6, i, j, prevHigh = 0, max = 0;
    int arr[size] = {5, 11, 3, 15, 30, 25};
    int LIS[size];
    for(i = 0 ; i < size ; i++)
        LIS[i] = 1;
    
    //outer loop i traverses from 1 to size
    //inner loop j traverses from 0 to size

    for(i = 1 ; i < size ; i++)
    {
        for(j = 0 ; j < size ; j++)
        {
            if(arr[i] > arr[j] && LIS[i] < LIS[j] + 1)
                LIS[i]++;
        }
    }

    cout << "Length of longest increasing subsequence is : " << *max_element(LIS, LIS + size) << "\n";

    return 0;
}