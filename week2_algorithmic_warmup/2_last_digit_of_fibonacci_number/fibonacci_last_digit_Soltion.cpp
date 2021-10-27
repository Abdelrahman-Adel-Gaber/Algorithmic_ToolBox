#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;
    unsigned long long x=0,y=1;
    unsigned long long next_num;
    unsigned long long z;
    for(int i=1;i<n;i++){
      next_num=x%10+y%10;
      //if((next_num<x)||(next_num<y))
      //std::cout<<"there is an overflow !!!\n"<<i;
      x=y%10;
      y=next_num%10;
    }
    
    //std :: cout<<next_num<<"\n";
    return next_num %10;

}

int main() {
    int n;
    std::cin >> n;
   int  c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
