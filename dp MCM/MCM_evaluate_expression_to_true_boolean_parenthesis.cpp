
// Method 2: MemoiZation

//HERE changing var are 3 , w(i,j,istrue) ,we need to make 3 D matrix, or can use map

#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int>m;

int solve( string s, int i,int j,bool istrue)
{
   //base cond 
	if(i>j) return 0;
	if(i==j)
		   {           //means last ele , we need true so if T is stored in it then 1 will be return else 0
		   	if (istrue==true) return (s[i]=='T');
		   else if(istrue==false) return (s[i]=='F');     //means we need false ,so 1 will be return when ele contains F in it.
		   }

   // also need to check in map if already present, so we need to make key of this exp,to search in map

string key= to_string(i);             /////////   //to_string
key.push_back(' ');
key.append(to_string(j));
key.push_back(' ');
key.append(to_string(istrue));

   if(m.find(key)!=m.end()) return m[key];


//else we need to cal

   int ans=0;

   for(int k=i+1; k<=j-1; k=k+2)
   {
      int lT= solve(s,i,k-1,true);
      int lF= solve(s,i,k-1,false);
      int rT= solve(s,k+1,j,true);
      int rF= solve(s,k+1,j,false);

      if(s[k]=='&')
      {
      	if(istrue==true) { ans =ans+ (lT*rT);}
      else if(istrue==false) {ans=ans + (lF*rT)+ (lT*rF)+ (lF*rF) ; }
      }
        
      if(s[k]=='|')
      {
      	if(istrue==true) { ans =ans+ (lT*rT) + (lF*rT)+ (lT*rF);}
      else if(istrue==false) {ans=ans + (lF*rF) ; }
      }

      if(s[k]=='^')
      {
      	if(istrue==true) {ans=ans+ lT*rF + lF*rT ;}
            else if(istrue==false) {ans=ans+ lT*rT + lF*rF ;}
      }



   }





return m[key]=ans;



}






int main()
{
   m.clear();


   string s; cin>>s;
   int n=s.size();

   int ans=solve(s,0,n-1,true);              //passed true, because we need true as final ans.

cout<<"No of ways to make expressio as true is "<<ans;


	return 0;
}


//


















/*// Method 1: recursive

// tASK FIND NO OF WAYS IN WHICH GIVEN EXPRESSION CAN BE TRUE

// Exception here we need to pass the 3 var here , to chk TRUE or FALSE value is passed , 
// when we divide main into sub problems , we have to keep track of both when try are T and When false 
// as tem_ans comes from :    solve() + solve + (1 opration of main string)
// and this main opration can ve xor, and ,or whick can be true under diff cond of true false , to make final ans as true;

#include<bits/stdc++.h>
using namespace std;
// task we are given a string s: T^F&T    task is to evaluate this exp to true by applying brackets;

//similar to MCM , we need to do selection to put brackets such that final ans true
// Approch
// select i and j  , i=0, j=n-1
// select base cond ,  i>j -> 0  , i==j  means single ele,so return T if t, else false
// loop of k on operators ,  k=i+1 ,k<j-1; k=k+2 , move to each oprator to apply bracketts and solve 
// recursive solve (i to k-1 ) and solve ( k+1,j) ,as at k pos operator is present    


int solve(string s, int i,int j,bool istrue)
{
		  //base cond 
			if(i>j) return 0;
			if(i==j)           //single char ,depends on value of istrue
			{  
				if(istrue==true) return  ( s[i]=='T');     //if s[i] is true the 1(true) will be returned
		        
		         else //(istrue==false)
		         	return s[i]=='F';
			}
int ans=0;
			// loop of k for(operator )
for(int k=i+1; k<=j-1; k=k+2)
{
   					// we can have 4 diff ans possible for 2 sub problems generated + we need process operator of main string which given these 2 sub problems

				int lT= solve(s,i,k-1,true);
				int lF=solve(s,i,k-1,false);

				int rT=solve(s,k+1,j,true);
				int rF=solve(s,k+1,j,false);

				// now we have processseed the sub problems,now cal a temp ans for
				// main operator + solve() (2 cases) + solve() (2 cases)
				// main operator can be &,^,|            as we need final as true, so cal when these operator will give true ans.

		if (s[k]=='&')
		{
  		 if(istrue==true)        // need tto chk when true posssible
  			 {
  		 	 ans=ans + (lT*rT);
 			  }
					   else if(istrue==false)     //used in case of or,^ to make statemnt T
					   {
			   	ans=ans+ ( lT*rF + lF*rT + lF*rF);
			   }
			}

				if(s[k]=='|')
				{
				   if(istrue==true)        // need tto chk when true posssible
				   {
				   	 ans=ans + (lT*rT  + lT*rF + lF*rT);
				   }
				   else if(istrue==false)     //used in case of or,^ to make statemnt T
				   {
				   	ans=ans+ (lF*rF);
				   }
				}

			if(s[k]=='^')
			{
			   if(istrue==true)        // need tto chk when true posssible
			   {
			   	 ans=ans + (lT*rF  + lF*rT );
			   }
			   else if(istrue==false)     //used in case of or,^ to make statemnt T
			   {
			   	ans=ans+ (lF*rF + lT*rT);
			   }
			}


}

return ans;

}


int main()
{
  string s; cin>>s;
  int n=s.size();

int ans=solve(s,0,n-1,true);              //passed true, because we need true as final ans.
cout<<"No of ways to make expressio as true is "<<ans;

	return 0;
}

// I/P:
// T|T&F^T
// O/P:
// No of ways to make expressio as true is 4



*/




///////////////////////////////////////////////////////////////////////////////////////






