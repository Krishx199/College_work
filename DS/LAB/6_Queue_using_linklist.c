#include <stdio.h>
#include <stdlib.h>
# define max 5

typedef struct node{
    int val;
    struct node* next;
}node;

typedef struct queue{
    node* front;
    node* rear;
    int count;
}queue;

queue q = {NULL,NULL,0};

void enqueue(int x){
    node* newnode = malloc(sizeof(node));
    newnode->val = x;
    newnode->next = NULL;
    if (q.count==max) printf("Overflow\n");
    else{
        if (q.front==NULL){
            q.front = newnode;
            q.rear = newnode;
            q.count++;
        }
        else if (q.count<=max){
            q.rear->next = newnode ;
            q.rear = newnode;
            q.count++;
        }
    }
}

void Dequeue(){
    if (q.count==0) printf("Underflow\n");
    else{
        if (q.front==q.rear){
            printf("Dequeued %d\n",q.front->val);
            q.front=q.front->next;
            q.rear=q.rear->next;
            q.count--;
        }
        else{
            printf("Dequeued %d\n",q.front->val);
            q.front=q.front->next;
            q.count--;
        }
    }
}

void peek(){
    if (q.front==NULL) printf("Queue Empty\n");
    else{
        printf("Current front is %d\n",q.front->val);
    }
}

int main(){
    for (int i=0 ; i<5 ; i++){   // enqueueing elements
        enqueue(i+1);
    }
    enqueue(6);  // testing edge case for overflow 

    peek();

    for (int i=0 ; i<5 ; i++){  // checking Dequeue()
       Dequeue();
    //    peek();
    }

    Dequeue(); // testing edge case for underflow 

    peek();
}