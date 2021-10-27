#include <iostream>

long long get_fibonacci_huge_naive(unsigned long long n,unsigned long long m) {
    if (n <= 1)
        return n;

   unsigned long long previous = 0;
   unsigned long long current  = 1;
   unsigned  long long tmp_previous; 
    for (long long i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
       /*Will repeat it(Geometric series)*/
       if((current==1)&&(previous==0)){
       // std::cout<<"One Time "<<i<<std::endl;
        n=n%(i+1);
        if (n <= 1)
        return n;

         i=-1;
         previous = 0;
         current  = 1;
        }
       
       }

    return current % m;
}

int main() {
    unsigned long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
   
}
