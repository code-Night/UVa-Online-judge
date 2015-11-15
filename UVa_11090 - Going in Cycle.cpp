#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

int oo = 10000010 ;

int no_nodes,no_edges;

struct Edge {
	int from;
	int to;
	double weight;
};

vector <Edge> edges;

bool is_negative_cycle(){
	bool made = false ;
	vector <long double> dist(no_nodes+1);
	fill(dist.begin(),dist.end(),oo) ;
	for(int i=0 ; i<no_nodes-1 ; i++){
		made = false ;
		for(int j=0 ; j< (int) edges.size() ; j++){
			Edge x = edges[j];
			if(dist[x.to] > dist[x.from] + x.weight){
				dist[x.to] = dist[x.from] + x.weight ;
				made = true ;
			}
		}
		if(!made) break;
	}
    for(int j=0 ; j< (int) edges.size() ; j++){
			Edge x = edges[j];
			if(dist[x.to] > dist[x.from] + x.weight){
				return true ;
			}
		}
		return false ;
}

bool tst(double x){
    for(int i=0 ; i<(int)edges.size() ; i++){
        edges[i].weight -= x ;
    }
    bool ans = is_negative_cycle();
     for(int i=0 ; i<(int)edges.size() ; i++){
        edges[i].weight += x ;
    }
    return ans ;
}

int main() {

    freopen("input.txt","r",stdin);
	int x ;cin >> x ;
	int tc = 0 ;
	double max_edge=0;
	bool newLine = false ;
	while(tc < x){
        cin >> no_nodes >> no_edges ;
        for(int i=0 ; i<no_edges ; i++){
            int x,y ;
            double z;
            cin >> x >> y >> z ;
            Edge e;
            e.from=x;
            e.to=y;
            e.weight=z;
            max_edge = max(max_edge,z);
            edges.push_back(e);
        }

        cout<< "Case #" << ++tc << ": " ;

        bool have_answer = tst(max_edge+100);
        if(have_answer){
            double lo=0,hi=max_edge+1,mid ;
            while(hi-lo > 10e-8){
                mid = lo + (hi-lo)/2 ;
                if(tst(mid)){
                    hi = mid ;
                }else{
                    lo = mid ;
                }
            }
            printf("%.2lf\n", mid);
        }
        else
            cout << "No cycle found." <<endl;
        newLine = true ;
        edges.clear();
	}

	return 0;
}
