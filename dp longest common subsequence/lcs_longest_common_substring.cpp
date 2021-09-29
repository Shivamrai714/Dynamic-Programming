
// the only diffence here  is that substring will be continous order of ele, where as sub sequence can be non continous

#include<bits/stdc++.h>
using namespace std;
int t[1000][1000];
int x;
int res=0;
int LCSS(string a,string b, int m ,int n)
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

// filling other  data

for(int i=1;i<m+1;i++)
  for(int j=1;j<n+1;j++)
  {
                // compare the last ele of given str
     if(a[i-1]==b[j-1]) 
     {
        t[i][j]=1+ t[i-1][j-1];            //1+ we have included it
        
        //res=max(res,t[i][j]);
          if(t[i][j] > res) 
            { res=t[i][j];  x=i;}

     }

     else
     {        t[i][j]= 0;   
     }  

  }

return res;

}
///////////////////////////////////

string print_lcs(string a,string b,int m,int n)
{
  string s="";

int i=x;
while(res--)
{     i--;
  s.push_back(a[i]);
}

return s;
}

     ///////////////////////////

void print_matrix(string a, string b,int m,int n)
{
   for(int i=1;i<m+1;i++)
    { for(int j=1;j<n+1;j++)
     {
           cout<<t[i][j]<<" ";
     }cout<<endl;
  }

}








        int main()
        {
              string a; string b;
              cin>>a; cin>>b;
              
              //Task to find length longest common sub - STRING , ans : bc 
              int ans=LCSS(a,b,a.size(),b.size());
              cout<<"lenght of lcss (substring) : "<<ans;
        cout<<endl;
          
        //  print_matrix(a,b,a.size(),b.size()) ;

cout<<endl;
cout<<x<<" "<<res;

cout<<endl;
cout<<endl;

        string ans_print=print_lcs(a,b,a.size(),b.size());;
         reverse(ans_print.begin(),ans_print.end());
        cout<<"Printing LCS : "<<ans_print;


        	return 0;
        }