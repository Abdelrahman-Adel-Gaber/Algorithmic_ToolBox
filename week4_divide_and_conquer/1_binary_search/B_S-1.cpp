#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size();
  //write your code here
  int s=right;
  int m;
  m=(left+right)/2;

        if(right==0){
            return -1;
        }
 right --;
      while (1)
      {
          if(left>right)
          {
              return -1;
          }
        if(a[m]==x){
            return m;
        }else if(a[m]<x){
            if(left == right)
                {return -1;}

            left=m+1;
            m=(left+right)/2;
        }else{
            if(left == right)
                {return -1;}

            //x>a[m]
            right =m-1;
            m=(left+right)/2;
        }
      }

  }

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
