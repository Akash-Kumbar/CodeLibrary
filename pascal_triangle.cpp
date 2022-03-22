#include<bits/stdc++.h>

using namespace std;

class Solution 
{
    public:
        vector<vector<int>> generate(int numRows)
        {
            vector<vector<int>> out;
            vector<int> temp;
            for(int i = 0 ; i < numRows ; i++)
            {
                if(out.size() == 0)
                {
                    temp.push_back(1);
                    out.push_back(temp);
                    temp.clear();
                }
                else if(out.size() == 1)
                {
                    temp.push_back(1);
                    temp.push_back(1);
                    out.push_back(temp);
                    temp.clear();
                }
                else
                {
                    temp.push_back(1);
                    for(int j = 0 ; j < out[i-1].size() - 1 ; j++)
                    {
                        temp.push_back(out[i-1][j] + out[i-1][j+1]);
                    }
                    temp.push_back(1);
                    out.push_back(temp);
                    temp.clear();
                }
            }
            return out;
        }
};

int main()
{
    Solution sol;
    vector<vector<int>> out = sol.generate(25); //Number of rows to be printed is entered in the generate function
    for(auto vec : out)
    {
        for(auto x : vec)
        {
            cout << x << " ";
        }
        cout << "\n";
    } 
    return 0;
}
