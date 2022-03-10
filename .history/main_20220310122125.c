#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//#include "add-cleaning-schedule.c"
#include "bookroom.c"
#include "cancel.c"
//#include "delete-customer.c"
#include "edit.c"
#include "exit.c"
#include "login.c"
#include "search.c"
#include "view.c"

// Struct for date 
typedef struct {
	int dd;
	int mm;
	int yy;
} date;

// Customer properties
typedef struct {
	char name[50];
	date birth;
	char sex[20];
	int phone[15];
	char email[100];	
} client_detail;

//room type 
struct category_room {
 	int max_people;
 	char type[50];
 	int price_per_night;	
} cost_room[4] = {  
	{2, "ROOM TYPE 1", 500000},
   	{5, "ROOM TYPE 2", 700000},
   	{8, "ROOM TYPE 3", 900000},
   	{11,"ROOM TYPE 4", 1100000}
};  

//services 
typedef struct{
	int id;
	char name_service[50];
	int price_service;
} service;

//hotel services cost
service list_service[5] = {
	{1, "service 1", 100000},
	{2, "service 2", 100000},
	{3, "service 3", 200000},
	{4, "service 4", 200000},
	{5, "service 5", 400000}
};

//Struct for a one room 
struct room_hotel {
    int id_room;
 	int numclient;  
 	client_detail client;
 	int longstay;
 	date checkin;
 	date checkout; 
 	int service_in_use[5];
 	int status  ; //1 : available -  0: full
 	int total_pay; 	 	
 } roomnumber[21]; // The number of a room is 20 room

//Declare PROTOTYPES
void roomstatus(struct room_hotel *roomnumber);
void bookroom();
void add(int h, int i);
int pay(struct room_hotel *roomnumber);
void view_all_room_has_book();
void view_services_in_use();
void home();
void view();
//void write(struct room_hotel *roomnumber);
void write();

//Global variables
int h, i, ch, k, num, isValid = 0;
int cost_service[5];
FILE *fp, *fp2;
#define home main

// void bookroom() {
// 	int i;
//     //SET AVAILABLE ROOM
//     for (i = 1; i <= 20; ++i) roomnumber[i].id_room = i;
// 	roomstatus(roomnumber);
	  
//     //Pick room
//     RUN1: {
// 		ch = "";
// 		printf("\n\n    Which room number you choose: ");
// 		scanf("%d", &i);
// 	};
    	
//    	//Check status of this room
// 	if(roomnumber[i].status == 1 || i > 20 || i < 1) {
// 		printf("The room you choose is not available now or have been booked !\n");
// 		printf("\nPlease pick another room >>   \n\n");
// 		printf("Return to home press --> \"H\" \nPick another room press --> \"A\" \n >> ");
// 	    ch = getch();
// 		if(ch == 'h' || ch == 'H'){
// //			system("cls"); // clear screan
// 			home();// write code to return to home of hotel 		
// 		}
//     }
// 	if (ch == 'a' || ch == 'A') goto RUN1;
				
// //======================================================================================
		
// 	//room type 1 max pp is 2
// 	if (i >= 1 && i <= 5 ){		
// 		int h = 0; //h bieu thi chi so index cua cau truc kieu mang cost_room[4]
// 		add(h, i); 
//   	}
    
//    	//room type 2 max pp is 5
//    	if (i >= 6 && i <= 10 ){
// 		int h = 1;
// 		add(h, i);
//    	}
//    	//room type 3 max pp is 8
//    	if (i >= 11 && i <= 15 ){
// 		int h = 2;
// 		add(h, i);
//    	}
//    	//room type 4 max pp is 11
//    	if (i >= 16 && i <= 20){
//    		int h = 3;
//    		add(h, i);
// 	}
	

// }
 
// void add (int h, int i) { 
//    fp = fopen("room list.txt", "a"); 
//    fp2 = fopen("room list 2.txt", "a"); 
// 	if (fp == 0 || fp2 == 0) {
//     	fp = fopen("room list.txt", "a");
//     //	system("cls");
// 	    printf("Please hold on while we set our database in your computer !!");
// 	    printf("\n Process completed press any key to continue !!");
// 	    getch();
// 	} 

