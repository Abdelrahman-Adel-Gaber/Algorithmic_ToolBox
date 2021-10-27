#include <iostream>
/******************My_Code************************/
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

long long lcm_naive(long long a,long long b) {
  int gcd=gcd_fast(a, b);
  return (long long) (a/gcd)*b;
  
  }
  /****************The_End*************************/
/*long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
*/
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
