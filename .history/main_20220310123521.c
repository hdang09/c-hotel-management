#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "constants.c"
//#include "add-cleaning-schedule.c"
#include "bookroom.c"
#include "cancel.c"
//#include "delete-customer.c"
#include "edit.c"
#include "exit.c"
#include "login.c"
#include "search.c"
#include "view.c"

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
void bookroom();

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