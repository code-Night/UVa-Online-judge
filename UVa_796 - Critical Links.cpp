#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>

#define UNVISITED -1

using namespace std;

vector < vector<int> > graph ;
int n=-1;

vector<int> dfs_num ;
vector<int> dfs_min ;
vector<int> dfs_parent ;
vector<bool> isArtPoint ;
vector< pair<int,int> > bridges ;
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
            if(dfs_min[v] > dfs_num[u])
                bridges.push_back(make_pair(min(u,v),max(u,v)));
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
    dfs_num.resize(n);
    dfs_min.resize(n);
    dfs_parent.resize(n);
    isArtPoint.resize(n);
    fill(dfs_num.begin(),dfs_num.end(),UNVISITED);
    for(int i=0 ; i< n ; i++){
        if(dfs_num[i] == UNVISITED){
            root = i ;
            rootChildren = 0 ;
            articPoint(i);
            isArtPoint[root] = rootChildren >=2 ;

        }
    }
}

int main(){
    freopen("input.txt","r",stdin);

    while(scanf("%d\n",&n) != EOF){
        ;
        bridges.clear();
        graph.clear();
        graph.resize(n) ;
        int u,num ;
        for(int i=0 ; i<n ; i++){
            scanf("%d (%d) ",&u,&num);
            for(int j=0 ; j<num ;j++){
                int v;cin >> v ;
                graph[u].push_back(v);
               // graph[v].push_back(u);
            }
        }
        init_DFS();
        sort(bridges.begin(),bridges.end());
        cout <<(int) bridges.size() <<" critical links" << endl ;
        for(int i=0 ; i<(int)bridges.size() ; i++){
            cout << bridges[i].first << " - " << bridges[i].second << endl ;
        }
        cout << endl ;
    }

    return 0;
}
