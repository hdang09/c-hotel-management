#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
 
struct CustomerDetails   //STRUCTURE DECLARATION
{
    char roomCleaning[10];
    char dateCleaning[10];
    char timeCleaning[10];
}s;
 
void addCleaningSchedule() {
    FILE *c;
    char test;
    c = fopen("cleaning.txt", "a+");
    if (c == 0) {
        c = fopen("add.txt", "w+");
        system("cls");
        printf("Please hold on while we set our database in your computer !!");
        printf("\nProcess completely press any key to continue !!");
        getch();
    }
    while (1) {
        system("cls");
        printf("ROOM CLEANING SCHEDULE");
        printf("***************************");
        printf("\nRoom need to cleaned: \n");
        scanf("%s",h.roomCleaning);
        fflush(stdin);
        printf("\nDate for cleaning: \n");
        scanf("%s",h.dateCleaning);
        printf("\nTime for cleaning: \n");
        scanf("%s",h.timeCleaning);
        fwrite(&s,sizeof(s),1,c);
        fflush(stdin);
        printf("\n\nAdd room cleaning schedule is successfully booked !!");
        printf("\n Press esc key to exit,  any other key to add another customer detail:");
        test = getche();
        if (test == 27) {
            break;
        }
    }
    fclose(c);
}
 
void showCleaningSchedule() {
    FILE *c;
    if ((c = fopen("cleaning.txt", "r")) == NULL) {
        exit(0);
    }
    system("cls");
    printf("Room\t");
    printf("Date for cleaning\t");
    printf("Time for cleaning\t\n");
   
    while(fread(&s,sizeof(s),1,c)==1) {
        printf(" \n%s \t%s \t\t %s\n", h.roomCleaning, h.dateCleaning, h.timeCleaning);
    }
   
    fclose(c);
    getch();
}
 


