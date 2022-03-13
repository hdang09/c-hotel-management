struct login                           // before the first use of `l`.
{
    char username[30];
    char password[30];
} l;

//#define createLoginSystem main

void login(void) {
    system("cls");

    int i = 0;
    char username[30], password[30], c;
    FILE *log;
 
    log = fopen("account.txt", "r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
  
    printf("\nPlease Enter your login credentials below\n\n");
    fflush(stdin);

    printf("Username:  ");
    scanf("%s", &username);
    printf("\nPassword: ");
    // fgets(password, 30, stdin);
    while (i < 30) {
	    password[i] = getch();
	    c = password[i];
	    if (c==13) break; else printf("*");
	    i++;
	}
	password[i]='\0';

    int lineLength = 255;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

	// Get first line
    while (fgets(line, sizeof(line), log)) {
        // Split string with delimeters to struct (Get username and pass)
        char * token = strtok(line, " ");
        if (token != NULL) strcpy(l.username, token);

        token = strtok(NULL, "");
        if (token != NULL) strcpy(l.password, token);
    }

    if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0) {
        textcolor(6);
        printf("\n\nSuccessful Login\n");
        setcolor(9);
    } else {
        printf("\nIncorrect Login Details\nPlease enter the correct credentials\n\n");
        printf("Press 'A': Type again\n");
        printf("Press 'C': Create an account if you don't have any account\n");
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

    printf("\nPress any key to continue...");
    getch();
    mainMenu();
    fclose(log);
    return;
}
 
void registration(void) { 
    system("cls");
    int i = 0;
    char name[15], c;
    FILE *log;
    log = fopen("account.txt", "w");
    if (log == NULL) {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
    printf("\nWe need to enter some details for registration.\n\n");
    printf("\nEnter Username: ");
    scanf("%s", l.username);
    printf("\nEnter Password: ");
    while (i < 30) {
	    l.password[i] = getch();
	    c = l.password[i];
	    if (c==13) break; else printf("*");
	    i++;
	}
	l.password[i] = '\0';

    fprintf(log, "%s %s", l.username, l.password);
    fclose(log);
    textcolor(14);
    printf("\n\nRegistration Successful!\n");
    setcolor(9);
    printf("\nPress any key to continue...");
    getch();
    system("CLS");
    login();
}
