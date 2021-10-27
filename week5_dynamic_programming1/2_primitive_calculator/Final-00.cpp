#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence[4];
  while (n >= 1) {
    sequence[0].push_back(n);
    if (n % 3 == 0) {
     n /= 3;  
    }else if (n % 2 == 0) {
      sequence[2]=optimal_sequence(n/2);
      sequence[3]=optimal_sequence(n-1);

              if(sequence[2].size()<= sequence[3].size()){
                n /= 2 ;
              }else{
               n = n - 1 ;
              }

    }
    else {
        n = n - 1 ;
    }




  }

  reverse(sequence[0].begin(), sequence[0].end());
  return sequence[0];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
