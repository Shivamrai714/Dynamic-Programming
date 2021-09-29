
#include<bits/stdc++.h>
using namespace std;
int t[1000][1000];
int x;
int res=0;
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

// filling other  data

for(int i=1;i<m+1;i++)
  for(int j=1;j<n+1;j++)
  {
                // compare the last ele of given str
     if(a[i-1]==b[j-1]) 
         t[i][j]=1+ t[i-1][j-1];            //1+ we have included it
        
       else 
       {
          t[i][j]= max(t[i-1][j], t[i][j-1]);
       }
 }
     

return t[m][n];

}
///////////////////////////////////

string print_scs(string a, string b,int m,int n)
{
  string s="";
int i=m,j=n;

  while(i>0 && j>0)
  {
     if(a[i-1] == b[j-1]) 
       {
      s.push_back(a[i-1]);     ///
          i--; j--;       
      }
     
     else 
     {
          if(t[i][j-1] > t[i-1][j]) 
             { s.push_back(a[i-1]);  j--;}

          else if(t[i-1][j] > t[i][j-1])
            {s.push_back(b[j-1]);  i--; } 
                                                            // include other ele , and go to max of the 
            
    }
  }

while(i>0)
{
  s.push_back(a[i-1]); i--;
}


while(j--)
{
  s.push_back(b[j-1]);j--;
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
     } cout<<endl;
  }

}








        int main()
        {
              string a; string b;
              cin>>a; cin>>b;
              int m=a.size(),n=b.size();
      
              //Task to find length longest common sub - STRING , ans : bc 
             int ans=LCS(a,b,a.size(),b.size());
              cout<<"lenght of lcs (subsequence) : "<<ans;
        cout<<endl;
          
    //      print_matrix(a,b,a.size(),b.size()) ;

           cout<<"lenght of  min_len (super_sequence) : "<<m+n-ans;

cout<<endl;
cout<<endl;
cout<<endl;

        string ans_print=print_scs(a,b,a.size(),b.size());
         reverse(ans_print.begin(),ans_print.end());
        cout<<"Printing SCS : "<<ans_print;


        	return 0;
        }