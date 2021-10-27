#include <algorithm>
#include <iostream>
#include <vector>


void sorting(int* a,size_t n){
int temp;
size_t i,m;
for(i=0;i<n-1;i++){
  for(m=i;m<n-1;m++){

        if(a[i]<a[m+1]){
            temp=a[i];
            a[i]=a[m+1];
            a[m+1]=temp;
        }
    }
}

}

long long max_dot_product(int* a, int* b,size_t n) {
  // write your code here
  long long result = 0;
  for (size_t i = 0; i < n; i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  int a[n], b[n];
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
 sorting(a,n);
 sorting(b,n);
  std::cout << max_dot_product(a, b,n) << std::endl;
}
