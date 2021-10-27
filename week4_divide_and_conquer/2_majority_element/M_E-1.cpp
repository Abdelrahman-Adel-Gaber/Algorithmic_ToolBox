#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

void sort(vector<int>&a,int left,int right){
 int i,m,temp;
 for(i=left;i<right;i++){
   for(m=i+1;m<right;m++){
     if(a[i]>a[m]){
       temp=a[m];
       a[m]=a[i];
       a[i]=temp;
     }
   }
 }

}
int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
 int count =0;
 int i;
 for(i=0;i<right-1;i++){
   if(a[i]==a[i+1]){
      count++;
      if((count+1) >(right/2)){
          return 1;
        }
   }else{
     count=0;
    }
  }
 return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  sort(a,0,(n/2)+1);
  sort(a,(n/2)+1,n);
  sort(a,0,n);

  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
