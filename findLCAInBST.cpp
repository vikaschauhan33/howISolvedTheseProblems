/*
* Method to find the LCA given two nodes in binary search tree
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

binaryTreeNode* findLCAInBST(binaryTreeNode* root, binaryTreeNode* small,
                            binaryTreeNode* high){
if(!root || !small || !high) return nullptr; // If any pointer is a nullptr
while(root->val < small->val || root->val > high->val){
  while(root->val < small->val){// LCA in right tree
    root = root->right;
  }
  while(root->val > high->val){
    root = root->left;
  }
}

return root;
}

int main(){
  /* Tree 1
  *                   20
  *                10    30
  *               5  15
  */
  binaryTreeNode* root = new binaryTreeNode(20);
  root->left = new binaryTreeNode(10);
  root->right = new binaryTreeNode(30);
  root->left->right = new binaryTreeNode(15);
  root->left->left = new binaryTreeNode(5);

  //Test NOT a BST
  assert(root->left->right == findLCAInBST(root, root->left->right, root->left->right));

  cout<< "Test 1 : LCA found : Passed\n";

  /* Tree 2
  *                   200
  *                10    300
  *               5  15
  */
  binaryTreeNode* root1 = new binaryTreeNode(200);
  root1->left = new binaryTreeNode(10);
  root1->right = new binaryTreeNode(300);
  root1->left->right = new binaryTreeNode(15);
  root1->left->left = new binaryTreeNode(5);

  //Test NOT a BST
  assert(nullptr == findLCAInBST(root1, nullptr, root1->left->right));

  cout<< "Test 2 : LCA not found : Passed\n";

  /* Tree 3
  *                   200
  *                10    300
  *               5  15
  */
  binaryTreeNode* root2 = new binaryTreeNode(200);
  root2->left = new binaryTreeNode(10);
  root2->right = new binaryTreeNode(300);
  root2->left->right = new binaryTreeNode(15);
  root2->left->left = new binaryTreeNode(5);

  //Test NOT a BST
  assert(root2->right == findLCAInBST(root2, root2->right, root2->right));

  cout<< "Test 3 : LCA found : Passed\n";


  /* Tree 4
  *                   200
  *                10    300
  *               5  15
  */
  binaryTreeNode* root3 = new binaryTreeNode(200);
  root3->left = new binaryTreeNode(10);
  root3->right = new binaryTreeNode(300);
  root3->left->right = new binaryTreeNode(15);
  root3->left->left = new binaryTreeNode(5);

  //Test NOT a BST
  assert(root3 == findLCAInBST(root3, root3->left->right, root3->right));

  cout<< "Test 4 : LCA found : Passed\n";



}
