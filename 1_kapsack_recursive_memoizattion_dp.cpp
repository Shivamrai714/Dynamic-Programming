// knapsack problem by ---- RECURSIVE APPROCH -------> MEMOZIATION -------> D.P
// 3           :n -size of array   
// 50          :W - capacity of knpsk
 // 10 20 30   :weigth array []
// 60 100 120  :val-price array[]

//O/p max profit 


// Method 1: Recursive

/*#include<bits/stdc++.h>
using namespace std;


int knapsack(int wt[],int val[], int W , int n)
{
   // base cond :                                //- think for smallest valid input eg. given array is min of 0 size , and capacity of knapsack is min 0 
                                                 //use mind for both case , we can 't' have any profit so return 0;
	if(n==0 || W==0) return 0;

	// choice diagram            , we are checking from last ele of item given 
    if(wt[n-1] <= W) 
     {
      return max  ( val[n-1] + knapsack(wt,val, W- wt[n-1] , n-1) ,  knapsack(wt,val,W , n-1) );
                       
     }

     else if(wt[n-1] > W)                 // wt[n-1] of ele exceeds capacity, need to exclude , but that [n-1]th  item is processed 
     {                                     // now in recursion we will check other left n-1 ele , as last one ele is cheked in previous step.
     	return knapsack(wt,val,W,n-1);
     }
}


int main()
{
   int n; cin>>n;                // n item are given with , weight and val array[]
   int W; cin>>W;               // W= capacity of knapsack

    int wt[n];int val[n];
// i have made this mistake 10 times.... takes input acc to condtion given, dont use single loop tto take input of both array together.
    // as in ques they are given as indepentdent arrays.

   for(int i=0;i<n;i++) 
   	{ cin>>wt[i];
   	
   	}

 for(int i=0;i<n;i++) 
   	{ 
   	 cin>>val[i];
   	}


// knapsack func will give max profit;
int profit= knapsack(wt,val,W,n); 

cout<<"Max profit is :"<<profit;


	return 0;
}*/
















// Writing memoziation code from down given recursive approch.  // just stroring the values and avoiding the repetive recursive 
//MEthod 2: MEMOZIATION

#include<bits/stdc++.h>
using namespace std;

int static t[100][100];

//memset(t,-1,sizeof t);


// so we add up this code, t[n][W] = ....  that is saving values in 2 D matrix.

int knapsack(int wt[],int val[], int W , int n)
{
   // base cond:
	if(n==0 || W==0) return 0;

    //METHOD 2: Addtion
    if(t[n][W]!=-1)                   //means value is derived from prev calculation.
    	return t[n][W];

	// choice diagram            , we are checking from last ele of item given 
    if(wt[n-1] <= W) 
     {
     	  //METHOD 2: Addtion t[n][W] = 
      return t[n][W] =  max  ( val[n-1] + knapsack(wt,val, W- wt[n-1] , n-1) ,  knapsack(wt,val,W , n-1) );
                       
     }

     else if(wt[n-1] > W)                 // wt[n-1] of ele exceeds capacity, need to exclude , but that [n-1]th  item is processed 
     {                                     // now in recursion we will check other left n-1 ele , as last one ele is cheked in previous step.
     	return t[n][W] = knapsack(wt,val,W,n-1);
     }
}


int main()
{

// code for the global array , to reset it to -1; to visulize teh memoization appproch (D.P)
memset(t, -1, sizeof(t));

//or can use this code. instead for memset().

// for(int i=0;i<100;i++)
// {
// for(int j=0;j<100;j++)
// {
// 	t[i][j]=-1;
// }
// }







   int n; cin>>n;                // n item are given with , weight and val array[]
   int W; cin>>W;               // W= capacity of knapsack

    int wt[n];int val[n];
// i have made this mistake 10 times.... takes input acc to condtion given, dont use single loop tto take input of both array together.
    // as in ques they are given as indepentdent arrays.

   for(int i=0;i<n;i++) 
   	{ cin>>wt[i];
   	
   	}

 for(int i=0;i<n;i++) 
   	{ 
   	 cin>>val[i];
   	}


// knapsack func will give max profit;
int profit= knapsack(wt,val,W,n); 

cout<<"Max profit is :"<<profit;


	return 0;
}



/*
// MEthod 3: 

//ITERATIVE APPROCH -@2


#include<bits/stdc++.h>
using namespace std; 

//-  Aditiya verma youtube
	 const int N=1e4;   // as global array are initializes to 0
	  int t[N][N];
// int knapsack(int wt[],int val[],int n, int W)
// {}


int main()
{

int n; cin>>n;
int W; cin>>W;         // 50         //W=weight of knapsack

int wt[n],val[n];

for(int i=0;i<n;i++)
 { cin>>wt[i];                   // 10 20 30     
                   
}
for(int i=0;i<n;i++)
 {                
 cin>>val[i];                  // 60 100 120
  }

/////////////////////////////////////////////


int t[n+1][W+1];
   // Step 1 make an auxillay array of n+1 and W+1 size  : 
    // Step 2 mark 0 row and 0 col as 0 (or whatever given in base cond of recursion)
	for(int i=0;i<n+1;i++)                              // here base cond of recursive approch is converted to initialization process in top-down dynamic programming.
		for(int j=0;j<W+1;j++)
		{
			if(i==0 || j==0)  t[i][j]=0;
		}
  
   //Step 3 : Fill other left 2-D array
 
 for(int i=1;i<n+1;i++)
 	for(int j=1;j<W+1; j++)             // just put i <-> n from recursive code and j <-> W
 	{
 		if(wt[i-1]<= j)
 		    {
 		 		t[i][j]= max(  val[i-1] + t[i-1][j- wt[i-1] ]   ,  t[i-1][j]   ) ;   // take max(ele included , ele excluded)
 		 	}
  else 
       {
       	 t[i][j]=t[i-1][j];                 //ele not included
       }
    }


cout<<"max profit: "<< t[n][W];

/////////////////////////////////

// int ans=knapsack(wt,val,n,W);
// cout<<ans;

	return 0;
}



*/












