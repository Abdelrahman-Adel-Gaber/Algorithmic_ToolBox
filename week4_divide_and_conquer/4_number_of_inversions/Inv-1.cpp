#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, size_t left, size_t right) {
  long long number_of_inversions = 0;
  //write your code here
 int i,m;
 for(i=left;i<right;i++)
  {
      for(m=i+1;m<right;m++)
      {
          if(a[i]>a[m]){
              number_of_inversions++;
          }

      }
  }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << get_number_of_inversions(a, 0, a.size()) << '\n';
}
