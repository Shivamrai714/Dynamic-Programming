// In dynamic programming we jsut need to make table of the recursion approch 
// initalizate it using base condition
//fill other using choice diagram



#include<bits/stdc++.h>
using namespace std;
int t[1000][1000];
int LCS(string a,string b, int m ,int n)
{
	// we are checking from last char
// in dp just we make matrix  and rest same as teh memoization

t[m+1][n+1]={0};
//initiallisation wrt base cond of recursion(mini valid input possible)  

for(int i=0;i<m+1;i++)
for(int j=0;j<n+1;j++)
  {
    if(i==0 || j==0 ) t[i][j]=0;      // if any 1 str is "" then LCS will also be ""
  }

string s="";
for(int i=1;i<m+1;i++)
  for(int j=1;j<n+1;j++)
  {
     // compare the last ele of given str
     if(a[i-1]==b[j-1]) 
     {
        t[i][j]=1+ t[i-1][j-1];            //1+ we have included it
     }

     else
     {

         //n two possible 
      t[i][j]= max  ( t[i-1][j] , t[i][j-1]  );     

     }  

  }
return t[m][n];

}

string print_lcs(string a,string b,int m,int n)
{
  string s="";

int i=m,j=n;
while(i>0 && j>0)
{
  if(a[i-1] == b[j-1])
  {
    // push in string this ele
    s.push_back(a[i-1]);
   //now go back to diagonal above ele
    i--; j--;
  }
  else
  {
      // go to max of prev ele
      if(t[i-1][j] > t[i][j-1] )
       i--;
        else
         j++;

  }


}

return s;
}

                                      
        int main()
        {
              string a; string b;
              cin>>a; cin>>b;
              
              //Task to find length longest common subsequence, ans : abdg 
              int ans=LCS(a,b,a.size(),b.size());
              cout<<"lenght of lcs : "<<ans;
        cout<<endl;
        string ans_print=print_lcs(a,b,a.size(),b.size());;
        reverse(ans_print.begin(),ans_print.end());
       cout<<"Printing LCS : "<<ans_print;


        	return 0;
        }