//============================================================================
// Name        : UVa-10891.cpp
// Author      : Ali Hafez
// Version     :
// Copyright   : Open Source
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

char face[500][500];
bool faceVisited[500][500];
char **die;
bool **visited;
int ind = 0 ;
int n,m ;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<int> nums;

bool valid(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m)
		return false;
	return true;
}
void print() {
    cout << endl ;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << face[i][j];
		}
		cout << endl ;
	}
	cout << endl ;
}

void floodFill2(int x, int y) {
	faceVisited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];
		if (valid(newX, newY)&&face[newX][newY] == 'X' && !faceVisited[newX][newY]) {
			floodFill2(newX, newY);
		}
	}
}
void connectedComp2() {
	memset(faceVisited, false, sizeof(faceVisited));
	int connected = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (face[i][j] == 'X' && !faceVisited[i][j]) {
				connected++;
				floodFill2(i, j);
			}
		}
	}
	nums.push_back(connected);
}
void floodFill1(int x, int y) {
	visited[x][y] = true;
	face[x][y] = die[x][y];
	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];
		if ( valid(newX, newY) && (die[newX][newY]=='*' || die[newX][newY]=='X') && !visited[newX][newY]) {
			floodFill1(newX, newY);
		}
	}
}



void connectedComp() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && (die[i][j] == '*'||die[i][j]=='X')) {
				memset(face, '.', sizeof(face));
				floodFill1(i, j);
				connectedComp2();
				//print() ;
			}
		}
	}
}

int main() {

	cin >> m >> n;
	while(n>0 && m >0){
	die = new char*[n];
	visited = new bool*[n];
	for (int i = 0; i < n; i++) {
		die[i] = new char[m];
		visited[i] = new bool[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> die[i][j];
			visited[i][j] = false;
		}
	}
	connectedComp();
	sort(nums.begin(), nums.end());
	cout << "Throw " << ++ind << endl ;
	cout << nums[0] ;
	for (int i = 1; i < (int) nums.size(); i++) {
		cout << " " << nums[i] ;
	}
	cout << endl << endl ;
	cin >> m >> n;
	nums.clear() ;
	}
	return 0;
}
