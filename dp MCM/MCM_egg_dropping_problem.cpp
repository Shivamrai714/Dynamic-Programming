// method 2: memoized approch

#include<bits/stdc++.h>
using namespace std;
int static t[1001][1000];
//  task : here we need to throw egg from various level in porder to detemine threshold floor (egg brokes )
// FIND teh min no of attempts

int solve(int e,int f)
{
  //base cond
	if(f==0 || f==1) return f;
	if(e==1) return f;              // we will start from bottom floor ,so in worst case need to do f throws

if(t[e][f] !=-1) return t[e][f];


 int mini=INT_MAX;

 for(int k=1; k<=f ;k++)
 {       // to avoid direct call , we can also search sub problems
     int low,high;
 	    if(t[e-1][k-1]!=-1) 
 		 low=t[e-1][k-1]; 
        else
 		{ low=solve(e-1,k-1);
 		 t[e-1][k-1]=low;
 		}
 	
    if(t[e][f-k]!=-1)
    	 high=t[e][f-k];
    		else 
    		{
    			high=solve(e,f-k);
                t[e][f-k]=high;
    		}

 	int temp=1+max(low,high);
 	mini=min(mini,temp);
 }
return t[e][f]=mini;
}


int main()
{
	memset(t,-1,sizeof(t));
	int e,f; 
	cin>>e>>f;   //3 //7

 int ans=solve(e,f);
  cout<<"Minimum attempts "<<ans;

	return 0;
}








/*#include<bits/stdc++.h>
using namespace std;

//  task : here we need to throw egg from various level in porder to detemine threshold floor (egg brokes )
// FIND teh min no of attempts

int solve(int e,int f)
{
  //base cond
	if(f==0 || f==1) return f;
	if(e==1) return f;              // we will start from bottom floor ,so in worst case need to do f throws

 int mini=INT_MAX;

 for(int k=1; k<=f ;k++)
 {
 	int temp=1+ max(solve(e-1,k-1) , solve(e,f-k));
 	mini=min(mini,temp);
 }
return mini;
}


int main()
{
	int e,f; 
	cin>>e>>f;   //3 //7

 int ans=solve(e,f);
  cout<<"Minimum attempts "<<ans;

	return 0;
}*/

/*//i/p:
2 
10

o/p
4*/