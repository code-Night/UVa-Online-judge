#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;
bool visited[10010] ;
//bool graph[10010][10010] ;
vector < vector<int> >graph ;
vector <int> pushed ;
int m,n,l;
int DFS(int source){
    int res = 0 ;
    stack<int>dfs_stack;
    dfs_stack.push(source);
    while(!dfs_stack.empty()){

        int curr = dfs_stack.top();dfs_stack.pop() ;
        if(!visited[curr])
            res++;
        visited[curr] = true ;
        for(int i=0 ; i < (int)graph[curr].size() ; i++){
            int nxt = graph[curr][i];
            if(!visited[nxt]){
                dfs_stack.push(nxt);
            }
        }
    }
    return res ;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tc;cin >> tc ;
    while(tc--){
        int result = 0 ;
        cin >> n >> m >> l ;
        //memset(graph,false,sizeof(graph));
        memset(visited,false,sizeof(visited));
        graph.resize(n+1);
        for(int i=0 ; i<m ; i++){
            int x,y;
            cin >> x >> y ;
            graph[x].push_back(y);
        }
        pushed.resize(n);
        for(int i=0 ; i<l ; i++){
            int x;cin >> x;
            result += DFS(x) ;
        }
        cout << result << endl;
        graph.clear() ;
    }
    return 0;
}
