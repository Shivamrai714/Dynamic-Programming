#include<bits/stdc++.h>
using namespace std;

// task to find the size of long pallidromic susequece from given string after removing char
// eg : s=agbcba    ans=5
//

int t[1001][1001];
int lcs(string a,string b,int m,int n)
{
   // using memoization 
    if(m==0||n==0) return 0;
    if(t[m][n]!=-1) return t[m][n];
    else
    {
      if(a[m-1]==b[n-1]) return t[m][n]=1+ lcs(a,b,m-1,n-1);
      
      else
        {   
         return max(lcs(a,b,m-1,n),lcs(a,b,m,n-1));
         }
    }
}


int main()
{ 
  memset(t,-1,sizeof(t));
  string a,b;     // a=agbcba 
  cin>>a;
   b=a;
   reverse(b.begin(),b.end());
  int m=a.size(),n=b.size() ;


int ans= lcs(a,b,m,n);

cout<<"LPS (longest pallidromic subsequece is ) :"<< ans;

 //  cout<<"Deletions needed: "<<m-lcs_length;
 // cout<<"\nInsertions needed: "<<n-lcs_length;
   
 

return 0;
}