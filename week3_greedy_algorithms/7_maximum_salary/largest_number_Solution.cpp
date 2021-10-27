#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using namespace std;

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

bool Sort_(string &A, string &B) {
  int a_digit=0,b_digits=0;

 while(A[a_digit]==B[b_digits] && (a_digit<A.size() || b_digits<B.size() ) ) {
   if(a_digit<A.size())
    a_digit++;
   if(b_digits<B.size())
    b_digits++;
   if(b_digits==B.size() && B.size()<A.size())
    b_digits=0;
   if(a_digit==A.size() && B.size()>A.size())
    a_digit=0;
 }


if(b_digits==B.size())
  {
    b_digits--;
  }
if(a_digit==A.size() ) {
 a_digit--;
 }
  if(A[a_digit]>B[b_digits])
   return true;
return false;}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(),a.end(),Sort_);
  for(auto u:a)
   std::cout <<u;
 // std::cout << largest_number(a);
}
