void mainMenu() {
	system("cls");
	int input;

	for(i = 0 ; i < 80 ; i ++) printf("-");
	printf("\n");
	printf("   ****************************  |MAIN MENU|  *************************** \n");
	for(i = 0; i < 80; i ++) printf("-");
	printf("\n");

	printf("\t\t      Please enter your choice for menu");
	printf("\n\n");
	printf(" \n Enter 1 -> Book a room");
	printf("\n------------------------------------------");
	printf(" \n Enter 2 -> View Customer Record");
	printf("\n------------------------------------------");
	printf(" \n Enter 3 -> Cancel A Room");
	printf("\n------------------------------------------");
	printf(" \n Enter 4 -> Search Customer Record");
	printf("\n------------------------------------------");
	printf(" \n Enter 5 -> Edit Record");
	printf("\n------------------------------------------");
	printf(" \n Enter 6 -> Add Room cleaning Schedule");
	printf("\n------------------------------------------");
    printf(" \n Enter 7 -> Show Room cleaning Schedule");
	printf("\n------------------------------------------");
	printf(" \n Enter 8 -> Exit");
	printf("\n------------------------------------------\n");
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
		// case '6': 
		// 	system("cls");
		// 	addCleaningSchedule();
		// 	break;
		// case '7':
		// 	system("cls");
		// 	showCleaningSchedule();
		// 	break;
		case '8':
			system("cls");
			exiting();
			break;
		default:
			mainMenu();
	}
}