#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int tc;cin >> tc;
    while(tc--){
        int l,n;
        cin >> l >> n ;
        int p [n];
        for(int i=0 ; i<n ; i++)
            cin >>p[i] ;
        int minAns = min(p[0],l-p[0]), maxAns=max(p[0],l-p[0]);
        for(int i=1 ; i<n ; i++){
            minAns = max(minAns,min(p[i],l-p[i])), maxAns=max(maxAns,max(p[i],l-p[i])) ;
        }
        cout << minAns << " " << maxAns << endl ;
    }
    return 0;
}
