#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
double x , p ,q ,r ,s ,t, u, ans;
double f(double x){
    //p ∗ e−x + q ∗ sin(x) + r ∗ cos(x) + s ∗ tan(x) + t ∗ x ^2 + u =
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u ;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    while(cin >> p >> q >> r >> s >> t >> u) {
        double lo = 0 , hi = 1 ,mid;
        if(f(lo)*f(hi) > 0 )
            printf("No solution\n");
        else{
            for(int i=0 ; i<50 ; i++){
                mid = lo+(hi-lo)/2 ;
                if(f(lo)*f(mid) < 0)
                    hi = mid ;
                else
                    lo = mid ;
            }


            printf("%0.4lf\n", mid);
        }
    }
    return 0;
}
