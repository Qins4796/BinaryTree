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
  
  // printf("starts test binary tree with 1 node\n");
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
/**
*          10
*         /  \
*       5    -
*      / \
*     1   -
*/
void test_recursive_print(void){
  Node Node1 = {NULL,NULL,1};
  Node Node5 = {&Node1,NULL,5};
  Node Node10 = {&Node5,NULL,10};
  Node root = Node10;

  display_Expect(1);
  display_Expect(5);
  display_Expect(10);

  binaryTreePrintInOrder(&root);
  // printf("======\n");
}
/**
*          20
*         /  \
*       10    -
*      / \
*     5   -
*    / \
*   1   -
*/
void test_recursive_print_for_4(void){
  Node Node1 = {NULL,NULL,1};
  Node Node5 = {&Node1,NULL,5};
  Node Node10 = {&Node5,NULL,10};
  Node Node20 = {&Node10,NULL,20};
  Node root = Node20;

  display_Expect(1);
  display_Expect(5);
  display_Expect(10);
  display_Expect(20);

  binaryTreePrintInOrder(&root);
  // printf("======\n");
}
/**
*          20
*         /  \
*       10    -
*      / \
*     5   -
*    / \
*   1   3
*/
void test_recursive_print_for_left(void){
  Node Node1 = {NULL,NULL,1};
  Node Node3 = {NULL,NULL,3};
  Node Node5 = {&Node1,&Node3,5};
  Node Node10 = {&Node5,NULL,10};
  Node Node20 = {&Node10,NULL,20};
  Node root = Node20;

  display_Expect(1);
  display_Expect(5);
  display_Expect(3);
  display_Expect(10);
  display_Expect(20);

  binaryTreePrintInOrder(&root);
  // printf("======\n");
}
/**
*          20
*         /  \
*       10    25
*      / \
*     5   15
*    / \
*   1   3
*/
void test_recursive_print_with_multiple_right_value(void){
  Node Node1 = {NULL,NULL,1};
  Node Node3 = {NULL,NULL,3};
  Node Node15 = {NULL,NULL,15};
  Node Node25 = {NULL,NULL,25};
  Node Node5 = {&Node1,&Node3,5};
  Node Node10 = {&Node5,&Node15,10};
  Node Node20 = {&Node10,&Node25,20};
  Node root = Node20;

  display_Expect(1);
  display_Expect(5);
  display_Expect(3);
  display_Expect(10);
  display_Expect(15);
  display_Expect(20);
  display_Expect(25);

  binaryTreePrintInOrder(&root);
  // printf("======\n");
}
/**
*          20
*         /  \
*        -    25
*            /  \
*           -   35
*              /  \
*             -   45
*/
void test_recursive_print_for_right(void){
  Node Node45 = {NULL,NULL,45};
  Node Node35 = {NULL,&Node45,35};
  Node Node25 = {NULL,&Node35,25};
  Node Node20 = {NULL,&Node25,20};
  Node root = Node20;

  display_Expect(20);
  display_Expect(25);
  display_Expect(35);
  display_Expect(45);

  binaryTreePrintInOrder(&root);
  // printf("======\n");
}
/**
*          20
*         /  \
*        15   25
*            /  \
*           22   35
*               /  \
*             30   45
*/
void test_recursive_print_for_right_with_left(void){
  Node Node15 = {NULL,NULL,15};
  Node Node22 = {NULL,NULL,22};
  Node Node30 = {NULL,NULL,30};
  Node Node45 = {NULL,NULL,45};
  Node Node35 = {&Node30,&Node45,35};
  Node Node25 = {&Node22,&Node35,25};
  Node Node20 = {&Node15,&Node25,20};
  Node root = Node20;

  display_Expect(15);
  display_Expect(20);
  display_Expect(22);
  display_Expect(25);
  display_Expect(30);
  display_Expect(35);
  display_Expect(45);

  binaryTreePrintInOrder(&root);
  // printf("======\n");
}

/**
 *      50     
 *     /  \     
 *   25   200    
 *        / \   
 *      150 220 
 */
void test_binary_tree_for_case_6(){
  Node Node150 = {NULL,NULL,150};
  Node Node220 = {NULL,NULL,220};
  Node Node25 = {NULL,NULL,25};
  Node Node200 = {&Node150,&Node220,200};
  Node Node50 = {&Node25,&Node200,50};
  Node root = Node50;
  Stack stack;
  stackNew_ExpectAndReturn(&stack);
  
  stackPush_Expect(&stack, &root);
  display_Expect(25);
  stackPop_ExpectAndReturn(&stack, &root);
  display_Expect(50);
  stackPush_Expect(&stack, &root);
  stackPush_Expect(&stack, &Node200);
  display_Expect(150);
  stackPop_ExpectAndReturn(&stack, &Node200);
  display_Expect(200);
  stackPush_Expect(&stack, &Node200);
  display_Expect(220);
  stackPop_ExpectAndReturn(&stack, &Node200);
  stackPop_ExpectAndReturn(&stack, &root);
  stackPop_ExpectAndReturn(&stack, NULL);
  
  stackDel_Expect(&stack);
  binaryTreeTraverseInOrder(&root);
}
/**
 *              175      
 *          /          \           
 *        100          400          
 *       /   \       /     \       
 *     50    150   250     500      
 *    / \    /   /    \     / \     
 *  25  65 120 200    300 450 550  
 *   \          \     / \      \    
 *   40         220 270 350    600 
 *                      /
 *                    330
 */
