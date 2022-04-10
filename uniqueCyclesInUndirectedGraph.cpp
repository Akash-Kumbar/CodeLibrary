#include<bits/stdc++.h>

using namespace std;

//adjacency list for representation of a graph
vector<int> arr[51];
int visited[51];
int DiscoveryTime[51];
int timer=1,k=0;
//function  for cycle detection
void Cycle_Detecter(int node,int par){

    DiscoveryTime[node]=timer;
    timer++;

    visited[node]=1;

    for(int child:arr[node]){
        if(child==par){
            continue;
        }
        if(visited[child]==1 && DiscoveryTime[child]<DiscoveryTime[node]){
            k++;
        }
        if(visited[child]!=1)
           Cycle_Detecter(child,node);

    }


}
int main(){

    int n,m,x,y;

    /*n is number of vertex and m is number of edge
    x and y is representing path between x and y  */
    cout<<"Enter number of vertex and number of edge"<<endl;
    cin>>n>>m;
    while(m--){
        cout<<"enter vertex having edge"<<endl;
        cin>>x>>y;
        //this is for undirected graph

        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    Cycle_Detecter(1,-1);
    cout<<"Total Number of unique cycle is = "<<k<<endl;
    return 0;

}
