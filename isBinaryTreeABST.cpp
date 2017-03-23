/*
* Method to tell if the given binary tree is a
* Binary Search Tree or Not.
*
* In this method we start with lower value as INT_MIN and
* higher value ad INT_MAX and keep tighthning the limits
* as we traverse down the tree
*/

#include <iostream>
#include <cassert>

using namespace std;

struct binaryTreeNode{
  int val;
  binaryTreeNode* left;
  binaryTreeNode* right;

  //Constructor
  binaryTreeNode(int v):val(v),
                        left(nullptr),
                        right(nullptr){};
};

bool isBST(binaryTreeNode* root, int lower = INT_MIN, int higher = INT_MAX){
  cout << lower << "  " << higher <<" " << '\n';
  if(root)
    cout <<"Val" <<root->val <<'\n';
  if(nullptr == root){
    return true;
  } else if( root->val < lower || root->val >= higher) {
      return false;
  }

  return isBST(root->left, lower, root->val) && isBST(root->right, root->val, higher);
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
  root->left->right = new binaryTreeNode(25);
  root->left->left = new binaryTreeNode(5);

  //Test NOT a BST
  assert(false == isBST(root));

  cout<< "Test 1 : NOT a BST : Passed\n";

  /* Tree 2
  *                   20
  *                10    20
  *               5  15
  */
  binaryTreeNode* root1 = new binaryTreeNode(20);
  root1->left = new binaryTreeNode(10);
  root1->right = new binaryTreeNode(20);
  root1->left->right = new binaryTreeNode(15);
  root1->left->left = new binaryTreeNode(5);

  //Test is a BST
  assert(true == isBST(root1));

  cout<< "Test 2 : Is a BST : Passed\n";

  /* Tree 3
  *                   20
  *                10
  *               5
  */
  binaryTreeNode* root2 = new binaryTreeNode(20);
  root2->left = new binaryTreeNode(10);
  root2->left->left = new binaryTreeNode(5);

  //Test NOT a BST
  assert(true == isBST(root2));

  cout<< "Test 3 : NOT a BST : Passed\n";

  /* Tree 4
  *                   20
  *                20    35
  *               5  20
  */
  binaryTreeNode* root3 = new binaryTreeNode(20);
  root3->left = new binaryTreeNode(20);
  root3->right = new binaryTreeNode(35);
  root3->left->right = new binaryTreeNode(20);
  root3->left->left = new binaryTreeNode(5);

  //Test is a BST
  assert(false == isBST(root3));

  cout<< "Test 4 : NOT a BST : Passed\n";

}
