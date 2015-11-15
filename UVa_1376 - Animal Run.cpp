#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include <queue>
using namespace std;

int n,m ;
vector < vector< pair<int,int> > > graph ;
vector <int> dist ;
vector <bool> visited ;

int djkstra_UQ(int s, int d) {
	fill(visited.begin(),visited.end(),false);
	fill(dist.begin(),dist.end(),INT_MAX) ;
	dist[s] = 0;
	priority_queue< pair<int, int> > path;
	path.push(make_pair(0, s));
	while (!path.empty()) {
		int selected = path.top().second;
		path.pop();
		if (!visited[selected]) {
			visited[selected] = true;
			//relax with the cloesest
			for (int i = 0; i < (int) graph[selected].size(); i++) {
				int neighbor = graph[selected][i].second;
				if (dist[neighbor] > dist[selected] + graph[selected][i].first) {
					dist[neighbor] = dist[selected] + graph[selected][i].first ;
					path.push(make_pair(-1 * dist[neighbor], neighbor));
				}
			}
		}
	}
	return dist[d];
}

void build_rows(int s,int d,int w,bool undirected){
    graph[s].push_back(make_pair(w,d)) ;  //weight - to
    if(undirected)
        graph[d].push_back(make_pair(w,s)) ;
}

int main()
{

    freopen("input.txt","r",stdin);
    int tc = 0;
    int n,m ; cin >> n >> m ;
    while(n!=0 && m!=0){

    graph.resize(2*(n-1)*(m-1)+2) ;
    dist.resize(2*(m-1)*(n-1)+2);
    visited.resize(2*(m-1)*(n-1)+2);
    for(int i=0 ; i<n ; i++){
        int pivot = 2*(m-1) ;
        for(int j=0 ; j<(m-1) ; j++){
            int f = pivot*i + j*2 ;
            int d = f+1 ;
            int x;cin >> x;
            if(i == 0)
                build_rows(2*(n-1)*(m-1),d,x,false);
            else if(i==n-1)
                build_rows(f-pivot,2*(n-1)*(m-1)+1,x,false);
            else
                build_rows(f-pivot,d,x,true );

        }
    }
    for(int i=0 ; i<n-1 ; i++){
        int pivot = 2*(m-1) ;
        for(int j=0 ; j<m*2 ; j+=2){
            int x;cin >> x;
            int f = (pivot*i+j) ;
            int d = f-1 ;
            if(j == 0) //fe awel el raw
                build_rows(f,2*(n-1)*(m-1)+1,x,false);
            else if(j == 2*(m-1)) // fe a5er el raw
                build_rows(2*(n-1)*(m-1),d,x,false);
            else{
                build_rows(f,d,x,true) ;
            }
        }
    }
    for(int i=0 ; i<(n-1) ; i++){
        int pivot = 2*(m-1) ;
        for(int j=0 ; j<2*(m-1) ; j+=2){
            int x;cin >> x;
            int f=i*pivot+j , d=i*pivot+j+1 ;
            build_rows(f,d,x,true);
        }
    }
//    for(int i=0 ; i<graph.size() ; i++){
//        for(int j=0 ; j<graph[i].size() ; j++){
//            cout << i << " " << graph[i][j].second << " " << graph[i][j].first << endl;
//        }
//    }
    cout << "Case " << ++tc << ": Minimum = " << djkstra_UQ(2*(m-1)*(n-1),2*(m-1)*(n-1)+1) << endl;
    graph.clear() ;
    cin >> n >> m ;
    }
    return 0;
}
