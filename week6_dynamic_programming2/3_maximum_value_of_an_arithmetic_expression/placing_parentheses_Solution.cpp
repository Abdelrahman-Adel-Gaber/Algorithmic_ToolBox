#include <iostream>
#include<stdio.h>
#include <cassert>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}


pair<long long,long long>MaxAndMin(int i , int j , vector<int>&value,vector<char>&OP , vector<vector<long long>> &M, vector<vector<long long>> &m) {
long long min_=INT_MAX;
long long max_=INT_MIN;
 for(int k=i;k<=j-1; k++) {
    long long a=eval(M[i][k],M[k+1][j],OP[k]);
    long long b=eval(M[i][k],m[k+1][j],OP[k]);
    long long c=eval(m[i][k],M[k+1][j],OP[k]);
    long long d=eval(m[i][k],m[k+1][j],OP[k]);

 min_=min(min_,a);
 min_=min(min_,b);
 min_=min(min_,c);
 min_=min(min_,d);

 max_=max(max_,a);
 max_=max(max_,b);
 max_=max(max_,c);
 max_=max(max_,d);
}

return {min_,max_};}


long long get_maximum_value(const string &exp) {
  //write your code here
  int n=(exp.size()/2)+1;
  vector<int>Num(n);
  vector<char>Op(n-1);
  for(int i=0,j=0; i<n-1; i++,j+=2) {
    Num[i]=exp[j]-'0';
    Op[i]=exp[j+1];
  }
  Num[n-1]=exp[n*2-2]-'0';

 vector<vector<long long>> M(n,vector<long long>(n));
 vector<vector<long long>> m(n,vector<long long>(n));

 for(int i=0; i<n ; i++)
    m[i][i]=M[i][i]=Num[i];

    for(int s=1;s<=n-1; s++){
        for(int i =0; i<n-s; i++) {
            int j=i+s;
            pair<long long,long long>x=MaxAndMin(i,j,Num,Op,M,m);
            m[i][j]=x.first;
            M[i][j]=x.second;
         }
    }
  return M[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
