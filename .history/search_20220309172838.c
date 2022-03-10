#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// #include "read-line.c"

typedef struct {
	int dd;
	int mm;
	int yy;
} date2;

struct CustomerDetails   //STRUCTURE DECLARATION
{
	int room2;
	int longstay2;
	date2 checkin2;
	date2 checkout2;
	char name2[50];
	date2 birth2;
	char sex2;
	int phone2[15];
	char email2[100];	
	int service_in_use2[5];
	int total_pay2; 	 
} s;

// #define cancel main

void search() {
    system("cls");
    FILE *f;
    char roomNumber[20];
    int flag=1;
    f=fopen("add.txt","r+");
    if(f==0)
        exit(0);
    fflush(stdin);
    printf("Enter Room number of the customer to search its details: \n");
    scanf("%s", roomNumber);
    while(fread(&s,sizeof(s),1,f)==1)
    {
        if(strcmp(s.roomNumber,roomNumber)==0){
            flag=0;
            printf("\n\tRecord Found\n ");
            printf("\nRoom Number:\t%s",s.roomNumber);
            printf("\nName:\t%s",s.name);
            printf("\nAddress:\t%s",s.address);
            printf("\nPhone number:\t%s",s.phoneNumber);
            printf("\nNationality:\t%s",s.nationality);
            printf("\nEmail:\t%s",s.email);
            printf("\nPeriod:\t%s",s.period);
            printf("\nArrival date:\t%s",s.arrivaldate);
            flag=0;
            break;
        }
    }
    if(flag==1){    
        printf("\n\tRequested Customer could not be found!");
    }
    printf("\nPress any key to go back to main menu");
    getch();
    mainMenu();
    fclose(f);
}


