/**********************
 *  rml3md 16156898
 *  Password Verification
 ***********************/




#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define USERLENGTH 8
#define PASSLENGTH 6
int load_data(char* file_name, char *account , char *password );
int checkAccountNumber(char *account, int number);
int checkpwdLength(char *password , int length);
int checkUpperLetter(char *password);
int checkDigit(char *password);
int checkSpecialchar(char *password);
int printUserFile(char* fileName , char* account, char* password);

int main (int argc , char** argv)

{
    char *account;
    char *password;
    char *string1;
    char *string2;

    if (argc != 3)
    {
        puts("Insufficient arguments");
        puts("You need the executable, an input file, and output file (in that order).");
    }
    if(argc == 3)

    {
        char* fileName = argv[2];
        account = malloc(sizeof(char)*USERLENGTH);
        password = malloc(sizeof(char)*PASSLENGTH);
        load_data(argv[1] , account , password );
        string1 = malloc(sizeof(char)*20);
        string2 = malloc(sizeof(char)*20);

        printf("\nAccount number is %s" , account);
        puts("");
        printf("\nPassword is %s" , password);
        puts("");

        while(checkAccountNumber(account, USERLENGTH) != 1)
        {
            printf("\nInvalid account! The account number should be %d digits long.\n" , USERLENGTH);
            printf("Enter the account number again:");
            scanf("%s" , account);
        }



        printf("Your account number is %s\n" , account);

        while(checkpwdLength(password , PASSLENGTH) != 1 || 
                checkUpperLetter(password) != 1 ||
                checkDigit(password) != 1 ||
                checkSpecialchar(password) != 1)

        {
            if(checkpwdLength(password , PASSLENGTH) != 1) 
            {
                printf("\nInvalid password!\nThe password should be %d letters long, and have at least one number, one special character, and one capital letter." , PASSLENGTH);
                printf("\nEnter the password again:");
                scanf("%s" , password);
            }


            if(checkUpperLetter(password) != 1)
            {
                printf("\nInvalid password!\nThe password should be %d letters long, and have at least one number, one special character, and one capital letter." , PASSLENGTH);
                printf("\nEnter the password again:");
                scanf("%s" , password);
            }
            if(checkDigit(password) != 1)
            {
                printf("\nInvalid password!\nThe password should be %d letters long, and have at least one number, one special character, and one capital letter." , PASSLENGTH);
                printf("\nEnter the password again:");
                scanf("%s" , password);
            }
            if(checkSpecialchar(password) != 1)
            {
                printf("\nInvalid password!\nThe password should be %d letters long, and have at least one number, one special character, and one capital letter." , PASSLENGTH);
                printf("\nEnter the password again:");
                scanf("%s" , password);
            }
        }
        printf("Your password is %s\n" , password);
        puts("");
        puts("Your account was successfully updated!");	
        puts("");
        printf("Account number: %s\n" , account);
        printf("Password: %s\n" , password);
        int saveSuccess = printUserFile( fileName , account, password);
            if(saveSuccess == 1)
            {
                puts("Save successful!");
            }
            else
            {
                puts("Uh oh! Something went wrong!");
            }
        free(account);
        free(password);

    }

    return 0;
}

int load_data(char* file_name, char *account , char *password )
{
    FILE* cfPtr = fopen( file_name , "r");

    if((cfPtr) == NULL)
    {
        return 0;
    }


    fscanf(cfPtr, "%s" , account);
    fscanf(cfPtr, "%s" , password);


    fclose(cfPtr);
    return 1;

}

int checkAccountNumber(char *account, int length)
{
    int i;

    for(i = 0; i < length; i++)
    {
        if(strlen(account) != length || isdigit(*(account + i)) == 0)
        {
            return 0;
        }
    }

    return 1;
}
int checkpwdLength(char *password , int length)
{

    if(strlen(password) < length)
        return 0;


    return 1;

}
int checkUpperLetter(char *password)
{

    int i;
    int counter = 0;
    for(i = 0; i < strlen(password); i++)
    {
        if( isupper(*(password + i)) != 0)
            return 1;
    }

    if(counter !=0)
        return counter;

    return 0;

}
int checkDigit(char *password)
{
    int i;
    int counter = 0;
    for(i = 0; i < strlen(password); i++)
    {
        if( isdigit(*(password + i)) != 0)
            return 1;
    }


    if(counter !=0)
        return counter;


    return 0;

}
int checkSpecialchar(char *password)
{
    int i;
    int counter = 0;


    for(i = 0; i < strlen(password); i++)
    {
        if( ispunct(*(password + i)) != 0)
            counter++;

    }

    if(counter !=0)
        return counter;


    return 0;

}
int printUserFile(char* fileName , char* account, char* password)
{
    FILE* filePointer = fopen(fileName , "w");
    if(filePointer == NULL)
    {
        return 0;
    }
    fprintf(filePointer , "%s\n%s", account , password);
    fclose(filePointer);
    return 1;
}
