void bookroom() {
	char ch;
	int i;

    //Set id for each room
    for (i = 1; i <= 20; ++i) roomnumber[i].id_room = i;
	roomstatus(roomnumber);
	  
    //Pick room
    RUN1: {
		printf("\n\n    Which room number you choose: ");
		scanf("%d", &i);
	};
    	
   	//Check status of this room
	if (roomnumber[i].status == 1 || i > 20 || i < 1) {
		printf("The room you choose is not available now or have been booked !\n");
		printf("\nPlease pick another room >>   \n\n");
		printf("Return to home press --> \"H\" \nPick another room press --> \"A\" \n >> ");
	    ch = getch();
		if(ch == 'h' || ch == 'H'){
			mainMenu();
		}
    }
	if (ch == 'a' || ch == 'A') goto RUN1;
				
//======================================================================================
		
	//room type 1 max people is 2
	if (i >= 1 && i <= 5 ){		
		int h = 0; //h bieu thi chi so index cua cau truc kieu mang cost_room[4]
		add(h, i); 
  	}
    
   	//room type 2 max people is 5
   	if (i >= 6 && i <= 10 ){
		int h = 1;
		add(h, i);
   	}
   	//room type 3 max people is 8
   	if (i >= 11 && i <= 15 ){
		int h = 2;
		add(h, i);
   	}
   	//room type 4 max people is 11
   	if (i >= 16 && i <= 20){
   		int h = 3;
   		add(h, i);
	}
}
 
