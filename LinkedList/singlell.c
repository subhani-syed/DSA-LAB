#include<stdio.h>
#include<stdlib.h>

void at_beg();
void at_pos();
void at_end();
void from_beg();
void from_pos();
void from_end();
void rev_ll();
void display();
struct node{
    int data;
    struct node* next;
};
struct node* head;
int main(){
    while (1)
    {
        printf("1.At Beginig\n2.At Position\n3.At end\n4.From Begining\n5.From Positon\n6.From End\n7.Reverse LL\n8.Display\n9.Exit\n");
        int choice;
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            at_beg();
            break;
        case 2:
            at_pos();
            break;
        case 3:
            at_end();
            break;
        case 4:
            from_beg();
            break;
        case 5:
            from_pos();
            break;
        case 6:
            from_end();
            break;
        case 7:
            rev_ll();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(1);
        default:
            break;
        }
    }   
    return 0;
}

void at_beg(){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("ENter the data of node\n");
    scanf("%d",&newnode->data);
    if(head==NULL){
        newnode->next = NULL;
        head = newnode;
    }else{
        newnode->next = head;
        head = newnode;
    }
}
void at_end(){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("ENter the data of node\n");
    scanf("%d",&newnode->data);
    if(head==NULL){
        newnode->next = NULL;
        head = newnode;
    }else{
        struct node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
}
void at_pos(){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("ENter the data of node\n");
    scanf("%d",&newnode->data);
    int val;
    printf("ENter the data after which to insert\n");
    scanf("%d",&val);
    if(head==NULL){
        newnode->next = NULL;
        head = newnode;
    }else{
        struct node* temp = head;
        while(temp->data!=val){
            temp = temp->next;
        }
        if(temp->next==NULL){ //Fix This
            printf("NOt possible");
            return;
        }else{
            newnode->next = temp->next;
            temp->next = newnode;   
        }
    }
}
void display(){
    if(head==NULL){
        printf("The LinkedList is Empty\n");
    }else{
        struct node* temp = head;
        while(temp->next!=NULL){
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }
}
void rev_ll(){
    struct node *current,*next,*prev;
    current = head;
    prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void from_beg(){
    if(head==NULL){
        printf("LinkedList is already Empty\n");
    }else{
        struct node* temp =head;
        head = temp->next;
        free(temp); 
    }
}
void from_end(){
    if(head==NULL){
        printf("LinkedList is already Empty\n");
    }else{
        struct node *temp1,*temp2;
        temp1 = head;
        temp2 = NULL;
        while (temp1->next!=NULL)
        {
            temp2 = temp1;
            temp1=temp1->next;
        }
        temp2->next = NULL;
        free(temp1);
    }
}
void from_pos(){
    int val;
    printf("Enter the Node Value to be deleted\n");
    scanf("%d",&val);
    if(head==NULL){
        printf("LinkedList is already Empty\n");
    }else{
        struct node *temp1,*temp2;
        temp1 = head;
        temp2 = NULL;
        while (temp1->data!=val)
        {
            temp2 = temp1;
            temp1=temp1->next;
        }
        temp2->next = temp1->next;
        free(temp1);
    }
}