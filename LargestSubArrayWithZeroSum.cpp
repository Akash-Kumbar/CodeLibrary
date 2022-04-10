#include <bits/stdc++.h>
using namespace std;
int maxLength(int arr[], int n)
{
    map<int, int> mp;
    int sum = 0; // Initialize the sum of elements
    int maxi = 0; // Initialize result
    for (int i = 0; i < n; i++) 
    {
        sum += arr[i]; // Add current element to sum
        if (sum == 0)
    	{
            maxi = i + 1;
    	}
        else
        {
        	if (mp.find(sum) != mp.end())
        	{
            	    maxi = max(maxi, i - mp[sum]);
        	}
        	else 
        	{
            	    mp[sum] = i;
        	}
    	}
    }
 
    return maxi;
}
 
// Driver Code
int main()
{
	int n;
	cout<<"Enter size of  an array"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter array Elememts\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
    int p = sizeof(a) / sizeof(a[0]);
    cout << "Length of the longest 0 sum subarray is "
         << maxLength(a, p);
 
    return 0;
}
