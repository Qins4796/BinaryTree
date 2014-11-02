#include "unity.h"
#include "BinaryTree.h"
#include "Traversal.h"
#include "mock_Print.h"
#include "mock_Stack.h"

void setUp(void){}
void tearDown(void){}

/**
*     6
*    /  \
*   -    -
*/
void test_binary_tree_with_1_node(void){
  Node root = {NULL,NULL,6};
  Stack stack;
  
  printf("starts test binary tree with 1 node\n");
  stackNew_ExpectAndReturn(&stack);
  display_Expect(6);
  stackPop_ExpectAndReturn(&stack, NULL);
  
  stackDel_Expect(&stack);
  binaryTreeTraverseInOrder(&root);
}
/**
*     10
*    /  \
*   5    -
*/
void test_binary_tree_with_2_node_parent_and_left_child(void){
  Node leftChild = {NULL,NULL,5};
  Node root = {&leftChild,NULL,10};
  Stack stack;
  
  stackNew_ExpectAndReturn(&stack);
  stackPush_Expect(&stack, &root);
  display_Expect(5);
  stackPop_ExpectAndReturn(&stack, &root);
  display_Expect(10);
  stackPop_ExpectAndReturn(&stack, NULL);
  
  stackDel_Expect(&stack);
  binaryTreeTraverseInOrder(&root);
}
/**
*     10
*    /  \
*   -    15
*/
void test_binary_tree_with_2_node_parent_and_right_child(void){
  Node rightChild = {NULL,NULL,15};
  Node root = {NULL,&rightChild,10};
  Stack stack;
  
  stackNew_ExpectAndReturn(&stack);
  display_Expect(10);
  stackPush_Expect(&stack, &root);
  display_Expect(15);
  stackPop_ExpectAndReturn(&stack, &root);
  stackPop_ExpectAndReturn(&stack, NULL);
  
  stackDel_Expect(&stack);
  binaryTreeTraverseInOrder(&root);
}
/**
*     10
*    /  \
*   5    20
*/
void test_binary_tree_with_3_node(void){
  Node leftChild = {NULL,NULL,5};
  Node rightChild = {NULL,NULL,20};
  Node root = {&leftChild,&rightChild,10};
  Stack stack;
  
  stackNew_ExpectAndReturn(&stack);
  stackPush_Expect(&stack, &root);
  display_Expect(5);
  stackPop_ExpectAndReturn(&stack, &root);
  display_Expect(10);
  stackPush_Expect(&stack, &root);
  display_Expect(20);
  stackPop_ExpectAndReturn(&stack, &root);
  stackPop_ExpectAndReturn(&stack, NULL);
  
  stackDel_Expect(&stack);
  binaryTreeTraverseInOrder(&root);
}
/**
*          10
*         /  \
*       5     -
*      / \
*    1    7
*/
void test_binary_tree_for_case_5(void){
  Node Node1 = {NULL,NULL,1};
  Node Node7 = {NULL,NULL,7};
  Node Node5 = {&Node1,&Node7,5};
  Node Node10 = {&Node5,NULL,10};
  Node root = Node10;
  Stack stack;
  
  stackNew_ExpectAndReturn(&stack);
  stackPush_Expect(&stack, &root);
  stackPush_Expect(&stack, &Node5);
  display_Expect(1);
  stackPop_ExpectAndReturn(&stack, &Node5);
  display_Expect(5);
  stackPush_Expect(&stack, &Node5);
  display_Expect(7);
  stackPop_ExpectAndReturn(&stack, &Node5);
  stackPop_ExpectAndReturn(&stack, &root);
  display_Expect(10);
  stackPop_ExpectAndReturn(&stack, NULL);
  
  stackDel_Expect(&stack);
  binaryTreeTraverseInOrder(&root);
}
/**
*          100
*         /  \
*       50    -
*      / \
*    20   -
*   / \
* 10   -
*/
void test_traversing_left(void){
  int i;
  Node Node10 = {NULL,NULL,10};
  Node Node20 = {&Node10,NULL,20};
  Node Node50 = {&Node20,NULL,50};
  Node Node100 = {&Node50,NULL,100};
  Node root = Node100;
  Stack stack;
  stackNew_ExpectAndReturn(&stack);
  stackPush_Expect(&stack, &root);
  stackPush_Expect(&stack, &Node50);
  stackPush_Expect(&stack, &Node20);
  display_Expect(10);
  stackPop_ExpectAndReturn(&stack, &Node20);
  display_Expect(20);
  stackPop_ExpectAndReturn(&stack, &Node50);
  display_Expect(50);
  stackPop_ExpectAndReturn(&stack, &root);
  display_Expect(100);
  stackPop_ExpectAndReturn(&stack, NULL);
  
  stackDel_Expect(&stack);
  binaryTreeTraverseInOrder(&root);
  
  // Node *currentNode, *root = &Node100;
  // currentNode = root;
  // for(i = 0; i<4;i++){
  // printf("%d\n",currentNode->data);
  // currentNode = currentNode->left;
  // }
}