#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
 
struct CustomerDetails2   //STRUCTURE DECLARATION
{
    char roomCleaning[10];
    char dateCleaning[10];
    char timeCleaning[10];
} clean;
 
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
        printf("******************* ROOM CLEANING SCHEDULE *******************");
        printf("\nRoom need to cleaned: ");
        scanf("%s", clean.roomCleaning);
        fflush(stdin);
        printf("\nDate for cleaning: ");
        scanf("%s", clean.dateCleaning);
        printf("\nTime for cleaning: ");
        scanf("%s", clean.timeCleaning);
        fwrite(&clean, sizeof(clean), 1, c);
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
   
    while(fread(&clean, sizeof(clean), 1, c)==1) {
        printf(" \n%s \t%s \t\t %s\n",  clean.roomCleaning,  clean.dateCleaning,  clean.timeCleaning);
    }
   
    fclose(c);
    getch();
}
 


