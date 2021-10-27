#include <iostream>
#include <vector>

using std::vector;

void arrange(vector<int> &A)
{
    int len =A.size();
for(int i=0; i<len ; i++ )
{
    for(int j=i+1 ;j <len ; j++)
    {
        if(A[i] > A[j] )
        {
            int temp =A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
}
}


int partition3(vector<int> &A,int sum) {
 //write your code here
   if(sum%3 !=0)
   {
        return 0;
   }
   
   
   arrange(A);

   int Num = sum/3 ;
   int n =A.size();
   vector<vector<int>> Knapsack(n+1,vector<int>(Num+1));
   for(int i=0 ; i<=n  ;i++)
   {
       Knapsack[i][0]=0;
   }
   for(int i=0 ; i<=Num ;i++)
   {
       Knapsack[0][i]=0;
   }
   
   for(int i=1; i<=n ;i++)
   {
        for(int j=1 ; j<=Num ; j++)
        {
            Knapsack[i][j] = Knapsack[i-1][j];
            if(A[i-1]<=j)
            {
                int temp=Knapsack[i-1][j-A[i-1]]+A[i-1];
                if(Knapsack[i][j]<temp)
                {
                    Knapsack[i][j]=temp;
                }
            }
        }
   }
   if( (Knapsack[n][Num]==Num) && (Knapsack[n-1][Num]==Num) && (Knapsack[n-1][Num]==Num)  )
   {
       return 1;
   }else
   {
      return 0;
   }
  
}

int main() {
  int n;
  int sum=0;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
    sum +=A[i];
  }
  std::cout << partition3(A,sum) << '\n';
}
