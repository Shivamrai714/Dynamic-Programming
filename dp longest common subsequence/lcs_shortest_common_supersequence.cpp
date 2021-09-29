#include<bits/stdc++.h>
using namespace std;
/* task        a: geek 
                b: eke        form the shortest string with contains both these.
              ans.length = "geeke" = 5 o/p  

// very easy concept : when we merge both of them repaeatting char are of LCS(b/t the given two strings) 
// hence  min length after merging is  a+b-LCS(a,b);
*/
int t[1001][1001];


int lcs_length(string a,string b,int m,int n)
{
  // (using memoization   = recursion + matrix )
	// base cond
	if(m==0 || n==0 )  return 0;

	if(t[m][n]!=-1) return t[m][n];     // checking if the value is previously present .

else
   {
        if(a[m-1]==b[n-1]) 
                           return t[m][n]=1+ lcs_length(a,b,m-1,n-1);
    
          else {
                    	return t[m][n]= max(lcs_length(a,b,m-1,n),lcs_length(a,b,m,n-1));
          }
   }

}



void  print_matrix(string a, string b, int m, int n)
{
	for(int i=0;i<m+1;i++)
	{ for(int j=0;j<n+1;j++)
		{
			cout<<t[i][j]<<" ";
		}
           cout<<endl;
	}
}

int main()
{
memset(t,-1,sizeof(t));

  string a,b; cin>>a>>b;
int m=a.size(),n=b.size();
int lcs_len= lcs_length(a,b,m,n);

// minimum len after merging is :
cout<<"Ans ,minimum len:  "<<m+n-lcs_len;

cout<<endl;

print_matrix(a,b,m,n);
cout<<endl;


	return 0;
}