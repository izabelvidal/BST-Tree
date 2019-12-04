#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(){
    Node* tree = NULL;
    Node* aux = NULL;
    int key,option;
    while(1){
      scanf("%d",&option);
      switch(option){
        case 1:
          scanf("%d", &key);
          tree = insert(tree, key);
          break;
        case 2:
          pre_order(tree);
          printf("\n");
          break;
        case 3:
          in_order(tree);
          printf("\n");
          break;
        case 4:
          pos_order(tree);
          printf("\n");
          break;
        case 5:
          scanf("%d", &key);
          tree = remover(tree, key);
          break;
        case 6:
          aux = find_maximum(tree);
          printf("[%d]", aux->key);
          printf("\n");
          break;
        case 7:
          aux = find_minimum(tree);
          printf("[%d]", aux->key);
          printf("\n");
          break;
        case 8: 
          printf("%d\n",height(tree));
          break;
        case 9:
          scanf("%d", &key);
          if(search_parent(tree, key)==NULL){
            printf("-1\n");  
          }else{
            aux = search_parent(tree, key);
            printf("%d\n", aux->key);
          }
          break;
        case 10:
          scanf("%d", &key);
          if(successor(tree, key)==NULL){
            printf("-1\n");  
          }else{
            aux = successor(tree, key);
            printf("%d\n",aux->key);
          }
          break;
        case 11:
          scanf("%d", &key);
          if(predecessor(tree, key)==NULL){
            printf("-1\n");  
          }else{
            aux = predecessor(tree, key);
            printf("%d\n",aux->key);
          }
          break;
        case 999:
          exit(0);
      }
    }

}
