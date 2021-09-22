ONLY A Structue of Unbound knapsak 


//UNBOUND knapsack
// here we can have multiple occurence if ele ,when they are included 
// change will be when we include a ele      t[i] will be writen not t[i-1] ,beacuse it can be again processed, 
// but ele which is excluded is same as it is.

#include<bits/stdc++.h>
using namespace std;

//AIMS is to maximize profit , when items are arr[] and capacity is W , and repetive ele are allowed.

int main()
{
     int n; cin>>n;
     int W; cin>>W;

     int wt[n],val[n];
     for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>val[i];
     
//initailisation.
     int t[n+1][W+1];
     for(int i=0;i<n+1;i++)
     for(int j=0;j<W+1;j++)
     {
     	if(i==0) t[i][j]=0;
       if(j==0) t[i][j]=1;
     } 

     for(int i=1;i<n+1;i++)
     for(int j=1;j<W+1;j++)
     {

      if(wt[i-1]<= W)
      {
      	 t[i][j]= max(val[i-1] + t[i][j-wt[i-1] ] ,   t[i-1][j]   );           //(included   / excluded)   : in included : ele not processed  : val[i-1] +    " t[i] " [ j-wt[i-1] ] 
      }
      else 
      	t[i][j]=t[i-1][j];                               //excluded  , so as it t[i-1][j]  // means ele is preocessed


     } 


   cout<<t[n][sum];

	return 0;

}