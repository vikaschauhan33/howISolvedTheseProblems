/*
* Code to find first occurance of an element in a BST
* Hint : Inoreder traversal returns the values in sorted (Asc) oreder.
*/

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

struct binaryTreeNode{
  int val;
  binaryTreeNode* left;
  binaryTreeNode* right;

  binaryTreeNode(int v): val(v),
                        left(nullptr),
                        right(nullptr){};
};

binaryTreeNode*  findFirstOfVal(binaryTreeNode* root, const int val){
  if(nullptr == root)
    return nullptr; //Base case

  if( root->val == val ){//If value found search in left subtree;
    binaryTreeNode* res = findFirstOfVal(root->left, val);
    return res ? res : root;
  }
return findFirstOfVal(root->val < val ? root->right : root->left, val);
}


int main(){
  /* Tree 1
  *                   20
  *                10    30
  *               5  25
  */
  binaryTreeNode* root = new binaryTreeNode(20);
  root->left = new binaryTreeNode(10);
  root->right = new binaryTreeNode(30);
  root->left->right = new binaryTreeNode(15);
  root->left->left = new binaryTreeNode(5);

  //Test value NOT in  BST
  assert(nullptr == findFirstOfVal(root, 300));

  cout<< "Test 1 : Value not present : Passed\n";

  /* Tree 2
  *                   20
  *                10    20
  *               5  15
  */
  binaryTreeNode* root1 = new binaryTreeNode(20);
  root1->left = new binaryTreeNode(10);
  root1->right = new binaryTreeNode(25);
  root1->left->right = new binaryTreeNode(15);
  root1->left->left = new binaryTreeNode(5);

  //Test value is in  BST
  assert(nullptr != findFirstOfVal(root1, 15));

  cout<< "Test 2 : Value is in  BST : Passed\n";

  /* Tree 3
  *                   20
  *                10
  *               5
  */
  binaryTreeNode* root2 = new binaryTreeNode(20);
  root2->left = new binaryTreeNode(10);
  root2->left->left = new binaryTreeNode(5);

  //Test value is in  BST
  assert(root2 == findFirstOfVal(root2, 20));

  cout<< "Test 3 : Value is in  BST : Passed\n";

  /* Tree 4
  *                   20
  *                10    35
  *               5  15    55
  */
  binaryTreeNode* root3 = new binaryTreeNode(20);
  root3->left = new binaryTreeNode(10);
  root3->right = new binaryTreeNode(35);
  root3->right->right = new binaryTreeNode(55);
  root3->left->right = new binaryTreeNode(15);
  root3->left->left = new binaryTreeNode(5);

  //Test value is in  BST
  assert(root3->right->right == findFirstOfVal(root3, 55));

  cout<< "Test 4 : Value is in  BST : Passed\n";

  /* Tree 5
  *                   20
  *                10    20
  *               5  15    20
  */
  binaryTreeNode* root4 = new binaryTreeNode(20);
  root4->left = new binaryTreeNode(10);
  root4->right = new binaryTreeNode(20);
  root4->right->right = new binaryTreeNode(20);
  root4->left->right = new binaryTreeNode(15);
  root4->left->left = new binaryTreeNode(5);

  //Test value is in  BST
  assert(root4 == findFirstOfVal(root4, 20));

  cout<< "Test 5 : Value is in  BST : Passed\n";
}
