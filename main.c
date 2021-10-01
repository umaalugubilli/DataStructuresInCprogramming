#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node* next;
}*head,*new_node,*temp,*previous,*head1;
void create()
{
    char ch;
    do
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter a value : ");
        scanf("%d",&new_node->num);
        new_node->next=NULL;
        if(head1==NULL)
        {
            head1=new_node;
            temp=new_node;
        }
        else
        {
            temp->next=new_node;
            temp=new_node;
        }
        printf("Do yo want to continue (y/n): ");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');

}
void show()
{
    temp=head;
    printf("\nThe elements in the list : ");
    while(temp!=NULL)
    {
        printf("%d ",temp->num);
        temp=temp->next;
    }
}
void insert_end()
{
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter a new element: ");
    scanf("%d",&new_node->num);
    new_node->next=NULL;
    if(head!=NULL)
    {
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=new_node;
    }
    else
    {
        head=new_node;
        head->next=NULL;
    }

}
void insert_begin()
{
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter a new element : ");
    scanf("%d",&new_node->num);
    if(head!=NULL)
    {
        new_node->next=head;
        head=new_node;
    }
    else
    {
        head=new_node;
        head->next=NULL;
    }
}
void insert_after()
{
    int num1,count=0;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->next=NULL;
    if(head!=NULL)
    {
        printf("Enter a element from the list to insert the new element after this : ");
        scanf("%d",&num1);
        temp=head;
        while(temp!=NULL)
        {
                if(temp->num==num1)
                {
                    count=1;
                    break;
                }
                temp=temp->next;
        }
        if(count==1)
        {
            if(temp->next==NULL)
                    insert_end();
            else
            {
                printf("\nEnter a new element : ");
                scanf("%d",&new_node->num);
                new_node->next=temp->next;
                temp->next=new_node;
            }
        }
        else
            printf("The element you have entered isn't in the list");
    }
    else
    {
        head=new_node;
        head->next=NULL;
    }
}
void insert_before()
{
    int num1,count=0;
    new_node=(struct node *)malloc(sizeof(struct node));
    previous=(struct node *)malloc(sizeof(struct node));
    if(head!=NULL)
    {
        printf("Enter a element from the list to insert the new element before this : ");
        scanf("%d",&num1);
        temp=head;
        previous=temp;
        if(temp->num==num1)
        {
            printf("\nEnter a new element : ");
            scanf("%d",&new_node->num);
            new_node->next=head;
            head=new_node;
        }
        else
        {
                while(temp!=NULL)
                {
                    if(temp->num==num1)
                    {
                        count=1;
                        break;
                    }
                    previous=temp;
                    temp=temp->next;
                }
                if(count==1)
                {
                    printf("\nEnter a new element : ");
                    scanf("%d",&new_node->num);
                    new_node->next=previous->next;
                    previous->next=new_node;
                }
                else
                    printf("The number you have entered isn't in the list ");
        }
    }
    else
    {
        head=new_node;
        head->next=NULL;
    }
}
void delete_head()
{
    if(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
        printf("Deleting the head node of the list . . . . ");
    }
    else
        printf("There is no list");
}
void delete_end()
{
    if(head!=NULL)
    {
        temp=head;
        while(temp->next!=NULL){
                previous=temp;
            temp=temp->next;
        }
        previous->next=NULL;
        printf("Deleting the last node of the list . . . . ");
    }
    else
        printf("There is no list");
}
void delete_specific()
{
    int num1,count=0;
    if(head!=NULL)
    {
        printf("Enter a element to delete : ");
        scanf("%d",&num1);
        temp=head->next;
        if(head->num==num1)
            delete_head();
        else
        {

            while(temp!=NULL)
            {
                if(temp->num==num1)
                {
                    count=1;
                    break;
                }
                previous=temp;
                temp=temp->next;
            }
            if(count==1)
            {
                if(temp->next==NULL)
                    delete_end();
                else
                    previous->next=temp->next;
                printf("\nDeleting the %d number in the list . . . .",num1);
            }
            else
                printf("The element you have entered isn't in the list");
        }
    }
    else
        printf("There is no list");
}
void find()
{
    int num1,i=1,count=0;
    if(head!=NULL)
    {
            printf("Enter a element to find where it is ? : ");
            scanf("%d",&num1);
            temp=head;
            while(temp!=NULL )
            {
                if(temp->num==num1)
                {
                    count=1;
                    break;
                }
                temp=temp->next;
                i++;
            }

            if(count==1)
               printf("\n\t---*--- The number %d is at the %d position  ---*---\n",num1,i);
            else
               printf("%d isn't in the list",num1);
    }
}
void modify()
{
    int num1;
    if(head!=NULL)
    {
        printf("Enter a node number to  modify : ");
        scanf("%d",&num1);
        temp=head;
        while(temp->num!=num1 && temp->next!=NULL)
        {
            temp=temp->next;

        }

        printf("Enter a new node number : ");
        scanf("%d",&temp->num);
    }

}
void merge()
{
    printf("\nFor merging we need another list so enter values for new list : ");
    if(head1==NULL)
        create();
    printf("\nThe elements in the newly created list ");
    temp=head1;
    while(temp!=NULL)
    {
        printf("%d ",temp->num);
        temp=temp->next;
    }
    temp=head;
    if(head!=NULL)
    {
        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=head1;
        printf("\n\nAfter merging . . . .  ");
        show();
    }
    else
        printf("\nThere is only one list is existed \n");
}
int main()
{
    char ch;
    int option;
    Main_menu :
        printf("\nSelect your option :  \n1.Insert at the head.\n2.Insert at the end.\n3.Insert after a particular element. ");
        printf("\n4.Insert before a particular element.\n5.Delete Head.\n6.Delete end.");
        printf("\n7.Delete specific element.\n8.Find specific element.\n9.Modify a node. \n10.Merge to lists");
    do
    {
        printf("\n\nEnter your option : ");
        scanf("%d",&option);

        switch(option)
        {
            case 1: insert_begin();
                    show();
                    break;
            case 2: insert_end();
                    show();
                    break;
            case 3: insert_after();
                    show();
                    break;
            case 4 : insert_before();
                    show();
                    break;
            case 5: delete_head();
                    show();
                    break;
            case 6 :delete_end();
                    show();
                    break;
            case 7: delete_specific();
                    show();
                    break;
            case 8: find();
                     show();
                     break;
            case 9: modify();
                     show();
                     break;
            case 10: merge();
                     break;

        }
        printf("\n\nDo you want to continue (y/n) : ");
        scanf(" %c",&ch);
        if(ch=='y'||ch=='Y')
            goto Main_menu;

    }while(ch=='y'|| ch=='Y');

}
