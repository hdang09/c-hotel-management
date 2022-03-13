#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#define home main 
#include "constants.h"
#include "graphic.h"
#include "add-cleaning-schedule.c"
#include "login.h"
#include "main-menu.h"
#include "bookroom.h"
#include "cancel.h"
#include "edit.h"
#include "exit.h"
#include "search.h"
#include "view.h"

void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;
if(GetConsoleScreenBufferInfo(hStdOut,&csbi)) {
	wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
	SetConsoleTextAttribute(hStdOut,wColor);
	}
}

void home() { 
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	int option;
	time_t t;
	time(&t);
	char choice;
	system("cls"); 
	textcolor(6);
	printf("%c", 201);
	for (int i = 0; i <= 80; i++) printf("%c", 205);
	printf("%c\n", 187);
	printf("%c                                                                                 %c\n", 186, 186);       
	printf("%c                                                                                 %c\n", 186, 186);
	printf("%c  OOOOOO    OOOOOO  OOOOOO  OOOOOO  OOOOOO  OOOOOO  O      O  OOOOOOO   OOOOOO   %c\n", 186, 186);
	printf("%c  O         O    O  O       O         O       O     O O    O  O         O        %c\n", 186, 186);
	printf("%c  O  OOOOO  OOOOOO  OOOOO   OOOOO     O       O     O  O   O  O  OOOOO  OOOOOO   %c\n", 186, 186);
	printf("%c  O    O    O  O    O       O         O       O     O   O  O  O    O         O   %c\n", 186, 186);
	printf("%c  OOOOOO    O   O   OOOOOO  OOOOOO    O     OOOOOO  O    O O  OOOOOO    OOOOOO   %c\n", 186, 186);
	printf("%c                                                                                 %c\n", 186, 186);
	
	printf("%c", 204);
	for (int i = 0; i <= 80; i++)
		printf("%c", 205);
	printf("%c\n", 185); 

	printf("%c\t\t                                                  \t\t  %c\n", 186, 186);
	printf("%c\t\t *************************************************\t\t  %c\n", 186, 186);
	printf("%c\t\t *                                               *\t\t  %c\n", 186, 186);
	printf("%c\t\t *         -----------------------------         *\t\t  %c\n", 186, 186);
	printf("%c\t\t *            WELCOME TO HOTEL TEAM 1            *\t\t  %c\n", 186, 186);
	printf("%c\t\t *         -----------------------------         *\t\t  %c\n", 186, 186);
	printf("%c\t\t *                                               *\t\t  %c\n", 186, 186);
	printf("%c\t\t *            Mentor: Le Ngoc Son                *\t\t  %c\n", 186, 186);
	printf("%c\t\t *           Members: Nguyen Hoang Anh           *\t\t  %c\n", 186, 186);
	printf("%c\t\t *                    Tran Hai Dang              *\t\t  %c\n", 186, 186);
	printf("%c\t\t *                    Doan Viet Thanh            *\t\t  %c\n", 186, 186);
	printf("%c\t\t *                                               *\t\t  %c\n", 186, 186);
	printf("%c\t\t *************************************************\t\t  %c\n", 186, 186);
	printf("%c\t\t                                                  \t\t  %c\n", 186, 186);
	printf("%c", 200);
	for (int i = 0; i <= 80; i++)  
		printf("%c", 205);
	printf("%c\n", 188);
	
	setcolor(15);
	for (i = 0; i < 83; i++)
		printf("-");
	    printf("\n                 Current date and time : %s",ctime(&t));
	    for(i=0;i<83;i++)
		printf("-");
	printf(" \n                            Press any key to continue  ");

	getch();	 
	system("cls");

	roomnumber[i].numclient = 0;
	roomnumber[i].id_room = i;
    printf("=================== ROOM %d ===================\n", i);
    printf("\nPrice per night is %d", cost_room[h].price_per_night); 
	printf("\nNote: Max people in %s is %d", cost_room[h].type, cost_room[h].max_people );		   

	// Validate longstay
	char c;
	RUN8: printf("\nEnter period (\'x\'days): ");
	fflush(stdin);
	if (scanf("%d%c", &roomnumber[i].longstay, &c) != 2 
		|| c != '\n' 
		|| roomnumber[i].longstay == 0) {
		textcolor(12);
		printf("Error\n");
		setcolor(9);
		goto RUN8;	
	}

	// Validate checkin
	isValid = 0;
	while (!isValid) {
		// Input
		printf("\nEnter day you checkin (dd/mm/yy): ");
		fflush(stdin);
		scanf("%d/%d/%d", &roomnumber[i].checkin.dd, &roomnumber[i].checkin.mm, &roomnumber[i].checkin.yy);
		int day = roomnumber[i].checkin.dd;
		int month = roomnumber[i].checkin.mm;
		int year = roomnumber[i].checkin.yy;

		//check year
		if (year >= 2022 && year <= 2100) { 
			//check month
			if (month >= 1 && month <= 12) {
				//check days
				if((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
					isValid = 1;
				else if((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
					isValid = 1;
				else if((day >= 1 && day <= 28) && (month == 2))
					isValid = 1;
				else if(day == 29 && month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
					isValid = 1;
				else
					isValid = 0;
			}
			else {
				isValid = 0;
			}
		}
		else {
			isValid = 0;
		}

		// Notification
		if (isValid != 1) {
			textcolor(12);
			printf("Your input is unvalid. Please try again!\n");
			setcolor(9);
		}

	textcolor(10);

	printf("\t\t%c", 218);
	for (int i = 0; i <= 38; i++) {
		printf("%c", 196);

	}
	printf("%c\n", 191);

	printf("\t\t%c\t Enter '1' to Register \t\t%c\n", 179, 179);
	printf("\t\t%c\t Enter '2' to Login    \t\t%c\n", 179, 179);

	printf("\t\t%c", 192);
	for (int i = 0; i <= 38; i++) {
		printf("%c", 196);
	}
	printf("%c\n", 217);

	//Book service
	printf("\n\nWe have these services\n");
	printf("1. Service 1 cost 100000\n");
	printf("2. Service 2 cost 100000\n");
	printf("3. Service 3 cost 200000\n");
	printf("4. Service 4 cost 200000\n");
	printf("5. Service 5 cost 400000\n");
	printf("\nNote: if you choose service 1 and 2 just type \" 1_1_0_0_0 \" with \"_\" mean space, \"0\" mean you don't want \n");
	int a;
	RUN3: printf("Your option: ");
	fflush(stdin);
	for (a=1; a<=5; a++){
		scanf("%d", &roomnumber[i].service_in_use[a]);
	}
    for (a=1; a<=5; a++){
	    if (roomnumber[i].service_in_use[a] == 1 ) 			
				cost_service[a] = list_service[a - 1].price_service;
		else if(roomnumber[i].service_in_use[a] == 0)
				cost_service[a] = 0;
		else {
			textcolor(12);
			printf("ERROR !\n");
			setcolor(9);
			goto RUN3;
		} 
	}		
	
	printf("\n---------------------------------------------");		
	printf("\n\n!!---Please fill this form---!!\n");
	
	roomnumber[i].numclient = 1;
	while (roomnumber[i].numclient <= cost_room[h].max_people) {
	   		
		printf("\n>>----Person %d----<<\n", roomnumber[i].numclient );

		printf("\n\nEnter your fullname: ");
		fflush(stdin);
		gets(roomnumber[i].client.name);

		// Validate birthday
		isValid = 0;
		while (!isValid) {
			// Input
			printf("\nBirthday (dd/mm/yyyy): ");
			fflush(stdin);
			scanf("%d/%d/%d", &roomnumber[i].client.birth.dd, &roomnumber[i].client.birth.mm, &roomnumber[i].client.birth.yy);
			int day = roomnumber[i].client.birth.dd;
			int month = roomnumber[i].client.birth.mm;
			int year = roomnumber[i].client.birth.yy;

			//check year
			if (year >= 1900 && year <= 2100) {
				//check month
				if (month >= 1 && month <= 12) {
					//check days
					if((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
						isValid = 1;
					else if((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
						isValid = 1;
					else if((day >= 1 && day <= 28) && (month == 2))
						isValid = 1;
					else if(day == 29 && month == 2 && (year%400 == 0 ||(year%4 == 0 && year%100 != 0)))
						isValid = 1;
					else
						isValid = 0;
				}
				else {
					isValid = 0;
				}
			}
			else {
				isValid = 0;
			}

			// Notification
			if (isValid != 1) {
				textcolor(12);
				printf("Your input is unvalid. Please try again!\n");
				setcolor(9);
			}
			// !isValid ? printf("Your input is unvalid. Please try again!\n") : 0;
		}
		
		// Validate sex
		isValid = 0;
		while (!isValid) {
			// Input
			printf("\nSex (M: Male/ F: Famale/ O: Others):  ");
        	roomnumber[i].client.sex = getche();

			switch (roomnumber[i].client.sex) {
				case 'M':
				case 'm':
				case 'F':
				case 'f':
				case 'O':
				case 'o':
					isValid = 1;
					break;
				default:
					isValid = 0;
			};

			// Notification
			if (isValid != 1) {
				textcolor(12);
				printf("\nYour input is unvalid. Please try again!\n");
				setcolor(9);
			}
			// !isValid ? printf("Your input is unvalid. Please try again!\n") : 0;
		}
		printf("\n");

        // Validate phone number
		{
			int c;
			char phone[15];
			RUN2: printf("\nPhone number: ");
			scanf("%s", phone);
			int length = strlen(phone);
			if( length != 10)
			{
				textcolor(12);
				printf("Phone number contains only 10 number characters! Please try again\n");
				setcolor(9);
				goto RUN2;
			}
			for (c = 0; c < 10; c++ ) {
				if (phone[c] < '0' || phone[c] > '9') {
					printf("Phone number is number ! \n");
					goto RUN2;
				}
			}
			roomnumber[i].client.phone = atoi(phone);
		}

        printf("\nEmail:  ");
        scanf("%s", roomnumber[i].client.email);

		// Print to "rooms.txt" file
		fprintf(fp, "%d, %d, %d/%d/%d, %d/%d/%d,", 
		roomnumber[i].id_room,
		roomnumber[i].longstay,
		roomnumber[i].checkin.dd, roomnumber[i].checkin.mm, roomnumber[i].checkin.yy,
		roomnumber[i].checkout.dd, roomnumber[i].checkout.mm, roomnumber[i].checkout.yy);

		fprintf(fp, "%s, %d/%d/%d, %c, %d, %s, ", 
	    roomnumber[i].client.name,
	    roomnumber[i].client.birth.dd, roomnumber[i].client.birth.mm, roomnumber[i].client.birth.yy,
	    roomnumber[i].client.sex,
	    roomnumber[i].client.phone,
	    roomnumber[i].client.email);   
	    		

        RUN6:
	printf("\n\nDo you want to add one more people press \"Y\" \n If NO press \"N\"");      	     		
        printf("\nY/N >>>  ");
	fflush(stdin);
        ch = getch();
        if (ch == 'N' || ch == 'n') {
			for (int a = 1; a <= 5; a++) fprintf(fp, "%d, ", roomnumber[i].service_in_use[a]);   	    			

			// Caluculate total pay
			roomnumber[i].total_pay = roomnumber[i].longstay * (cost_room[h].price_per_night + cost_service[1] + cost_service[2] + cost_service[3] + cost_service[4] + cost_service[5] );
			// Print total pay to "rooms.txt"	
			fprintf(fp, "%d\n", roomnumber[i].total_pay);
		  	break; 
	} else if (ch == 'Y' || ch == 'y') {
         	roomnumber[i].numclient++;
     	        if (roomnumber[i].numclient > cost_room[h].max_people) {
				textcolor(12);
				printf("Sorry the room has max people !\n");
				setcolor(9);
				break;
		   } 
    	}
	else goto RUN6;

		// Print to "rooms.txt" file
		for (int a = 1; a <= 5; a++) fprintf(fp, "%d, ", roomnumber[i].service_in_use[a]);   	    			

		// Caluculate total pay
		roomnumber[i].total_pay = roomnumber[i].longstay * (cost_room[h].price_per_night + cost_service[1] + cost_service[2] + cost_service[3] + cost_service[4] + cost_service[5] );
		// Print total pay to "rooms.txt"	
		fprintf(fp, "%d\n", roomnumber[i].total_pay);
   } 

	
	//Print total pay to screen
	printf("\nYour total bill: %d VND ", roomnumber[i].total_pay );  
	fclose(fp);	
    
    roomnumber[i].status = 1; // 1: Room has been booked
	textcolor(14);
	printf("\nSuccesfully requested booking\n");
	setcolor(9);
	printf("\t\t\t   Your choice is : ");
	scanf("%d", &option);
    getchar();

    if (option == 1)
        {
            system("CLS");
            registration();
        }
    else if (option == 2)
        {
            system("CLS");
            login();
        }  
	else
	 	{
			home();
		}
    system("cls");
	mainMenu();
}
