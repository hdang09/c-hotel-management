#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// void view() {
// 	FILE *fp;
// 	fp = NULL;
// 	char arr[100000];
// 	fp = fopen("room list.txt", "r+");
// 	while(fgets(arr, 100000, fp) != NULL) {
// 		printf("%s", arr);
// 	}
// 	fclose(fp);

// 	printf("\nPress anykey to return home screen");
// 	getch();
// 	system("cls");
// 	fflush(stdin);
// 	mainMenu();
// }


void view() {
	FILE *fp;
//	fp = NULL;
	char arr[100000];
	fp = fopen("room list 2.txt", "r+");

	int lineLength = 255, roomNumber, numClient = 1;
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

		token = strtok(NULL, ", ");
		if (token != NULL) strcpy(s.sex2, token);

		token = strtok(NULL, ", ");
		s.phone2 = strtol(token, NULL, 10);
		
		token = strtok(NULL, ", ");
		if (token != NULL) strcpy(s.email2, token);

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

		printf("%d - %d", roomNumber, s.room2);
		
		// Handling
		if (roomNumber != s.room2) {
			// for (int i = 0; i < 40; i++) printf("="); printf("\n");
			printf("\n\n\n** ROOM %d ** \n Period days %d\n Checkin %d/%d/%d \n checkout %d/%d/%d \n ",
			s.room2,
			s.longstay2,
			s.checkin2.dd, s.checkin2.mm, s.checkin2.yy,
			s.checkout2.dd, s.checkout2.mm, s.checkout2.yy);
			// for (int i = 0; i < 40; i++) printf("="); printf("\n");
			roomNumber = s.room2;
			numClient = 1;
		}

		printf("\nPerson %d \n >>----------<< \n fullname: %s \n Birthday(mm/dd/yyyy): %d/%d/%d \n Sex: %s \n Phone number: %d \n Email: %s", 
		numClient,
		s.name2,
		s.birth2.dd, s.birth2.mm, s.birth2.yy,
		s.sex2,
		s.phone2,
		s.email2);   
		numClient++;
	}

	fclose(fp);

	printf("\nPress anykey to return home screen");
	getch();
	system("cls");
	fflush(stdin);
	mainMenu();
}
