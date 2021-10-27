#include <iostream>
#include <vector>
#include <sys/resource.h>
#include <bits/stdc++.h>


using std::vector;

struct  Coords
{
  long long  value;
  char type;
  long long Index;
};

bool sort_(Coords &a, Coords &b) {
if(a.value==b.value) {
    if(a.type=='L')
        return true;
    else if(b.type=='L')
        return false;
    else if(a.type=='P')
        return true;
    else if(b.type=='P')
        return false;
    else if(a.type == 'R')
        return true;
    else
        return false;
}
return a.value<b.value;}

vector<long long> fast_count_segments(vector<long long> starts, vector<long long> ends, vector<long long> points) {
  vector<long long> cnt(points.size(),0);
  //write your code here
  vector<Coords>temp;
  for(long long unsigned int i=0; i<points.size(); i++) {
    Coords t;
    t.value=points[i];
    t.type='P';
    t.Index=i;
    temp.push_back(t);
  }

  for(long long unsigned int i=0;i<starts.size(); i++){
    Coords t;
    t.value=starts[i];
    t.type='L';
    temp.push_back(t);
    t.value=ends[i];
    t.type='R';
    temp.push_back(t);
  }
  sort(temp.begin(),temp.end(),sort_);
  int segments=0;
  for(auto u:temp) {
    if(u.type=='L')
     segments++;
    else if(u.type=='R')
     segments--;
     else
     cnt[u.Index]=segments;
  }
  return cnt;
}



int main() {
//This COde to increase the stack limits
const __rlim_t kStackSize = 64L * 1024L * 1024L;  // min stack size = 64 Mb
    struct rlimit rl;

    int result;
    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }



  long long n, m;
  std::cin >> n >> m;
  vector<long long> starts(n), ends(n);
  for (long long unsigned int i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<long long> points(m);
  for (long long unsigned int i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }

  //use fast_count_segments
  /*vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }

std::cout<<"\n";
*/
vector<long long> cnt1 = fast_count_segments(starts, ends, points);
  for (long long unsigned int i = 0; i < cnt1.size(); i++) {
    std::cout << cnt1[i] << ' ';
  }

}
