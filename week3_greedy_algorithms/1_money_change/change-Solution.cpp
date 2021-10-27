#include <iostream>
using namespace std;
int get_change(int m) {
  //write your code here
  int n=0;
  n=m/10;
  m-=10*(m/10);
  n+=m/5;
  m-=5*(m/5);
  n+=m;
  return n;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
