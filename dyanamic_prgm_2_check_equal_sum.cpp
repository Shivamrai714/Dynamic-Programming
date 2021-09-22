/*#include<bits/stdc++.h>
using namespace std;
int main()

{
b
cout<<"hi";
	return 0;}*/
#include<bits/stdc++.h>
using namespace std;
bool check_subset_sum(int a[],int sum,int n)
{
   int t[n+1][sum+1];
//initialisation
   for(int i=0;i<n+1;i++)
   	for(int j=0;j<sum+1;j++)
   	{
   		if(i==0) t[i][j]=false;
   		if(j==0) t[i][j]=true;
   	}

// rrmaining table

   for(int i=1;i<n+1;i++)
   	for(int j=1;j<sum+1;j++)
   	{
                                   // here i is n    and  j is W 
      if( a[i-1] <= j)             //chk last ele wt < knapsak wt
     {                                   // a[n-1] is last ele because a[n-1] is last index of array a[]
 
      t[i][j]= ( t[i-1][j-a[i-1]] )  || ( t[i-1][j] );      //(included /excluded)  ... [n-1] as ele is preocesed    
     }
      else               // wt is more not inlcuded 
      {
       t[i][j] = t[i-1][j];
      }

   	}

   	
return t[n][sum];

}

int main()
{ 
    //Task is to find out whether subset can be formed of given arrray in two equal sum.
	// s1 { , , }  = s2 { , , }              // or s1{} -s2{}=0
	int n; 
   cin>>n;
	int a[n];
	for(int i=0 ;i<n ;i++) cin>>a[i];
    
                    // {1,5,5} = {11}
                    //YEs
int sum=0;
for(int i=0;i<n;i++) sum+=a[i];

if(sum%2!=0) cout<<"NO";  // odd sum can't be equalyy divided
else                       //sum is even ,can be posssible
 {
     // we are checking sum/2 is present as {, ,} in array if it is present remainning of array ele will give s2.                      

if(check_subset_sum(a,sum/2,n) == true)
 cout<<"Yes equal sum partition possible";

else cout<<"Not possible";

 }
 
	return 0;
}


