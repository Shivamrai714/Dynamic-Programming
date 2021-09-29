// solving MCM memoized approch

// task : to find minimum cost of multiply of matrices given.
// dimension of matrix is : A[i] = a[i-1] X a[i]; 

 //40 20 30 10 30 

/*  // 5 values in arry = 4 matrix possisble with dimesions
   A=40 X 20
   B=20 X 30
   C=30 X 10
   D=10 X 30
we need to multiply all matrix , by applying brackets 
*/
/*
cost : of multiply(X) a and b is   40 * 20 * 30
*/

// General concepts
// 1. find i and j pos:
// 2. base cond ,where invalid/valid 
// 3. find k loop , loop to find possible pos of partioning
// 4. find temp ans from all possible so and return main ans


#include<bits/stdc++.h>
using namespace std;

int static t[1001][1001];

int solve(int a[],int i,int j)
{  
    int mini=INT_MAX;
   //base cond 
   if(i>j || i==j) return 0; 

   if(t[i][j]!=-1) return t[i][j]; //check in matrix

   
         for(int k=i ; k<=j-1; k++)         //otherwise if k=j no right (ele) sub problem to solve
         {
                  int temp_ans=solve(a,i,k ) + solve(a,k+1,j) + a[i-1]*a[k]*a[j] ;

            if(temp_ans < mini )
               mini=temp_ans;
          
         }
   
return t[i][j]=mini;
}


int main()
{
  memset(t,-1,sizeof(t));

  int n ;cin>>n;
   int a[n];
   for(int i=0;i<n;i++) cin>>a[i];  
  int min_cost=solve(a,1,n-1);
cout<<" Mini cost of MCM : "<<min_cost;


return 0;
}

//
// input:
// 5
// 40 20 30 10 30 
// output:
// 26000