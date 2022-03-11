void cancel() {
	system("cls");

	FILE *f, *t;
	int isHaveRoom = 0;
	char roomNumber[10];

//  Check if files are available
	f = fopen("room-list.txt","r");
	t = fopen("temp.txt","w");
	if (f == NULL || t == NULL) exit(0);

//  Input a room to cancel
	printf("Input a room number to cancle: ");
	fflush(stdin);
	scanf("%s", &roomNumber);

	int lineLength = 255;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

	// Loop each line
    while (fgets(line, sizeof(line), f)) {
		if (line == "") break;
		
		// Copy a new string from line to line2
		strcpy(line2, line);

		// Split string with delimeters to struct
		// - Get id room
		char * token = strtok(line, ", ");
		s.room2 = strtol(token, NULL, 10);

		// - Get longstay
		token = strtok(NULL, ", ");
		s.longstay2 = strtol(token, NULL, 10);

		// - Get checkin
		token = strtok(NULL, "/");
		s.checkin2.dd = strtol(token, NULL, 10);
		token = strtok(NULL, "/");
		s.checkin2.mm = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		s.checkin2.yy = strtol(token, NULL, 10);

		
		// - Get checkout
		token = strtok(NULL, "/");
		s.checkout2.dd = strtol(token, NULL, 10);
		token = strtok(NULL, "/");
		s.checkout2.mm = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		s.checkout2.yy = strtol(token, NULL, 10);
		
		
		// - Get name
		token =  strtok(NULL, ", ");
		if (token != NULL) strcpy(s.name2, token);

		// - Get birthday
		token = strtok(NULL, "/");
		s.birth2.dd = strtol(token, NULL, 10);
		token = strtok(NULL, "/");
		s.birth2.mm = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		s.birth2.yy = strtol(token, NULL, 10);

		// - Get sex
		token = strtok(NULL, ", ");
		if (token != NULL) strcpy(s.sex2, token);

		// - Get phone number
		token = strtok(NULL, ", ");
		s.phone2 = strtol(token, NULL, 10);		
		strcpy(s.email2, strtok(NULL, ", "));

		// - Get services
		token = strtok(NULL, ", ");
		s.service_in_use2[0] = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		s.service_in_use2[1] = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");		
		s.service_in_use2[2] = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		s.service_in_use2[3] = strtol(token, NULL, 10);
		token = strtok(NULL, ", ");
		s.service_in_use2[4] = strtol(token, NULL, 10);

		// - Get total pay
		token = strtok(NULL, ", ");
		s.total_pay2 = strtol(token, NULL, 10);
		
		// Ckeck each line to find exact room
		if (atoi(roomNumber) == s.room2) {
			isHaveRoom = 1;
			//continue;
		} 
		else {
			// Print to "temp.txt"
			 fprintf(t, "%s", line2);
		}
	}

		// Notification
		if (isHaveRoom) 
			printf("Remove successfully!\n");
		else 
			printf("The room that you input doesn't exist\n");

		//	File handling
		fclose(f);
		fclose(t);
		remove("room-list.txt");
		rename("temp.txt", "room-list.txt");

		// Go back to main menu
		printf("Press any key to go back to main menu");
		getch();
		mainMenu();
}
