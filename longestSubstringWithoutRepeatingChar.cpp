#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) 
{
        vector<int> mp(256,-1);
        int left =0;
        int right =0;                               
        int n=s.size();
        int len =0;
        while(right<n)
        {
            if(mp[s[right]] !=-1)
            {
                left=max(mp[s[right]]+1,left);  
            }
            mp[s[right]]=right;                    
            len=max(len,right-left+1);             
            right++;   
        }
        return len;
}
int main()
{
	string s;
	cout<<"Enter a string"<<endl;
	cin>>s;
	cout<<"Length of the longest substring Without repeating characters is : "<<lengthOfLongestSubstring(s);
}