// 	roomnumber[i].numclient = 0;
// 	roomnumber[i].id_room = i;
//     printf("---ROOM %d---\n", i);
//     printf("\nPrice per night is %d", cost_room[h].price_per_night);
// 	printf("\nNote: Max people in %s is %d", cost_room[h].type, cost_room[h].max_people );		   
// 	printf("\nEnter period(\'x\'days):  ");
//     scanf("%d", &roomnumber[i].longstay);

// 	// Validate checkin
// 	isValid = 0;
// 	while (!isValid) {
// 		// Input
// 		printf("\nEnter day you checkin (dd/mm/yy): ");
// 		fflush(stdin);
// 		scanf("%d/%d/%d", &roomnumber[i].checkin.dd, &roomnumber[i].checkin.mm, &roomnumber[i].checkin.yy);
// 		int day = roomnumber[i].checkin.dd;
// 		int month = roomnumber[i].checkin.mm;
// 		int year = roomnumber[i].checkin.yy;

// 		//check year
// 		if (year >= 1900 && year <= 9999) {
// 			//check month
// 			if (month >= 1 && month <= 12) {
// 				//check days
// 				if((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
// 					isValid = 1;
// 				else if((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
// 					isValid = 1;
// 				else if((day >= 1 && day <= 28) && (month == 2))
// 					isValid = 1;
// 				else if(day == 29 && month == 2 && (year%400 == 0 ||(year%4 == 0 && year%100 != 0)))
// 					isValid = 1;
// 				else
// 					isValid = 0;
// 			}
// 			else {
// 				isValid = 0;
// 			}
// 		}
// 		else {
// 			isValid = 0;
// 		}

// 		// Notification
// 		!isValid ? printf("Your input is unvalid. Please try again!\n") : 0;
// 	}

// 	// Validate checkout
// 	isValid = 0;
// 	while (!isValid) {
// 		// Input
// 		printf("\nEnter day you checkout (dd/mm/yy): " );
// 		fflush(stdin);
// 		scanf("%d/%d/%d", &roomnumber[i].checkout.dd, &roomnumber[i].checkout.mm, &roomnumber[i].checkout.yy );	
// 		int day = roomnumber[i].checkout.dd;
// 		int month = roomnumber[i].checkout.mm;
// 		int year = roomnumber[i].checkout.yy;

// 		//check year
// 		if (year >= 1900 && year <= 9999) {
// 			//check month
// 			if (month >= 1 && month <= 12) {
// 				//check days
// 				if((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
// 					isValid = 1;
// 				else if((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
// 					isValid = 1;
// 				else if((day >= 1 && day <= 28) && (month == 2))
// 					isValid = 1;
// 				else if(day == 29 && month == 2 && (year%400 == 0 ||(year%4 == 0 && year%100 != 0)))
// 					isValid = 1;
// 				else
// 					isValid = 0;
// 			}
// 			else {
// 				isValid = 0;
// 			}
// 		}
// 		else {
// 			isValid = 0;
// 		}

// 		// Notification
// 		!isValid ? printf("Your input is unvalid. Please try again!\n") : 0;
// 	}
      
//     printf("\n--------------------------------------------------");
    
// 	fprintf(fp,"\n\n\n** ROOM %d ** \n Period days %d\n Checkin %d/%d/%d \n checkout %d/%d/%d \n ",
// 	roomnumber[i].id_room,
// 	roomnumber[i].longstay,
// 	roomnumber[i].checkin.dd, roomnumber[i].checkin.mm, roomnumber[i].checkin.yy,
// 	roomnumber[i].checkout.dd, roomnumber[i].checkout.mm, roomnumber[i].checkout.yy);

// 	printf("---------------------------------------------");
     		
// 	//Book service
//     printf("\n\nWe have these services\n");
//     printf("1. Service 1 cost 100000\n");
//     printf("2. Service 2 cost 100000\n ");
//     printf("3. Service 3 cost 200000\n");
//     printf("4. Service 4 cost 200000\n");
//     printf("5. Service 5 cost 400000\n");
//     printf("\nNote: if you choose service 1 and 2 just type \" 1_1_0_0_0 \" with \"_\" mean space, \"0\" mean you don't want \n");
//     printf("Your option: ");
//     int a = 1;
//     while (a <= 5){
//        	scanf("%d", &roomnumber[i].service_in_use[a]);
//        	a++;
//     }		
	
// 	printf("\n\n!!---Please fill this form---!!\n");
	
