#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct accommodation 
{ 
    char firstname[50]; 
    char lastname[50]; 
    char accommodation_type[20]; 
    int idtype; 
    struct idnum 
    { 
        char aadhaar[15]; 
        char passport[15]; 
        char empcode[15]; 
    }idnm; 
    char address[100];
	int key;            //key is record number here
	struct accommodation *left;
	struct accommodation *right;
	int height; 
}acc;
typedef struct index
{
	int key;    //key is number for index inserted
	int index;
	char firstname[50];
	char lastname[50];
	struct index *left;
	struct index *right;
	int height;
}in;
typedef struct accommodation_type
{
   struct accommodation_typeA
   {
   	    char A[10];
   }Atype;
   struct accommodation_typeB
   {
   	    char B[10];
   }Btype;
   struct accommodation_typeC
   {
   	    char C[10];
   }Ctype;
   struct accommodation_typeD
   {
   	    char D[10];
   }Dtype;
   int key;    //key is accommodation_type node number
   struct accommodation_type *left;
   struct accommodation_type *right;
   int height;
}acctype;
int max(int x, int y)    //maximum of two numbers
{
    return (x>y) ? x:y;
}
acc *create_record(int key,char fn[],char ln[],char at[],int idtype,char idnum[],char add[]) 
{                                                              //creating node for accommodation
    acc *ptr=(acc *)malloc(sizeof(acc));
    ptr->key=key;
    strcpy(ptr->firstname,fn);
    strcpy(ptr->lastname,ln);
    strcpy(ptr->accommodation_type,at);
    strcpy(ptr->address,add);
    ptr->idtype=idtype;
    if(idtype==0)
    {
    	strcpy(ptr->idnm.aadhaar,idnum);
	}
	else if(idtype==1)
	{
	    strcpy(ptr->idnm.passport,idnum);	
	}
	else if(idtype==2)
	{
		strcpy(ptr->idnm.empcode,idnum);
	}
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->height=1;
    return ptr;
}
int height(acc *A)    //Get height
{
	if(A==NULL)
	{
        return 0;
    }
    else
    {
        return A->height;
    }
}
int getbal(acc *A)     // Get balance factor
{
    if(A==NULL)
    {
        return 0;
    }
    else
    {
        return (height(A->left)-height(A->right));
	}
}
acc *right_rotate(acc *A)    //right rotation
{
    acc *I=A->left;
    acc *J=I->right;
    I->right=A;
    A->left=J;
    A->height=max(height(A->left),height(A->right))+1;
    I->height=max(height(I->left),height(I->right))+1;
    return I;
}
acc *left_rotate(acc *A)      //left rotation
{
    acc *I=A->right;
    acc *J=I->left;
    I->left=A;
    A->right=J;
    A->height=max(height(A->left),height(A->right))+1;
    I->height=max(height(I->left),height(I->right))+1;
    return I;
}
acc *insertRecord(acc *A,int key,char fn[],char ln[],char at[],int idtype,char idnum[],char add[]) 
{                                                 // Insert Record
    if(A==NULL)
    {
        return(create_record(key,fn,ln,at,idtype,idnum,add));
    }
    if(key<A->key)
    {
        A->left=insertRecord(A->left,key,fn,ln,at,idtype,idnum,add);
    }
    else if(key>A->key)
    {
        A->right=insertRecord(A->right,key,fn,ln,at,idtype,idnum,add);
    }
    else
    {
        return A;
    }
    A->height=1+max(height(A->left),height(A->right)); // Update the balance factor of each node and Balance the tree
    int balance=getbal(A);
    if(balance>1 && key<A->left->key)
    {
        return right_rotate(A);
    }
    if(balance<-1 && key>A->right->key)
    {
        return left_rotate(A);
    }
    if(balance>1 && key>A->left->key) 
	{
        A->left = left_rotate(A->left);
        return right_rotate(A);
    }
    if (balance<-1 && key<A->right->key) 
	{
        A->right = right_rotate(A->right);
        return left_rotate(A);
    }
  return A;
}
void printrecords(acc *root)         //inorder of accommodation tree
{
  if (root!=NULL) 
  {
  	if(root->idtype==0)
  	{
        printf("%s %s %s %d %s %s \n",root->firstname,root->lastname,root->accommodation_type,root->idtype,root->idnm.aadhaar,root->address);
    }
    if(root->idtype==1)
    {
        printf("%s %s %s %d %s %s \n",root->firstname,root->lastname,root->accommodation_type,root->idtype,root->idnm.passport,root->address);
  	}
	if(root->idtype==2)
    {
        printf("%s %s %s %d %s %s \n",root->firstname,root->lastname,root->accommodation_type,root->idtype,root->idnm.empcode,root->address);
    }
	printrecords(root->left);
    printrecords(root->right);
  }
}
void printrecord0(acc *root)  //print records with idtype 0
{
    if (root!=NULL) 
    { 
  	    if(root->idtype==0)
  	    {
            printf("%s %s %s %d %s %s \n",root->firstname,root->lastname,root->accommodation_type,root->idtype,root->idnm.aadhaar,root->address);
        }
	    printrecord0(root->left);
        printrecord0(root->right);
    }
}
void printrecord1(acc *root)   //print records with idtype 1
{
    if (root!=NULL) 
    { 
  	    if(root->idtype==1)
  	    {
            printf("%s %s %s %d %s %s \n",root->firstname,root->lastname,root->accommodation_type,root->idtype,root->idnm.passport,root->address);
        }
	    printrecord1(root->left);
        printrecord1(root->right);
    }
}
void printrecord2(acc *root)   //print records with idtype 2
{
    if (root!=NULL) 
    { 
  	    if(root->idtype==2)
  	    {
            printf("%s %s %s %d %s %s \n",root->firstname,root->lastname,root->accommodation_type,root->idtype,root->idnm.empcode,root->address);
        }
	    printrecord2(root->left);
        printrecord2(root->right);
    }
}
void printRecords(acc *root)   //printing records such that idtype 0 are printed first,1 next and then 2 at end
{
	printrecord0(root); //first print records with idtype 0
	printrecord1(root); //then print records with idtype 1
	printrecord2(root); //then print records with idtype 2
}
in *set_index(int key,int index,char fn[],char ln[]) //set index(create node for in tree)
{
    in *ptr=(in *)malloc(sizeof(in));
    ptr->key=key;
    ptr->index=index;
    strcpy(ptr->firstname,fn);
    strcpy(ptr->lastname,ln);
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->height=1;
    return ptr;
}
int height_index(in *A)    //get height
{
	if(A==NULL)
	{
        return 0;
    }
    else
    {
        return A->height;
    }
}
int getbal_index(in *A)   // Get balance factor
{
    if(A==NULL)
    {
        return 0;
    }
    else
    {
        return height_index(A->left) - height_index(A->right);
	}
}
in *right_rotate_index(in *A)   //right rotation
{
    in *I=A->left;
    in *J=I->right;
    I->right=A;
    A->left=J;
    A->height=max(height_index(A->left),height_index(A->right))+1;
    I->height=max(height_index(I->left),height_index(I->right))+1;
    return I;
}
in *left_rotate_index(in *A)  //left rotation
{
    in *I=A->right;
    in *J=I->left;
    I->left=A;
    A->right=J;
    A->height=max(height_index(A->left),height_index(A->right))+1;
    I->height=max(height_index(I->left),height_index(I->right))+1;
    return I;
}
in *insert_index(in *A,int key,int in,char fn[],char ln[])   //insert index
{
    if(A==NULL)
    {
        return(set_index(key,in,fn,ln));
    }
    if(key<A->key)
    {
        A->left=insert_index(A->left,key,in,fn,ln);
    }
    else if(key>A->key)
    {
        A->right=insert_index(A->right,key,in,fn,ln);
    }
    else
    {
        return A;
    }      // Update the balance factor of each node and Balance the tree
    A->height=1+max(height_index(A->left),height_index(A->right));
    int balance=getbal_index(A);
    if(balance>1 && key<A->left->key)
    {
        return right_rotate_index(A);
    }
    if(balance<-1 && key>A->right->key)
    {
        return left_rotate_index(A);
    }
    if(balance>1 && key>A->left->key) 
	{
        A->left = left_rotate_index(A->left);
        return right_rotate_index(A);
    }
    if (balance<-1 && key<A->right->key) 
	{
        A->right = right_rotate_index(A->right);
        return left_rotate_index(A);
    }
    return A;
}
in* indexrecord(acc* A)          //giving index to record in alphabetical order
{
	int r=0,i;
	in* l;
    acc* x=A;
	acc* s=x->left;
    while(x!=NULL)
    {
        acc* ptr=s;
        char fn[50],ln[50];
        strcpy(fn,x->firstname);
        strcpy(ln,x->lastname);
        int i;
        while(ptr!=NULL)
        {
        	if(strcmp(x->firstname,ptr->firstname)==0)
            {
            	if(strcmp(x->lastname,ptr->lastname)>0)
            	{
                    i++;
                }
            }
        	else if(strcmp(x->firstname,ptr->firstname)>0)
            {
                i++;
            }
            ptr=ptr->left;
		}
		r++;
		l=insert_index(l,r,i,fn,ln);
		x=x->left;
    }
    return l;
}
acc* search(acc *root,char name[])   //search record with first name name[]
{
	acc *ptr=root,*ptr2=root;
    if(ptr!=NULL)
    {
        if(strcmp(name,ptr->firstname)!=0)
        {
            ptr=search(ptr->left,name);
        }
    }
	return ptr;
}
acc* get0(acc *root,char idnum[])           //get record with id number idnum[] of idtype 0
{
    if(root!=NULL)
    {		
        if(strcmp(idnum,root->idnm.aadhaar)!=0)
        {
            root=get0(root->left,idnum);
        }
    }
	return root;
}
acc* get1(acc *root,char idnum[])     //get record with id number idnum[] of idtype 1
{
    if(root!=NULL)
    {		
        if(strcmp(idnum,root->idnm.passport)!=0)
        {
            root=get1(root->left,idnum);
        }
    }
	return root;
}
acc* get2(acc *root,char idnum[])    //get record with id number idnum[] of idtype 2
{	
    if(root!=NULL)
    {		
        if(strcmp(idnum,root->idnm.empcode)!=0)
        {
            root=get2(root->left,idnum);
        }
    }
	return root;
}
acc* get(acc *root,int id,char idnum[])     //get record with id number idnum[] and idtype id
{
    if(id==0)
    {
    	root=get0(root,idnum);
	}
	if(id==1)
	{
		root=get1(root,idnum);
	}
	if(id==2)
	{
		root=get2(root,idnum);
	}
	return root;
}
acc *minValue(acc *A)          
{
    acc *current=A;
    while (current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}
acc *deleteRecord(acc *root, int key)   //deleting a record with record number key
{
    if(root == NULL)
    {
        return root;
    }
    if(key<root->key)
    {
        root->left = deleteRecord(root->left, key);
    }
    else if (key>root->key)
    {
        root->right = deleteRecord(root->right, key);
    }
    else 
	{
        if((root->left == NULL) || (root->right == NULL)) 
		{
            acc *temp = root->left ? root->left : root->right;
            if (temp == NULL) 
		    {
                temp = root;
                root = NULL;
            }    
		    else
		    {
                *root = *temp;
            }
		    free(temp);
		}
	   else 
	   {
            acc *temp = minValue(root->right);
            root->key = temp->key;
            root->right = deleteRecord(root->right, temp->key);
        }
    }
    if (root == NULL)
    {
        return root;
    }
    root->height = 1 + max(height(root->left),height(root->right)); // Update the balance factor of each node and Balance the tree
    int balance = getbal(root);
    if (balance > 1 && getbal(root->left) >= 0)
    {
		return right_rotate(root);
    }
    if (balance > 1 && getbal(root->left) < 0) 
	{
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if (balance < -1 && getbal(root->right) <= 0)
    {
        return left_rotate(root);
    }
    if (balance < -1 && getbal(root->right) > 0) 
	{
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}
void updateRecord(acc *root,char name[])  //update record with employee firstname name[]
{
	int i,id;
	char fn[50],ln[50],at[20],add[100],idnum[15];
	root=search(root,name);
	printf("Enter the field you want to update\n1 for firstname\n2 for lastname\n3 for acctype\n4 for idtype and idnum\n5 for address");
	scanf("%d",&i);   //updating based on field
	if(i==1)
	{
		printf("Enter first name to update:\n");
		scanf("%s",fn);
		strcpy(root->firstname,fn);
	}
	if(i==2)
	{
		printf("Enter last name to update:\n");
		scanf("%s",ln);
		strcpy(root->lastname,ln);
	}
	if(i==3)
	{
		printf("Enter accommodation to update:\n");
		scanf("%s",at);
		strcpy(root->accommodation_type,at);
	}
	if(i==4)
	{
		printf("Enter idtype to update:\n");
		scanf("%d",&id);
		root->idtype=id;
		if(id==0)
		{
			printf("Enter idnum(aadhaar) to update:\n");
			scanf("%s",idnum);
			strcpy(root->idnm.aadhaar,idnum);
		}
	    else if(id==1)
		{
			printf("Enter idnum(passport) to update:\n");
			scanf("%s",idnum);
			strcpy(root->idnm.passport,idnum);
		}	
		else if(id==2)
		{
			printf("Enter idnum(empcode) to update:\n");
			scanf("%s",idnum);
			strcpy(root->idnm.empcode,idnum);
		}
		else
		{
			printf("No such idtype\n");
		}
	}
	if(i==5)
	{
		printf("Enter address to update:\n");
		scanf("%s",add);
		strcpy(root->address,add);
	}
	return ;
}
acctype *create_acctype(int key,char A[],char B[],char C[],char D[]) //create node for acctype tree
{
    acctype *ptr=(acctype *)malloc(sizeof(acctype));
    ptr->key=key;
    strcpy(ptr->Atype.A,A);
    strcpy(ptr->Btype.B,B);
    strcpy(ptr->Ctype.C,C);
    strcpy(ptr->Dtype.D,D);
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->height=1;
    return ptr;
}
int height_acctype(acctype *A) //get height
{
	if(A==NULL)
	{
        return 0;
    }
    else
    {
        return A->height;
    }
}
int getbal_acctype(acctype *A) // Get the balance factor
{
    if(A==NULL)
    {
        return 0;
    }
    else
    {
        return height_acctype(A->left) - height_acctype(A->right);
	}
}
acctype *right_rotate_acctype(acctype *A) //right rotation
{
    acctype *I=A->left;
    acctype *J=I->right;
    I->right=A;
    A->left=J;
    A->height=max(height_acctype(A->left),height_acctype(A->right))+1;
    I->height=max(height_acctype(I->left),height_acctype(I->right))+1;
    return I;
}
acctype *left_rotate_acctype(acctype *A)   //left rotation
{
    acctype *I=A->right;
    acctype *J=I->left;
    I->left=A;
    A->right=J;
    A->height=max(height_acctype(A->left),height_acctype(A->right))+1;
    I->height=max(height_acctype(I->left),height_acctype(I->right))+1;
    return I;
}
acctype *insert_acctype(acctype *A,int key,char atA[],char atB[],char atC[],char atD[]) 
{
    if(A==NULL)
    {
        return(create_acctype(key,atA,atB,atC,atD));
    }
    if(key<A->key)
    {
        A->left=insert_acctype(A->left,key,atA,atB,atC,atD);
    }
    else if(key>A->key)
    {
        A->right=insert_acctype(A->right,key,atA,atB,atC,atD);
    }
    else
    {
        return A;
    }    //Update the balance factor of each node and Balance the tree
    A->height=1+max(height_acctype(A->left),height_acctype(A->right));
    int balance=getbal_acctype(A);
    if(balance>1 && key<A->left->key)
    {
        return right_rotate_acctype(A);
    }
    if(balance<-1 && key>A->right->key)
    {
        return left_rotate_acctype(A);
    }
    if(balance>1 && key>A->left->key) 
	{
        A->left = left_rotate_acctype(A->left);
        return right_rotate_acctype(A);
    }
    if (balance<-1 && key<A->right->key) 
	{
        A->right = right_rotate_acctype(A->right);
        return left_rotate_acctype(A);
    }
    return A;
}
int allocateBlock(acctype* X) //allocate a block if available
{
	int i=0,found=0;
	while(i<10&&found==0)
	{
		if(X->Atype.A[i]=='n')
		{
			X->Atype.A[i]='a';
			found=1;	
		}
		i++;
	}
	i=0;
	while(i<10&&found==0)
	{
		if(X->Btype.B[i]=='n')
		{
			X->Btype.B[i]='a';
			found=1;	
		}
		i++;
	}
	i=0;
	while(i<10&&found==0)
	{
		if(X->Ctype.C[i]=='n')
		{
			X->Ctype.C[i]='a';
			found=1;	
		}
		i++;
	}
	i=0;
	while(i<10&&found==0)
	{
		if(X->Dtype.D[i]=='n')
		{
			X->Dtype.D[i]='a';
			found=1;	
		}
		i++;
	}
	return found;
}
int deallocateBlock(acctype* X)   //deallocate a block
{
	int i=0,found=0;
	while(i<10&&found==0)
	{
		if(X->Atype.A[i]=='a')
		{
			X->Atype.A[i]='n';
			found=1;	
		}
		i++;
	}
	i=0;
	while(i<10&&found==0)
	{
		if(X->Btype.B[i]=='a')
		{
			X->Btype.B[i]='n';
			found=1;	
		}
		i++;
	}
	i=0;
	while(i<10&&found==0)
	{
		if(X->Ctype.C[i]=='a')
		{
			X->Ctype.C[i]='n';
			found=1;	
		}
		i++;
	}
	i=0;
	while(i<10&&found==0)
	{
		if(X->Dtype.D[i]=='a')
		{
			X->Dtype.D[i]='n';
			found=1;	
		}
		i++;
	}
	return found;
}
int specialRequestAllocation(acctype *X,int bt,int b)   //allocate a block requested
{
    int found=0,i=0;
    if(bt==1)
    {
        if(X->Atype.A[b-1]=='n')
        {
            found=1;
            X->Atype.A[b-1]='a';
        }
    }
    else if(bt==2)
    {
        if(X->Btype.B[b-1]=='n')
        {
            found=1;
            X->Btype.B[b-1]='a';
        }
    }
    else if(bt==3)
    {
        if(X->Ctype.C[b-1]=='n')
        {
            found=1;
            X->Ctype.C[b-1]='a';
        }
    }
    else if(bt==4)
    {
        if(X->Dtype.D[b-1]=='n')
        {
            found=1;
            X->Dtype.D[b-1]='a';
        }
    }
    return found;	
}
void printblocklist(acctype *root) //print acctype tree 
{
	int i;
    if(root!=NULL) 
    {
    	printf("a indicates allocated and n indicates non allocated\n");
	    for(i=0;i<10;i++)
		{
			int j=i+1;
		    printf("A%d = %c\t",j,root->Atype.A[i]);
		}
		printf("\n");
	    for(i=0;i<10;i++)
		{
			int j=i+1;
		    printf("B%d = %c\t",j,root->Btype.B[i]);
		}  
		printf("\n");
	    for(i=0;i<10;i++)
		{
			int j=i+1;
		    printf("C%d = %c\t",j,root->Ctype.C[i]);
		} 
		printf("\n");
	    for(i=0;i<10;i++)
		{
			int j=i+1;
		    printf("D%d = %c\t",j,root->Dtype.D[i]);
		} 
		printf("\n");              
  }
}
void addressSearch(acctype *X,int bt,int br1,int br2)   //get information about block allocation for given range
{
	int i;
	if(bt==1)
	{
		for(i=br1;i<=br2;i++)
		{
			if(X->Atype.A[i-1]=='a')
			{
			    printf("A%d-Allocated\n",i);
			}
			else
			{
				printf("A%d-Not Allocated\n",i);
			}
		}
	}
	if(bt==2)
	{
		for(i=br1;i<=br2;i++)
		{
			if(X->Btype.B[i-1]=='a')
			{
			    printf("B%d-Allocated\n",i);
			}
			else
			{
				printf("B%d-Not Allocated\n",i);
			}
		}
	}
	if(bt==3)
	{
		for(i=br1;i<=br2;i++)
		{
			if(X->Ctype.C[i-1]=='a')
			{
			    printf("C%d-Allocated\n",i);
			}
			else
			{
				printf("C%d-Not Allocated\n",i);
			}
		}
	}
	if(bt==4)
	{
		for(i=br1;i<=br2;i++)
		{
			if(X->Dtype.D[i-1]=='a')
			{
			    printf("D%d-Allocated\n",i);
			}
			else
			{
				printf("D%d-Not Allocated\n",i);
			}
		}
	}
}
void printlist(in *root)   //print index tree
{
  if (root!=NULL) 
  {
        printf("%d %s %s %d\n",root->index,root->firstname,root->lastname,root->key);
	    printlist(root->left);
        printlist(root->right);
  }
}
int main(int argc, char *argv[])
{
    acc *root=NULL;
    acctype *roota=NULL;
    in *rooti=NULL;
    char A[10]="nnananannn",B[10]="nanaannana",C[10]="nnaannaann",D[10]="aannaannaa";
	roota=insert_acctype(roota,1,A,B,C,D);
    char f[50],l[50],at[20],idnum[15],ad[100];
	int choice,id,r=0;
    do
    {
    	printf("\t||MENU||\n");
    	printf("\t---------\n");
    	printf("Enter 1 for inserting record\n");
    	printf("Enter 2 for removing duplicate entries of records \n");
    	printf("Enter 3 for printing records like idtype 0 are printed first,1 next and then 2 at end\n");
    	printf("Enter 4 for printing sorted records in alphabetical order of names\n");
    	printf("Enter 5 for searching record\n");
    	printf("Enter 6 for deleting record\n");
    	printf("Enter 7 for updating record\n");
    	printf("Enter 8 for knowing about block allocation(address search,special request allocation,etc)\n");
    	printf("Enter 9 for printing records\n");
    	printf("Enter 10 for exit\n");
    	scanf("%d",&choice);
    	if(choice == 1)
    	{
    		r++;
    		printf("ENTER EMPLOYEE DETIALS FOR INSERTING\nEnter first name:");
    		scanf("%s",f);
    		printf("Enter last name:");
    		scanf("%s",l);
    		printf("Enter accommodation type(I or II or III or IV):");
    		scanf("%s",at);
    		printf("Enter address(without spaces):");
    		scanf("%s",ad);
            printf("ENTER idtype 0 or 1 or 2(0 for aadhar 1 for passport 2 for empcode):");
            scanf("%d",&id);
            if(id==0)
            {
            	printf("Enter idnum(aadhaar):");
    		    scanf("%s",idnum);
                root=insertRecord(root,r,f,l,at,id,idnum,ad);
                printf("\nINSERTION DONE\n");
                int s=allocateBlock(roota);
				if(s==1)
				{
					printf("Block allocated\n\n");
				}
				else
				{
					printf("No Empty Blocks to allocate\n\n");
				}
			}
			else if(id==1)
            {
            	printf("Enter idnum(passport):");
    		    scanf("%s",idnum);
                root=insertRecord(root,r,f,l,at,id,idnum,ad);
                printf("\nINSERTION DONE\n");
                int s=allocateBlock(roota);
				if(s==1)
				{
					printf("Block allocated\n\n");
				}
				else
				{
					printf("No Empty Blocks to allocate\n\n");
				}
			}
			else if(id==2)
            {
            	printf("Enter idnum(employee code):");
    		    scanf("%s",idnum);
                root=insertRecord(root,r,f,l,at,id,idnum,ad);
                printf("\nINSERTION DONE\n");
                int s=allocateBlock(roota);
				if(s==1)
				{
					printf("Block allocated\n\n");
				}
				else
				{
					printf("No Empty Blocks to allocate\n\n");
				}
			}
            else
			{
				printf("\nYOU HAVE ENTERED A INVALID IDTYPE.\n\n");
			}
		}
		if(choice == 2)
		{
			//removeDuplicates(root);
			printf("No duplicate entries allowed in trees\n\n");
		}
		if(choice==3)
		{
		    printRecords(root);
		    printf("\n");
		}
		if(choice==4)
		{
			//rooti=indexrecord(root);
			printlist(rooti);
			printf("\n\n");
		}
		if(choice==5)
		{
			acc *ptr;
			printrecords(root);
			printf("Enter first name of employee to search:");
			scanf("%s",f);
			ptr=search(root,f);
			if(ptr->idtype==0)
			{
				printf("%s %s %s %d %s %s\n\n",ptr->firstname,ptr->lastname,ptr->accommodation_type,ptr->idtype,ptr->idnm.aadhaar,ptr->address);
			}
			else if(ptr->idtype==1)
			{
				printf("%s %s %s %d %s %s\n\n",ptr->firstname,ptr->lastname,ptr->accommodation_type,ptr->idtype,ptr->idnm.passport,ptr->address);
			}
			else if(ptr->idtype==2)
			{
				printf("%s %s %s %d %s %s\n\n",ptr->firstname,ptr->lastname,ptr->accommodation_type,ptr->idtype,ptr->idnm.empcode,ptr->address);
			}
		}
		if(choice==6)
		{
			printf("Records list: \n");
			printrecords(root);
			printf("ENTER THE IDTYPE AND IDNUMBER OF LIST YOU WANT TO DELETE FROM ABOVE LIST/n");
			scanf("%d %s",&id,idnum);
			acc* ptr=get(root,id,idnum);
	        int key=ptr->key;
			deleteRecord(root,key);
			//rooti=indexrecord(root);
			printf("Record Deleted\n");
			int s= deallocateBlock(roota);
			if(s==1)
			{
				printf("Block deallocated\n\n");
			}
			else
			{
				printf("No allocated Blocks to deallocate\n\n");
			}
		}
		if(choice == 7)
		{
			printrecords(root);
			printf("Enter name(first name) of employee from above list whose record is to be updated\n");
			scanf("%s",f);
			updateRecord(root,f);
			//rooti=indexrecord(root);
			printf("\n\n");
		}
		if(choice==8)
		{
			int o;
			printf("Enter 1 for seeing allocations of blocks\n");
			printf("Enter 2 for address search\n");
			printf("Enter 3 for special allocating block\n");
			scanf("%d",&o);
			if(o==1)
			{
				printblocklist(roota);
				printf("\n\n");				
			}
			if(o==2)
			{
				int bt,br1,br2;
				printf("Enter Block type(1,2,3,4 for A,B,C,D respectively) and block number range(ex:for B3 to B5 enter 2 3 5):");
			    scanf("%d %d %d",&bt,&br1,&br2);
			    if(bt==1||bt==2||bt==3||bt==4)
			    {
				    addressSearch(roota,bt,br1,br2);
				    printf("\n\n");
				}
				else
				{
					printf("No such Block type.You have entered invalid blocktype\n\n");
				}
			}
			if(o==3)
			{
				int bt,b;
				printf("Enter block type(1,2,3,4 for A,B,C,D respectively) and number for special allocation\n");
				scanf("%d %d",&bt,&b);
				int s=specialRequestAllocation(roota,bt,b);
                if(s==0)
                {
                    printf("The block you entered is already filled\n\n");
                }
                else
                {
                    printf("ALLOCATION DONE\n\n");
                }
			}
		}
		if(choice == 9)
		{
			printf("\nRecords:\n");
			printrecords(root);
			printf("\n\n");
		}
	}while(choice != 10);
	    return 0;
}
