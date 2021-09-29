//Method: 2 using memozation: just use matrix to avoid same recursive calls

#include<bits/stdc++.h>
using namespace std;
 int t[1001][1001];

int LCS(string a,string b, int m ,int n)
{
  //base cond ()
  if(m==0 || n==0) return 0;

  if(t[m][n]!=-1) return t[m][n];        // already present 

  else
   {
      if(a[m-1]==b[n-1]) return  t[m][n]= 1+ LCS(a,b,m-1,n-1);      // yes same chareter +1 to include in length
      
      else
      {
         return t[m][n]= max( LCS(a,b,m-1,n), LCS(a,b,m,n-1));
      }      


   }

}
                             

string print_lcs(string a,string b, int m, int n)
{
  int i=m,j=n;
   string ans="";
  while(i>0 && j>0)
  {
    
     if(a[i-1] == b[j-1])            //here we are checking the last ele of each given array of size m and n , so last ele of each will be a[m-1] and a[n-1] , i=m, j=n already initiallised
       {    i--; j--; 
       // ans.push_back(a[i]);
         ans +=a[i];  
           }                 //it has come from diagonal +1 val in table                
     else
     {      //this has come from max of pre col(,)
       if( t[i-1][j] > t[i][j-1] )
            i--;
       
       else 
        j--;
    
     }

  }


return ans;
}


int main()
 {
    memset(t,-1,sizeof(t));

              string a; string b;
              cin>>a;
               cin>>b;
              int m=a.size(); int n=b.size();
              //Task to find length longest common subsequence, ans : abdg 
              int ans=LCS(a,b, m,n);
              cout<<"lenght of lcs : "<<ans<<endl;

for(int i=1;i<m+1;i++)
{
  for(int j=1;j<n+1;j++)
  {
    cout<< t[i][j]<<" ";
  }
  cout<<endl;
}
    cout<<endl;
    cout<<endl;



cout<<"Print lcs :  ";
string str=print_lcs(a,b,m,n);

reverse(str.begin(),str.end());
cout<<str;


          return 0;
}











/*//Method 1.using recursion

#include<bits/stdc++.h>
using namespace std;

int LCS(string a,string b, int m ,int n)
{
	// we are checking from last char
	// recursion : base cond (small valid input)  , choice diagram, call on small inputs
   if(m==0 || n==0) return 0;

   else 
   {
     if(a[m-1]==b[n-1])  return 1+LCS(a,b,m-1,n-1);

     else
     {
     	return max( LCS(a,b,m,n-1) , LCS(a,b,m-1,n) );
     }

   }


}


                                      
        int main()
        {
              string a; string b;
              cin>>a; cin>>b;
              
              //Task to find length longest common subsequence, ans : abdg 
              int ans=LCS(a,b,a.size(),b.size());
              cout<<"lenght of lcs : "<<ans;
        



        	return 0;
        }*/






