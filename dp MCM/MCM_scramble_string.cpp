//method 2 memoization

#include<bits/stdc++.h>
using namespace std;
 unordered_map<string,bool>m;


bool solve(string a, string b)
{
	//base cond
	if(a.compare(b)==0) return true;     //both str are equal then scramble ,as no swaps done
	if(a.size()<=1) return false;

string key=a; key.push_back(' '); key.append(b);

if(m.find(key)!=m.end()) return m[key];


int n=a.length();

bool flag=false;
for(int i=1;i<=n-1;i++)
{      //  a.substr(start,length)
  //case when (ele swap) / (ele not swapped)  // case 1 swap (compare 1 part, compare 2 part)
 if(   ( (solve(a.substr(0,i), b.substr(n-i,i))==true) && (solve(a.substr(i,n-i),b.substr(0,n-i))==true)
 	   ) 
 	    or  (
         (solve(a.substr(0,i),b.substr(0,i))==true) && (solve(a.substr(i,n-i),b.substr(i,n-i))==true)
       ))
 {
 flag=true; break;
      }


}
return m[key]=flag;
}


int main()
{
	m.clear();

  string a,b;
  cin>>a>>b;

 if(a.size()!=b.size()) cout<<"No";
 // if(a.size()==0) cout<<"No";       //empty 

if(solve(a,b))
 cout<<"Yes Scramble str";
else cout<<"Not";

	return 0;
}

/*
coder
ocder
o/p: Yes
caebd
abcde
o/p: Not

*/
















//////////////////////////////////////////////


/*#include<bits/stdc++.h>
using namespace std;

//Task is to find is it possible to obtain string b from string a , rule for scramble str is str char will be divided in child of binary tree, and swaping of child of non leaf nodes are allowed 
// loop of k to break 
// two options swap childs/not swap

 //case1. when (ele swap) / case2 (ele not swapped)
 // if case1 || case 2 ->true  ,then strings are scramble
 //in case 1, we comapre 1 part with last part of b string
 //in case 2 we compare 1 part with 1 part of b string as no swap involved.  


bool solve(string a, string b)
{
	//base cond
	if(a.compare(b)==0) return true;     //both str are equal then scramble ,as no swaps done
	if(a.size()<=1) return false;
int n=a.length();

bool flag=false;
for(int i=1;i<=n-1;i++)
{      //  a.substr(start,length)
  //case when (ele swap) / (ele not swapped)  // case 1 swap (compare 1 part, compare 2 part)
 if(   ( (solve(a.substr(0,i), b.substr(n-i,i))==true) && (solve(a.substr(i,n-i),b.substr(0,n-i))==true)
 	   ) 
 	    or  (
         (solve(a.substr(0,i),b.substr(0,i))==true) && (solve(a.substr(i,n-i),b.substr(i,n-i))==true)
       ))
 {
 flag=true; break;
      }


}
return flag;
}


int main()
{
  string a,b;
  cin>>a>>b;

 if(a.size()!=b.size()) cout<<"No";
 // if(a.size()==0) cout<<"No";       //empty 

if(solve(a,b))
 cout<<"Yes Scramble str";
else cout<<"Not";

	return 0;
}

/*
coder
ocder
o/p: Yes
caebd
abcde
o/p: Not

*/