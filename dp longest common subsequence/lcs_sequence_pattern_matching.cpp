#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];

//done directly with mattrix -> dp 
int lcs(string a,string b,int m,int n)
{
	for(int i=0;i<m+1;i++)
		for(int j=0;j<n+1;j++)
		{ 
			if(m==0 || n==0)                         // base cond: if len are 0 , then no lcs
			t[i][j]=0;
		}

for(int i=1;i<m+1;i++)
	for(int j=1;j<n+1;j++)
	{
		if(a[i-1]==b[j-1]) t[i][j]=1+t[i-1][j-1];
       else
        t[i][j]= max(t[i-1][j] , t[i][j-1]);
	}


return t[m][n];
}


int main()
{
  string a,b;  // A: AXY   B:ADXCPY 
  cin>>a>>b;   //task is to find a is matching with b 

// trick is ,we are cal the lcs from both , if lcs lenght is same as the a .length , tehn o/p yes
int m=a.size(); int n=b.size();
int lcs_length=lcs(a,b,m,n);

if(lcs_length==m || lcs_length==n) cout<<"Yes";      //a is present in b ,||  // b is present in a
   
else cout<<"No";


return 0;
}