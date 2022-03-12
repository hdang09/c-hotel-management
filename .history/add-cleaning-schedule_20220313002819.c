#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
 
struct CustomerDetails2   //STRUCTURE DECLARATION
{
    int roomCleaning;
    date dateCleaning;
    time timeCleaning;
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

        RUN4: printf("\nRoom need to be cleaned: ");
        fflush(stdin);
        scanf("%d", &clean.roomCleaning);
        if (clean.roomCleaning < 1 || clean.roomCleaning > 20) goto RUN4;

        // Validate cleaning date
        isValid = 0;
        while (!isValid) {
            // Input
            printf("\nDate for cleaning: ");
            fflush(stdin);
            scanf("%d/%d/%d", &clean.dateCleaning.dd, &clean.dateCleaning.mm, &clean.dateCleaning.yy);
            int day = clean.dateCleaning.dd;
            int month = clean.dateCleaning.mm;
            int year = clean.dateCleaning.yy;

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
            !isValid ? printf("Your input is unvalid. Please try again!\n") : 0;
        }

        // Validate cleaning time
        isValid = 0;
        while (!isValid) {
            // Input
            printf("\nTime for cleaning: ");
            fflush(stdin);
            scanf("%d:%d", &clean.timeCleaning.hh, &clean.timeCleaning.mm);
            int day = clean.timeCleaning.dd;
            int month = clean.timeCleaning.mm;
            int year = clean.timeCleaning.yy;

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
            !isValid ? printf("Your input is unvalid. Please try again!\n") : 0;
        }

        fwrite(&clean, sizeof(clean), 1, c);
        fflush(stdin);
        printf("\n\nAdd room cleaning schedule is successfully booked !!\n\n");
        printf(" Press 'ESC': Go back to main menu\n");
        printf(" Press another key: Add another customer detail");
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
   
    while(fread(&clean, sizeof(clean), 1, c) == 1) {
        printf(" \n%d \t%d/%d/%d \t\t %d:%d\n", clean.roomCleaning, 
        clean.dateCleaning.dd, clean.dateCleaning.mm, clean.dateCleaning.yy,
        clean.timeCleaning.hh, clean.timeCleaning.mm);
    }
   
    fclose(c);
    getch();
}
 


