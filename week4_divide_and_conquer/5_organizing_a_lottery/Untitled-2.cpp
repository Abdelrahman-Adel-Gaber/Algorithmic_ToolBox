#include <iostream>
#include <vector>

using std::vector;
void sorting(vetor<int>&starts,vetor<int>&ends)
{
int i,m;
for(i=1;i<starts.size();i++)
{
    for(m=i+1;m<starts.size();m++)
    {
        if(starts[m]<starts[i])
        {
            int temp =starts[i];
            starts[i]=starts[m];
            starts[m]=temp;
            temp =ends[i];
            ends[i]=ends[m];
            ends[m]=temp;
        }
    }
}
}
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
