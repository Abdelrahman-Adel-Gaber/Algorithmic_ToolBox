#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int log_3(int x){
if(x<3){
    return 0;
}
while(x>=3){
    if(x%3==0){
        x= x / 3;
    }else{
         return 0;
         }
}
if(x == 1){
    return 1;
}else{
return 0;
}
}
int log_2(int x){
if(x<2){
    return 0;
}
while( x >= 2 ) {
    if ( x%2 == 0 ){
        x= x / 2;
    }else{
         return 0;
         }
}
if(x == 1){
    return 1;
}else{
return 0;
}
}
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;

  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    }else if ( (n %3== 1) && (log_3(n-1)==1) ) {
        n= n - 1;

    }else if ( (n % 4 != 0) && ( n % 9 == 1 ) ) {
      n = n - 1 ;

    }else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());

  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  if(n>1)
  {
      vector<int> sequence1 = optimal_sequence(n-1);
      if((sequence.size())>(sequence1.size()+1))
      {
              std::cout << sequence1.size() << std::endl;
              for (size_t i = 0; i < sequence1.size(); ++i) {
                std::cout << sequence1[i] << " ";
              }
              std::cout<< n <<" ";
      }else{
                          std::cout << sequence.size() - 1 << std::endl;
              for (size_t i = 0; i < sequence.size(); ++i) {
                std::cout << sequence[i] << " ";
              }
      }

  }else{
  std::cout<< 0<<std::endl;
  std::cout<< 1 <<" ";
  }

}
