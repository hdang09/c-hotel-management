struct login                           // before the first use of `l`.
{
    char username[30];
    char password[20];
} l;

//#define createLoginSystem main

void login(void) {
    char username[30], password[20];
    FILE *log;
 
    log = fopen("login.txt", "r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
 
    struct login l;
 
    printf("\nPlease Enter your login credentials below\n\n");
    fflush(stdin);
    printf("Username:  ");
    fgets(username, 30, stdin);
    printf("\nPassword: ");
    printf("\n");
    fgets(password, 20, stdin);

    int lineLength = 255;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

    printf("Hello");
	// Get first line
    fgets(line, sizeof(line), log);
    printf("Hello 2");

    // Split string with delimeters to struct (Get username and pass)
    char * token = strtok(line, " ");
    if (token != NULL) strcpy(l.username, token);

    token = strtok(NULL, " ");
    if (token != NULL) strcpy(l.password, token);

    if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0)  
            printf("\nSuccessful Login\n");
    else
        printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");

    getch();
    fclose(log);
    
    return;
}
 
void registration(void)
{
    char name[15];
    FILE *log;
 
    log = fopen("login.txt", "w");
    if (log == NULL) {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
    printf("\nWe need to enter some details for registration.\n\n");

    // printf("Enter your name: ");
    // scanf("%s", &name);
    printf("\nEnter Username: ");
    scanf("%s", l.username);
    printf("\nEnter Password: ");
    scanf("%s", l.password);

    // fwrite(&l, sizeof(l), 1, log);
    fclose(log);
    // printf("\nConfirming details...\n...\nWelcome, %s!\n\n", name);
    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
    getch();
    system("CLS");
    login();
}

 
//void createLoginSystem(void) {
//    int option;
//    printf("Press '1' to Register\nPress '2' to Login\n\n");
//    scanf("%d", &option);
//    getchar();           // catching newline.
//    if(option == 1)
//        {
//            system("CLS");
//            registration();
//        }
//    else if(option == 2)
//        {
//            system("CLS");
//            login();
//        }
//        system("cls");
//}
 

