#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
 
struct login                           // before the first use of `l`.
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
};
 
int createLoginSystem(void) {
    int option;
    printf("Press '1' to Register\nPress '2' to Login\n\n");
    scanf("%d", &option);
    getchar();           // catching newline.
    if (option == 1)
        {
            system("CLS");
            registration();
        }
    else if(option == 2)
        {
            system("CLS");
            login();
        }
        system("cls");
}
 
void login(void) {
    char username[30],password[20];
    FILE *log;
 
    log = fopen("login.txt","r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
 
    struct login l;
 
    printf("\nPlease Enter your login credentials below\n\n");
    printf("Username:  ");
    fgets(username, 30, stdin);
    printf("\nPassword: ");
    printf("\n");
    fgets(password, 20, stdin);
 
    while(fread(&l,sizeof(l),1,log))
        {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
 
            {  
                printf("\nSuccessful Login\n");
            }
        else
            {
                printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
            }
        }
 
    fclose(log);
 
    return;
}
 
void registration(void)
{
    char firstname[15];
    FILE *log;
 
    log=fopen("login.txt","w");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
    struct login l;
    printf("\nWe need to enter some details for registration.\n\n");
    printf("\nEnter Username:\n");
    scanf("%s",l.username);
    printf("\nEnter Password:\n");
    scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,log);
    fclose(log);
    printf("\nConfirming details...\n...\nWelcome, %s!\n\n",firstname);
    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
        getchar();
    system("CLS");
    login();
}

