#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
struct accommodation
{
   char firstname[50];
   char lastname[50];
   char accommodation_type [20];
   int idtype;
   struct idnum
   {
      char aadhaar[15];
      char passport[15];
      char empcode [15];
   }idnum;
   char address[100];
};
struct accommodation insertrecord( int i )
{
    struct accommodation a[N];
    printf("ENTER firstname,lastname,accommodation_type");
    scanf("%s %s %s",a[N].firstname,a[N].lastname,a[N].accommodation_type);
    printf("ENTER idtype");
    scanf("%d",&a[N].idtype);
    if(a[N].idtype == 0)
    {
      printf("ENTER id number(aadhaar)");
      scanf("%s",a[N].idnum.aadhaar);
    }
    else if(a[N].idtype == 1)
    {
      printf("ENTER id number(passport)");
      scanf("%s",a[N].idnum.passport);
    }
    else if(a[N].idtype == 2)
    {
      printf("ENTER id number(empcode)");
      scanf("%s",a[N].idnum.empcode);
    }
    printf("ENTER address");
    scanf("%s",a[N].address);
    return a[N];
}
void removeDuplicates(struct accommodation B[100],struct accommodation C[100],int n)
{
	int i,j,k,temp ;
	//printf("%d\n", n);
    for(i=0;i<n;i++)
    
    {
    	temp=1;
	}
	for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if(B[i].idtype==0 && B[j].idtype==0)
            {
                if (strcmp(B[i].idnum.aadhaar, B[j].idnum.aadhaar) == 0)
                {
                        temp=0;
                } 
            }
            else if(B[i].idtype==1 && B[j].idtype==1)
            {
                if (strcmp(B[i].idnum.passport, B[j].idnum.passport) == 0)
                {
                	temp=0;
				}           
			}
			else if(B[i].idtype==2 && B[j].idtype==2)
			{
				if (strcmp(B[i].idnum.empcode, B[j].idnum.empcode) == 0)
				{
				 	temp=0;
				}
			}
        }
    }
    k=0;
    while(n!=0)
    {
        for(i=0;i<n;i++)
        {
		    if(temp==1)
    	    {
    	    	C[k]=B[k];
    		    printf("%s %s %s %d %s %s\n",C[i].firstname,C[i].lastname,C[i].accommodation_type,C[i].idtype,C[i].idnum,C[i].address);
    		    k++;
    		    n--;
    	    }
	    }
	}
}
void printRecords(struct accommodation C[],int n)
{
	int i,j=0;
	for(i=0;i<n;i++)
	{
   		if(C[i].idtype == 1)
  		{
			
            printf("%s %s %s %d %s  %s\n", C[i].firstname, C[i].lastname, C[i].accommodation_type, C[i].idtype, C[i].idnum.passport, C[i].address);
		}
		else if (C[i].idtype == 0)
  		{
	  		printf("%s %s %s %d %s  %s\n", C[i].firstname, C[i].lastname, C[i].accommodation_type, C[i].idtype, C[i].idnum.aadhaar, C[i].address);

		}
		else if(C[i].idtype == 2)
		{
			printf("%s %s %s %d %s  %s\n", C[i].firstname, C[i].lastname, C[i].accommodation_type, C[i].idtype, C[i].idnum.empcode, C[i].address);
		}
  	}
}
void printSortedRcords(struct accommodation B[], int n)
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            char temp[50];
            if (strcmp(B[i].firstname, B[j].firstname) == 0)
            {
                if (strcmp(B[i].lastname, B[j].lastname) > 0)
                {
                    strcpy(temp, B[i].lastname);
                    strcpy(B[i].lastname, B[j].lastname);
                    strcpy(B[j].lastname, temp);
                }
            }
            if (strcmp(B[i].firstname, B[j].firstname) > 0)
            {
                strcpy(temp, B[i].firstname);
                strcpy(B[i].firstname, B[j].firstname);
                strcpy(B[j].firstname, temp);
            }
        }
    }

    //printRecords(&B[100],n);
}
void search(struct accommodation B[], int n)
{
	int i;
    char name[100];
    scanf("%s", name);

    for (i = 0; i < n; i++)

    {

        // printf("this %s", name);

        if (strcmp(B[i].firstname, name) == 0)

        {

            if (B[i].idtype == 0)
            {
                printf("%s %s %s %d %s  %s\n", B[i].firstname, B[i].lastname, B[i].accommodation_type, B[i].idtype, B[i].idnum.aadhaar, B[i].address);
            }

            else if (B[i].idtype == 1)
            {
                printf("%s %s %s %d %s  %s\n", B[i].firstname, B[i].lastname, B[i].accommodation_type, B[i].idtype, B[i].idnum.passport, B[i].address);
            }

            else if (B[i].idtype == 2)
            {
                printf("%s %s %s %d %s  %s\n", B[i].firstname, B[i].lastname, B[i].accommodation_type, B[i].idtype, B[i].idnum.empcode, B[i].address);
            }
        }

        /*else if (strcmp(B[i].firstname, name) != 0)
        {
            printf("There is no record of employee named %s", name);
        }*/
    }
}
void deleteRecord(struct accommodation B[], int n)
{
	int i,k;
    int type;
    char num[50];
    scanf("%d %s", &type, num);

    switch (type)
    {
    case 0:
    {
        for ( i = 0; i < n; i++)
        {
            if (strcmp(B[i].idnum.aadhaar, num) == 0)
            {
                for ( k = i; i <= n; k++)
                {
                    //printf("this");
                    B[k] = B[k + 1];
                    n = n - 1;
                }
            }
        }
    }
    case 1:
    {
        for ( i = 0; i < n; i++)
        {
            if (strcmp(B[i].idnum.passport, num) == 0)
            {
                for ( k = i; i < n; k++)
                {
                    //printf("this");
                    B[k] = B[k + 1];
                    n = n - 1;
                }
            }
        }
    }
    case 2:
    {
        for ( i = 0; i < n; i++)
        {
            if (strcmp(B[i].idnum.empcode, num) == 0)
            {
                for ( k = i; i < n; k++)
                {
                    //printf("this");
                    B[k] = B[k + 1];
                    n = n - 1;
                }
            }
        }
    }
    }
    //printRecords(&B[100],n);
}
void updateRecord(struct  accommodation B[],int n)
{
	int  choice,i,j;
	char NAME[15];
	printf("enter first name of employee to update");
	scanf("%s",NAME);
	for(i=0;i<n;i++)
	{
		if(strcmp(NAME,B[i].firstname)==0)
		j=i;
	}
	printf("ENTER field to be updated (press 1 for firstname  2 for last name 3 for accomodation type)");
	printf(" \n4 id type 5 address");
	scanf("%d",choice);
	if(choice==1)
	{
		printf("Enter the new firstname.\n");
        scanf("%s",B[j].firstname);
	}
	else if(choice==2)
	{
		printf("Enter the new lastname.\n");
        scanf("%s",B[j].lastname);
	}
	else if(choice==3)
	{
		printf("Enter the new accommodation type.\n");
        scanf("%d",B[j].accommodation_type);
	}
	else if(choice==4)
	{
		printf("Enter the new id num.\n");
        scanf("%d",&B[j].idtype);
        if(B[j].idtype==0)
        {
        	printf("enter aadhaar num");
        	scanf("%s",B[j].idnum.aadhaar);
		}
		else if(B[j].idtype==1)
        {
        	printf("enter passport num");
        	scanf("%s",B[j].idnum.passport);
		}
		else if(B[j].idtype==2)
        {
        	printf("enter aadhaar num");
        	scanf("%s",B[j].idnum.empcode);
		}
	}
}
void specialRequestAllocation(struct accommodation B[], int n)
{
	int i;
    int I = 0;
    int II = 0;
    int III = 0;
    int IV = 0;

    for ( i = 0; i < n; i++)
    {

        if (strcmp(B[i].accommodation_type, "type-I") == 0)
        {
            I++;
        }
        else if (strcmp(B[i].accommodation_type, "type-II") == 0)
        {
            II++;
        }
        else if (strcmp(B[i].accommodation_type, "type-III") == 0)
        {
            III++;
        }
        else if (strcmp(B[i].accommodation_type, "type-IV") == 0)
        {
            IV++;
        }
    }
    printf("%d %d %d %d", I, II, III, IV);
    char name[50];
    char change[50];
    scanf("%s", name);
    scanf("%s", change);
    for (i = 0; i < n; i++)
    {
        //printf("1");
        if (strcmp(B[i].firstname, name) == 0)
        {
            //printf("2");
            char temp[50];
            strcpy(temp, B[i].accommodation_type);
            if (strcmp(change, "type-I"))
            {
                // printf("3");
                if (I < 10)
                {

                    if (strcmp(temp, "type-II"))
                    {
                        II--;
                    }
                    if (strcmp(temp, "type-III"))
                    {
                        III--;
                    }
                    if (strcmp(temp, "type-IV"))
                    {
                        IV--;
                    }
                    strcpy(B[i].accommodation_type, "type-I");
                    I++;
                }
            }
            if (strcmp(change, "type-II"))
            {
                if (II < 10)

                {

                    if (strcmp(temp, "type-I"))
                    {
                        I--;
                    }
                    if (strcmp(temp, "type-III"))
                    {
                        III--;
                    }
                    if (strcmp(temp, "type-IV"))
                    {
                        IV--;
                    }
                    strcpy(B[i].accommodation_type, "type-II");
                    II++;
                }
            }
            if (strcmp(change, "type-III"))
            {
                if (III < 10)

                {

                    if (strcmp(temp, "type-II"))
                    {
                        II--;
                    }
                    if (strcmp(temp, "type-I"))
                    {
                        I--;
                    }
                    if (strcmp(temp, "type-IV"))
                    {
                        IV--;
                    }
                    strcpy(B[i].accommodation_type, "type-III");
                    III++;
                }
            }
            if (strcmp(change, "type-IV"))
            {
                if (IV < 10)

                {

                    if (strcmp(temp, "type-II"))
                    {
                        II--;
                    }
                    if (strcmp(temp, "type-III"))
                    {
                        III--;
                    }
                    if (strcmp(temp, "type-I"))
                    {
                        I--;
                    }
                    strcpy(B[i].accommodation_type, "type-IV");
                    IV++;
                }
            }
        }
    }
    printf("%d %d %d %d", I, II, III, IV);
}
int main()
{
	int n,i;
	printf("ENTER NUMBER OF RECORDS TO BE INSERTED n");
	scanf("%d",&n);
	struct accommodation B[n];
	struct accommodation C[n];
	for(i=0;i<n;i++)
	{
	    B[i]=insertrecord(i);
	}
	for(i=0;i<n;i++)
	{
	    printf("%s %s %s %d %s %s",B[i].firstname,B[i].lastname,B[i].accommodation_type,B[i].idtype,B[i].idnum,B[i].address);
	}
	removeDuplicates(&B[n],&C[n],n);
	printRecords(&C[n],n);
	printSortedRcords(&B[n],n);
	search(&B[n],n);
    deleteRecord(&B[n],n);
    updateRecord(&B[N],n);
    specialRequestAllocation(&B[n],n);
    return 0;
}
