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
    FILE *f;
    f = fopen("room list.txt", "r+");
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

//      ======================================================
		// Bug this line
		token = strtok(NULL, ", ");
		// strcpy(s.sex2, token);
//      ======================================================

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

            // printf("\nEnter Name    :");
            // fflush(stdin);
            // scanf("%s", &s.name2);
            // printf("\nDate of birth        :");
            // scanf("%d %d %d", &s.address2);
            // printf("\nEnter Phone number :");
            // scanf("%f", &s.phoneNumber2);
            // printf("\nEnter Nationality :");
            // scanf("%s", &s.nationality2);
            // printf("\nEnter Email :");
            // scanf("%s", &s.email2);
            // printf("\nEnter Period :");
            // scanf("%s", &s.period2);
            // printf("\nEnter Arrival date :");
            // scanf("%s", &s.arrivaldate2);
            // fseek(f, size, SEEK_CUR);  //to go to desired position infile
            // fwrite(&s, sizeof(s), 1, f);
            // break;
		} 
	}

    if (k == 1){
        printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
        fclose(f);
        getch();
    } else {
    fclose(f);
    printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
    getch();
}
}
 

