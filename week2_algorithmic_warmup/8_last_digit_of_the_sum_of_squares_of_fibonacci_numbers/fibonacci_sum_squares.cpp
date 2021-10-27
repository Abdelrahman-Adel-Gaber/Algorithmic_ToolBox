#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

unsigned long long previous = 0;
unsigned long long current  = 1;
unsigned long long sum      = 1;
unsigned long long tmp_previous;
    
    for (long long i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
 
               
        sum += ((current%10)*(current%10)%10) ;
        //std::cout<<sum<<"\n";
        
    }

    return sum%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
