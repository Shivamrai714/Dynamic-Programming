#include<bits/stdc++.h>
using namespace std;

// Task is to cut Rod of given length N into some pieces (price of pieces is also given) 
// ... we need to cut as many pieces so profitt is maximised.

// it is unbound knapsack because ,,,, many piece of same length are possible.

// here : one price array is given price[] , and Lentgth of rod N 
// we can construct , lenght array ,when not given    L{1,2,3,4,5,6...N}

/*// Similarity

lenght[]            --> wt[]             
// ... sometimes lenght[a,b,c,d] is given in Ques . ie which lengh can be cut are given.   , then n=lenght.size();

price[]             --> val[]
lenght_of_rod_(N)   --> W  (knapsack capacity)

*/

int unbound_knapsack(int lenght[],int price[],int L,int n)
{

   int t[n+1][L+1];
   for(int i=0;i<n+1;i++)
     for(int j=0;j<L+1;j++)
     {
          if(i==0 ) t[i][j]=0;
               if(j==0 ) t[i][j]=0;
     }

for(int i=1;i<n+1;i++)
     for(int j=1;j<L+1;j++)
     {

          if(lenght[i-1]<= j)
          {
               t[i][j]= max( price[i-1]+  t[i][j- lenght[i-1]] , t[i-1][j] );
          }
          else
               t[i][j]=t[i-1][j];
     }

return t[n][L];

}

int main()
{
      int n ;cin>>n;
      int price[n];
      for(int i=0;i<n;i++)cin>>price[i]; 
 
 int L; cin>>L;                  //FULL LENGHT OF ROD

//since lenght array is not given manually constructing it.
                                     //as size() of price[] = length[L]
      int lenght[L];
      for(int i=0;i<L;i++) lenght[i]=i+1;   //{1,2,3,4,    ,L}


int profit= unbound_knapsack(lenght,price,L,n);            //knapsack(wt,val,W,n)


cout<<"MAx profit  : "<<profit;


     return 0;
}

















































/*
int main()
{
     int n; cin>>n;           //size of array_given=price[] array
     
int price[n];
    for(int i=0;i<n;i++) cin>>price[i];

//int L; cin>>L;          // total lenght of Rod (L) = N        ===W(knapsack)
int N=n;        //when in ques lenth[] not given ,we make full lenght array as full length of rod

// manually making length[1,2,3,4,5,6,7,8]  for lenght of rod N size
int  length[N];
for(int i=0;i<N;i++) {length[i]=i+1;}

// for(int i=0;i<N;i++)
// cout<<length[i];

// return 0;


//initailisation.

     int t[n+1][N+1];                       // size of length[]  vs sum possible[0 - N] .

     for(int i=0;i<N+1;i++)
     for(int j=0;j<N+1;j++)
     {
     	if(i==0) t[i][j]=0;           // as t[0][0], t[0][3]   .means there is no ele in length_arr[], so how could sum will come 2,3 
          if(j==0) t[i][j]=0;    //as t[1][0] ,t[2][0]  means ele are 1,2 present but , they dont have lenght as 0
     } 

     for(int i=1;i<N+1;i++)
     for(int j=1;j<N+1;j++)
     {
                                              // just change wt[] <--> length[]    , val[] <--> price[]  ,
                        // *  //doing mistake here 
      if(length[i-1] <= j )                   //N is L of rod , which is binding cond  // piece of rod cant be grter then total L (N)
      {
      	 t[i][j]= max(price[i-1] + t[i][j-length[i-1]] , t[i-1][j] );           //(included   / excluded)   : in included : ele not processed  : val[i-1] +    " t[i] " [ j-wt[i-1] ] 
      }
      else 
      	t[i][j]=t[i-1][j];                               //excluded  , so as it t[i-1][j]  // means ele is preocessed


     } 


   cout<<t[N][N];

	return 0;

}*/