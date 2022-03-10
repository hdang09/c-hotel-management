#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void view() {
	FILE *f;
//	fp = NULL;
	char arr[100000];
	f = fopen("room list 2.txt", "r+");
	while(fgets(arr, 100000, f) != NULL)
	{
		printf("%s", arr);
	}
	fclose(f);

	printf("\nPress anykey to return home screen");
	getch();
	system("cls");
	fflush(stdin);
	mainMenu();
}
