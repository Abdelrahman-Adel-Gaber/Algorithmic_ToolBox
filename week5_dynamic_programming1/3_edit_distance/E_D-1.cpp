#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2,int n,int m) {
  //write your code here
  int Edit_Distane_value= 0;
  int i=0,j=0;

  while(1){
    if( (i == (str1.size() -1)) &&(j < ((str2.size() -1)))  ){
                        if(str1[i]==str2[j]){
                        i++;
                        j++;
                        Edit_Distane_value+=str2.size()-j;
                        }else if(str1[i]==str2[j+1]){
                          j++;
                        Edit_Distane_value+=str2.size()-j;
                        }else{
                          i++;
                          Edit_Distane_value+=str2.size()-j;

                        }



    }else if( (j == (str2.size() -1)) &&(i < ((str1.size() -1))) )
    {
                        if(str1[i]==str2[j]){
                            i++;
                            j++;
                            Edit_Distane_value+=str1.size()-i;
                        }else if(str1[i+1]==str2[j]){
                            i++;
                            Edit_Distane_value+=str1.size()-i;
                        }else{
                          j++;
                          Edit_Distane_value+=str1.size()-i;
                        }


    }else if( (i ==(str1.size()-1) ) && (j ==(str2.size()-1) )  )
    {

                if(str1[i]==str2[j]){
                        i++;
                        j++;
                 }else{
                           i++;
                           j++;
                          Edit_Distane_value++;
                       }

     }else{
                 if(str1[i]==str2[j]){
                    i++;
                    j++;

                  }else if(str1[i+1]==str2[j]){
                   i++;
                            if((str1[i]==str2[j+1]))
                                {
                                ++j;
                               }
                   Edit_Distane_value++;

                  }else if(str1[i]==str2[j+1]){
                   j++;
                           if((str1[i+1]==str2[j]))
                                {
                                ++i;
                               }
                   Edit_Distane_value++;

                  }else{
                   i++;
                   j++;
                   Edit_Distane_value++;

                   }


        }



      if( ( i > (str1.size()-1) ) || ( j > (str2.size()-1) ) )
        {
            break;
         }
  }
  return Edit_Distane_value ;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2, str1.size(), str2.size()) << std::endl;
  return 0;
}
