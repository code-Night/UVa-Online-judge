#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <istream>
#include <iostream>
#include <cstdio>
using namespace std;


struct Event {
    int dist;
    string type;
};
vector <Event> road ;
map<double,double>fuel_map;

bool can(double amount){
    double n = amount ;
    double cur_dist,next_dist,fuel_con,leaks=0 ;
    for(int i=1 ; i < (int)road.size(); i++){
        Event next_ev = road[i];
        Event cur_ev = road[i-1] ;
        cur_dist = cur_ev.dist;
        next_dist = next_ev.dist ;
        if(cur_ev.type == "FC")
            fuel_con = fuel_map[cur_dist];
        else if(cur_ev.type == "L")
            leaks++;
        else if(cur_ev.type == "GS")
            n = amount ;
        else if(cur_ev.type == "M")
            leaks = 0 ;
        else if(cur_ev.type == "GOAL")
            break ;
        n -= (fuel_con/100)*(next_dist-cur_dist) ;
        n -= leaks*(next_dist-cur_dist) ;
        if(n <= 0)
            break ;
    }
    return n>=0 ;
}

double bin_search (){
    double lo = 0;
    double hi = 10000;
    double mid;
    for(int i=0 ; i<50 ; i++){
        mid = lo + (hi-lo)/2 ;
        if(can(mid))
            hi = mid ;
        else
            lo = mid ;
    }
    return mid;
}


int main()
{
    //freopen("input.txt","r",stdin);
    string s = "" ;
    getline(cin,s);
    while(s != "0 Fuel consumption 0"){
        Event e ;
        stringstream ss (s);
        //cout << s << endl ;

        if(s.find("Fuel consumption")!=string::npos){
            int dist,fuel;
            Event e;
            string dummy;
            ss >> dist >> dummy >> dummy >> fuel ;
            e.dist = dist ;
            e.type = "FC" ;
            fuel_map[dist] = fuel ;
            road.push_back(e);
        }else if(s.find("Leak")!=string::npos){
            int dist;
            ss >> dist ;
            e.dist = dist ;
            e.type = "L";
            road.push_back(e);
        }else if(s.find("Gas station")!=string::npos){
            int dist;
            ss >> dist;
            e.dist = dist ;
            e.type = "GS";
            road.push_back(e);
        }else if(s.find("Mechanic")!=string::npos){
            int dist;
            ss >> dist;
            e.dist = dist;
            e.type = "M";
            road.push_back(e);
        }else{
            int dist ;
            ss >> dist ;
            e.dist = dist ;
            e.type = "GOAL" ;
            road.push_back(e);
            double ans = bin_search() ;
            printf("%0.3lf\n", ans);
            road.clear();
            fuel_map.clear();
        }
        getline(cin,s);
    }
    return 0;
}
