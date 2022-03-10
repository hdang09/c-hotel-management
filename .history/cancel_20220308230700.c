#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
	int dd;
	int mm;
	int yy;
} date;

struct CustomerDetails   //STRUCTURE DECLARATION
{
	int room;
	int longstay2;
 	date checkin2;
 	date checkout2;
	char name2[50];
	date birth2;
	char sex2[20];
	int phone2[15];
	char email2[100];	
	int service_in_use2[5];
	int total_pay2; 	 
} s;

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
    while (fgets(line, lineLength, f)) {
		// Loop each parameters
		printf("%s\n", line);

		char * token = strtok(line, ", ");
		s.room = token;
		s.longstay2 = strtok(NULL, ", ")
		checkin2.dd = strtok(NULL, "/");
		checkin2.mm = strtok(NULL, "/");
		checkin2.yy = strtok(NULL, ", ");
		checkin2.dd = strtok(NULL, "/");
		checkin2.mm = strtok(NULL, "/");
		checkin2.yy = strtok(NULL, ", ");
		name2[50] = strtok(NULL, ", ");
		birth2 = strtok(NULL, ", ");
		sex2[20] = strtok(NULL, ", ");
		phone2[15] = strtok(NULL, ", ");
		email2[100]; = strtok(NULL, ", ");
		service_in_use2[5] = strtok(NULL, ", ");
		total_pay2 = strtok(NULL, ", ");
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
