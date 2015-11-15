#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef  long long int lli;

int n;
lli sumTree [16000000+1] ;
lli value [200000] ;

void build(int i,int l,int r){
    if(l == r){
        sumTree[i] = value[l] ;
        return ;
    }
    int mid = (l+r)/2 ;
    build(i*2+1,l, mid);
    build(i*2+2,mid+1,r);
    sumTree[i] = sumTree[2*i+1]+sumTree[2*i+2] ;
}

lli query (int i,int li,int ri,int a,int b){
    if(li > b || ri < a)
        return 0 ;
    if(li >= a && ri <= b)
        return sumTree[i] ;
    int mid = (li+ri)/2;
    return query(2*i+1,li,mid,a,b)+query(2*i+2,mid+1,ri,a,b) ;
}

void update(int i, int li,int ri,int target,int newValue) {
    if((li == ri)&& (ri == target)){
        sumTree[i] = newValue ;
        return ;
    }else if(target <= (li+ri)/2){
        update(2*i+1,li,(li+ri)/2,target,newValue);
    }else{
        update(2*i+2,(li+ri)/2+1,ri,target,newValue);
    }
    sumTree[i] = sumTree[2*i+1]+sumTree[2*i+2];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);

    cin >> n ;int tc = 1 ;
    while(n!=0){
        if(tc > 1)
            cout << endl ;
        cout << "Case " << tc++ << ":\n" ;
        memset(sumTree,-1,sizeof(sumTree));
        for(int i=0 ; i<n ; i++){
            cin >> value[i];
        }
        build(0,0,n-1);
        while(true){
            string  Q = "" ;
            cin >> Q ;
            int x, y ;
            if(Q == "END")
                break ;
            else{
                cin >> x >> y ;
                if(Q == "S")
                    update(0,0,n-1,x-1,y);
                else
                    cout << query(0,0,n-1,x-1,y-1) << endl;
            }
        }
        cin >> n ;
    }
    return 0;
}
