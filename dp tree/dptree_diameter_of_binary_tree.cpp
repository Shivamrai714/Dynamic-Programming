#include<bits/stdc++.h>
using namespace std;

//task is to find the diameter of tree (ie largest no of nodes from one leaf to other leaf node)

//////////////////////////////////////

// make binary tree
struct node
{ 
    int data;
    node* left;
    node* right;
};

node* createnode(int data)
{
    node* object = new node();
    object->data=data;
    object->left=NULL;
    object->right=NULL;
}

node* insertnode(node* root, int data)
{
 if(root==NULL)  {root=createnode(data);}
 else if(data <= root->data)  root->left = insertnode(root->left,data); 
 else if(data > root->data  )  root->right = insertnode(root->right,data);

return root;
}

///////////////////////////////

int solve(node* root, int &res)
{ // 1.base cond
   if(root ==NULL) return 0 ;
  
//2.hypothesis
  int l=solve(root->left,res);
  int r=solve(root->right,res);

//3.induction -  temp , ans , res 
   
  int temp= max(l,r)+1;      //passing to upper nodes
  int ans =max( temp  , l+r+1 ) ;                  //chking max (temp & itself) is behaving as root ,to form diameter

 res= max(res, ans);

 return temp;          // will return temp (cal passed to upper node) for futher possible ans
                        // max nodes in diameter will be updating in "res"
}




int main()
{

   /////////

node* root=NULL;

   root=insertnode(root,10);
   root=insertnode(root,5);
   root=insertnode(root,15);
   root=insertnode(root,3);
      root=insertnode(root,40);
      root=insertnode(root,14);
      root=insertnode(root,13);
      root=insertnode(root,12);
      root=insertnode(root,11);




 /////////////


    int res=INT_MIN;
   solve(root,res);
   cout<<"diameter of tree "<<res;
	return 0;
}

//input tree:
/*

                 10
               /    \
              5      15 
            /       /  \ 
           3      14    40
                 /
               13
              /
             12
            /
           11
*/
//output 8 : as diameter of trree