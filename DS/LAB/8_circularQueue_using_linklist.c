#include<stdio.h>
#include<stdlib.h>
# define max 5

typedef struct node{
    int val;
    struct node* next;
}node;

typedef struct cqueue{
    node* front;
    node* rear;
    int count;
}cqueue;

cqueue cq = {NULL,NULL,0};

void push(int x){
    node* newnode = malloc(sizeof(node));
    newnode->val=x;
    newnode->next=NULL;
    if (cq.count==max) printf("Overflow\n");
    else{
        if (cq.front==NULL){
            cq.front=newnode;
            newnode->next=cq.front;
            cq.rear=newnode;
            cq.rear->next=cq.front;
            cq.count++;
        }
        else{
            newnode->next=cq.front;
            cq.rear->next=newnode;
            cq.rear=newnode;

        }
    }
}

void pop(){
    if (cq.front==NULL) printf("Underflow\n");
    else{
        if (cq.front==cq.rear){
            printf("Popped %d\n",cq.front->val);
            cq.front=NULL;
            cq.rear=NULL;
            cq.count--;
        }
        else{
            printf("Popped %d\n",cq.front->val);
            cq.front=cq.front->next;
            cq.rear->next=cq.front;
            cq.count--;
        }
    }
}

void peek(){
    if (cq.front==NULL) printf("Queue empty\n");
    else printf("Current front is %d\n",cq.front->val);
}
    

int main(){
    push(1);
    push(2);
    push(3);
    push(4);

    // node* curr=cq.front;
    // int c=1;
    // while(c<=cq.count){
    //     printf("%d ",curr->val);
    //     curr=curr->next;
    //     c++;
    // }

    peek();

    pop();
    pop();

    push(5);
    push(6);

    peek();

    pop();
    pop();

    peek();

    pop();
    pop();

    peek();
}