













/*#include<bits/stdc++.h>
using namespace std;

int main()
{                                      // Task is check wheter sum is possible from addtion of el from any of subset of given array.
                                       // To ans in yes or NO
  int n; cin>>n; int a[n];
  int sum; cin>>sum;  
  for(int i=0;i<n;i++) cin>>a[i];

// using the same knapsak variation to use boolean 2 -D matrix
// when only 1 array is given it is equated to wt[] ,neglect val[]  ,, and sum=W(weight of knapsack)
bool t[n+1][sum+1];
 
for(int i=0;i<n+1;i++)
{
for(int j=0;j<sum+1;j++)            // fill 0 row and 0 col using brain.  
{                                     // i refers to (no of ele taken) / n  and j refers to columns (sum possible) = sum(W)
     if(i==0)  t[i][j]=false;
    if(j==0)   t[i][j]=true;  
	                                // make 2-D diagram in copy , (j==0) means 1 column  
}
}

for(int i=1;i<n+1;i++)
	{for(int j=1;j<sum+1;j++)
	{
		if(a[i-1]<=j )
		{                        // we have modified , max of previous code to  ||
              t[i][j] = ( t[i-1][j-a[i-1]]  ||  t[i-1][j] );      //( included / exluded )
		}
          else   // if(a[i-1] > j)
          {
          	t[i][j] = t[i-1][j];
          }

	}
}

for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
	{
		printf("%4d",t[i][j]);
	}
cout<<endl;
}

cout<<endl;
cout<<endl;


if(t[n][sum] == true) cout<<"YEs";
else cout<<"NO";

	return 0;
}

/*
input 
4
4
3 4 5 2 

output

   1   0   0   0   0
   1   0   0   1   0
   1   0   0   1   1
   1   0   0   1   1
   1   0   1   1   1


YEs



*/