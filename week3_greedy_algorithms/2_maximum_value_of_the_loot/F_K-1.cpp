#include <iostream>
#include <vector>

using std::vector;

void Sorting_in_decreasing_order(int n, double*VpW, int* weights){

 int i,m,temp1;
 double temp2;

    for(i=0;i<n-1;i++){
        for(m=i;m<n-1;m++){
             if(VpW[i]<VpW[m+1]){
                  temp2=VpW[i];
                  VpW[i]=VpW[m+1];
                  VpW[m+1]=temp2;

                  temp1= weights[i];
                  weights[i]=weights[m+1];
                  weights[m+1]=temp1;
             }else{
                 //do nothing
             }
        }
    }
}


double get_optimal_value(int capacity, int n , int* weights, double* VpW) {
  double value = 0.0;
  int m=0;
  // write your code here
  while ((capacity!=0)&&(m<n))
  {
          if(weights[m]<capacity){
              capacity=capacity-weights[m];
              value+= VpW[m]*weights[m];

              }else{
                value+= (VpW[m]*(double)capacity);
                capacity=0;

               }
    m++;
  }


  return value;
}

int main() {
  int n;
  int capacity;
/*Reading thr input*/
  std::cin >> n >> capacity;
  int values[n];
  int weights[n];
  double VpW[n];
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
    VpW[i]=((double)values[i])/weights[i];
  }

   Sorting_in_decreasing_order( n, VpW, weights);

   double optimal_value = get_optimal_value(capacity, n, weights, VpW);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
