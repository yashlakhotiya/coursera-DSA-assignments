#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(long long dist, int tank, vector<long long> & stops) {
    long long threshold = tank;
    int min_refil = 0;
    int i = 0;
    long long dist_travelled = 0;
    auto it2 = stops.end();
    while(dist_travelled <= *(stops.end()-1) && stops.size()!=0){
        auto it1 = std::upper_bound(stops.begin(),it2,threshold);
        //cout<<"\nit1 "<<*it1<<"\n";
        it1--;
        //cout<<"\nit1 "<<*it1<<"\n";
        if(it1 == stops.begin()) return -1;
        if(it1 == stops.end()) return min_refil;
        dist_travelled = *it1;
        //cout<<"\n"<<"dist travelled"<<dist_travelled;
        min_refil++;
        threshold = dist_travelled + tank;
        //cout<<"\n"<<"threshold"<<threshold<<"\n";
        //cout<<"\nstops size prev: "<<stops.size()<<"\n";
        //cout<<"\nstops begin prev: "<<*stops.begin()<<"\n";
        //cout<<"\nstops end prev: "<<*(it1+1)<<"\n";
        if(dist_travelled == dist) break;
        stops.erase(stops.begin(),it1);
        //cout<<"\nstops size aftr: "<<stops.size()<<"\n";
        //cout<<"\nstop values\n";
        //for(auto it = stops.begin();it!=stops.end();it++) cout<<*it<<"\t";
    }

    return (min_refil-1);
}


int main() {
    long long d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<long long> stops(n+2);
    stops.at(0) = 0;
    stops.at(n+1) = d;
    for (int i = 1; i < n+1; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
