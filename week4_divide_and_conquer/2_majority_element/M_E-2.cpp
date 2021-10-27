#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  //Right =n
  int i,m;
  int count=1;
  
  for(i=0;i<((right/4)+1);i++){
      for(m=i+1;m<(right/2);m++){
          if(a[i]==a[m])
           {
              count ++;
            }
            if(((right/2)-m+count)<(right/4))
            { break;}
      }
      if(count>(right/4)){
          if(count>right/2)
            {return 1;}
        int j;
        for(j=right/2;j<right;j++){
            if(a[i]==a[j])
            {
                count++;
                if(count>right/2){
                    return 1;
                }
            }
        }
      }
      count =1;
  }
int new1=(right/2)+((right-(right/2))/2)+1;
  for(i=(right/2);i<new1;i++){
      for(m=i+1;m<right;m++){
          if(a[i]==a[m])
           {
              count ++;
            }
            
            if((right-m+count)<(right/4))
            { break;}
      }
      if(count>(right/4)){
          if(count>right/2)
            {return 1;}
        int j;
        for(j=0;j<(right/2);j++){
            if(a[i]==a[j])
            {
                count++;
                if(count>right/2){
                    return 1;
                }
            }
        }
      }
      count =1;
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
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
