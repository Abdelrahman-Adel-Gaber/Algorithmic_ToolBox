#include <iostream>
#include <string>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
int l1=str1.size();
int l2=str2.size();
int D[l1+1][l2+1];
int i,j;
        for(i=0;i<=l1;i++)
        {
            D[i][0]=i;
        }
        for(j=0;j<=l2;j++)
        {
            D[0][j]=j;
        }
   for(i=1;i<=l1;i++)
   {
       for(j=1;j<=l2;j++)
       {
           if( str1[i-1] == str2[j-1] )
           {
               int temp=min( (D[i][j-1]+1) ,(D[i-1][j]+1) );
               D[i][j]=min( temp , (D[i-1][j-1]) );

           }else
           {
               int temp=min( (D[i][j-1]+1) ,(D[i-1][j]+1) );
               D[i][j]=min( temp , (D[i-1][j-1]) +1 );

           }

       }
   }


  return D[l1][l2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