void add (int h, int i) { 
   fp = fopen("rooms.txt", "a+"); 
	if (fp == 0) {
    	fp = fopen("rooms.txt", "a+");
	    printf("Please hold on while we set our database in your computer !!");
	    printf("\n Process completed press any key to continue !!");
	    getch();
	} 

	roomnumber[i].numclient = 0;
	roomnumber[i].id_room = i;
    printf("---ROOM %d---\n", i);
    printf("\nPrice per night is %d", cost_room[h].price_per_night);
	printf("\nNote: Max people in %s is %d", cost_room[h].type, cost_room[h].max_people );		   
	printf("\nEnter period(\'x\'days):  ");
    scanf("%d", &roomnumber[i].longstay);

	// Validate checkin
	isValid = 0;
	while (!isValid) {
		// Input
		printf("\nEnter day you checkin (dd/mm/yy): ");
		fflush(stdin);
		scanf("%d/%d/%d", &roomnumber[i].checkin.dd, &roomnumber[i].checkin.mm, &roomnumber[i].checkin.yy);
		int day = roomnumber[i].checkin.dd;
		int month = roomnumber[i].checkin.mm;
		int year = roomnumber[i].checkin.yy;

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

	// Validate checkout
	isValid = 0;
	while (!isValid) {
		// Input
		printf("\nEnter day you checkout (dd/mm/yy): " );
		fflush(stdin);
		scanf("%d/%d/%d", &roomnumber[i].checkout.dd, &roomnumber[i].checkout.mm, &roomnumber[i].checkout.yy );	
		int day = roomnumber[i].checkout.dd;
		int month = roomnumber[i].checkout.mm;
		int year = roomnumber[i].checkout.yy;

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
				else if(day == 29 && month == 2 && (year%400 == 0 ||(year%4 == 0 && year%100 != 0)))
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
      
    printf("\n--------------------------------------------------");

	//Book service
	printf("\n\nWe have these services\n");
	printf("1. Service 1 cost 100000\n");
	printf("2. Service 2 cost 100000\n ");
	printf("3. Service 3 cost 200000\n");
	printf("4. Service 4 cost 200000\n");
	printf("5. Service 5 cost 400000\n");
	printf("\nNote: if you choose service 1 and 2 just type \" 1_1_0_0_0 \" with \"_\" mean space, \"0\" mean you don't want \n");
	printf("Your option: ");
	int a = 1;
		while (a <= 5) { 
			scanf("%d", &roomnumber[i].service_in_use[a]);
			if (roomnumber[i].service_in_use[a] == 1 ) {			
				cost_service[a] = list_service[a - 1].price_service;
			} else {
				cost_service[a] = 0;
			}
			a++;    					
		}		
	
	printf("\n---------------------------------------------");		
	printf("\n\n!!---Please fill this form---!!\n");
	
	roomnumber[i].numclient = 1;
	while (roomnumber[i].numclient <= cost_room[h].max_people) {
	   		
		printf("\n>>----Person %d----<<\n", roomnumber[i].numclient );

		printf("\n\nEnter your fullname: ");
		fflush(stdin);
		gets(roomnumber[i].client.name);

		// Validate birthday
		isValid = 0;
		while (!isValid) {
			// Input
			printf("\nBirthday (dd/mm/yyyy): ");
			fflush(stdin);
			scanf("%d/%d/%d", &roomnumber[i].client.birth.dd, &roomnumber[i].client.birth.mm, &roomnumber[i].client.birth.yy);
			int day = roomnumber[i].client.birth.dd;
			int month = roomnumber[i].client.birth.mm;
			int year = roomnumber[i].client.birth.yy;

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
					else if(day == 29 && month == 2 && (year%400 == 0 ||(year%4 == 0 && year%100 != 0)))
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
		
		// Validate sex
		isValid = 0;
		while (!isValid) {
			// Input
			printf("\nSex (M: Male/ F: Famale/ O: Others):  ");
        	roomnumber[i].client.sex = getche();

			switch (roomnumber[i].client.sex) {
				case 'M':
				case 'm':
				case 'F':
				case 'f':
				case 'O':
				case 'o':
					isValid = 1;
					break;
				default:
					isValid = 0;
			};

			// Notification
			!isValid ? printf("Your input is unvalid. Please try again!\n") : 0;
		}
		printf("\n");

        // Validate phone number
		{
			int c;
			char phone[15];
			RUN2: printf("\nPhone number: ");
			scanf("%s", phone);
			int length = strlen(phone);
			if( length != 10)
			{
				printf("Phone number contains only 10 number characters ! \n");
				goto RUN2;
			}
			for (c = 0; c < 10; c++ ) {
				if (phone[c] < '0' || phone[c] > '9') {
					printf("Phone number is number ! \n");
					goto RUN2;
				}
			}
			roomnumber[i].client.phone = atoi(phone);
		}

        printf("\nEmail:  ");
        scanf("%s", roomnumber[i].client.email);

		fprintf(fp, "%d, %d, %d/%d/%d, %d/%d/%d,", 
		roomnumber[i].id_room,
		roomnumber[i].longstay,
		roomnumber[i].checkin.dd, roomnumber[i].checkin.mm, roomnumber[i].checkin.yy,
		roomnumber[i].checkout.dd, roomnumber[i].checkout.mm, roomnumber[i].checkout.yy);

		fprintf(fp, "%s, %d/%d/%d, %c, %d, %s, ", 
	    roomnumber[i].client.name,
	    roomnumber[i].client.birth.dd, roomnumber[i].client.birth.mm, roomnumber[i].client.birth.yy,
	    roomnumber[i].client.sex,
	    roomnumber[i].client.phone,
	    roomnumber[i].client.email);   
	    		

        printf("\n\nDo you want to add one more people press \"Y\" \n If NO press \"N\"");      	     		
        printf("\nY/N >>>  ");
        ch = getch();
        if (ch == 'N' || ch == 'n') {
			for (int a = 1; a <= 5; a++) fprintf(fp, "%d, ", roomnumber[i].service_in_use[a]);   	    			

			// Caluculate total pay
			roomnumber[i].total_pay = roomnumber[i].longstay * (cost_room[h].price_per_night + cost_service[1] + cost_service[2] + cost_service[3] + cost_service[4] + cost_service[5] );
			// Print total pay to "rooms.txt"	
			fprintf(fp, "%d\n", roomnumber[i].total_pay);
		  	break; 
		} else if (ch == 'Y' || ch == 'y') {
         	roomnumber[i].numclient++;
     	    if (roomnumber[i].numclient > cost_room[h].max_people) {
     	       	printf("Sorry the room has max people !\n");
     	        break;   					
    	   }
    	}

		for (int a = 1; a <= 5; a++) fprintf(fp, "%d, ", roomnumber[i].service_in_use[a]);   	    			

		// Caluculate total pay
		roomnumber[i].total_pay = roomnumber[i].longstay * (cost_room[h].price_per_night + cost_service[1] + cost_service[2] + cost_service[3] + cost_service[4] + cost_service[5] );
		// Print total pay to "rooms.txt"	
		fprintf(fp, "%d\n", roomnumber[i].total_pay);
   } 

	
	//Print total pay to screen
	printf("\nYour total bill: %d VND ", roomnumber[i].total_pay );  
	fclose(fp);	
    
    roomnumber[i].status= 1; // 1: Room has been booked
    printf("Succesfully requested booking\n");
    
	printf("\nPress any key to return to main menu");
    getch();
	system("cls");
	fflush(stdin);
	mainMenu();
}


void roomstatus(struct room_hotel *roomnumber){
	char *pc;
	FILE *f;
	f = fopen("rooms.txt", "r");

	int lineLength = 255, roomNum;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

	// Read file to assign room.status = 1
    while (fgets(line, sizeof(line), f)) {
		if (line == "") break;

		// Split string with delimeters to struct
		// - Get room number
		char * token = strtok(line, ", ");
		roomNum = strtol(token, NULL, 10);

		roomnumber[roomNum].status = 1;
	}
	fclose(f);

    printf("\t\n\tRoom   \t  Category  \tPrice per night  \tAvailable  \tCheckin  \tChekout\n");				
	for (i = 1; i <= 5; ++i){
		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
		printf("\t %d  \t%s        %d                  %s  \t%s  \t%s\n", i,  cost_room[0].type, cost_room[0].price_per_night, pc, roomnumber[i].checkin, roomnumber[i].checkout );
	}
	for (i = 6; i <= 10; ++i){
		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
		printf("\t %d  \t%s        %d                  %s  \t%s  \t%s\n", i,  cost_room[1].type, cost_room[1].price_per_night, pc, roomnumber[i].checkin, roomnumber[i].checkout);
	}
	for (i = 11; i <= 15; ++i){
		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
		printf("\t %d  \t%s        %d                  %s  \t%s  \t%s\n", i,  cost_room[2].type, cost_room[2].price_per_night, pc, roomnumber[i].checkin, roomnumber[i].checkout );
	}
	for (i = 16; i <= 20; ++i) {
		pc = roomnumber[i].status == 1 ? "NO" : "YES";	
		printf("\t %d  \t%s        %d                 %s  \t%s  \t%s\n", i,  cost_room[3].type, cost_room[3].price_per_night, pc, roomnumber[i].checkin, roomnumber[i].checkout );
	}
}