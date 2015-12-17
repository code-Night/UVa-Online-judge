#include <iostream>
#include <vector>
#define oo 1<<30
using namespace std;



int dist[100] ;
int no_nodes,no_edges;

struct Edge {
	int from;
	int to;
	int weight;
};

vector <Edge> edges;

int bellman_ford(int s,int d){
	bool made = false ;
	fill(dist,dist+100,oo) ;
	dist[s] = 0 ;
	for(int i=0 ; i<no_nodes-1 ; i++){
		made = false ;
		for(int j=0 ; j< (int) edges.size() ; j++){
			Edge x = edges[j];
			if(dist[x.to] > dist[x.from] + x.weight){
				dist[x.to] = dist[x.from] + x.weight ;
				made = true ;
			}
			if(!made)
				break ;
		}
	}
	return dist[d] ;
}

int main() {

	int x ;cin >> x ;
	int tc = 0 ;
	while(tc < x){
        cin >> no_nodes >> no_edges ;
        for(int i=0 ; i<no_edges ; i++){
            int x,y,z ;
            cin >> x >> y >> z ;
            Edge e;
            e.from = x ;e.to = y;e.weight = z ;
            edges.push_back(e);
        }
        bellman_ford(1,no_nodes) ;
        bool ans = false ;
        for(int j=0 ; j< (int) edges.size() ; j++){
			Edge x = edges[j];
			if(dist[x.to] > dist[x.from] + x.weight){
				ans = true ;
				break ;
			}
		}
		if(ans)
            cout << "possible" << endl ;
        else
            cout << "not possible" << endl ;
	}
	return 0;
}
