#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "constants.h"
//#include "add-cleaning-schedule.h"
#include "main-menu.h"
#include "bookroom.h"
#include "cancel.h"
//#include "delete-customer.h"
#include "edit.h"  
#include "exit.h"
#include "login.h"
#include "search.h"
#include "view.h"

void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;
if(GetConsoleScreenBufferInfo(hStdOut,&csbi)) {
	wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
//	SetConsoleTextAttributes(hStdOut,wColor);
	SetConsoleTextAttribute(hStdOut,wColor);
	}
}

void home() {
	int option;
    time_t t;
	time(&t);
	char choice;
	system("cls");   // FOR CLEARING SCREEN
	setcolor(15);
	printf("___________________________________________________________________________\n");
	printf("|                                                                         |\n");      
	printf("|                                                                         |\n");
	printf("|  OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOOO  OOOOOO   |\n");
	printf("|  O        O    O O      O        O      O    O O    O O        O        |\n");
	printf("|  O  OOOOO OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOOOO OOOOOO   |\n");
	printf("|  O    O   O  O   O      O        O      O    O   O  O O    O        O   |\n");
	printf("|  OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO   |\n");
	printf("|                                                                         |\n");                       
	printf("|_________________________________________________________________________|\n");
	setcolor(9);
	printf("\t\t*************************************************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*          WELCOME TO HOTEL TEAM 1              *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*           Mentor: Le Ngoc Son                 *\n");
	printf("\t\t*          Members: Nguyen Hoang Anh            *\n");
	printf("\t\t*                   Tran Hai Dang               *\n");
	printf("\t\t*                   Doan Viet Thanh             *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*************************************************\n");
	setcolor(15);
	for (i = 0; i < 80; i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
	printf(" \n Press any key to continue:");

	getch();	
	system("cls");
    printf("Press '1' to Register\nPress '2' to Login\n\n");
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