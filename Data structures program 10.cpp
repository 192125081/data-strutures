#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>

  struct node {
    int data;
    struct node * next;
  };
  
  // decalre all functions
struct node * start = NULL;
struct node * create_ll(struct node * );
struct node * display(struct node * );
struct node * insert_beg(struct node * );
struct node * insert_end(struct node * );

struct node * delete_beg(struct node * );
struct node * delete_end(struct node * );

struct node * delete_list(struct node * );


voidmain() {
    
  int option;
  do {
    printf("\n\n *****MAIN MENU *****");
    printf("\n 1: Create a list");
    printf("\n 2: Display the list");
    printf("\n 3: Add a node at the beginning");
    printf("\n 4: Add a node at the end");
 
    printf("\n 5: Delete a node from the beginning");
    printf("\n 6: Delete a node from the end");
   
    printf("\n 7: Delete the entire list");
    
    printf("\n 8: EXIT");
    
    printf("\n\n Enter your option : ");
    scanf("%d", &option);
    switch (option) {
    case 1:
      start = create_ll(start);
      printf("\n LINKED LIST CREATED");
      break;
    case 2:
      start = display(start);
      break;
    case 3:
      start = insert_beg(start);
      break;
    case 4:
      start = insert_end(start);
      break;
   
    case 5:
      start = delete_beg(start);
      break;
    case 6:
      start = delete_end(start);
      break;
  
    case 7:
      start = delete_list(start);
      printf("\n LINKED LIST DELETED");
      break;
 
    }
  } while (option != 8);
  getch();
  
}

//Create linked list function
//it will keep asking for data until -1 is entered
struct node * create_ll(struct node * start) {
  struct node * new_node, * ptr;
  int num;
  printf("\n Enter -1 to end");
  printf("\n Enter the data: ");
  scanf("%d", & num);
  while (num != -1) {
    new_node = (struct node * ) malloc(sizeof(struct node));
    new_node -> data = num;
    if (start == NULL) {
      new_node -> next = NULL;
      start = new_node;
    } else {
      ptr = start;
      while (ptr -> next != NULL)
        ptr = ptr -> next;
      ptr -> next = new_node;
      new_node -> next = NULL;
    }
    printf("\n Enter the data : ");
    scanf("%d", & num);
  }
  return start;
}

//display linked list data 
//after looping it from start until NULL
struct node * display(struct node * start) {
  struct node * ptr;
  ptr = start;
  while (ptr != NULL) {
    printf("\t %d", ptr -> data);
    ptr = ptr -> next;
  }
  return start;
}

//insert a node at beginning
struct node * insert_beg(struct node * start) {
  struct node * new_node;
  int num;
  printf("\n Enter the data: ");
  scanf("%d", & num);
  new_node = (struct node *) malloc(sizeof(struct node));
  new_node -> data = num;
  new_node -> next = start;
  start = new_node;
  return start;
}

//insert a node at the end of linked list
struct node * insert_end(struct node * start) {
  struct node * ptr, * new_node;
  int num;
  printf("\n Enter the data: ");
  scanf("%d", &num);
  new_node = (struct node * ) malloc(sizeof(struct node));
  new_node -> data = num;
  new_node -> next = NULL;
  ptr = start;
  while (ptr -> next != NULL)
    ptr = ptr -> next;
  ptr -> next = new_node;
  return start;
}

//delete the first node of Linked list
struct node * delete_beg(struct node * start) {
  struct node * ptr;
  ptr = start;
  start = start -> next;
  free(ptr);
  return start;
}

//delete the last node of linked list
struct node * delete_end(struct node * start) {
  struct node * ptr, * preptr;
  ptr = start;
  while (ptr -> next != NULL) {
    preptr = ptr;
    ptr = ptr -> next;
  }
  preptr -> next = NULL;
  free(ptr);
  return start;
}

//delete list completly
struct node * delete_list(struct node * start) {
  struct node * ptr;
  if (start != NULL) {
    ptr = start;
    while (ptr != NULL) {
      printf("\n %d is to be deleted next", ptr -> data);
      start = delete_beg(ptr);
      ptr = start;
    }
  }
  return start;
}