// 	roomnumber[i].numclient = 1;
// 	while (roomnumber[i].numclient <= cost_room[h].max_people) {
	   		
// 		printf("\n>>----Person %d----<<\n", roomnumber[i].numclient );

// 		// Validate name
// 		isValid = 0;
// 		while (!isValid) {
// 			// Input
// 			printf("\n\nEnter your fullname: ");
// 			fflush(stdin);

// 			isValid = scanf("%50[a-zA-Z]", &roomnumber[i].client.name);

// 			// Notification
// 			!isValid ? printf("Your input is unvalid. Please try again!\n") : 0;
// 		}

// 		// Validate birthday
// 		isValid = 0;
// 		while (!isValid) {
// 			// Input
// 			printf("\nBirthday (dd/mm/yyyy):");
// 			fflush(stdin);
// 			scanf("%d/%d/%d", &roomnumber[i].client.birth.dd, &roomnumber[i].client.birth.mm, &roomnumber[i].client.birth.yy);
// 			int day = roomnumber[i].client.birth.dd;
// 			int month = roomnumber[i].client.birth.mm;
// 			int year = roomnumber[i].client.birth.yy;

// 			//check year
// 			if (year >= 1900 && year <= 9999) {
// 				//check month
// 				if (month >= 1 && month <= 12) {
// 					//check days
// 					if((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
// 						isValid = 1;
// 					else if((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
// 						isValid = 1;
// 					else if((day >= 1 && day <= 28) && (month == 2))
// 						isValid = 1;
// 					else if(day == 29 && month == 2 && (year%400 == 0 ||(year%4 == 0 && year%100 != 0)))
// 						isValid = 1;
// 					else
// 						isValid = 0;
// 				}
// 				else {
// 					isValid = 0;
// 				}
// 			}
// 			else {
// 				isValid = 0;
// 			}

// 			// Notification
// 			!isValid ? printf("Your input is unvalid. Please try again!\n") : 0;
// 		}
		
// 		// Validate sex
// 		isValid = 0;
// 		while (!isValid) {
// 			// Input
// 			printf("\nSex (M: Male/ F: Famale/ O: Others):  ");
//         	scanf("%s", &roomnumber[i].client.sex);

// 			switch (roomnumber[i].client.sex[0]) {
// 				case 'M':
// 				case 'm':
// 				case 'F':
// 				case 'f':
// 				case 'O':
// 				case 'o':
// 					isValid = 1;
// 					break;
// 				default:
// 					isValid = 0;
// 			};

// 			// Notification
// 			!isValid ? printf("Your input is unvalid. Please try again!\n") : 0;
// 		}

        
//         printf("\nPhone number:   ");
//         scanf("%s", &roomnumber[i].client.phone);
//         printf("\nEmail:  ");
//         scanf("%s", &roomnumber[i].client.email);

// 		fprintf(fp2, "%d, %d, %d/%d/%d, %d/%d/%d, ", 
// 		roomnumber[i].id_room,
// 		roomnumber[i].longstay,
// 		roomnumber[i].checkin.dd, roomnumber[i].checkin.mm, roomnumber[i].checkin.yy,
// 		roomnumber[i].checkout.dd, roomnumber[i].checkout.mm, roomnumber[i].checkout.yy);

// 		fprintf(fp2, "%s, %d/%d/%d, %s, %s, %s, ", 
// 	    roomnumber[i].client.name,
// 	    roomnumber[i].client.birth.dd, roomnumber[i].client.birth.mm, roomnumber[i].client.birth.yy,
// 	    roomnumber[i].client.sex,
// 	    roomnumber[i].client.phone,
// 	    roomnumber[i].client.email);   
	    

// 		roomnumber[i].total_pay = pay(roomnumber);	
// 		fprintf(fp,"\n Total pay: %d", roomnumber[i].total_pay);
// 		fprintf(fp2,"%d\n", roomnumber[i].total_pay);

//         printf("\n\nDo you want to add one more people press \"Y\" \n If NO press \"N\"");      	     		
//         printf("\nY/N >>>  ");
//         ch = getch();
        
//         if (ch == 'N' || ch == 'n')
// 		  	break; 
//        	if (ch == 'Y' || ch == 'y') {
//          	roomnumber[i].numclient++;
//      	    if (roomnumber[i].numclient > cost_room[h].max_people) {
//      	       	printf("Sorry the room has max people !\n");
//      	        break;   					
//     	   }
//     	}
//    } 
    
