/*
* Method to find out if a given tree is balanced or not.
*/

#include <iostream>
#include <cassert>
#include <cmath>

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

int maxDepth(binaryTreeNode* root){
  if(root == nullptr)
    return 0;

  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(binaryTreeNode* root){
  if(root == nullptr)
    return 0;

  return 1 + min(minDepth(root->left), minDepth(root->right));
}

bool isBalancedTree(binaryTreeNode* root){
  cout << maxDepth(root) << " " << minDepth(root);
  return ( maxDepth(root) - minDepth(root) <= 1 );
}


int main(){
  /* Tree 1
  *                   20
  *                10    30
  *               5  15
  *                     18
  */
  binaryTreeNode* root = new binaryTreeNode(20);
  root->left = new binaryTreeNode(10);
  root->right = new binaryTreeNode(30);
  root->left->right = new binaryTreeNode(15);
  root->left->right->right = new binaryTreeNode(18);
  root->left->left = new binaryTreeNode(5);

  //Test NOT a BST
  assert(false == isBalancedTree(root));

  cout<< "Test 1 : NOT a balanced : Passed\n";

}
