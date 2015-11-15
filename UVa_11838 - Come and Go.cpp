#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m ;
    while(n+m != 0){
        bool adjMat [n][n];
        memset(adjMat,false,sizeof(adjMat));
        for(int i=0 ; i<n ; i++)
            adjMat[i][i]=true ;
        for(int i=0 ; i<m ; i++){
            int v,w,p;
            cin >> v >> w >> p ;
            adjMat[--v][--w]=true ;
            if(p == 2)
                adjMat[w][v]=true ;
        }
        for(int k=0 ; k<n ; k++)
            for(int i=0 ; i<n ; i++)
                for(int j=0 ; j<n ; j++)
                    adjMat[i][j] = adjMat[i][j]||(adjMat[i][k]&&adjMat[k][j]);
        bool ans = true ;
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<n ; j++)
                ans &= adjMat[i][j] ;
        if(ans)
            cout << 1 << endl ;
        else
            cout << 0 << endl;
        cin >> n >> m ;

    }
    return 0;
}
