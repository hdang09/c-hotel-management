void view() {
	fp = NULL;
	char arr[100000];
	fp = fopen("room list.txt", "r+");
	while(fgets(arr, 100000, fp) != NULL)
	{
		printf("%s", arr);
	}
	fclose(fp);

	printf("\nPress anykey to return home screen");
	getch();
	system("cls");
	fflush(stdin);
	mainMenu();
}