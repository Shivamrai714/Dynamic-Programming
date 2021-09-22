#include<bits/stdc++.h>
using namespace std;

//  Task is to assing +/- sign in ele given in arr[], such that sum of all comes to given sum
//And  find the count of such subset{} possible.
//  this is same problem to count No of subset which given diff given

//because eg {1 , 1, 2, 3} no after assign sign 
//  {+1, -1, -2, +3 } this gives net sum as +1
// it is same as s1 of + ve no s1 +{1 ,3} and of -ve no  s2 -{1,2}
// adding them means     (+s1{})  + (-s2{})  basically  s1-s2 only 




int count_subset_sum(int a[],int n, int sum)
{
   int t[n+1][sum+1];

//intialization.
   for(int i=0;i<n+1;i++)
   	for(int j=0;j<sum+1;j++)
   	{   //think in brain pratically t[0][0],t[0][1] ,wrt to 2D matrix
   		  // t[ele of array avilable][sum possible]
   		if(i==0) t[i][j]=0;
   		if(j==0) t[i][j]=1;                  //t[2][0], t[3][0]       ,,yes empty set is possible
   	}

//filling rest matrix

for(int i=1;i<n+1;i++)
for(int j=1;j<sum+1;j++)
{
    if(a[i-1] <= j)       //chk of last ele wt. <= W(capacity kapsk) 
    {

        t[i][j]= t[i-1][j-a[i-1]] + t[i-1][j];
    }
    else
    	t[i][j]=t[i-1][j];


}

return t[n][sum];
}
 
int main()
{
	int n; cin>>n; int a[n];
	int sum_T=0;
	for(int i=0;i<n;i++) 
		{cin>>a[i];
          sum_T+=a[i];
		}

    // int diff; cin>>diff;
  int sum_given; cin>>sum_given;
                                                               // 1 eq :   s1{}-s2{}= diff
                                                           // comman sense   // 2 eq:   s1{}+s2{}= sumT(all ele)                                     
                              
                                                    // using maths               s1= (diff + sum_T)/2       

int sum_s1= (sum_given + sum_T)/2;


// now we have s1 and we know a function which can search for a sum of subset is possible or not in a given array.and it can also give count of such subsets.

 int ans=count_subset_sum(a,n,sum_s1);
    
cout<<"count of subset (pair s1{},s2{}) possible of given diff are :"<<ans;

	return 0;
}

/*
input:
4
1 1 2 3
1

o/p
count of subset (pair s1{},s2{}) possible of which gives net sum as: given are :3*/