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



int partition3(vector<int> &A ,size_t sum) {
  //write your code here
  if( (sum % 3 !=0) || (A.size()<3) )
  {
      return 0;
  }

  size_t Num= sum/3;
  arrange(A);

       for(int i =0 ;i<2 ;i++)
       {
            if(Num < A[A.size()-1] )
              {
               return 0;
              }

           int index =A.size()-1;
           size_t temp = Num-A[index];
           A.erase(A.begin()+index);

            if(temp != 0 )
                 {

                   for(int j=A.size()-1 ;j>=0 ;j--)
                    {
                         if( A[j]<=temp )
                        {
                           if( A[j]==temp ){
                                    temp -= A[j];
                                    A.erase(A.begin()+j);
                                    if(temp <=0)
                                    {
                                        j=0;
                                    }

                            }else
                            {
                                int z=A[j];
                                for(int m=j-1 ; m>=0 ;m--)
                                  {
                                    if(A[m]<=(temp-z))
                                    {
                                        z+=A[m];
                                        if( z == temp)
                                            {
                                                m=0;
                                                temp -= A[j];
                                                A.erase(A.begin()+j);
                                                if(temp ==0)
                                                {
                                                    j=0;
                                                }
                                            }
                                    }

                                }
                            }
                        }


                      }
                 }

             if(temp != 0 )
             {
                 return 0;
             }

       }

return 1;
}


int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  size_t sum =0;
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
    sum += A[i];
  }

  std::cout << partition3(A,sum) << '\n';
}
