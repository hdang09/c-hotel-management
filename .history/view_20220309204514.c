#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void view() {
	FILE *fp;
//	fp = NULL;
	char arr[100000];
	fp = fopen("room list 2.txt", "r+");

	int lineLength = 255;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

    while (fgets(line, sizeof(line), fp)) {
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

//      ======================================================
		// Bug this line
		token = strtok(NULL, ", ");
		// strcpy(s.sex2, token);
//      ======================================================

		token = strtok(NULL, ", ");
		s.phone2 = strtol(token, NULL, 10);
		
		token = strtok(NULL, ", ");
		if (token != NULL) strcpy(s.email2, token);
		printf("Hello");

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
		printf("\n\n\n** ROOM %d ** \n Period days %d\n Checkin %d/%d/%d \n checkout %d/%d/%d \n ",
		s.room2,
		s.longstay2,
		s.checkin2.dd, s.checkin2.mm, s.checkin2.yy,
		s.checkout2.dd, s.checkout2.mm, s.checkout2.yy);

		printf("\nPerson %d \n >>----------<< \n fullname: %s \n Birthday(mm/dd/yyyy): %d/%d/%d \n Sex: %s \n Phone number: %s \n Email: %s", 
	    s.numclient, s.client.name,
	    s.client.birth.dd, s.client.birth.mm, s.client.birth.yy,
	    s.client.sex,
	    s.client.phone,
	    s.client.email);   
		
	}

	fclose(fp);

	printf("\nPress anykey to return home screen");
	getch();
	system("cls");
	fflush(stdin);
	mainMenu();
}
