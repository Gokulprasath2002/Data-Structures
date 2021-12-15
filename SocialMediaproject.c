#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
    {
        char name[50];
        int age;
        char gender[10];
        char country[10];
        char username[20];
        char password[10];
        char copassword[10];
        char message[100];
        char recmessage[100];
        struct node *next;
    }*head,*ptr,*temp,*present;
    int x=0,y=0,z=0;
void Display_Profile();
void Available_User();
void Send_Message(); 
void read_message();
int Login()
{
    char user[20],pass[20];
    int flag=1,z=1,x=0,y=0,i=0,a=1;
    
    if(head==NULL)
    {
        printf("\nYou haven't created an account\n");
    }
    else
    {
    while(flag>0)
    {
        if(z==2)
        {
            printf("\nInvalid username or Password\n");
            printf("Enter your username:");
            scanf("%s",user);
            printf("Enter your password:");
            scanf("%s",pass);
            flag=1;
        }
        else if(z==1)
        {    printf("Enter your username:");
            scanf("%s",user);
             printf("Enter your password:");
            scanf("%s",pass);
        }
        else
        {
            flag=0;
        }
        temp=head;
        while(temp!=NULL)
        {   
            x=strcmp(temp->username,user);
            y=strcmp(temp->password,pass);
            if(x==0 && y==0)
            {
                printf("\nSuccessfully logined\n");
                while(1)
                {
                    present=temp;
                    int choice;
                    printf("\n1]Display Profile\n2]List available users\n3]Send Message\n4]Read Message\n5]Exit\n");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1:
                            Display_Profile();
                            break;
                        case 2:
                            Available_User();
                            break;
                        case 3:
                            Send_Message();
                            break;
                        case 4:
                            read_message(present);
                            break;
                        case 5:
                            return 0;
                        default:
                            printf("\nInvalid option\n");
                    }
                }    
                flag=0;
            }    
            i++;
            temp=temp->next;    
        }
        z=2;
    }
    }
}
void Display_Profile()
{
    printf("Username:%s\n",present->username);
    printf("Name:%s\n",present->name);
    printf("Age:%d\n",present->age);
    printf("Gender:%s\n",present->gender);
    printf("Country:%s\n",present->country);
}
void Available_User()
{
    int x=0;
    temp=head;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        x=strcmp(temp->username,present->username);
        if(x!=0)
        {
            printf("%s\n",temp->username);
        }    
        else
           continue; 
    }
}
void Send_Message()
{
    char tuser[20],msg[100];
    int flag=1,z=1,x=0,i=0,a=1,m=-1;
    
    while(flag>0)
    {
        if(z==2)
        {
            printf("\nInvalid username\n");
            printf("Enter the username:");
            scanf("%s",tuser);
            flag=1;
        }
        else if(z==1)
        {    printf("Enter the username:");
            scanf("%s",tuser);
        }
        else
        {
            flag=0;
        }
        temp=head;
        while(temp!=NULL)
        {   
            x=strcmp(temp->username,tuser);
            if(x==0)
            {
                int ch=0;
                
                printf("\n%s is Available\n",tuser);
                while(a)
                {   
                    printf("\nEnter 1]To Message 2]Exit\n");
                    scanf("%d",&ch);
                    switch(ch)
                    {
                        case 1:
                            m++;
                            printf("Enter the message to send\n");
                            int c;
                            
                            while ( (c = getchar()) != '\n' && c != EOF ) { }
                           scanf ("%[^\n]", temp->message);
                            strcpy(temp->recmessage,temp->message);
                            break;
                        case 2:
                            a=0;
                            break;
                        default:
                            printf("\nInvalid choice\n");
                    }
                }
                flag=0;
            }    
            i++;
            temp=temp->next;    
        }
        z=2;
    }
}
void read_message(struct node *present)
{
    int x;
    temp=head;
    while(temp!=NULL)
    {
        x=strcmp(present->username,temp->username);
        if(x==0)
        {
             printf("%s",temp->recmessage);
         
        }    
        temp=temp->next;
    }
}
void Signup()
{
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
        printf("\nError Occured!Please try again\n");
    else
    {
       printf("Enter your name:");
        scanf("%s",ptr->name);
        printf("\nEnter your age:");
        scanf("%d",&ptr->age);
        printf("\nEnter your gender:");
        scanf("%s",ptr->gender);
        printf("\nEnter your country:");
        scanf("%s",ptr->country);
        printf("\nEnter your username:");
        scanf("%s",ptr->username);
        printf("\nEnter your password:");
        scanf("%s",ptr->password);
        printf("\nConfirm your password:");
        scanf("%s",ptr->copassword);
        if(head==NULL)
        {
             y=strcmp(ptr->password,ptr->copassword);
            while(y)
            {
                z=0;
                printf("\nConfirm Password doesn't Match with Password\n");
                printf("Confirm Password:");
                scanf("%s",ptr->copassword);
                z=strcmp(ptr->password,ptr->copassword);
                if(z==0)
                    y=0;
                else
                    y=1;
            }
            ptr->next=NULL;
            head=ptr;
            printf("\nAccount Created Successfully!!!\n");
        }
        else
        {  
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            temp=head;
            while(temp->next!=NULL)
            {
                x=strcmp(ptr->username,temp->username);
                if(x==0)
                {
                    printf("The username already exist!!!\n");
                    printf("\nEnter a valid  username:");
                    scanf("%s",ptr->username);
                    y=strcmp(ptr->username,temp->username);
                    while(!y)
                        {
                            printf("The username already exist!!!\n");
                            printf("\nEnter a valid  username:");
                            scanf("%s",ptr->username);
                            z=strcmp(ptr->username,temp->username); 
                            if(z==0)
                                y=0;
                            else
                                y=1;
                        }
                }    
                temp=temp->next;    
            }
            y=strcmp(ptr->password,ptr->copassword);
            while(y)
            {
                int z=0;
                printf("\nConfirm Password doesn't Match with Password\n");
                printf("Confirm Password:");
                scanf("%s",ptr->copassword);
                z=strcmp(ptr->password,ptr->copassword);
                if(z==0)
                    y=0;
                else
                    y=1;
            }
            ptr->next=NULL;
            printf("\nAccount Created Successfully!!!\n");
        }
    }
}
void display()
{   int i=1;
    temp=head;
    if(temp==NULL)
        printf("\nNo users are present here\n");
    else
    {
    while(temp!=NULL)
    {
        printf("User %d : %s\n",i,temp->username);
        temp=temp->next;
        i++;
    }
    }
}
void rec()
{
    int ch=0;
        printf("Enter your choice\n1]Signup\n2]Login\n3]Users\n4]Exit\n");
        scanf("%d",&ch);
        int c;
        while((c=getchar()!='\n' && c!=EOF)){}
        if(ch==1 || ch==2 || ch==3 || ch==4)
        switch(ch)
        {
            case 1:
                Signup();
                break;
            case 2:
                Login();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                
            default:
                printf("\nInvalid choice\n");
        }
        else
            rec();
}
int main()
{
    int x=0;
    head=NULL;
    temp=NULL;
    while(1)
    {
        rec();
    }
    return 0;
}