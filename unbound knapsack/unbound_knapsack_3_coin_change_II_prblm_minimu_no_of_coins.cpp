

// Method : 2 using D.p

#include<bits/stdc++.h>
using namespace std;


unbound_kapsack(int a[],int n,int sum)            // a[]= same as coins[]
{
//initialisation
   int t[n+1][sum+1];
   for(int i=0;i<n+1;i++)
   	for(int j=0;j<sum+1;j++)
   	{
         //base cond:
         //if elements =0  in array ,,,,, then to get sum hypothetically we need INT_MAX-1 coins
         //if sum=0   , return 0  yes possible indepentdent of no of ele 
         //we need 0 coins to get 0 sum 
         // here min no of coins is so need to think wisely with brain, not no_of_way is asked to get sum=0       

          if(i==0)  t[i][j] = INT_MAX-1 ;                    // we are storing MAX-1 , (because we are storing the min_count ) so need to do +1 , if we are including ele
           if(j==0)  t[i][j]=0;
     	}

// Initialisation 2.

//fro this exceptional case we need to 2 initialisation of 2 row.
//eg let  a[3,4,5]   , fill t[1][3] = ie 1 ele in a['3'] and sum(j) requeied is 3 , so yes possible  . so store     t[i][j]= j/a[0];
//  and                     t[1][4]   ie a['3'] ,and sum(j) required is 4 , so not posible ,fill hypothetically by INT_MAX-1;

for(int i=1,j=1;j<sum+1;j++)
     	{
         if(j%a[0]==0) t[i][j]= j/a[0]; 
         else
         t[i][j]=INT_MAX-1;    
     	}

//fill other matrix

for(int i=2;i<n+1;i++)
for(int j=1;j<sum+1;j++)
	{

      if(a[i-1]<= j)
      {                        // we are req. to find min no of coins possible.

      	t[i][j]=  min ( t[i][j- a[i-1]] +  1   , t[i-1][j]  );     //(included  , excluded)
      }
      else 
      {
      	t[i][j]=t[i-1][j];                 // excluded
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


int minimum_no_of_coins=unbound_kapsack(a,n,sum);

cout<<"minimum_no_of_coins:"<<minimum_no_of_coins;


	return 0;
}