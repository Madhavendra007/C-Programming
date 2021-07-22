#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank
{
   int account;
   char name[40];
   char address[40];
   double mobile;
   int balance;
}acc;
int i=0;
FILE *DataFile;

void add()
{
    fseek(DataFile, i*sizeof(struct bank), SEEK_SET);
    printf("Enter the account number " );
    scanf("%d", &acc.account);
    printf("Enter the name " );
    scanf("%s", acc.name);
    printf("Your name is %s.", acc.name);
    printf("Enter the address " );
    scanf("%s", acc.address);
    printf("Enter the phone number " );
    scanf("%lf", &acc.mobile);
    printf("Enter the account balance " );
    scanf("%d", &acc.balance);
    fwrite (&acc, sizeof(struct bank), 1, DataFile);
    i = i + 1;
}

void delete(int n)
{   
    int j = 1;
    FILE *temp;
    temp = fopen("temp.dat", "w+");
    while(j<n)
    {
        fread (&acc, sizeof(struct bank), 1, DataFile);
        fwrite (&acc, sizeof(struct bank), 1, temp);
    }
    fseek(DataFile, sizeof(struct bank), SEEK_CUR);
    while(j<=i)
    {
        fread (&acc, sizeof(struct bank), 1, DataFile);
        fwrite (&acc, sizeof(struct bank), 1, temp);
    }
    DataFile = freopen("Bank.dat", "w+", DataFile);
    j = 1;
    i = i - 1;
    while(j<=i)
    {
        fread (&acc, sizeof(struct bank), 1, temp);
        fwrite (&acc, sizeof(struct bank), 1, DataFile);
    }
    fclose(temp);
}

void update(int n)
{
    int j = 1;
    FILE *temp;
    temp = fopen("temp.dat", "w+");
    while(j<n)
    {
        fread (&acc, sizeof(struct bank), 1, DataFile);
        fwrite (&acc, sizeof(struct bank), 1, temp);
    }
    printf("Enter your account number " );
    scanf("%d", &acc.account);
    printf("Enter the Account name " );
    scanf("%s", acc.name);
    printf("Enter your address " );
    scanf("%s", acc.address);
    printf("Enter your phone number " );
    scanf("%lf", &acc.mobile);
    printf("Enter the account balance " );
    scanf("%d", &acc.balance);
    fwrite (&acc, sizeof(struct bank), 1, temp);
    fseek(DataFile, sizeof(struct bank), SEEK_CUR);
    while(j<=i)
    {
        fread (&acc, sizeof(struct bank), 1, DataFile);
        fwrite (&acc, sizeof(struct bank), 1, temp);
    }
    DataFile = freopen("Bank.dat", "w+", DataFile);
    j = 1;
    while(j<=i)
    {
        fread (&acc, sizeof(struct bank), 1, temp);
        fwrite (&acc, sizeof(struct bank), 1, DataFile);
    }
    fclose(temp);
}

void display(int n)
{
    
    fseek (DataFile, (n-1)*sizeof(struct bank), SEEK_SET);
    fread (&acc, sizeof(struct bank), 1, DataFile);
    printf("\nYour account number is %d", acc.account);
    printf("\nYour name is " );
    puts(acc.name);
    printf("\nThe address is " );
    puts(acc.address);
    printf("\nYour phone number is %lf", acc.mobile);
    printf("\nYour account balance is %d", acc.balance);
}

int main()
{   
    int option;
    int num;
    DataFile = fopen ("Bank.dat", "w+");
    if (DataFile == NULL)
    {
        printf("\nError to open the file!\n");
        exit (1);
    }
    while(1)
    {
        printf("Welcome to Madhavendra Jha Bank Management System!\nPlease select your option.\n1. Create an account.\n2. Delete an account.\n3. Update an account.\n4. Display an account.");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                add();
                break;
            case 2:
                printf("Enter the Account no. you want to delete ");
                scanf("%d", &num);
                delete(num);
                break;
            case 3:
                printf("Enter the Account no. to modify ");
                scanf("%d", &num);
                update(num);
                break;
            case 4:
                printf("Enter the Account no. to display ");
                scanf("%d", &num);
                display(num);
                break;
        }
    };
    fclose(DataFile);
    return 0;
}