// 	//calculate totalpay
//     printf("\nYour total bill: %d VND ", roomnumber[i].total_pay ); 
// 	fclose(fp);	
// 	fclose(fp2);	
    
//     roomnumber[i].status= 1; // chuyen status tu 0 ve 1
//     printf("Succesfully requested booking\n");
    
// 	printf("\nPress any key to return to main menu");
//     getch();
// 	system("cls");
// 	fflush(stdin);
// 	mainMenu();
// }

// int pay(struct room_hotel *roomnumber){
// 	int payy;
// 	int a = 1;
// 	fprintf(fp,"\n\nServices in use \n Service 1 \t Service 2 \t Service 3 \t Service 4 \t Service 5 \n ");
// 	while (a <= 5){    	    			
// 		fprintf(fp2, "%d, ", roomnumber[i].service_in_use[a]);
// 		if(roomnumber[i].service_in_use[a] == 1 ){
// 			cost_service[a] = list_service[a - 1].price_service;
// 		    fprintf(fp,"YES                ");
// 		}
// 		else{
// 			cost_service[a]= 0;
// 			fprintf(fp,"NO                ");		
// 			    }
// 		a++;    					
// 	}

// 	payy = roomnumber[i].longstay * (cost_room[h].price_per_night + cost_service[1] + cost_service[2] + cost_service[3] + cost_service[4] + cost_service[5] );
			                                                
// 	return payy;
// }

// void roomstatus(struct room_hotel *roomnumber){
// 	char *pc;
// 	FILE *f;
// 	f = fopen("room list 2.txt", "r");

// 	int lineLength = 255, roomNum;
//     char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

// 	// Read file to assign room.status = 1
//     while (fgets(line, sizeof(line), f)) {
// 		if (line == "") break;
// 		// Copy a new string from line to line2
// 		for (int i = 0; i < strlen(line); i++) line2[i] = line[i];

// 		// Split string with delimeters to struct
// 		char * token = strtok(line, ", ");
// 		roomNum = strtol(token, NULL, 10);
// 		roomnumber[roomNum].status = 1;
// 	}
// 	fclose(f);

//     printf("\t\n\tRoom   \t  Category  \tPrice per night  \tAvailable  \tCheckin  \tChekout\n");				
// 	for (i = 1; i <= 5; ++i){
// 		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
// 		printf("\t %d  \t%s        %d                  %s  \t%s  \t%s\n", i,  cost_room[0].type, cost_room[0].price_per_night, pc, roomnumber[i].checkin, roomnumber[i].checkout );
// 	}
// 	for (i = 6; i <= 10; ++i){
// 		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
// 		printf("\t %d  \t%s        %d                  %s  \t%s  \t%s\n", i,  cost_room[1].type, cost_room[1].price_per_night, pc, roomnumber[i].checkin, roomnumber[i].checkout);
// 	}
// 	for (i = 10; i <= 15; ++i){
// 		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
// 		printf("\t %d  \t%s        %d                  %s  \t%s  \t%s\n", i,  cost_room[2].type, cost_room[2].price_per_night, pc, roomnumber[i].checkin, roomnumber[i].checkout );
// 	}
// 	for (i = 16; i <= 20; ++i) {
// 		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
// 		printf("\t %d  \t%s        %d                 %s  \t%s  \t%s\n", i,  cost_room[3].type, cost_room[3].price_per_night, pc, roomnumber[i].checkin, roomnumber[i].checkout );
// 	}
// }

/*void view() { // xem het tat ca du lieu nhap vao file
	FILE *fp;
	if((fp=fopen("Book room list.txt","r")) == NULL){
		printf(" hahah");
    	system("cls");
	}
	
	i = 1;
	while(fread(&roomnumber[i], sizeof(struct room_hotel), 1, fp) == 1){
	printf("Room  %d  ", roomnumber[i].id_room);
	printf("Period day  %d   ", roomnumber[i].longstay);
	printf("Checkin %d/%d/%d ", roomnumber[i].checkin.dd,  roomnumber[i].checkin.mm,  roomnumber[i].checkin.yy );
	printf("Checkout %d/%d/%d ", roomnumber[i].checkout.dd,  roomnumber[i].checkout.mm,  roomnumber[i].checkout.yy );
	
	printf("\nName  %s ", roomnumber[i].client.name);
	printf("\nBirthday  %d/%d/%d ", roomnumber[i].client.birth.dd,  roomnumber[i].client.birth.mm,  roomnumber[i].client.birth.yy );
	printf("\nSex  %s ", roomnumber[i].client.sex);
	printf("\nPhone %s  ", roomnumber[i].client.phone);
	printf("\nEmail %s  ",  roomnumber[i].client.email);
	printf("\nTotal pay %d", roomnumber[i].total_pay);	
	i++;	
	}
	fclose(fp);
	
}*/

