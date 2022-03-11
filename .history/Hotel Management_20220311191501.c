#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define home main

#include "constants.h"
//#include "add-cleaning-schedule.c"
#include "login.c"
#include "main-menu.h"
#include "bookroom.h"
#include "cancel.h"
//#include "delete-customer.c"
#include "edit.h"
#include "exit.c"
#include "search.h"
#include "view.h"

void home() {
	int option;
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
