

#include<stdio.h>
#include<stdlib.h>

struct node {
    char data;
    struct node *next;
    
};

struct node *first,*temp,*ptr,*prev,*ptr1,*nextnode;

void create(){
    int i,n,x;
    first = NULL;

    printf("How many nodes : \t");
    scanf("%d",&n);

    for(i =1 ;i <=n ; i++ ){
        printf("Enter Data : ");
        scanf("%d",&x);

        temp=(struct node *)malloc(sizeof(struct node));

        temp -> data = x;
        temp -> next = NULL;

        if (first == NULL){
            first = temp;
        }

        else{
           
           ptr = first;
           while(ptr -> next != NULL){
                ptr = ptr -> next;
            }

            ptr -> next =  temp;

           

        }
         
        

    }

    printf("\nCreation Done.\n");



}

void display(){

    

    if (first == NULL){
        printf("Linked List is Empty\n");
    }

    else {

    ptr = first;
    printf("The Linked List contains : ");
    while(ptr != NULL){


          printf(" %d ",ptr -> data);
          ptr = ptr -> next;
          
        }
        printf("\n");
    }
}

void traverse(){

    if (first == NULL){
        printf("Linked List is Empty. \n");
    }
    
    else{
    int count = 0;
    ptr = first;
    while(ptr != NULL){
        ptr = ptr -> next;
        count++;
        
    }
    printf("\n");
    printf("The No. of Nodes are : %d \t",count);
    }
}


void insert(int m){

    int pos,insert;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = m;
    temp->next = NULL;

    printf("Enter the choice : \n");
    printf("1 :- Insertion at Beginning. \n");
    printf("2 :- Insertion at end. \n");
    printf("3 :- Insertion in Between.\n");
    scanf("%d",&insert);

    switch(insert){

        case 1 :
            temp -> next = first;
            first = temp;
            printf("\nInsertion at Beginning Done.\n");

            break;


        case 2 :
            ptr = first;
            while(ptr ->next != NULL){
                ptr = ptr ->next;
            }
            ptr -> next = temp;
            printf("\nInsertion at Last Done.\n");

            break;
        
        case 3 :
            
            printf("Enter the position you Want to insert :\n");
            scanf("%d",&pos);

            int i =2 ;
            ptr = first;
            while(ptr != NULL && i != pos){
                i++;
                ptr = ptr-> next;
            }

            if(ptr == NULL){
                printf("Insufficient No. of Nodes. \n");

            }
            else{
                temp ->next = ptr -> next;
                ptr -> next = temp;
                printf("\nInsertion( in between ) Done.\n");

            }
            

    }
}

void delete(){

     int pos,delete;
    temp = (struct node*)malloc(sizeof(struct node));
    
    temp->next = NULL;

    printf("Enter the choice : \n");
    printf("1 :- Deletion at Beginning. \n");
    printf("2 :- Deletion at end. \n");
    printf("3 :- Deletion in Between.\n");
    scanf("%d",&delete);

    switch(delete){

        case 1 :
            temp = first;
            first = first ->next;
            free((void *)temp);
            printf("Deletion at Beginning Done. \n");
            break;

        case 2 :
            ptr = first;
            while(ptr ->next != NULL){
                prev = ptr;
                ptr = ptr ->next;
            }
             
            prev -> next = NULL;
            free((void *)ptr);
            printf(" Deletion at Last Done. \n");
            break;
        
        case 3 :
            
            printf("Enter the position you Want to delete node :\n");
            scanf("%d",&pos);

            int i =2 ;
            ptr = first;
            while(ptr != NULL && i != pos){
                i++;
                ptr = ptr-> next;
            }

            if(ptr == NULL){
                printf("Insufficient No. of Nodes. \n");

            }
            else{
                ptr1 = ptr -> next;
                ptr -> next = ptr1 -> next;
                free((void *)ptr1);
                printf(" Deletion(in between) Done. \n");
                
            }
            

    }

    
}

void reverse(){

    if(first == NULL){
           printf("Empty Linked List");
    }

    else{
     
           prev = first;
           ptr = first -> next;
           nextnode = ptr -> next;
           first ->next = NULL;

       while(nextnode != NULL){
           ptr -> next = prev;
           prev = ptr;
           ptr = nextnode;
           nextnode = nextnode ->next;
           
       }

       ptr -> next = prev;
       first = ptr;

      
       printf("\nReversal Done.\n ");

    }


}


void update(int p , int v){
    
    
    if(first == NULL){
        printf(" Empty List \n");
        return;

    }

    else
    {
       int i = 1;
       ptr = first;
    
       do{
           ptr = ptr -> next;
           i++;
        }while(i<p  && ptr != NULL);

        if(ptr == NULL || i != p){
            printf("Position not found");
        }

        else{
        ptr -> data = v;
        printf("\nValue Sucessfully Updated.\n ");
        }

    }

}

int main(){

    int x, choice , p ,v;
    
    // Creating a Node of a  Single Linked List
    
    // struct node *first = NULL;
    // first = (struct node *)malloc(sizeof(struct node));
    
    // first-> data =45;
    // first-> next = NULL;
    // printf("%d \t",first->data=45);
   

    // struct node * temp = (struct node*) malloc(sizeof(struct node));
    // temp -> data = 94;
    // first-> next = temp;
    // temp -> next = NULL;

    // printf("%u\t",first->next);
    //  create();

    //  display();

    // traverse();

    // printf("\nEnter the Value you want to insert :\t ");
    // scanf("%d",&x);
    // insert(x);

    // display();

    //delete();
    //display();
  
    //   delete();
    //   display();
    while(1)
    
    {
   
    printf("\n Enter the operatoin you want to perform on Linked List : \n");
    printf(" Reminder , Make sure you have created the Linked List First.\n");
    printf(" Enter 1 :- to Create a Linked List. \n ");
    printf("Enter 2 :- to Display the Linked List \n ");
    printf("Enter 3 :- to Insert a element in the Linked List. \n ");
    printf("Enter 4 :- to Delete a element in the Linked List. \n ");
    printf("Enter 5 :- to Traverse and count the no. of Nodes in a Linked List. \n ");
    printf("Enter 6 :- to Reverse a Linked List. \n ");
    printf("Enter 7 :- to update a element in the Linked List. \n ");
    printf("Enter 8 :- to Search a element in the Linked List. \n ");
    printf("Enter 9 :- to Exit. \n");

    
    scanf("%d",&choice);

    switch(choice){

        case 1 :
            create();
            break;

        case 2 :
            display();
            break;

        case 3 :
            printf("\nEnter the Value you want to insert : ");
            scanf("%d",&x);
            insert(x);
            break;

        case 4 :
            delete();
            break;

        case 5 :
            traverse();
            break;

        case 6 :
           reverse();
           break;

        case 7 :
            printf("Enter the Position  to update : \n");
            scanf("%d",&p);
            printf("Enter the Value to update : \n");
            scanf("%d",&v);
            update(p,v);
            break;

        // case 8 :
        //     search();
        //     break;

        case 8 :
            exit(1);
            break;

        default :
            printf("Invalid Input");
                
        }

    }

    return 0;
}
