#include <iostream>

int get_change(int m) {
  //write your code here
  //coins{1,3,4}
  //2=3-1
 if(m==2){
    return 2;
 }
  int temp;
  temp=m%4;
  if(temp==0){
      return m/4;
  }
  else if(temp==1)
  {
      return ((m/4)+1);
  }else if(temp==2){
      return(((m-6)/4)+2);
  }else{
      return((m/4)+1);
  }

}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
