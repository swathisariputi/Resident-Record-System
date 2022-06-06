#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
typedef struct accommodation
{
   char firstname[N];
   char lastname[N];
   char accommodation_type [N];
   int idtype;
   struct idnum
   {
      char aadhaar[N];
      char passport[N];
      char empcode [N];
      struct idnum *next;
   }idnm;
   char address[N];
   struct accommodation *next;
}acc;
typedef struct list
{ 
   int data;
   char fn[N];
   char ln[N];
   struct list* next;
}ll;
acc* insertrecord(acc* a,int i)
{
	char idn[100];
	acc *ptr1 , *ptr, *x;
	x=a;
	ptr1=(acc*)malloc(sizeof(acc));
	printf("Enter first name,last name,accommodation type(I or II or III or IV)\n");
	scanf("%s %s %s",ptr1->firstname,ptr1->lastname,ptr1->accommodation_type);
	ptr1->idtype=i;
	if(ptr1->idtype==0)
	{
		printf("enter id number(aadhaar)\n");
		scanf("%s",idn);
		strcpy(ptr1->idnm.aadhaar,idn);
	}
	if(ptr1->idtype==1)
	{
		printf("enter id number(passport)\n");
		scanf("%s",idn);
		strcpy(ptr1->idnm.passport,idn);
	}
	if(ptr1->idtype==2)
	{
		printf("enter id number(empcode)\n");
		scanf("%s",idn);
		strcpy(ptr1->idnm.empcode,idn);
	}
	printf("enter address\n");
	scanf("%s",ptr1->address);
    ptr1->next=NULL;
	if(x==NULL)
	{
		x=ptr1;
		ptr1->next=NULL;
	}
	else
	{
		if(x->idtype > ptr1->idtype)
		{
			ptr1->next=x;
			x=ptr1;
		}
		else
		{
			ptr=x;
			while((ptr->next!=NULL) && ptr->next->idtype<=ptr1->idtype)
			{
				ptr=ptr->next;
			}
			ptr1->next=ptr->next;
			ptr->next=ptr1;
		}
	}
	return a;
}
ll* createlist(int x,char fn[N], char ln[N])
{
	ll* list=(ll*)malloc(sizeof(ll));
	list->data=x;
	strcpy(list->fn,fn);
	strcpy(list->ln,ln);
}
ll* insertlist(ll* l,int x,char fn[N],char ln[N])
{
	ll* i=createlist(x,fn,ln);
	i->next=l;
	l=i;
	return l;
}
void printrecord(acc *a)
{
	acc* x=a;
	printf("This is the records list:\n");
	printf("firstname  lastname  acctype  idtype  number  address\n");
	while(x != NULL)
	{
		printf("%s",x->firstname);
		printf("\t%s\t",x->lastname);
		printf("\t%s\t",x->accommodation_type);
		printf("\t%d\t",x->idtype);
		if(x->idtype == 0)
        {
            printf("\t%s",x->idnm.aadhaar);
        }
        else if(x->idtype == 1)
        {
        	printf("\t%s",x->idnm.passport);
        }
        else if(x->idtype == 2)
        {
        	printf("\t%s",x->idnm.empcode);
        }
		printf("\t%s",x->address);
		x=x->next;
		printf("\n");
	}
}
void removeDuplicates(acc *a)
{
	acc *ptr1,*ptr2,*f;
	ptr1=a;
	while(ptr1!=NULL && ptr1->next!=NULL)
    {
    	ptr2=ptr1;
        while(ptr2->next!=NULL)
        {
            if(ptr1->idtype==0 && ptr2->next->idtype==0)
            {
                if (strcmp(ptr1->idnm.aadhaar, ptr2->next->idnm.aadhaar) == 0)
                {
                	f=ptr2;
                	ptr2->next=ptr2->next->next;
                	free(f);
                } 
            }
            else if(ptr1->idtype==1 && ptr2->next->idtype==1)
            {
                if (strcmp(ptr1->idnm.passport, ptr2->next->idnm.passport) == 0)
                {
                	f=ptr2;
                	ptr2->next=ptr2->next->next;
                	free(f);
				}           
			}
			else if(ptr1->idtype==2 && ptr2->next->idtype==2)
			{
				if (strcmp(ptr1->idnm.empcode, ptr2->next->idnm.empcode) == 0)
				{
					f=ptr2;
                	ptr2->next=ptr2->next->next;
                	free(f);
				}
			}
			else
			{
				ptr2=ptr2->next;
			}
        }
        ptr1=ptr1->next;
    }
}
void printRecords(acc *a)
{
	acc *temp=a;
	printf("firstname  lastname  acctype  idtype  number  address\n");
	while(a!=NULL)
	{
   		if(a->idtype == 0)
  		{
            printf("%s\t%s\t\t%s\t\t%d\t\t%s\t%s",a->firstname,a->lastname,a->accommodation_type,a->idtype,a->idnm.aadhaar,a->address);
            printf("\n");
		}
		a=a->next;
	}
	a=temp;
	while(a!=0)
	{
		if (a->idtype == 1)
  		{
	  		printf("%s\t%s\t\t%s\t\t%d\t\t%s\t%s",a->firstname,a->lastname,a->accommodation_type,a->idtype,a->idnm.passport,a->address);
	  		printf("\n");
		}
		a=a->next;
	}
	a=temp;
	while(a!=0)
	{
		if(a->idtype == 2)
		{
			printf("%s\t%s\t\t%s\t\t%d\t\t%s\t%s",a->firstname,a->lastname,a->accommodation_type,a->idtype,a->idnm.empcode,a->address);
			printf("\n");
		}
		a=a->next;
  	}
  	a=temp;
}
void printSortedRecords(acc *a,ll *l)
{
	acc* x=a;
	ll* y=l; 
	int i=1;
	while(i!=6)
	{
	while(y!=NULL)
	{
		while(x!=NULL)
		{
		    if(y->data==i)
		    {
				if(strcmp(y->fn,x->firstname)==0)
				{
					if(x->idtype==0)
			        {
				        printf("%s\t%s\t\t%s\t\t%d\t\t%s\t%s",x->firstname,x->lastname,x->accommodation_type,x->idtype,x->idnm.aadhaar,x->address);
				        printf("\n");
			        }
			        if(x->idtype==1)
			        {
				        printf("%s\t%s\t\t%s\t\t%d\t\t%s\t%s",x->firstname,x->lastname,x->accommodation_type,x->idtype,x->idnm.passport,x->address);
				        printf("\n");
			        }
			        if(x->idtype==2)
			        {
				        printf("%s\t%s\t\t%s\t\t%d\t\t%s\t%s",x->firstname,x->lastname,x->accommodation_type,x->idtype,x->idnm.empcode,x->address);
				        printf("\n");
			        }
			    }
		    }
		    x=x->next;
        }
        x=a;
		y=y->next;
	}
	y=l;
	i++;
}
}
ll* indexRecords(acc *a,ll *l)
{
	acc *x=a;
    while(x!=NULL)
    {
    	acc *ptr=a;
    	char fn[N],ln[N];
    	strcpy(fn,x->firstname);
    	strcpy(ln,x->lastname);
    	int i=1;
        while(ptr!=NULL)
        {
            char temp[N],temp2[N];
            if (strcmp(x->firstname, ptr->firstname) == 0)
            {
                if (strcmp(x->lastname, ptr->lastname) > 0)
                {
                    i++;
                }
            }
            else if (strcmp(x->firstname,ptr->firstname) > 0)
            {
                i++;
            }
            ptr=ptr->next;
        }
        l=insertlist(l,i,fn,ln);
        x=x->next;
    }
    return l;
}
void search(acc *a)
{
	int c=0,s=0;
	acc *x=a;
    char name[100];
    printf("enter name of employee to search record\n");
    scanf("%s", name);
    while(x!=NULL)
    {
        if (strcmp(x->firstname, name) == 0)
        {
            if (x->idtype == 0)
            {
                printf("%s %s %s %d %s  %s\n",x->firstname,x->lastname,x->accommodation_type,x->idtype,x->idnm.aadhaar,x->address);
            }
            else if (x->idtype == 1)
            {
                printf("%s %s %s %d %s  %s\n",x->firstname,x->lastname,x->accommodation_type,x->idtype,x->idnm.passport,x->address);
            }
            else if (x->idtype == 2)
            {
                printf("%s %s %s %d %s  %s\n",x->firstname,x->lastname,x->accommodation_type,x->idtype,x->idnm.empcode,x->address);
            }
        }
        x=x->next;
        c++;
    }
    x=a;
    while(x!=NULL)
    {
	    if(strcmp(x->firstname,name)!=0)
		{
		    s++;	
		}
		x=x->next;	
	}
	if(c==s)
	{
		printf("THERE IS NO RECORD OF EMPLOYEE NAMED %s\n",name);
	}
}
void deleteRecord(acc **a,int i,char j[])
{
	acc *temp=*a,*prev=NULL;
    while(temp!=NULL)
    {
	 if(temp->idtype==i)
     {
    	if(i==0 && strcmp(temp->idnm.aadhaar,j)==0)
    	{
    		if(temp == *a)
    		{
		   	    *a=temp->next;
    	        free(temp);
    	    }
    	    else
    	    {
    	    	prev->next=temp->next;
    	    	free(temp);
			}
    	}
    	else if(i==1 && strcmp(temp->idnm.passport,j)==0)
    	{
    		if(temp == *a)
    		{
		   	    *a=temp->next;
    	        free(temp);
    	    }
    	    else
    	    {
    	        prev->next=temp->next;
    	    	free(temp);
			}
    	}
    	else if(i==2 && strcmp(temp->idnm.empcode,j)==0)
    	{
    		if(temp == *a)
    		{
		   	    *a=temp->next;
    	        free(temp);
    	    }
    	    else
    	    {
    	    	prev->next=temp->next;
    	    	free(temp);
			}
    	}
	}
	prev=temp;
	temp=temp->next;
   }
}
void updateRecord(acc *a,char name[N])
{
	acc *x=a;
	int  choice,s=0,c=0,temp;
	char tmp[N];
	while(x!=NULL)
	{
	if(strcmp(name,x->firstname)==0)
	{
	printf("ENTER field to be updated (press 1 for firstname  2 for last name 3 for accomodation type)\n");
	printf(" \n4 id type 5 address\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Enter the new firstname.\n");
        scanf("%s",tmp);
        strcpy(x->firstname,tmp);
        printf("updated\n");
	}
	else if(choice==2)
	{
		printf("Enter the new lastname.\n");
        scanf("%s",tmp);
        strcpy(x->lastname,tmp);
        printf("updated\n");
	}
	else if(choice==3)
	{
		printf("Enter the new acctype.\n");
	    scanf("%s",tmp);
        strcpy(x->accommodation_type,tmp);
        printf("updated\n");
	}
	else if(choice==4)
	{
		printf("Enter the new id num.\n");
        scanf("%d",&temp);
        x->idtype=temp;
        if(x->idtype==0)
        {
        	printf("enter aadhaar num\n");
        	scanf("%s",tmp);
            strcpy(x->idnm.aadhaar,tmp);
            printf("updated\n");
		}
		else if(x->idtype==1)
        {
        	printf("enter passport num\n");
        	scanf("%s",tmp);
            strcpy(x->idnm.passport,tmp);
            printf("updated\n");
		}
		else if(x->idtype==2)
        {
        	printf("enter empcode num\n");
        	scanf("%s",tmp);
            strcpy(x->idnm.empcode,tmp);
            printf("updated\n");
		}
	}
	else if(choice==5)
	{
		printf("enter address\n");
		scanf("%s",tmp);
        strcpy(x->address,tmp);
        printf("updated\n");
	}
   }
   	x=x->next;
	c++;
   }
   while(x!=NULL)
   {
   	if(strcmp(name,x->firstname)>0)
   	{
   		s++;
	}
   }
   if(s==c)
   {
   	printf("\nTHER IS NO SUCH RECORD NAMED %s TO UPDATE\n",name);
   }
   return ;
}
typedef struct accommodation_type
{
   char firstnam[N];
   char lastnam[N];
   char accommodation_type1 [10];
   char accommodation_type2 [10];
   char accommodation_type3 [10];
   char accommodation_type4 [10];
   int idtyp;
   struct idnm
   {
      char aadhar[N];
      char pasport[N];
      char empcod[N];
   }idn;
   char adress[N];
   struct accommodation_type *next;
}acctype;
acctype* create_record1(char fn[N], char ln[N], char acctype1[10],char acctype2[10],char acctype3[10],char acctype4[10], int id, char idnm[N], char add[N])
{
	acctype* x=(acctype*)malloc(sizeof(acctype));
	strcpy(x->firstnam,fn);
	strcpy(x->lastnam,ln);
	strcpy(x->accommodation_type1,acctype1);
    strcpy(x->accommodation_type2,acctype2);
    strcpy(x->accommodation_type3,acctype3);
    strcpy(x->accommodation_type4,acctype4);
	x->idtyp=id;
    if(id == 0)
    {
    	strcpy(x->idn.aadhar,idnm);
	}
	if(id == 1)
    {
    	strcpy(x->idn.pasport,idnm);
	}
	if(id == 2)
    {
    	strcpy(x->idn.empcod,idnm);
	}
    strcpy(x->adress,add);
    return x;
}
acctype* insertrecord1(acctype* at,char fn[N], char ln[N], char acctype1[N],char acctype2[N],char acctype3[N],char acctype4[N], int id, char idnm[N], char add[N])
{
    acctype* i=create_record1(fn,ln,acctype1,acctype2,acctype3,acctype4,id,idnm,add);
    i->next=at;
    at=i;
    return at;
}
int specialRequestAllocation(int S, int B,acctype *at)
{
    int value;
    if(S==1)
    {
        if(at->accommodation_type1[B-1]=='a')
        {
            value = 0;
        }
        else
        {
        	value = 1;
            at->accommodation_type1[B-1] = 'a';
        }
    }
    else if(S==2)
    {
        if(at->accommodation_type2[B-1]=='a')
        {
            value = 0;
        }
        else
        {
        	value = 1;
            at->accommodation_type2[B-1] = 'a';
        }
    }
    else if(S==3)
    {
        if(at->accommodation_type3[B-1]=='a')
        {
            value = 0;
        }
        else
        {
        	value = 1;
            at->accommodation_type3[B-1] = 'a';
        }
    }
    else if(S==4)
    {
        if(at->accommodation_type4[B-1]=='a')
        {
            value = 0;
        }
        else
        {
        	value = 1;
            at->accommodation_type4[B-1] = 'a';
        }
    }
    return value;
}
int main()
{
    acc *a=(acc*)malloc(sizeof(acc));
    ll *l=(ll*)malloc(sizeof(ll));
    strcpy(a->firstname,"swathi");
    strcpy(a->lastname,"sariputi");
    strcpy(a->accommodation_type,"I");
    a->idtype=1;
    strcpy(a->idnm.passport,"4527893");
    strcpy(a->address,"Bajaj Nagar,Nagpur");
    a->next=NULL;
    l->data=0;
    strcpy(l->fn,"fn");
    strcpy(l->ln,"ln");
    l->next=NULL;
    char firstname[N],lastname[N],accommodation_type[N],idnum[N],add[N];
	int choice,idtyp;
    do
    {
    	printf("enter 1 for inserting record\n");
    	printf("enter 2 for removing duplicate and printing records\n");
    	printf("enter 3 for printing records like idtype 0 are printed frst and 1 second and 2 at end\n");
    	printf("enter 4 for printing sorted records in alphabetical order\n");
    	printf("enter 5 for searching record\n");
    	printf("enter 6 for deleting record\n");
    	printf("enter 7 for updating record\n");
    	printf("enter 8 for knowing availability of block for allocation\n");
    	printf("enter 9 for removing records\n");
    	printf("enter 10 for exit\n");
    	scanf("%d",&choice);
    	if(choice == 1)
    	{
            printf("ENTER idtype 0 or 1 or 2(0 for aadhar 1 for passport 2 for empcode)\n");
            scanf("%d",&idtyp);
            if(idtyp == 0)
            {
                a=insertrecord(a,idtyp);
                printf("\nINSERTION DONE\n\n");
			}
			else if(idtyp == 1)
            {
                a=insertrecord(a,idtyp);
                printf("\nINSERTION DONE\n\n");
			}
			else if(idtyp == 2)
            {
                a=insertrecord(a,idtyp);
                printf("\nINSERTION DONE\n\n");
			}
            else
			{
				printf("\nYOU HAVE ENTERED A INVALID IDTYPE.\n\n");
			}
		}
		if(choice == 2)
		{
			printrecord(a);
		}
		if(choice==3)
		{
		    printRecords(a);
		}
		if(choice==4)
		{
			l=indexRecords(a,l);
			printSortedRecords(a,l);
		}
		if(choice==5)
		{
			search(a);
		}
		if(choice==6)
		{
			printf("ENTER THE IDTYPE AND IDNUMBER OF LIST YOU WANT TO DELETE/n");
			scanf("%d %s",&idtyp,idnum);
			deleteRecord(&a,idtyp,idnum);
			indexRecords(a,l);
		}
		if(choice == 7)
		{
			char name[N];
			printf("enter name(first name) of employee whose record is to be updated\n");
			scanf("%s",name);
			updateRecord(a,name);
			indexRecords(a,l);
		}
		if(choice==8)
        {
        	int b,s;
        	acctype *at=(acctype*)malloc(sizeof(acctype));
        	strcpy(at->firstnam,"swathi");
            strcpy(at->lastnam,"sariputi");
            strcpy(at->accommodation_type1,"I");
            strcpy(at->accommodation_type2,"II");
            strcpy(at->accommodation_type3,"III");
            strcpy(at->accommodation_type4,"IV");
            at->idtyp=1;
            strcpy(at->idn.pasport,"4527893");
            strcpy(at->adress,"Bajaj Nagar,Nagpur");
            at->next=NULL;
            at=insertrecord1(at,"a","b","aaaaananaa","aananaaana","aaaaaaaaaa","anaanaaaaa",1,"234567","nagpur");
            printf("Enter the accommodation type(1 for I,2 for II,3 for III and 4 for IV) and block number(1 to 10) to accommodate:");
            scanf("%d %d",&s,&b);
            if(specialRequestAllocation(s,b,at)==0)
            {
                printf("The block you entered is already filled\n\n");
            }
            if(specialRequestAllocation(s,b,at)==1)
            {
                printf("\nALLOCATION DONE\n");
            }
		}		
		if(choice == 9)
		{
			printrecord(a);
		}
	}while(choice != 10);
	    return 0;
}

