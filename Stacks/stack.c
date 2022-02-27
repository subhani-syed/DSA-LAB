#include<stdio.h>
#include<stdlib.h>
int top = -1;
int stack[10];
void push();
void pop();
void display();
int main(){
    while (1)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        int choice;
        printf("Enter Your Chioce:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Choose From given options only\n");
                break;
        }
    }
    
}
void push(){
    if(top==9){
        printf("Stack Overflow\n");
    }else{
        int val;
        printf("Enter Value\n");
        scanf("%d",&val);
        top++;
        stack[top] = val;
    }
}
void pop(){
    if(top==-1){
        printf("Stack is Empty\n");
    }else{
        top--;
    }
}
void display(){
    if(top==-1){
        printf("Stack is Empty\n");
    }else{
        for(int i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}