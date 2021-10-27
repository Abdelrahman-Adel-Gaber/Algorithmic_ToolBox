#include <iostream>
#include <vector>

using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int n=a.size(),m=b.size(),l=c.size();
  int arr[n+1][m+1][l+1];

   for(int i=0; i<n+1; i++)
     for(int j=0; j<m+1; j++)
      for(int k=0; k<l+1; k++)
      {
        if(k==0 || j==0 || i==0)
         arr[i][j][k]=0;
         else if(a[i-1]==b[j-1] && a[i-1]==c[k-1]) {
          arr[i][j][k]=arr[i-1][j-1][k-1]+1;
         }else
         {
           arr[i][j][k]=max(arr[i-1][j][k],arr[i][j-1][k]);
           arr[i][j][k]=max(arr[i][j][k],arr[i][j][k-1]);
         }
      }

  return arr[n][m][l];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
