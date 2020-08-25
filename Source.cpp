#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
int count=1,k=1,co=1;
struct node
{
    int key;
    char s[10];
    struct node *left, *right;
};
struct noq
{
    char data[10];
    struct noq*next;
};
struct noq*make(char[]);
void enqueue(char[]);
struct node*create(int,char[]);
struct node*insert(struct node*,int,char[]);
struct node*dequeue(struct node*);
void display();
struct node * minValueNode(struct node*);
struct node* deleteNode(struct node*, int,char[]);
void start();
void login();
void tim();
int flag=0;
int preorder(struct node*,char []);
void fun(struct node*);
struct noq*START=NULL;
struct noq*last=NULL;
struct noq*make(char data[])
{
    struct noq*temp;
    temp=(struct noq*)malloc(sizeof(struct noq));
    strcpy(temp->data,data);
    temp->next=NULL;
    return(temp);
};
void enqueue(char s[])
{
    struct noq*temp;
    temp=make(s);
    if(START==NULL)
    {
        START=temp;
        last=temp;
    }
    else
    {
        last->next=temp;
        last=last->next;
    }
}
struct node *create(int item,char sk[])
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    strcpy(temp->s,sk);
    temp->left = temp->right = NULL;
    return temp;
}
struct node* insert(struct node* node, int key,char sk[])
{
    struct node*temp;
    temp=create(key,sk);
    if (node == NULL)
    {
        node=temp;
        count++;
        return node;
    }
    if (key < node->key)
        node->left  = insert(node->left, key,sk);
    else
        node->right = insert(node->right, key,sk);

    return node;
}
struct node*dequeue(struct node*root)
{
    if(count<=20)
    {
    int tok;
    char sp[10];
    if(START==NULL)
    {
        printf("All car is parked\n");
        getch();
    }
    else
    {
        struct noq*t;
        t=START;
        strcpy(sp,t->data);
        START=START->next;
        printf("Enter the token number\n");
        scanf("%d",&tok);
        root=insert(root,tok,sp);
        free(t);
    }
    return(root);
    }
    else
    {
        printf("PARKING IS FULL, NO MORE CAR CAN BE INSERTED\n");
        return(root);
    }
}
void display()
{
    int p=0;
    struct noq*t;
    if(START==NULL)
    {
        printf("No car in Waiting area\n");
    }
    else
    {
        t=START;
        printf("________________________________________________________________________________________________________\n");
        while(t!=NULL)
        {
            printf("%s|\t|",t->data);
            p++;
            t=t->next;
        }
        printf("\n");
        printf("_______________________________________________________________________________________________________\n");
        printf("Total no of CARS need to parked are %d\t",p);


    }
}
struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
    {
         current = current->left;
    }
    return current;
}
struct node* deleteNode(struct node* t, int key,char s[])
{
    if (t == NULL)
    {
        printf("Currently the parking slot is empty\n");
        return t;
    }


    if (key < t->key)
    {

        t->left = deleteNode(t->left, key,s);
    }


    else if (key > t->key)
    {

        t->right = deleteNode(t->right, key,s);
    }
    else
    {
        if (t->left == NULL)
        {
            struct node *temp = t->right;
            free(t);
            count--;
            return temp;
        }
        else if (t->right == NULL)
        {
            struct node *temp = t->left;
            free(t);
            count--;
            return temp;
        }
        struct node* temp = minValueNode(t->right);

        t->key = temp->key;
        strcpy(t->s,temp->s);
        t->right = deleteNode(t->right, temp->key,temp->s);
    }
    count--;
    return t;
}

void inorder(struct node*root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s\t",root->s);
        co++;
        inorder(root->right);
    }
}

