#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
int n=a.size(),m=b.size();
int arr[n+1][m+1];

for(int i=0; i<n+1 ;i++)
    arr[i][0]=0;
for(int i=0; i<m+1 ;i++)
    arr[0][i]=0;


for(int i=1; i<n+1; i++)
{
  for(int j=1; j<m+1;j++ ) {
    if(a[i-1]==b[j-1]) {
       arr[i][j]=arr[i-1][j-1]+1;
     }
     else
     {
       arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
     }
  }
}

return arr[n][m]; }

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
