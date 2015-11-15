#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <stack>
#include <cstdio>

#define UNVISITED -1

using namespace std;

int ID = 0 ;
int P,T ;
int counter = 0 ;

map <string,int> dict ;
vector < vector<int> > graph ;
vector < vector<int> > graphT ;
vector <int> dfs_num ;
stack <int> order ;

void DFS1(int u){
    dfs_num[u] = 1 ;
    for(int i=0 ; i<(int)graphT[u].size() ; i++){
        int v = graphT[u][i];
        if(dfs_num[v] == UNVISITED)
            DFS1(v);
    }
    order.push(u);
}
void TLS(){
    fill(dfs_num.begin(),dfs_num.end(),UNVISITED);
    for(int i=0 ; i<P ; i++){
        if(dfs_num[i] == UNVISITED)
            DFS1(i);
    }
}
void DFS2(int u){
    dfs_num[u] = counter ;
    for(int i=0 ; i<(int)graph[u].size() ; i++){
        int v = graph[u][i] ;
        if(dfs_num[v] == UNVISITED)
            DFS2(v);
    }
}
void SCC(){
    counter = 0 ;
    fill(dfs_num.begin(),dfs_num.end(),UNVISITED);
    while(!order.empty()){
        int u = order.top() ; order.pop();
        if(dfs_num[u] == UNVISITED){
            DFS2(u);
            counter++;
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    scanf ("%d %d\n",&P,&T);
    while(P+T!= 0){
        bool adjMat [P][P] ;
        memset(adjMat,false,sizeof(adjMat));
        graph.clear() ;
        graphT.clear() ;
        dfs_num.clear() ;
        dict.clear() ;
        counter = 0 ;
        ID = 0 ;
        for(int i=0 ; i<P ; i++){
            string tmp ;
            getline(cin,tmp);
            dict[tmp]=ID++ ;
        }
        graph.resize(P);
        graphT.resize(P);
        for(int i=0 ; i<T ; i++){
            string u; getline(cin,u);
            string v; getline(cin,v);
            if(!adjMat[dict[u]][dict[v]]){
                graph[dict[u]].push_back(dict[v]);
                graphT[dict[v]].push_back(dict[u]);
                adjMat[dict[u]][dict[v]] = true ;
            }
        }
        dfs_num.resize(P);
        TLS();
        SCC();

        printf("%d\n",counter);

        scanf ("%d %d\n",&P,&T);
    }
    return 0;
}
