#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void edit()
{
    system("cls");
    FILE *f, *t;
    f = fopen("room list 2.txt", "r");
    t = fopen("temp.txt", "w");
    if (f == NULL) exit(0);

    int k = 1;
    char roomNumber[20];
    printf("Enter Room number of the customer to edit:\n\n");
    scanf("%s", roomNumber);
    fflush(stdin);

    int lineLength = 255;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

    while (fgets(line, sizeof(line), f)) {
		// Copy a new string from line to line2
		for (int i = 0; i < strlen(line); i++) line2[i] = line[i];

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
		
		// Handling
		if (atoi(roomNumber) == s.room2) {
            k = 0;
            // printf("\nEnter Room Number     :");
            // gets(s.roomNumber);

            // printf("\nEnter period(\'x\'days):  ");
            // scanf("%d",  &s.longstay2);
            // printf("\nEnter day you checkin (dd/mm/yy): ");
            // scanf("%d/%d/%d",  &s.checkin2.dd,  &s.checkin2.mm,  &s.checkin2.yy);
            // printf("\nEnter day you checkout (dd/mm/yy): " );
            // scanf("%d/%d/%d",  &s.checkout2.dd,  &s.checkout2.mm,  &s.checkout2.yy );	

            printf("\n\nEnter your fullname: ");
            scanf("%s", &s.name2);
            printf("\nBirthday (dd/mm/yyyy):");
            scanf("%d/%d/%d", &s.birth2.dd, &s.birth2.mm, &s.birth2.yy);
            printf("\nSex (M: Male/ F: Famale/ O: Others):  ");
            scanf("%s", &s.sex2);
            printf("\nPhone number:   ");
            scanf("%s", &s.phone2);
            printf("\nEmail:  ");
            scanf("%s", &s.email2);

            printf("\n\nWe have these services\n");
            printf("1. Service 1 cost 100000\n");
            printf("2. Service 2 cost 100000\n ");
            printf("3. Service 3 cost 200000\n");
            printf("4. Service 4 cost 200000\n");
            printf("5. Service 5 cost 400000\n");
            printf("\nNote: if you choose service 1 and 2 just type \" 1_1_0_0_0 \" with \"_\" mean space, \"0\" mean you don't want \n");
            printf("Your option: ");
            int a = 1;
            while (a <= 5){
                scanf("%d", &s.service_in_use2[a]);
                a++;
            }		

            // fseek(f, size, SEEK_CUR);  //to go to desired position infile
            fprintf(t, "%d, %d, %d/%d/%d, %d/%d/%d, ", 
            s.room2,
            s.longstay2,
            s.checkin2.dd, s.checkin2.mm, s.checkin2.yy,
            s.checkout2.dd, s.checkout2.mm, s.checkout2.yy);

            fprintf(t, "%s, %d/%d/%d, %s,  ", 
            s.name2,
            s.birth2.dd, s.birth2.mm, s.birth2.yy,
            s.sex2);

            // fprintf(t, "%s, %d/%d/%d, %s, %d, %s, ", 
            // s.name2,
            // s.birth2.dd, s.birth2.mm, s.birth2.yy,
            // s.sex2,
            // s.phone2,
            // s.email2);
            printf("Hello\n");

            for (int a = 0; a < 5; a++) 
                fprintf(t, "%d, ", s.service_in_use2[a]);
                
            printf("Hello 3\n");
            
            // break;
		} else {
			// Print to "temp.txt"
            printf("Hello 2\n");
            fprintf(t, "%s", line2);
		}
	}

    if (k == 1){
        printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
       
    } else {
        printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
    }
    
    //	File handling
    fclose(f);
    fclose(t);
    remove("room list 2.txt");
    rename("temp.txt", "room list 2.txt");

    // Go back to main menu
    printf("Press any key to go back to main menu");
    getch();
    mainMenu();
}
 