void home() {
	int option;
	system("cls");
    printf("Press '1' to Register\nPress '2' to Login\n\n");
    scanf("%d", &option);
    getchar();           // catching newline

    if(option == 1)
        {
            system("CLS");
            registration();
        }
    else if(option == 2)
        {
            system("CLS");
            login();
        }
    system("cls");
	mainMenu();
}

void mainMenu() {
	system("cls");
	int input;

	for(i = 0 ; i < 80 ; i ++) printf("-");
	printf("\n");
	printf("   ******************************  |MAIN MENU|  ***************************** \n");
	for(i = 0; i < 80; i ++) printf("-");
	printf("\n");

	printf("\t\t *Please enter your choice for menu*:");
	printf("\n\n");
	printf(" \n Enter 1 -> Book a room");
	printf("\n-----------------------------------");
	printf(" \n Enter 2 -> View Customer Record");
	printf("\n-----------------------------------");
	printf(" \n Enter 3 -> Cancel A Room");
	printf("\n-----------------------------------");
	printf(" \n Enter 4 -> Search Customer Record");
	printf("\n-----------------------------------");
	printf(" \n Enter 5 -> Edit Record");
	printf("\n-----------------------------------");
	printf(" \n Enter 6 -> Exit");
	printf("\n-----------------------------------");
	printf("\n");
	for(i = 0; i < 80; i ++) printf("-");

	printf("\nYour choice is: ");
	fflush(stdin);
	input = getchar();
	switch (input) {
		case '1':
			system("cls");
			bookroom();
			break;
		case '2':
			system("cls");
			view();
			break;
		case '3':
			system("cls");
			cancel();
			break;
		case '4':
			system("cls");
			search();
			break;
		case '5':
			system("cls");
			edit();
			break;
		case '6':
			system("cls");
			exiting();
			break;
		default:
			mainMenu();
	}

}

/*void write() {
	fp=fopen("room list.txt", "a+"); 
	if(fp==0){
    	fp=fopen("room list.txt", "w+");
    //	system("cls");
	    printf("Please hold on while we set our database in your computer !!");
	    printf("\n Process completed press any key to continue !!");
	    getch();
	} 
	
	fprintf(fp,"\n** ROOM %d ** \n Period days %d\n Checkin %d/%d/%d \n checkout %d/%d/%d \n ",
	roomnumber[i].id_room,
	roomnumber[i].longstay,
	roomnumber[i].checkin.dd, roomnumber[i].checkin.mm, roomnumber[i].checkin.yy,
	roomnumber[i].checkout.dd, roomnumber[i].checkout.mm, roomnumber[i].checkout.yy );
	int j = 1;
	while(j <= roomnumber[i].numclient){
		fprintf(fp,"\n\n Person %d \n >>----------<< \n fullname: %s \n Birthday(mm/dd/yyyy): %d/%d/%d \n Sex: %s \n Phone number: %s \n Email: %s", 
	    j, roomnumber[i].client.name,
	    roomnumber[i].client.birth.dd, roomnumber[i].client.birth.mm, roomnumber[i].client.birth.yy,
	    roomnumber[i].client.sex,
	    roomnumber[i].client.phone,
	    roomnumber[i].client.email);	
	}	
	fprintf(fp,"\n Total pay: %d", roomnumber[i].total_pay);
	fclose(fp);	
} */

/*void read() {
    FILE *fp = fopen("book room list","r");
    if(fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("book room list","w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        exit(1);
    }

    fread(roomnumber, sizeof(struct room_hotel), 21, fp);
    fclose(fp);
}*/

/*void write() {
    FILE *fp = fopen("book room list","w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(&roomnumber[i], sizeof(struct room_hotel), 1, fp);

    fclose(fp);
} */
