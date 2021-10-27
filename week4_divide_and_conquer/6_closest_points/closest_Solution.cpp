#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using std::vector;
using std::string;
using std::pair;
using std::min;

bool Sort_Y(pair<int,int> a, pair<int,int> b) {

return a.second<b.second;}

bool sort_function (pair<int,int>a,pair<int,int>b) {

 return a.first<b.first;}

double minimal_distance(vector<pair<int,int>> &points,int l,int r) {
  //write your code here
  if(r-l==1)
   return sqrt(pow(points[l].first-points[r].first,2)+pow(points[l].second-points[r].second,2));

  int m= (l+r)/2;
  double d1= m-l>1? minimal_distance(points,l,m):sqrt(pow(points[l].first-points[m].first,2)+pow(points[l].second-points[m].second,2));
  double d2= r-m>1? minimal_distance(points,m+1,r):sqrt(pow(points[r].first-points[m].first,2)+pow(points[r].second-points[m].second,2)) ;

  double d=min(d1,d2);
  vector<pair<int,int>>first_part;
  vector<pair<int,int>>second_part;
   if(r-l>=3) {
     double mid_plan=points[m].first;
     for(int i=l; i<m; i++){
      if((mid_plan-points[m].first)<d)
      first_part.push_back(points[i]);
      }
      first_part.push_back(points[m]);
     for(int i=m+1; i<=r; i++){
       if((points[i].first-mid_plan)<d)
         second_part.push_back(points[i]);
     }

      for(auto i:first_part ){
        for(auto j:second_part) {
         double temp=sqrt(pow(i.first-j.first,2)+pow(i.second-j.second,2));
          d=min(d,temp);
          }
       }
   }


  return d;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<pair<int,int>> points(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> points[i].first >> points[i].second;
  }

  std::cout << std::fixed;
  sort(points.begin(),points.end(),sort_function);
  std::cout << std::setprecision(9) << minimal_distance(points,0,n-1) << "\n";
}
