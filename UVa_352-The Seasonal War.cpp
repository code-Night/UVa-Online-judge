//============================================================================
// Name        : DFS.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//             : this code uses Adjacency matrix of max * max and a stack
//============================================================================

#include <iostream>
#include <stack>
#include <string.h>
#include <cstdio>
using namespace std;
int last;
int ind = 1;
bool **visited;
bool print = false ;
int **ADJ;
int num = 0;

void DFS(int x, int y) {
	num++;
	stack<pair<int, int> > search;
	visited[x][y] = true;
	search.push(make_pair(x, y));
	while (!search.empty()) {
		pair<int, int> curr = search.top();
		search.pop();
		int north = curr.first - 1;
		bool Vnorth = true ;
		if(north < 0)
			Vnorth = false ;
		int south = curr.first + 1;
		bool Vsouth = true;
		if (south >= last)
			Vsouth = false;
		int east = curr.second + 1;
		bool Veast = true;
		if (east >= last)
			Veast = false;
		int west = curr.second - 1;
		bool Vwest = true;
		if (west >= last || west < 0)
			Vwest = false;
		if (Vnorth){
			if(ADJ[north][curr.second] == 1 && !visited[north][curr.second]){    //check north
				search.push(make_pair(north,curr.second));
				visited[north][curr.second] = true ;
			}
		}
		if(Vnorth && Veast){                                                     //check north east
			if(ADJ[north][east] == 1 && !visited[north][east]){
				search.push(make_pair(north,east));
				visited[north][east] = true ;
			}
		}
		if(Vnorth && Vwest){
			if(ADJ[north][west] == 1 && !visited[north][west]){                //check north west
				search.push(make_pair(north,west));
				visited[north][west] = true ;
			}
		}
		if(Vwest){
			if(ADJ[curr.first][west] == 1 && !visited[curr.first][west]){
				search.push(make_pair(curr.first,west));
				visited[curr.first][west] = true;
			}
		}
		if (Veast) {
			if (ADJ[curr.first][east] == 1 && !visited[curr.first][east]) {     //check east
				search.push(make_pair(curr.first, east));
				visited[curr.first][east] = true;
			}
		}
		if (Vsouth) {
			if (ADJ[south][curr.second] == 1 && !visited[south][curr.second]) { // check south
				search.push(make_pair(south, curr.second));
				visited[south][curr.second] = true;
			}
		}
		if (Vsouth && Veast) {
			if (ADJ[south][east] == 1 && !visited[south][east] && Vsouth) { // check south east
				search.push(make_pair(south, east));
				visited[south][east] = true;
			}
		}
		if (Vsouth && Vwest) {
			if (ADJ[south][west] == 1 && !visited[south][west] && Vsouth && Vwest) { //check south west
				search.push(make_pair(south, west));
				visited[south][west] = true;
			}
		}
	}

}

int main() {
	//FILE *read = fopen("Bumble.in.txt", "r");
	//FILE *write = fopen
	while (cin >> last) {
		string input[last];
		for (int i = 0; i < last; i++)
			cin >> input[i];
		visited = new bool*[last];
		for (int i = 0; i < last; i++)
			visited[i] = new bool[last];
		ADJ = new int*[last];
		for (int i = 0; i < last; i++)
			ADJ[i] = new int[last];
		for (int i = 0; i < last; i++) {
			for (int j = 0; j < last; j++) {
				if (input[i][j] == '1') {
					ADJ[i][j] = 1;
				} else {
					ADJ[i][j] = 0;
				}
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < last; i++) {
			for (int j = 0; j < last; j++) {
				if (ADJ[i][j] == 1 && !visited[i][j]) {
					DFS(i, j);
				}
			}

		}
		if(print)
			cout << endl ;
		cout<<"Image number " << ind++  << " contains "<< num  <<" war eagles.";
		num = 0;
		print = true ;
	}
	cout << endl ;
	return 0;
}
