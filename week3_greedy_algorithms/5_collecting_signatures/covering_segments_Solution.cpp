#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  int Time_of_last_Visit=segments[0].end;
  points.push_back(Time_of_last_Visit);
  for (size_t i = 1; i < segments.size(); ++i) {
     if(Time_of_last_Visit<segments[i].start) {
       Time_of_last_Visit=segments[i].end;
       points.push_back(Time_of_last_Visit);
     }
  }
  return points;
}

bool Sort_Segments(Segment &A,Segment &B) {

return A.end<B.end;}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

  std::sort(segments.begin(),segments.end(),Sort_Segments);
  

  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
