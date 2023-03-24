#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node * rlink, * llink;
};

typedef struct node * NODE;

NODE getNode() {
  NODE temp = (struct node *) malloc (sizeof(struct node));

  if(temp == NULL) 
    exit(1);

  return temp;
}

NODE create(int arr[], int index, int size) {

  NODE root = NULL;
  if( index < size ) {

    root = getNode();
    root -> data = arr[index];

    root -> llink = create(arr, (2 * index + 1), size);//the element towards the left of the Sub tree is always at the index 2 * i + 1

    root -> rlink = create(arr, (2 * index + 2), size);//and element towards the right subtree is always at the index of 2 * index + 2 FROM THE CURRENT INDEX
  }

  return root;
}

void inOrder(NODE root) {

  if(root == NULL)
    return;

  inOrder(root -> llink);
  printf("%d\t", root -> data);
  inOrder(root -> rlink);
}

int main () {

  int arr[] = {1, 2, 3, 4, 5};

  int size = sizeof(arr) / sizeof(arr[0]);
  int startingIndex = 0;
  NODE root = create(arr, startingIndex, size);

  inOrder(root);
  return 0;
}