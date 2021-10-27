#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned  long long current  = 1;
    unsigned long long sum      = 1;
    if (n>=60){
    
    for (long long i = 0; i < 59; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum = (sum+current)%10;
        }
        sum=sum*(n/60);
        sum=sum%10;
        n=n%60;
        if(n!=0)
         sum++;
        }
        previous=0;
        current =1;
        sum=sum%10;
   //std::cout<<sum<<"   "<<n <<std::endl;
    for (long long i = 0; i < n -1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum = sum+current;
        
    }

    return sum % 10;
}


int main() {
    long long n = 0;
   // std::cout<<832564823476%60<<std::endl;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
