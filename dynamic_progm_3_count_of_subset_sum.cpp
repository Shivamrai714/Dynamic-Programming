



#include<bits/stdc++.h>
using namespace std;
int main()
{  
	//Task is to check how many subset are present containg the sum as subset_ele sum { , +, +,}
     // before we are only finding true /false 

  int n; cin>>n; int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
int sum; cin>>sum;

int t[n+1][sum+1];

for(int i=0;i<n+1;i++)
for(int j=0;j<sum+1; j++)
{
  if( i==0  ) t[i][j]=0;            // not possible is 0
  if( j==0) t[i][j]=1;               // empty set is possible which has sum =0 , independetn of no of elements
}

for(int i=1;i<n+1;i++)
  for(int j=1;j< sum+1 ; j++)
	{
          if(a[i-1] <= j)           // option: (include ele/ exclude ele)
          { 
          	t[i][j]=   t[i-1][j-a[i-1]]  + t[i-1][j];    // while we are storing t/f used this :   = t[i-1][j-a[i-1]] || t[i-1][j]; 
                                                       
          }
          else 
          	t[i][j]= t[i-1][j];

	}


cout<<"Count of given sum possible is  : "<<t[n][sum];


	return 0;
}