void inorder1(struct node*root)
{
    if(root!=NULL)
    {
        inorder1(root->left);
        printf("The car no is:%s\t with token no is:%d\n",root->s,root->key);
        inorder1(root->right);
    }

}
int preorder(struct node*root,char c[])
{
    if(root!=NULL)
    {
        if(strcmp(root->s,c)==0)
        {
            flag=1;
            return(0);
        }
        else
        {
            preorder(root->left,c);
            preorder(root->right,c);
        }
    }
}
int main()
{
    system("color 4f");
    printf("\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t\t\t\t\xdb                                                     \xdb\n");
	printf("\t\t\t\t\xdb       =======================================       \xdb\n");
	printf("\t\t\t\t\xdb       ARDUINOMATED PARKING ALLOCATION SYSTEM        \xdb\n");
	printf("\t\t\t\t\xdb       =======================================       \xdb\n");
	printf("\t\t\t\t\xdb                                                     \xdb\n");
	printf("\t\t\t\t\xdb             Brought To You By VITIANS               \xdb\n");
	printf("\t\t\t\t\xdb                                                     \xdb\n");
	printf("\t\t\t\t\xdb                   PVR PARKING                       \xdb\n");
	printf("\t\t\t\t\xdb                                                     \xdb\n");
	printf("\t\t\t\t\xdb                 MAINTAIN SILENCE                    \xdb\n");
	printf("\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
	printf(" \n\t Press ENTER  To Continue:");
    getch();
    system("cls");
    login();
    start();
}
void start()
{
    int t,j,tempo,m;
    struct node *root = NULL;
    char s[10];
    char te[10];
    while(1)
    { system("cls");
    system("color 4f");
    printf("\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t\t\t\t\xdb                                                    \xdb\n");
	printf("\t\t\t\t\xdb       =============================                \xdb\n");
	printf("\t\t\t\t\xdb               PVR PARKING                          \xdb\n");
	printf("\t\t\t\t\xdb       =============================                \xdb\n");
	printf("\t\t\t\t\xdb        1.Arrival of Vehicle in Queue               \xdb\n");
	printf("\t\t\t\t\xdb        2.Insert Vehicle in Parking Slot            \xdb\n");
	printf("\t\t\t\t\xdb        3.Total no of Vehicle need to allot parking \xdb\n");
	printf("\t\t\t\t\xdb        4.Departure of Vehicle                      \xdb\n");
	printf("\t\t\t\t\xdb        5.Condition of Parking Area                 \xdb\n");
	printf("\t\t\t\t\xdb        6.Existence of Vehicle in parking slot      \xdb\n");
	printf("\t\t\t\t\xdb        7.Exit                                      \xdb\n");
	printf("\t\t\t\t\xdb                                                    \xdb\n");
	printf("\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
        printf("Enter your choice\n");
        scanf("%d",&t);
        switch(t)
        {
        case 1:
            printf("Enter the VEHICLE number\n");
            scanf("%s",&s);
            enqueue(s);
            break;
        case 2:
            root=dequeue(root);
            break;
        case 3:
            display();
            getch();

            break;
        case 4:
            system("cls");
            system("color E");
            printf("\nThe existing  token numbers are\n");
            inorder1(root);
            printf("\nEnter the token number of the VEHICLE and VEHICLE number to be depart \n");
            scanf("%d",&tempo);
            scanf("%s",&te);
            root=deleteNode(root,tempo,te);
            printf ( "\nPress any key to continue..." ) ;
            getch();
            break;
        case 5:
            system("cls");
            co=1;
            inorder(root);
            for(int i=co;i<=20;i++)
            {
                if(i<=10)
                {
                    printf("0\t");
                }
                else if(i==11)
                {
                    printf("\n");
                    printf("0\t");
                }
                else
                {
                    printf("0\t");
                }
            }
            if(root==NULL)
            {
                printf("\n");

                printf("Parking area is empty\n");
            }
            printf ( "\nPress any key to continue..." ) ;
            getch( ) ;
            break;
        case 6:
            system("cls");
            system("color D");
            printf("Enter the Vehicle number need to be searched\n");
            flag=0;
            scanf("%s",&te);
            j=preorder(root,te);
            if(flag==1)
            {
                printf("Vehicle found\n");
                printf("Press any key to continue\n");
                getch();

            }
            else
            {
                if(root==NULL)
                {
                    printf("Parking area is empty\n");
                }
                else
                {
                printf("Vehicle not found in Parking slot\n");
                }
                printf("Press any key to continue\n");
                getch();
            }
            break;
        case 7:
            exit(0);

        }
    }
}
void login()
{
    system("color E");
    int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="vit";
    char pass[10]="vit";
    char cap[10];
    do
{
    printf("\n");
    printf("\n");
    printf("\n");

    tim();
    printf("\n          \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  LOGIN FIRST  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  ");
    printf(" \n\n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n\n                       ENTER PASSWORD:-");

	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
	printf("\n");
	printf("                                        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf(" \n                       ENTER CAPTCHA:-> \xB2  Za5GTX \xB2\n");
	printf("                                        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	scanf("%s", &cap);


		if(strcmp(uname,"vit")==0 && strcmp(pword,"vit")==0 && strcmp(cap,"Za5GTX")==0)
	{
	    printf("\n\nPassword Match!\nLOADING");
        Sleep(1000);
        printf("\xDB\xDB\xDB\xDB");
        Sleep(1000);
        printf("\xDB\xDB\xDB\xDB");
        Sleep(1000);
        printf("\xDB\xDB\xDB\xDB");
        system("cls");
	    printf("  \n\n\n       WELCOME !! YOUR LOGIN IS SUCCESSFUL");
        printf("\n\n\n\t\t\t\tPress ENTER to continue...");
	    getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();

	}
}
while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}
void tim()
{
	int hours, minutes, seconds, day, month, year;


	time_t now;


	time(&now);

	printf("                                            %s", ctime(&now));

	struct tm *local = localtime(&now);

	hours = local->tm_hour;
	minutes = local->tm_min;
	seconds = local->tm_sec;

	day = local->tm_mday;
	month = local->tm_mon + 1;
	year = local->tm_year + 1900;


	if (hours < 12)
		printf("                                                        %02d:%02d:%02d am\n", hours, minutes, seconds);
	else
		printf("                                                    %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);


	printf("                                                    %02d/%02d/%d\n", day, month, year);

}



















