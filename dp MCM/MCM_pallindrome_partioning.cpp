/*// Method 1: recursive approch



#include<bits/stdc++.h>
using namespace std;
// s: nitin  o/p=2     n | iti | n
// here we need to find the min no of partition need in given string to make it pallindrome.

// General concepts
// 1. find i and j pos:
// 2. base cond ,where invalid/valid 
// 3. find k loop , loop to find possible pos of partioning
// 4. find temp ans from all possible so and return main ans

bool ispallindrome(string a,int i,int j)
{   int r=0;
	int length= j-i+1;
    for(int v=0+i; v< (length/2)+ i ; v++)    //v<=(length/2)+ i , no problem just again checkning 
    {
    	if(a[v]!= a[j-r]) return false;
    	else r++;
    }
    return true;
}

int solve(string a, int i, int j)
{
    //base cond
    if(i>=j) return 0;          // all processsed
    if(ispallindrome(a,i,j)==true) return 0;          //no more parttion                      

    int mini=INT_MAX;

   //loop of k to check partitions at various pos:
  int temp_ans; 
   for(int k=i ; k<= j-1 ; k++ ) 
    {
        temp_ans = 1 + solve(a,i,k) + solve(a,k+1,j);   // 1 is for partion in main string  ,then sub problems are solved
        mini=min(mini,temp_ans);
    }
return mini;
}


int main()
{
 string a; cin>>a;
int n=a.size();
int min_partition=solve(a,0,n-1);           // pos to start , i and j
cout<<"Partitions req : "<<min_partition;
	return 0;
}
*/

/*
i/p:
lilsts
o/p:
Partitions req : 1
*/





// Method 2: Memoizised approch

#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001];
bool ispallindrome(string a,int i,int j)
{  
  int r=0; int len=j-i+1;
  for(int v=i;v<len/2 +i ; v++)
  {
    if(a[v]!=a[j-r])  return false;
    else r++;
  }
return true;
}

int solve(string a, int i, int j)
{   
       int mini=INT_MAX;
   // base cond
    if(i>=j) return 0;
    if(ispallindrome(a,i,j)) return 0;  //alredy pallindrome ,no need more  partion so return 0;

    if(t[i][j]!=-1) return t[i][j];


       for(int k=i;k<=j-1;k++)
       {
         int temp_ans= 1+ solve(a,i,k)+solve(a,k+1,j);
         
         // for each temp_ans cal by partition at k pos ,we store 
          
         mini=min(mini,temp_ans);           
       
       }  
          
    
   
return t[i][j]=mini;
}


int main()
{  
    memset(t,-1,sizeof(t));
string a; cin>>a;
int n=a.size();
int min_partition=solve(a,0,n-1);           // pos to start , i and j
cout<<"Partitions req : "<<min_partition;
	return 0;
}






