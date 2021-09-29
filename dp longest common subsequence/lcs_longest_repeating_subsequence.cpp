#include<bits/stdc++.h>
using namespace std;

// Task is to find : longest repaeating subsequence: 
// s: AABEBCDD  : ABD is repeative ans = 3

// theme: is : we are taking the lcs (a,a)  of the same string with a condition that index are not same and elements are same( i!=j)  
// because to get the repeative subsequence , we need 2 char , that have diffrerent index val


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
    	{
        if(a[i-1] == b[j-1]  and i!=j)   // we need only char with different index
          {
           t[i][j]=1+t[i-1][j-1];
          }
      
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
     string a;
  cin>>a;
int m=a.size();
  int ans = lcs(a,a,m,m);
 
  cout<<"long repeating subsequence  "<<ans  ;


return 0;

}