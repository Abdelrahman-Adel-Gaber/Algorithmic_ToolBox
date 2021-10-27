#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight[w.size()+1][W+1];

  for(int i=0 ;i< (w.size()+1) ; i++ )
  {
     current_weight[i][0]=0;
  }

  for(int i=0 ;i< (W+1) ; i++ )
  {
     current_weight[0][i]=0;
  }
int l=w.size();
 for(int i =1 ; i<=l ; i++)
 {
     for(int j=1; j<= W; j++)
     {
         current_weight[i][j]=current_weight[i-1][j];
         if( w[i-1] <= j )
         {
             int val =current_weight[i-1][j-w[i-1]]+w[i-1];
             if( current_weight[i][j] < val )
             {
               current_weight[i][j]=val;
             }


     }


     }
 }


  return current_weight[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);

  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }

  std::cout << optimal_weight(W, w) << '\n';
}
