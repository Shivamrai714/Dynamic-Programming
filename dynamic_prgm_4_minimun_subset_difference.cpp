#include<bits/stdc++.h>
using namespace std;
int main()
{
  // task is to find the min diff of      s1{} - s2{}  of subsets of array

   // or we can understand like :    abs( s1{}- s2{} ) need to minimum
   
   // we have sloved a prblm where we divided s1{}==s2{}  ,or can say s1{}-s2{}=0
    
// we suppose s1 will be smaller , s1{} + s2{}=range(total sum)
                           // or   s2= range-s1;
						
						// we need to minimize  : s2 -s1 
				// or    we need now to minimise: range-s1 -s1 
				// or         MINIMISE THIS     : (range -2s1)    

// WE HAVE DONE THIS BECAUSE WE HAVE KNAPSAK APPROCH WHERE WE CAN FIND A GIVEN SUM IS PRESENT IN ARRAY SYBSET OR NOT.
// now we will find elements beloing to s1 (0 to n/2) , and put values in above expression to minimise it

int n; cin>>n; 
int a[n];
int range=0;
for(int i=0;i<n;i++) {cin>>a[i]; range+=a[i];}

	int sum=range;
// we have find range of sum (min sum =0,      max sum= sum of all ele  a[] )

// step 1: make a 2D matrix knapsak , to find ele contribute in sum(range) or not  

bool t[n+1][sum+1];
//initialisation of 2D matrix
for(int i=0;i<n+1;i++)
for(int j=0;j<sum+1;j++)
{
	if(i==0) t[i][j]=false;
	if(j==0) t[i][j]=true;
}

// filling all other 


//  IMPROTANT : WE DONT KNOW SUM OF ANY OF SUBSET , SO WE HAVE CALCU. FOR FULL sum AND WILL STORE ELE CONTRIBUTING IN MAX SUM . AND PUT ELE SUM TO GET MIN VAL OD EXP.

for(int i=1;i<n+1;i++)
	for(int j=1;j<sum+1;j++)
	{
        if( a[i-1] <= j)    // option (include/exclude) 
        {
               t[i][j]=( t[i-1][j- a[i-1]] || t[i-1][j] );
        }
        else 
        	t[i][j]=t[i-1][j];
	}

//NO NEED TO GO BY VECTOR APPROCH : STORING ALL ELE OF LAST ROW THEN FINDING MINIMAL VALUE OF EXPRESSION.

 
// we are using the last row of 2D matrix: because it last row has all ele....and columns contains various sum possible.  

// since we asssumed s1 will be smaller sum  , so searching for values fo s1 which will give 
	// minimise the expression range-2*s1

int min_diff=INT_MAX;

	for(int j= sum/2 ;j>=0 ;j--)
	{
    if(t[n][j] == true)                 //means last row ele,,, which contriute true in sum
	  {
	  	// simultanes 1 check required only ,,,,because max sum of S1{} will make the expression minimal
      min_diff= sum- 2 * j;               // where j represtn max sum possible for s1{}
break;
	  }
	}

cout<<min_diff;


	return 0;

}