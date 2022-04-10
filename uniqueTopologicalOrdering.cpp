#include<iostream>
#include<vector>
#include<map>
using namespace std;

//adjacency list for representation of a graph
vector<int> arr[51];
int visited[51];
map<int,int> m;

//function for calculating indegree of node
void indegree(int n){
    for(int i=1;i<=n;++i){

        for(int child:arr[i]){
            m[child]++;
        }
    }
}

//function for checking topological order
int Unique_Topological(int n){

    //for checking possible node having in degree 0
    int counter=0,j=1000;
    for(int i=1;i<=n;++i){
        if(m[i]==0){
            j=i;
            counter++;
        }
    }
        if(counter>=2){
            //m[j]=-1;
            return 1;
        }
        if(j==1000){
            return 0;
        }
        else{
            m[j]=-1;
            for(int child:arr[j]){
                m[child]--;
            }
            return Unique_Topological(n);
        }

}
int main(){

    int n,m,x,y;

    /*n is number of vertex and m is number of edge
    x and y is representing path between x and y  */
    cout<<"Enter number of vertex and number of edge"<<endl;
    cin>>n>>m;
    while(m--){
        cout<<"enter vertex having edge in format u-->v"<<endl;
        cin>>x>>y;
        //this is for undirected graph

        arr[x].push_back(y);

    }

    indegree(n);
    if(Unique_Topological(n)==1){
        cout<<"Not Unique Topological order exist"<<endl;
    }
    else{
        cout<<"Unique Topological order exist"<<endl;
    }
    return 0;


}
