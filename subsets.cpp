#include<bits/stdc++.h>

using namespace std;

void PrintAll(vector<int> subset, int size);
void GenAllsubs(int arr[], int N, int i, vector<int> &subset, int size);

int main()
{
    int arr[] = {1, 2, 3, 4};
    int N = sizeof(arr)/sizeof(arr[0]);
    vector<int> subset;
    GenAllsubs(arr, N, 0, subset, 0);

    return 0;
}

void PrintAll(vector<int> subset, int size)
{
    int i;
    cout << "[";
    for(i = 0 ; i < size ; i++)
    {
        cout << subset[i] << " " ;
    }
    cout << "]\n";
}

void GenAllsubs(int arr[], int N, int i, vector<int> &subset, int size)
{
    if(i == N)
    {
        PrintAll(subset, size);
        return;
    }

    else
    {
        GenAllsubs(arr, N, i+1, subset, size++);
        subset.push_back(arr[i]);
        GenAllsubs(arr, N, i+1, subset, size++);
        subset.pop_back();
        //GenAllsubs(arr, N, i, subset, size++);
    }
}