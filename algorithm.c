#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct student
{
    int val;
    char ch;
    short int status;
    struct student *next;
}NODE;
char no=0,change;
char *arr,*fe;
int n;
void main()
{
    int i,j;
    char a;
    arr=malloc(n*(sizeof(char)));
    fe=malloc(n*(sizeof(char)));
    NODE *male=NULL,*female=NULL;
    printf("\nenter number:");
    scanf("%d",&n);
    printf("\nMale Details\n");
    change=0;
    for(i=1;i<=n;i++)
    {
        addRecord1(&male,i);
        for(j=1;j<=n;j++)
        {
        printf("Enter female preferences for male\n",j,i);
        addRecord(&male,j);
        }
    }
    change=1;
    printf("\nFemale details");
    for(i=1;i<=n;i++)
    {
        addRecord1(&female,i);
        for(j=1;j<=n;j++)
        {
        printf("Enter Male preferences for female\n",j,i);
        addRecord(&female,j);
        }
    }
    printf("\nMale DataStructure");
    printRecord(male);
    printf("\nFemale DataStructure");
    printRecord(female);
    /*for(i=0;i<n;i++)
        printf("%c",arr[i]);
    for(i=0;i<n;i++)
        printf("%c",fe[i]);*/

       findmale(&male,&female);
}
void addRecord(NODE **p,int a)
{
    NODE *nu,*temp=*p;
    nu=malloc(sizeof(NODE));
    nu->val=a;
    printf("\t\tEnter name");
    scanf("\n%c",&nu->ch);
    nu->status=0;
    if(*p==NULL)
    {
        nu->next=NULL;
        *p=nu;
    }
    else
    {
        while(temp->next)
        temp=temp->next;

        nu->next=0;
        temp->next=nu;
    }
}
void printRecord(struct student *p)
{
    while(p)
    {
        printf("%c->",p->ch);
        if(((p->val)%n==0)&&((p->val)!=n))
            printf("\n");
        p=p->next;
    }
}
void addRecord1(NODE **p,int a)
{
    printf("\n--------------------\n");
    if(no==(n))
        no=0;
    NODE *nu,*temp=*p;
    nu=malloc(sizeof(NODE));
    nu->val=a;
    printf("\tEnter name");
    scanf("\n%c",&nu->ch);
    if(change==0)
        arr[no]=nu->ch;
    else if(change==1)
    {
     fe[no]=nu->ch;
     //printf("no=%d,n=%d",no,n);
    }
    nu->status=0;
    if(*p==NULL)
    {
        nu->next=NULL;
        *p=nu;
    }
    else
    {
        while(temp->next)
        temp=temp->next;

        nu->next=0;
        temp->next=nu;
    }
    no++;
}
void findmale(NODE **p,NODE **q)
{
    NODE *mtemp=*p,*mtemp1=*p;
    NODE *ftemp=*q,*ftemp1=*q;
    char a,b;
    for(int i=0;i<n;i++)
    {
        //printf("\narr=%c",arr[i]);
      while(((mtemp->ch)!=arr[i])&&(mtemp->next))
        mtemp=mtemp->next;
       //printf("\nmtemp->ch=%c",mtemp->ch);//
        mtemp1=mtemp;
        for(int j=0;j<n;j++)
        {
            mtemp1=mtemp1->next;
            //printf("\nmtemp1->ch=%c",mtemp1->ch);
            ftemp=*q;
            while(((ftemp->ch)!=(mtemp1->ch)))
                ftemp=ftemp->next;
               // printf("\nftemp->ch=%c",ftemp->ch);
                ftemp1=ftemp;
                while(((ftemp1->ch)!=(mtemp->ch)))
                    ftemp1=ftemp1->next;
                //printf("\nftemp1->ch=%c",ftemp1->ch);
           //for(int k=0;k<n;k++)
            //{
                if(((ftemp1->ch)==(mtemp->ch)))
                {
                    //printf("\nftemp1->ch=%c",ftemp1->ch);
                    //printf("\nmtemp1->ch=%c",mtemp1->ch);
                    //printf("\nmtemp->ch=%c",mtemp->ch);
                    //printf("\nftemp1->ch=%c",ftemp1->ch);
                    b=mtemp1->val;
                   // printf("\nwith respect to %c %c value=%d",arr[i],ftemp->ch,b);
                    a=ftemp1->val;
                    //printf("\nwith respect to %c %c value=%d\n\n",ftemp->ch,arr[i],a);
                    //if(b==1)
                   // printf("\n%c is perfect match with %c",arr[i],ftemp->ch);
                   if((a<=(n/2))&&(b<=(n/2)))
                    {
                     printf("\n%c perfect match with %c",arr[i],ftemp->ch);
                     ftemp1->val=1;
                     mtemp1->val=1;
                    }
                     else if(b>=a)
                      {
                          char low=a;
                          if(a<low)
                          {
                           printf("\n%c perfect match with %c",arr[i],ftemp->ch);
                           ftemp1->val=1;
                           mtemp1->val=1;
                          }
                      }

                }
                else
                ftemp1=ftemp1->next;
          //  }
        }

    }
}
