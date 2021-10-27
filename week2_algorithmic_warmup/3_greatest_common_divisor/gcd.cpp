#include <iostream>
/*
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

*/
/*My implementation*/
int gcd_fast(long long a, long long b) {
if(b==0)
return (int)a;

long long reminder;
if(a>b)
{reminder=a%b;
return gcd_fast(b,reminder);
}else
{
reminder=b%a;
return gcd_fast(a,reminder);
}

}
/***************************/
int main() {
  int a, b;
  std::cin >> a >> b;
 // std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
