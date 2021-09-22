/*#include<bits/stdc++.h>
using namespace std; 

// Recursive approch -  Aditiya verma youtube

int knapsack(int wt[],int val[],int n, int W)
{
   if(n==0 || W==0) return 0;

  if(wt[n-1] <= W)                                    // wt of ele is less then W ,then option is there to include/exclude
  {
       return max(     val[n-1]+ knapsack(wt,val, n-1, W-wt[n-1] )  ,          // ele included and itts wt is - from W
                    knapsack(wt,val,n-1,W)                                     // not include the ele
       	         );
  }
  else if(wt[n-1]> W)
  {           // wt of ele > W (kanpsak capa) , only need to exclude it.

return knapsack(wt,val,n-1,W);                  // n-1 ele has been processed 
  }



}


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


int ans=knapsack(wt,val,n,W);
cout<<ans;

	return 0;
}

//INPUTS 
//3
// 50
// 10 20 30 
// 60 100 120

//OUTPUT 
// 220
// max profit 
*/





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



