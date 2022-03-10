struct login                           // before the first use of `l`.
{
    char username[30];
    char password[20];
} l;

//#define createLoginSystem main

void login(void) {
    system("cls");

    char username[30], password[20], c;
    FILE *log;
 
    log = fopen("login.txt", "r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
  
    printf("\nPlease Enter your login credentials below\n\n");
    fflush(stdin);
    printf("Username:  ");
    fgets(username, 30, stdin);
    printf("\nPassword: ");
    fgets(password, 20, stdin);

    int lineLength = 255;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

	// Get first line
    while (fgets(line, sizeof(line), log)) {
        // Split string with delimeters to struct (Get username and pass)
        char * token = strtok(line, " ");
        if (token != NULL) strcpy(l.username, token);
        printf("Token: %s", token);

        token = strtok(NULL, " ");
        if (token != NULL) strcpy(l.password, token);
        printf("Token: %s", token);
    }

    printf("\n%d", strcmp(username, l.username));
    printf("\n%d", strcmp(password, l.password));

    if (strcmp(username, l.username) == 1 && strcmp(password, l.password) == 1)  
            printf("\nSuccessful Login\n");
            // printf("Press any key to continue");
            // getch();
    else {
            printf("\nIncorrect Login Details\nPlease enter the correct credentials\n\n");
            printf("Press 'A' to type again!\n");
            printf("If you don't have an account, press 'C' to create an account!\n");
            c = getch();

            if (c == 'a' || c == 'A') {
                login();
            } else if (c == 'c' || c == 'C') {
                registration();
            } else {
                printf("Invalid input. Please try again!");
                getch();
                home();
            }
        }

    printf("Press any key to continue...");
    getch();
    mainMenu();
    fclose(log);
    
    return;
}
 
void registration(void) { 
    system("cls");

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

    fprintf(log, "%s %s", l.username, l.password);
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
 

