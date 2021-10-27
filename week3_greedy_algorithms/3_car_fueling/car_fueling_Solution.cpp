#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int last_station=0;
    int num_refill=0;

    for(int i=0; i<stops.size(); i++) {
     if(stops[i]>(last_station+tank)) {
            if(i>0) {
                last_station=stops[i-1];
                num_refill++;
                if(stops[i]>(last_station+tank))
                    return -1;
            }
            else{
                return -1;
            }

     }
    }
    if(dist>last_station+tank){
     if(last_station==stops[stops.size()-1])
        return -1;

            last_station=stops[stops.size()-1];
            num_refill++;
            if(dist>last_station+tank)
                return -1;
    }

return num_refill;}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