void test_binary_tree_TraverseInOrder_for_FINAL_case(){
  Node Node40 = {NULL,NULL,40};
  Node Node65 = {NULL,NULL,65};
  Node Node120 = {NULL,NULL,120};
  Node Node220 = {NULL,NULL,220};
  Node Node270 = {NULL,NULL,270};
  Node Node330 = {NULL,NULL,330};
  Node Node450 = {NULL,NULL,450};
  Node Node600 = {NULL,NULL,600};
  
  Node Node25 = {NULL,&Node40,25};
  Node Node150 = {&Node120,NULL,150};
  Node Node200 = {NULL,&Node220,200};
  Node Node350 = {&Node330,NULL,350};
  Node Node550 = {NULL,&Node600,550};
  
  Node Node300 = {&Node270,&Node350,300};
  Node Node500 = {&Node450,&Node550,500};
  Node Node50 = {&Node25,&Node65,50};
  
  Node Node250 = {&Node200,&Node300,250};
  
  Node Node100 = {&Node50,&Node150,100};
  Node Node400 = {&Node250,&Node500,400};
  
  Node Node175 = {&Node100,&Node400,175};
  
  Node root = Node175;
  Stack stack;
  stackNew_ExpectAndReturn(&stack);
  
  //start
  //left
  stackPush_Expect(&stack, &root);
  stackPush_Expect(&stack, &Node100);
  stackPush_Expect(&stack, &Node50);
  display_Expect(25);
  stackPush_Expect(&stack, &Node25);
  display_Expect(40);
  stackPop_ExpectAndReturn(&stack, &Node25);
  stackPop_ExpectAndReturn(&stack, &Node50);
  display_Expect(50);
  stackPush_Expect(&stack, &Node50);
  display_Expect(65);
  stackPop_ExpectAndReturn(&stack, &Node50);
  stackPop_ExpectAndReturn(&stack, &Node100);
  display_Expect(100);
  stackPush_Expect(&stack, &Node100);
  stackPush_Expect(&stack, &Node150);
  display_Expect(120);
  stackPop_ExpectAndReturn(&stack, &Node150);
  display_Expect(150);
  stackPop_ExpectAndReturn(&stack, &Node100);
  stackPop_ExpectAndReturn(&stack, &root);
  display_Expect(175);
  
  //right
  stackPush_Expect(&stack, &root);
  stackPush_Expect(&stack, &Node400);
  stackPush_Expect(&stack, &Node250);
  display_Expect(200);
  stackPush_Expect(&stack, &Node200);
  display_Expect(220);
  stackPop_ExpectAndReturn(&stack, &Node200);
  stackPop_ExpectAndReturn(&stack, &Node250);
  display_Expect(250);
  stackPush_Expect(&stack, &Node250);
  stackPush_Expect(&stack, &Node300);
  display_Expect(270);
  stackPop_ExpectAndReturn(&stack, &Node300);
  display_Expect(300);
  stackPush_Expect(&stack, &Node300);
  stackPush_Expect(&stack, &Node350);
  display_Expect(330);
  stackPop_ExpectAndReturn(&stack, &Node350);
  display_Expect(350);
  stackPop_ExpectAndReturn(&stack, &Node300);
  stackPop_ExpectAndReturn(&stack, &Node250);
  stackPop_ExpectAndReturn(&stack, &Node400);
  display_Expect(400);
  stackPush_Expect(&stack, &Node400);
  stackPush_Expect(&stack, &Node500);
  display_Expect(450);
  stackPop_ExpectAndReturn(&stack, &Node500);
  display_Expect(500);
  stackPush_Expect(&stack, &Node500);
  display_Expect(550);
  stackPush_Expect(&stack, &Node550);
  display_Expect(600);
  stackPop_ExpectAndReturn(&stack, &Node550);
  stackPop_ExpectAndReturn(&stack, &Node500);
  stackPop_ExpectAndReturn(&stack, &Node400);
  stackPop_ExpectAndReturn(&stack, &root);
  stackPop_ExpectAndReturn(&stack, NULL);
  
  stackDel_Expect(&stack);
  binaryTreeTraverseInOrder(&root);
}
void test_binary_tree_PrintInOrder_for_FINAL_case(){
  Node Node40 = {NULL,NULL,40};
  Node Node65 = {NULL,NULL,65};
  Node Node120 = {NULL,NULL,120};
  Node Node220 = {NULL,NULL,220};
  Node Node270 = {NULL,NULL,270};
  Node Node330 = {NULL,NULL,330};
  Node Node450 = {NULL,NULL,450};
  Node Node600 = {NULL,NULL,600};
  
  Node Node25 = {NULL,&Node40,25};
  Node Node150 = {&Node120,NULL,150};
  Node Node200 = {NULL,&Node220,200};
  Node Node350 = {&Node330,NULL,350};
  Node Node550 = {NULL,&Node600,550};
  
  Node Node300 = {&Node270,&Node350,300};
  Node Node500 = {&Node450,&Node550,500};
  Node Node50 = {&Node25,&Node65,50};
  
  Node Node250 = {&Node200,&Node300,250};
  
  Node Node100 = {&Node50,&Node150,100};
  Node Node400 = {&Node250,&Node500,400};
  
  Node Node175 = {&Node100,&Node400,175};
  
  Node root = Node175;
  
  //start
  //left
  display_Expect(25);
  display_Expect(40);
  display_Expect(50);
  display_Expect(65);
  display_Expect(100);
  display_Expect(120);
  display_Expect(150);
  display_Expect(175);
  
  //right
  display_Expect(200);
  display_Expect(220);
  display_Expect(250);
  display_Expect(270);
  display_Expect(300);
  display_Expect(330);
  display_Expect(350);
  display_Expect(400);
  display_Expect(450);
  display_Expect(500);
  display_Expect(550);
  display_Expect(600);

  binaryTreePrintInOrder(&root);
}