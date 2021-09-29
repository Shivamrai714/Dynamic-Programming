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


///////////////////////////////

int solve(node* root, int &res)
{ // 1.base cond
   if(root ==NULL) return 0 ;
  
//2.hypothesis
  int l=solve(root->left,res);
  int r=solve(root->right,res);

//3.induction -  temp , ans , res 
    
    //when we need to choose from leaf to leaf, we can neglect -ve value comes in between node, we have to give max all the way possible 

  int temp=max(l,r) +root->data ;                            //passing to upper nodes ( max (left + right + node->val) , node->val) (if child contrubute -ve , take val of node only) 
  int ans =max( temp  , l+r+root->data) ;                  //chking max (temp & itself) is behaving as root ,to form diameter

  // no need of other conditions                     

 res= max(res, ans);

 return temp;          // will return temp (cal passed to upper node) for futher possible ans
                        // max nodes in diameter will be updating in "res"
}




int main()
{          // refer other sources to check input of tree nodes val. 

   /////////

node* root;
        // input from gfg
    root = createnode(-15);

    root->left = createnode(5);

    root->right = createnode(6);

    root->left->left = createnode(-8);

    root->left->right = createnode(1);

    root->left->left->left = createnode(2);

    root->left->left->right = createnode(6);

    root->right->left = createnode(3);

    root->right->right = createnode(9);

    root->right->right->right= createnode(0);

    root->right->right->right->left= createnode(4);

    root->right->right->right->right= createnode(-1);

    root->right->right->right->right->left= createnode(10);


 /////////////


    int res=INT_MIN;
   solve(root,res);
   cout<<"maximum path sum (any nodes) "<<res;
	return 0;
}


//input tree:
/*

               -15
              /    \
            5    *  6
          /  \     /  \ 
         -8   1   3    9
        /  \          /  \    
        2  6              0
                         /  \
                        4    -1
                            /
                           10  *
maximum path sum (any nodes) : 42
*/