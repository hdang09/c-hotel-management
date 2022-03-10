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
    printf("Username:  ");
    fgets(username, 30, stdin);
    printf("\nPassword: ");
    printf("\n");
    fgets(password, 20, stdin);

    int lineLength = 255;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

	// Loop each line
    fgets(line, sizeof(line), log)

    // Split string with delimeters to struct
    char * token = strtok(line, ", ");
    s.room2 = strtol(token, NULL, 10);

    token = strtok(NULL, ", ");
    s.longstay2 = strtol(token, NULL, 10);

    token = strtok(NULL, "/");
    s.checkin2.dd = strtol(token, NULL, 10);
    token = strtok(NULL, "/");
    s.checkin2.mm = strtol(token, NULL, 10);
    token = strtok(NULL, ", ");
    s.checkin2.yy = strtol(token, NULL, 10);

    token = strtok(NULL, "/");
    s.checkout2.dd = strtol(token, NULL, 10);
    token = strtok(NULL, "/");
    s.checkout2.mm = strtol(token, NULL, 10);
    token = strtok(NULL, ", ");
    s.checkout2.yy = strtol(token, NULL, 10);
    
    token =  strtok(NULL, ", ");
    if (token != NULL) strcpy(s.name2, token);

    token = strtok(NULL, "/");
    s.birth2.dd = strtol(token, NULL, 10);
    token = strtok(NULL, "/");
    s.birth2.mm = strtol(token, NULL, 10);
    token = strtok(NULL, ", ");
    s.birth2.yy = strtol(token, NULL, 10);

    token = strtok(NULL, ", ");
    if (token != NULL) strcpy(s.sex2, token);

    token = strtok(NULL, ", ");
    s.phone2 = strtol(token, NULL, 10);
    
    strcpy(s.email2, strtok(NULL, ", "));

    token = strtok(NULL, ", ");
    s.service_in_use2[0] = strtol(token, NULL, 10);

    token = strtok(NULL, ", ");
    s.service_in_use2[1] = strtol(token, NULL, 10);

    token = strtok(NULL, ", ");
    s.service_in_use2[2] = strtol(token, NULL, 10);

    token = strtok(NULL, ", ");
    s.service_in_use2[3] = strtol(token, NULL, 10);

    token = strtok(NULL, ", ");
    s.service_in_use2[4] = strtol(token, NULL, 10);

    token = strtok(NULL, ", ");
    s.total_pay2 = strtol(token, NULL, 10);
    
    // Ckeck each line to find exact room
    if (atoi(roomNumber) == s.room2) {
        isHaveRoom = 1;
        //continue;
    } 
    else {
        // Print to "temp.txt"
            fprintf(t, "%s", line2);
    }
 
    while(fread(&l, sizeof(l), 1, log))
        {
        if(strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0)
 
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

    fprintf(log, "%s, %s", l.username, l.password);
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
 

