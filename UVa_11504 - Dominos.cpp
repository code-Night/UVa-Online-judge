#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <cstdio>
#define  UNVISITED -1



using namespace std;
typedef vector<int> vi ;
typedef stack<int> si ;

set < pair<int,int> > compressedG ;
vector <vi> graph ;
vector <vi> graphT ;

vi componentNum;
vi inDegree ;
int counter = 0 ;
vector <bool> visited;
si TLS ;
int n,m ;

void DFS1(int u){
    visited[u]=true;
    for(int i=0 ; i<(int)graphT[u].size() ; i++){
        int v = graphT[u][i];
        if(!visited[v])
            DFS1(v);
    }
    TLS.push(u);
}
void toplocialSort(){
    visited.resize(n);
    fill(visited.begin(),visited.end(),false);
    for(int i=0 ; i<n ; i++){
        if(!visited[i])
            DFS1(i);
    }
}
void DFS2(int u){
    componentNum[u]=counter ;
    for(int i=0 ; i<(int)graph[u].size() ; i++){
        int v = graph[u][i];
        if(componentNum[v] == UNVISITED){
            DFS2(v);
        }else if(componentNum[v] != counter){
            compressedG.insert(make_pair(counter,componentNum[v]));
        }
    }
}
void SCC(){
    componentNum.resize(n);
    fill(componentNum.begin(),componentNum.end(),UNVISITED);
    for(int i=0 ; i<n ; i++){
        int u = TLS.top() ;//cout << u ;
        TLS.pop();
        if(componentNum[u] == UNVISITED){
            DFS2(u);
            counter++;
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int tc;cin >> tc;
    while(tc--){
        graph.clear();
        graphT.clear();
        compressedG.clear();

        visited.clear();
        inDegree.clear();
        counter = 0 ;
        cin >> n >> m ;
        graph.resize(n);
        graphT.resize(n);
        for(int i=0 ; i<m ; i++){
            int x,y; cin >> x >> y ;--x,--y;
            graph[x].push_back(y);
            graphT[y].push_back(x);
        }

        toplocialSort();
        SCC();
        cout << counter << endl ;
    }

    return 0;
}
