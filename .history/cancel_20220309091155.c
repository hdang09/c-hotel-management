#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "read-line.c"

//typedef struct {
//	int dd;
//	int mm;
//	int yy;
//} date;

//struct CustomerDetails   //STRUCTURE DECLARATION
//{
//	int room2;
//	int longstay2;
// 	date checkin2;
// 	date checkout2;
//	char name2[50];
//	date birth2;
//	char sex2;
//	int phone2[15];
//	char email2[100];	
//	int service_in_use2[5];
//	int total_pay2; 	 
//} s;

#define cancel main

void cancel() {
	FILE *f, *t;
	int isHaveRoom = 0;
	char roomnumber[10];

	int lineLength = 255;
    char line[lineLength]; /* not ISO 90 compatible */

//  Check if files are available
	f = fopen("room list 2.txt","r");
	t = fopen("temp.txt","w");
	if (f == NULL || t == NULL) exit(0);

//  Input a room to cancel
	printf("Input a room number to cancle: ");
	fflush(stdin);
	scanf("%s", &roomnumber);




	// Loop each line
	FILE *f, *t;
	//  Check if files are available
	f = fopen("room list 2.txt","r");
	t = fopen("temp.txt","w");
//	if (f == NULL || t == NULL) exit(0);
	

    
    while (fgets(line, lineLength, f)) {
		// Loop each parameters
		printf("%s\n", line);

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
		
		strcpy(s.name2, strtok(NULL, ", "));

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

		strcpy(s.phone2, strtok(NULL, ", "));
		
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

		strcpy(s.checkin2.yy, strtok(NULL, ", "));

        printf("%d", s.room2);
       if (s.room2 == 5) {
           printf("TRUE");
		} else 
           printf("FALSE");
	}
}
	
	 
	
	
    



	
//	while(fread(&s, sizeof(s), 1, f) != 0) {
//		if (strcmp(roomnumber, s.roomnumber) == 0) {
//			isHaveRoom = 1;
//			//continue;
//		} 
//		else
//			fwrite(&s, sizeof(s), 1, t);	
//	}
//	
////	Validate Notification
//	if (isHaveRoom) 
//		printf("Remove successfully!\n");
//	else {
//		printf("The room that you input doesn't exist\n");
//		main();
//	}
		
//	File handling
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt", "add.txt");
		
}
