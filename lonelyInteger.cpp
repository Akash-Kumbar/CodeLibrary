#include<bits/stdc++.h>

using namespace std;

int lonelyInteger(int arr[], int size);

int main()
{
    int size, lone;
    cout << "Enter size of array : ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of array :\n";
    for(int i = 0 ; i < size ; i++)
    {
        cin >> arr[i];
    }
    lone = lonelyInteger(arr, size);
    cout << lone << "\n";
    return 0;
}

int lonelyInteger(int arr[], int size)
{
    int temp = arr[0];
    int count0 = 0, ret;

    if(temp == 0)
        count0++;
    for(int i = 1 ; i < size ; i++)
    {
        temp = temp ^ arr[i];
        if(arr[i] == 0)
            count0++;
    }
    if(temp == 0 && count0 == 1)
        ret = 0;
    else if(temp == 0 && count0 != 1)
        ret = -1;
    else
        ret = temp;
    return ret;
}