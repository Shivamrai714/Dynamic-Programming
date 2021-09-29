#include<bits/stdc++.h>
using namespace std;

//task is to find maximum path sum ,from any node , so we are not fored to take leaf node
// that is induction step ,while cal. value we will keep check if contribution from left and right child is -ve then neglect them and take the root value itself

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


/*
node* insertnode(node* root, int data)
{
 if(root==NULL)  {root=createnode(data);}
 else if(data <= root->data)  root->left = insertnode(root->left,data); 
 else if(data > root->data  )  root->right = insertnode(root->right,data);

return root;
}*/

///////////////////////////////

int solve(node* root, int &res)
{ // 1.base cond
   if(root ==NULL) return 0 ;
  
//2.hypothesis
  int l=solve(root->left,res);
  int r=solve(root->right,res);

//3.induction -  temp , ans , res 
   
  int temp= max(  max(l,r) +root->data , root->data);                            //passing to upper nodes ( max (left + right + node->val) , node->val) (if child contrubute -ve , take val of node only) 
  int ans =max( temp  , l+r+root->data) ;                  //chking max (temp & itself) is behaving as root ,to form diameter

 res= max(res, ans);

 return temp;          // will return temp (cal passed to upper node) for futher possible ans
                        // max nodes in diameter will be updating in "res"
}




int main()
{          // refer other sources to check input of tree nodes val. 

   /////////

node* root;

  root=createnode(10);
root->left= createnode(2);
root->right= createnode(10);
root->left->left =createnode(20);
root->left->right=createnode(1);
root->right->right =createnode(-25);
root->right->right->left =createnode(3);
root->right->right->right =createnode(4);


 /////////////


    int res=INT_MIN;
   solve(root,res);
   cout<<"maximum path sum (any nodes) "<<res;
	return 0;
}


//input tree:
/*

                10
              /    \
            2       10 
          /  \      /  \ 
         20   1        -25
                       /  \    
                      3   4


maximum path sum (any nodes) : 42
*/