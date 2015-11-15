#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdio>

using namespace std;

vector < vector<int> > graph ;
bool visited[300];
int color[300];
int n=-1;

bool is_bipartite(int src){
    stack<int> srch ;
    srch.push(src);
    color[src]=1 ;
    while(!srch.empty()){
        int curr = srch.top(); srch.pop() ;
        int nxtColor = 3 - color[curr];
        visited[curr] = true ;
        for(int i=0 ; i<(int)graph[curr].size() ; i++){
            int nxt = graph[curr][i] ;
            if(!visited[nxt]){
                color[nxt] = nxtColor ;
                srch.push(nxt);
            }else if(color[curr] == color[nxt])
                return false ;
        }
    }
    return true ;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    cin >> n ;
    while(n != 0){
        graph.resize(n+1);
        int x=-1,y=-1 ;
        cin >> x >> y ;
        while(x!=0 && y!=0){
            graph[x].push_back(y) ;
            graph[y].push_back(x) ;
            cin >> x >> y ;
        }
        if(is_bipartite(1))
            cout << "YES" << endl ;
        else
            cout << "NO" << endl ;
        cin >> n ;
        graph.clear();
        memset(color,0,sizeof(color));
        memset(visited,false,sizeof(visited));
    }
    return 0;
}
