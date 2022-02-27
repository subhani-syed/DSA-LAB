#include<stdio.h>
#include<stdlib.h>
int queue[5];
int front = -1;
int rear = -1;
void enqueue();
void dequeue();
void display();
int main(){
    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        int choice;
        printf("Enter your chioce:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Enter from given options only\n");
                break;
        }
    }
    return 0;
}
void enqueue(){
    if(rear==4){
        printf("Queue is Full\n");
    }else{
        int val;
        printf("Enter the value:");
        scanf("%d",&val);
        if(front==-1){
            front = 0;
            rear++;
            queue[rear] = val;
        }else{
            rear++;
            queue[rear] = val;
        }
    }
}
void dequeue(){
    if(front>rear||front==-1){
        printf("Queue is Empty\n");
    }else{
        front++;
    }
}
void display(){
    if(front>rear||front==-1){
        printf("Queue is Empty\n");
    }else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}