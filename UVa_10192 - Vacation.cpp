#include <iostream>
#include <cstring>

using namespace std;

int memo [110][110];
string s1,s2 ;

int LCS (int n,int m){
    if(memo[n][m] != -1)
        return memo[n][m];
    if(n == s1.size() || m == s2.size())
        return memo[n][m] = 0;
    if(s1[n] == s2[m])
        return memo[n][m] = 1+LCS(n+1,m+1);
    else
        return memo[n][m] = max(LCS(n,m+1),LCS(n+1,m));
}

int main()
{
    ios_base::sync_with_stdio(false);
    int i=0;
    getline(cin,s1);
    while(s1 != "#"){
        memset(memo,-1,sizeof(memo));
        getline(cin,s2);
        cout << "Case #" << ++i << ": you can visit at most " << LCS(0,0) << " cities." << endl ;
        getline(cin,s1);
    }
    return 0;
}
