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


int pay(struct room_hotel *roomnumber){
	int payy;
	int a = 1;
	fprintf(fp,"\n\nServices in use \n Service 1 \t Service 2 \t Service 3 \t Service 4 \t Service 5 \n ");
	while (a <= 5){    	    			
		fprintf(fp2, "%d, ", roomnumber[i].service_in_use[a]);
		if(roomnumber[i].service_in_use[a] == 1 ){
			cost_service[a] = list_service[a - 1].price_service;
		    fprintf(fp,"YES                ");
		}
		else{
			cost_service[a]= 0;
			fprintf(fp,"NO                ");		
			    }
		a++;    					
	}

	payy = roomnumber[i].longstay * (cost_room[h].price_per_night + cost_service[1] + cost_service[2] + cost_service[3] + cost_service[4] + cost_service[5] );
			                                                
	return payy;
}

void roomstatus(struct room_hotel *roomnumber){
	char *pc;

    printf("\t\n\tRoom   \t  Category  \tPrice per night  \tAvailable  \tCheckin  \tChekout\n");				
	for (i = 1; i <= 5; ++i){
		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
		printf("\t %d  \t%s        %d                  %s  \t%s  \t%s\n", i,  cost_room[0].type, cost_room[0].price_per_night, pc, roomnumber[i].checkin, roomnumber[i].checkout );
	}
	for (i = 6; i <= 10; ++i){
		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
		printf("\t %d  \t%s        %d                  %s  \t%s  \t%s\n", i,  cost_room[1].type, cost_room[1].price_per_night, pc, roomnumber[i].checkin, roomnumber[i].checkout);
	}
	for (i = 10; i <= 15; ++i){
		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
		printf("\t %d  \t%s        %d                  %s  \t%s  \t%s\n", i,  cost_room[2].type, cost_room[2].price_per_night, pc, roomnumber[i].checkin, roomnumber[i].checkout );
	}
	for (i = 16; i <= 20; ++i){
		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
		printf("\t %d  \t%s        %d                 %s  \t%s  \t%s\n", i,  cost_room[3].type, cost_room[3].price_per_night, pc, roomnumber[i].checkin, roomnumber[i].checkout );
	}
}

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
