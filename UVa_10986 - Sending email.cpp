#include <iostream>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;
const int oo = 1 << 30;
int n, m, s, t;
vector< vector< pair<int,int> > > ADJ_list;
vector<int> dist;
bool visited[20000];

int djkstra_UQ(int s, int d) {
	memset(visited, false, sizeof(visited));
	dist.resize(n + 1);
	fill(dist.begin(),dist.begin()+n+1,oo) ;
	dist[s] = 0;
	priority_queue< pair<int, int> > path;
	path.push(make_pair(0, s));
	while (!path.empty()) {
		int selected = path.top().second;
		path.pop();
		if (!visited[selected]) {
			visited[selected] = true;
			//relax with the cloesest
			for (int i = 0; i < (int) ADJ_list[selected].size(); i++) {
				int neighbor = ADJ_list[selected][i].first;
				if (dist[neighbor] > dist[selected] + ADJ_list[selected][i].second) {
					dist[neighbor] = dist[selected] + ADJ_list[selected][i].second ;
					path.push(make_pair(-1 * dist[neighbor], neighbor));
				}
			}
		}
	}
	return dist[d];
}
int main() {
	int ind = 0;
	int test;
	cin >> test;
	for(int x=0 ; x<test ; x++){
		ADJ_list.clear();
		dist.clear();
		cin >> n >> m >> s >> t;
		ADJ_list.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
            ADJ_list[y].push_back(make_pair(x,w));
            ADJ_list[x].push_back(make_pair(y,w));
		}
		int shortest_path = djkstra_UQ(s, t);
		if (shortest_path == oo)
			cout << "Case #" << ++ind << ": " << "unreachable" << endl;
		else
			cout << "Case #" << ++ind << ": " << shortest_path << endl;
	}
	return 0 ;
}
