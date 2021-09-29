#include<bits/stdc++.h>
using namespace std;
int t[1000][1000];
  // using dp
int lcs(string a,string b,int m,int n)
{  
	//initialisation
    for(int i=0;i<m+1;i++)
    for(int j=0;j<n+1;j++)
    {
    	t[i][j]=0;
    } 
      //fill
    for(int i=1;i<m+1;i++)
    {	for(int j=1;j<n+1;j++)
    	{  if(a[i-1] == b[j-1]){ t[i][j]=1+t[i-1][j-1];}
               else
               {
               	t[i][j]=max(t[i-1][j],t[i][j-1]);
               }
    	} 
    }
return t[m][n];
}

int main()
{
   // task is to find min deletions to get a pallindrome string.
    //i/p : agbcba    --- o/p :1
    // trick : minimum deletions means lenght of pallindrome will be max 
    // and we know how to get max lenght pallindrom : ie take 
    //  LPS= LCS(a, reverse (a) ) 
  string a,b;
  cin>>a;
  b=a;
  reverse(b.begin(),b.end());
int m=a.size(), n=b.size();
  int max_length_pallindrome = lcs(a,b,m,n);
 
  cout<<"Mini no of deletions : "<< m - max_length_pallindrome;




}