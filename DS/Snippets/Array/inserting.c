#include <stdio.h>
int a[100];
int b[100];

// inserting at the back
void insertback(int val, int* lower_bound , int* upper_bound){
    if (*lower_bound==-1 && *upper_bound==-1){
        (*lower_bound) +=1;
        (*upper_bound) +=1;
        b[*upper_bound]=val;
    }
    else{
        *upper_bound+=1;
        b[*upper_bound]=val;
    }
}

//inserting at the front or in the middle 
// btw this can work for inserting at the back too if you give position pos=upper_bound+1;
//! here pos argument is the index
void insert(int val , int pos , int* upper_bound){
    int i = (*upper_bound)+1; // (no. of elements) n = upper_bound +1 and the max index will always be n-1
    while (i>pos){
        b[i]=b[i-1];
        i--;
    }
    *upper_bound+=1;
    b[pos]=val;
}

int main(){

    // inserting at the back
    int lower_bound=-1 , upper_bound=-1; 
    for (int i=0 ;i<5 ; i++){
        insertback(i,&lower_bound,&upper_bound);
    } 
    // b={0,1,2,3,4}

    // printf("%d %d\n",lower_bound,upper_bound);
    for (int i=lower_bound ; i<=upper_bound ; i++){
        printf("%d ",b[i]);
    }
    printf("\n");

    //inserting in the middle
    insert(10,1,&upper_bound); //! here pos argument is the index 
    // b={0,10,1,2,3,4}

    // printf("%d %d\n",lower_bound,upper_bound);
    for (int i=lower_bound ; i<=upper_bound ; i++){
        printf("%d ",b[i]);
    }
    printf("\n");


}   