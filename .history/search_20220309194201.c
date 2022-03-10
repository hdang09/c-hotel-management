#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// #include "read-line.c"

typedef struct {
	int dd;
	int mm;
	int yy;
} date2;

struct CustomerDetails   //STRUCTURE DECLARATION
{
	int room2;
	int longstay2;
	date2 checkin2;
	date2 checkout2;
	char name2[50];
	date2 birth2;
	char sex2;
	int phone2[15];
	char email2[100];	
	int service_in_use2[5];
	int total_pay2; 	 
} s;

#define search main

void search() {
    system("cls");
    FILE *f;
    char roomNumber[20];
    int flag = 1;
    f = fopen("room list 2.txt","r+");
    if(f == 0)
        exit(0);
    fflush(stdin);
    printf("Enter Room number of the customer to search its details: \n");
    scanf("%s", roomNumber);

    int lineLength = 255;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

    while (fgets(line, sizeof(line), f)) {
		// Copy a new string from line to line 2
		for (int i = 0; i < strlen(line); i++) line2[i] = line[i];
		// printf("%s\n", line);

		// Loop each parameters
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
		
		token = strtok(NULL, ", ");
		if (token != NULL) strcpy(s.name2, token);

		token = strtok(NULL, "/");
		s.birth2.dd = strtol(token, NULL, 10);
		token = strtok(NULL, "/");
		s.birth2.mm = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		s.birth2.yy = strtol(token, NULL, 10);

//      ======================================================
		token = strtok(NULL, ", ");
		// strcpy(s.sex2, token);
//      ======================================================

		token = strtok(NULL, ", ");
		s.birth2.yy = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		if (token != NULL) strcpy(s.phone2, token);
		
		token = strtok(NULL, ", ");
		if (token != NULL) strcpy(s.email2, token);
		printf("This is a phone number: %s", s.email2);

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
			flag = 0;
            printf("\n\tRecord Found\n ");
            // printf("\nRoom Number:\t%s",s.roomNumber);
            // printf("\nName:\t%s",s.name);
            // printf("\nAddress:\t%s",s.address);
            // printf("\nPhone number:\t%s",s.phoneNumber);
            // printf("\nNationality:\t%s",s.nationality);
            // printf("\nEmail:\t%s",s.email);
            // printf("\nPeriod:\t%s",s.period);
            // printf("\nArrival date:\t%s",s.arrivaldate);
            break;
		} 
	}

   
    if(flag == 1){    
        printf("\n\tRequested Customer could not be found!");
    }
    printf("\nPress any key to go back to main menu");
    getch();
//    mainMenu();
    fclose(f);
}


