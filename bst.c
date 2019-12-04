#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

Node *createNode(int key){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node *search(Node *node, int key){
  if(node == NULL){
    return NULL;
  }
  if(node->key == key){
    return node;
  }
  if(key <= node->key){
    return search(node->left, key);
  }
  if(key > node->key){
    return search(node->right, key);
  }
}



Node * insert(Node *node, int key){
  if(node == NULL){
    node = createNode(key);
  }
  else if(node-> key > key){
    node->left = insert(node->left, key);        
  }
  else{
    node->right = insert(node->right, key);  
  }
  return node;
} 
Node *find_maximum(Node *node){
  while(node!= NULL && node->right!=NULL ){
    node = node->right;
  }
  return node;
}

Node* find_minimum(Node *node){
    while(node!=NULL && node->left!=NULL){
      node = node->left;
    }
    return node;
}

Node* binary_search(Node* node, int key){
    if(node == NULL){
        return NULL;                
    }
    if(node->key == key){
        return node;
    }
    if(node->key > key){
        binary_search(node->left, key);
    }
    if(node->key < key){
        binary_search(node->right, key);
    }
}

Node * predecessor(Node *node, int key){
  Node *aux = search(node, key);
  if(aux==NULL){
    return NULL;
  }
  if(aux->left != NULL){
    return find_maximum(aux->left);
  }else{
    Node *successor = node;
    Node *before = NULL;
    while(successor != aux){
      if(aux->key > successor->key){
        before = successor;
        successor = successor->right;
      }else{
        successor = successor->left;
      }
    }
    return before;
  }
  return NULL;
}

Node *successor(Node *node, int key){
  Node* aux = search(node,key);
  if(aux==NULL){
    return NULL;
  }
  if(aux->right != NULL){
    return find_minimum(aux->right);
  }else{
    Node *successor = NULL;
    Node *before = node;
    while(before !=aux){
      if(aux->key < before->key){
        successor = before;
        before = before->left;
      }else{
        before = before->right;
      }
    }
    return successor;
  }
  return NULL;
}

Node *search_parent(Node *node, int key){
  if(node == NULL || node->key == key){
    return NULL;
  }
  Node *daddy = NULL;
  while(node != NULL){
    if(key < node->key){
      daddy = node;
      node = node->left;
      if(node==NULL){
        return NULL;
      }
    }else if(key > node->key){
      daddy = node;
      node = node->right;
      if(node == NULL){
        return NULL;
      }
    }else{
      break;
    }
  }return daddy;
}

int height(Node* node){  
  if (node == NULL)  
      return 0;  
  else{        
    int left = height(node->left);  
    int right = height(node->right);  
    if(left > right){
      return(left + 1);
    }  
    else{
      return(right + 1);
    }   
  }  
} 

void pre_order(Node *node){
    if(node != NULL){
    printf("[%d]", node->key);
    pre_order(node->left);
    pre_order(node->right);
    }
    
}

void pos_order(Node *node){
    if(node != NULL){
    pos_order(node->left);
    pos_order(node->right);
    printf("[%d]", node->key);
    }
    
}

void in_order(Node *node){
    if(node != NULL){
    in_order(node->left);
    printf("[%d]", node->key);
    in_order(node->right);  
    } 
}

Node * remover(Node *node, int key){
    if(node == NULL){
        return node;
    }
    if(key > node->key){
        node->right = remover(node->right, key);
    }else if(key < node->key){
        node->left = remover(node->left, key);
    }else{
        //no children
        if(node->left==NULL && node->right==NULL){
            free(node);
            return NULL;
        }
        //one child
        else if(node->left==NULL || node->right==NULL){
            Node *temp;
            if(node->left==NULL){
                temp = node->right;
            }else{
                temp = node->left;
            }
            free(node);
            return temp;
        }else{ //two children
            Node *temp = find_minimum(node->right);
            node->key = temp->key;
            node->right = remover(node->right,temp->key);
        }
    }
    return node;
}
