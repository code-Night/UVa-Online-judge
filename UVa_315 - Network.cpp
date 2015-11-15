#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>

#define UNVISITED -1

using namespace std;

vector < vector<int> > graph ;
int n;

vector <int> dfs_num ;
vector <int> dfs_min ;
vector <int> dfs_parent ;
vector <bool> isArtPoint ;
int root ;
int rootChildren = 0 ;
int counter = 0 ;

void articPoint (int u){
    dfs_num[u] = dfs_min[u] = counter++ ;
    for(int i=0 ; i<(int)graph[u].size() ; i++){
        int v = graph[u][i] ;
        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u ;
            if(u == root)
                rootChildren++ ;
            articPoint(v) ;
            if(dfs_min[v] >= dfs_num[u])
                isArtPoint[u]=true ;
            dfs_min[u] = min(dfs_min[u],dfs_min[v]);

        }else if(dfs_parent[u]!=v)
            dfs_min[u] = min(dfs_min[u],dfs_num[v]);
    }

}
void init_DFS(){
    dfs_num.clear();
    dfs_min.clear();
    isArtPoint.clear();
    dfs_parent.clear();
    dfs_num.resize(n+1);
    dfs_min.resize(n+1);
    dfs_parent.resize(n+1);
    isArtPoint.resize(n+1);
    fill(dfs_num.begin(),dfs_num.end(),UNVISITED);
    for(int i=1 ; i<=n ; i++){
        if(dfs_num[i] == UNVISITED){
            root = i ;
            rootChildren = 0 ;
            articPoint(i);
            isArtPoint[root] = rootChildren >=2 ;

        }
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    int nodes;
    scanf("%d\n",&nodes);
    while(nodes != 0){
        n = nodes ;
        graph.clear();
        graph.resize(n+1);
        string dum;
        getline(cin,dum);
        stringstream ss (dum);
        int x;
        ss >> x ;
        while(x != 0){
            int tmp;
            while(ss >> tmp){
                graph[x].push_back(tmp);
                graph[tmp].push_back(x);
            }
            getline(cin,dum);
            ss.str("");
            ss.clear();
            ss << dum ;
            ss >> x;
        }
        init_DFS();
        int ans = 0 ;
        for(int i=1 ; i<=n ; i++)
            if(isArtPoint[i])
                ans++;
        cout << ans << endl ;
        scanf("%d\n",&nodes);
    }
    return 0;
}
