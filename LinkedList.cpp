#include<bits/stdc++.h>
using namespace std;

struct node {
  int val;
  node * next;
};

node * root = NULL;

void append(int val) {
  //if the linked list is empty then creat the first node//
  if (root == NULL) {
    root = new node();
    root -> val = val;
    root -> next = NULL;
  } 
  //if the linked list already had element//
  else {
    node * current_node = root;
    while (current_node -> next != NULL) {
      current_node = current_node -> next;
    }
    node * newNode = new node();
    newNode -> val = val;
    newNode -> next = NULL;
    current_node -> next = newNode;
  }
}
void delet(int n) {
  node * currentNode = root;
  //if the deleted element in the first node, then change the address of the root node//
  if (currentNode -> val == n) {
    root = currentNode -> next;
  } 
  else {
    while (currentNode -> next != NULL) {
      if (currentNode -> next -> val == n) {
        currentNode -> next = currentNode -> next -> next;
      } 
      else {
        currentNode = currentNode -> next;
      }
    }
  }

}
void print() {
  node * currentNode = root;
  while (currentNode -> next != NULL) {
    cout << currentNode -> val;
    currentNode = currentNode -> next;
  }
  cout << currentNode -> val;
}
int main() {
  for (int i = 0; i <= 3; i++) {
    append(i);
  }
  
  delet(3);
  print();

  return 0;
}
