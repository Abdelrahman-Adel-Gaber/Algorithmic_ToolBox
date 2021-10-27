#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int L, int r) {
  int x = a[L];
  int j = L;
  for (int i = L + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);

    }
  }
  swap(a[L], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int L, int r) {
  if (L >= r) {
    return;
  }

  int k = L + rand() % (r - L + 1);
  swap(a[L], a[k]);
  int m = partition2(a, L, r);
  int n=m;
  if(m>0){
      int i=m;
      while((i>0)&&(a[i]==a[i-1]))
      {
            n--;
            i--;
      }
  }
  randomized_quick_sort(a, L, n - 1);
  randomized_quick_sort(a, m + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
