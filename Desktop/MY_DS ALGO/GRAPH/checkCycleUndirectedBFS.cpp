#include<bits/stdc++.h>
using namespace std;
bool checkforCycle(int s, int v, vector<int>adj[], vector<int>&visisted){
    queue<pair<int,int>>q;
    visisted[s]=true;
    q.push({s,-1});

    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
       
       for(auto it:adj[node]){
           if(!visisted[it]){
               visisted[it]=true;
               q.push({it,node});
           }
           else if(parent!=it)
           {
               return true;
           }
       }

    }

    return false;

}

bool isCycle(int v,vector<int>adj[]){
    vector<int>vis(v+1,0);
    for(int i=1;i<=v;i++){
        if(!vis[i]){
            if(checkforCycle(i,v,adj,vis))
            return true;
        }
    }
    return false;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int v,e;
        cin>>v>>e;
        vector<int>adj[v];
        for(int i=0;i<e;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        bool ans=isCycle(v,adj);

        if(ans){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    
}