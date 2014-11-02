#include <stdio.h>
#include "BinaryTree.h"
#include "Stack.h"


void changeNodeState(Node *curNode){
  switch(curNode->state){
  case ENTERED_NODE: curNode->state = VISITED_LEFT_NODE; break;
  case VISITED_LEFT_NODE: curNode->state = VISITED_RIGHT_NODE; break;
  default: curNode->state = UNKNOWN_NODE_STATE; break;
  }
}

void binaryTreeTraverseInOrder(Node *root){
  Stack *stack = stackNew();
  Node *currentNode = root;
  
  printf("\ncreated a stack\n");
  currentNode->state = ENTERED_NODE;
  while(currentNode!= NULL){
    if(currentNode->state == ENTERED_NODE){
      if(currentNode->left == NULL && currentNode->right == NULL){
        display(currentNode->data);
        currentNode->state = VISITED_RIGHT_NODE;
      }
      else if(currentNode->left != NULL){ //left value
        printf("left\n");
        stackPush(stack,currentNode);
        currentNode = currentNode->left;
        currentNode->state = ENTERED_NODE;
      }
      else if(currentNode->right != NULL){ //right value
        printf("right\n");
        currentNode->state = VISITED_LEFT_NODE;}
      else currentNode->state = UNKNOWN_NODE_STATE;
    } 
    if(currentNode->state == VISITED_LEFT_NODE){
    printf("VISITED_LEFT_NODE\n");
      if(currentNode->right != NULL){
        display(currentNode->data);
        stackPush(stack,currentNode);
        currentNode = currentNode->right;
        currentNode->state = ENTERED_NODE;
        printf("right enter\n");
      }
      else{ currentNode->state = VISITED_RIGHT_NODE;
        display(currentNode->data);
        printf("right done\n");
      }
    } 
    if(currentNode->state == VISITED_RIGHT_NODE){
    printf("pop here\n");

    currentNode = stackPop(stack);

      if(currentNode ==NULL) break;
      if(currentNode->state == ENTERED_NODE){
        currentNode->state = VISITED_LEFT_NODE;
      }
      else if(currentNode->state == VISITED_LEFT_NODE){
        currentNode->state = VISITED_RIGHT_NODE;
      }
    }
  }
  
  stackDel(stack);
  printf("deleted a stack\n");
}