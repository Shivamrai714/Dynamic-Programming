/*
Using recursion: 1


#include<bits/stdc++.h>
using namespace std;

unbound_kapsack(int a[],int n,int sum)
{
   // base cond of recursion
	if(n==0 )  return 0  ;
		if(sum==0) return 1 ;

if( a[n-1]<= sum )          //(include/ exclude)
 {
     //code of kanpsack:  return max( val[n-1] + unbound_kapsack(a,n-1,sum-a[n-1])  , unbound_kapsack(a,n-1,sum));
    // but for unbound knapsack  wt[] <--> a[]    , val[] <-->  X   , W  <--> sum  

    return (unbound_kapsack(a,n,sum-a[n-1]) +  unbound_kapsack(a,n-1,sum));

 }
else 
	return unbound_kapsack(a,n-1,sum);   //(excluded) 

}

int main()
{
                                        // Task is to find the no of ways possible to get sum (by addtion if coins) (repeated coins are alllowed)
   int n; cin>>n;int a[n];

   for(int i=0;i<n;i++) cin>>a[i];
   int sum;cin>>sum;

  // 


int no_of_ways=unbound_kapsack(a,n,sum);

cout<<" Max no_of_ways :"<<no_of_ways;

	return 0;
}*/




// Method : 2 using D.p

#include<bits/stdc++.h>
using namespace std;


unbound_kapsack(int a[],int n,int sum)
{
//initialisation
   int t[n+1][sum+1];
   for(int i=0;i<n+1;i++)
   	for(int j=0;j<sum+1;j++)
   	{

   		if(i==0)  t[i][j]=0;           // when 0 ele are given ,, sum 1,2 , is not possible
   		if(j==0)  t[i][j]=1;              // when many ele are given , to get sum 0 , yes it is posssible by taking { empty } set
   	}

//fill other matrix

for(int i=1;i<n+1;i++)
	for(int j=1;j<sum+1;j++)
	{
		if(a[i-1]<=j)
		{
			t[i][j]=( t[i][j- a[i-1]] +  t[i-1][j]);       //( when included t[i][]   not t[i-1][]   because ele can be processed agin in unvlounded kapsak  )
		}                                                // when excluded , no worries.
	else 
	{
		t[i][j]=t[i-1][j];
	}
	}

return t[n][sum];
}

int main()
{

	                                     // Task is to find the no of ways possible to get sum (by addtion if coins) (repeated coins are alllowed)
   int n; cin>>n;int a[n];

   for(int i=0;i<n;i++) cin>>a[i];
   int sum;cin>>sum;


int no_of_ways=unbound_kapsack(a,n,sum);

cout<<" Max no_of_ways :"<<no_of_ways;


	return 0;
}