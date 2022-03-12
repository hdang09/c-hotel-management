void edit()
{
    system("cls");
    FILE *f, *t;
    f = fopen("room-list.txt", "r");
    t = fopen("temp.txt", "w");
    if (f == NULL) exit(0);

    int k = 1, price_per_night2;
    char roomNumber[20];
    printf("Enter Room number of the customer to edit:\n\n");
    scanf("%s", roomNumber);
    fflush(stdin);

    int lineLength = 255;
    char line[lineLength], line2[lineLength]; /* not ISO 90 compatible */

    // Loop each line
    while (fgets(line, sizeof(line), f)) {
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
		token =  strtok(NULL, ",");
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
		
		// Handling
		if (atoi(roomNumber) == s.room2) {
            k = 0;
            // printf("\nEnter Room Number     :");
            // gets(s.roomNumber);

            printf("\nEnter period(\'x\'days):  ");
            scanf("%d",  &s.longstay2);
            printf("\nEnter day you checkin (dd/mm/yy): ");
            scanf("%d/%d/%d",  &s.checkin2.dd,  &s.checkin2.mm,  &s.checkin2.yy);
            printf("\nEnter day you checkout (dd/mm/yy): " );
            scanf("%d/%d/%d",  &s.checkout2.dd,  &s.checkout2.mm,  &s.checkout2.yy );
            
            printf("\n\nEnter your fullname: ");
            fflush(stdin);
            gets(s.name2);

            // Validate birthday
            isValid = 0;
            while (!isValid) {
                // Input
                printf("\nBirthday (dd/mm/yyyy):");
                fflush(stdin);
                scanf("%d/%d/%d", &s.birth2.dd, &s.birth2.mm, &s.birth2.yy);
                int day = s.birth2.dd;
                int month = s.birth2.mm;
                int year = s.birth2.yy;

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
                scanf("%s", &s.sex2);

                switch (s.sex2[0]) {
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

            printf("\nPhone number:   ");
            scanf("%d", &s.phone2);
            printf("\nEmail:  ");
            scanf("%s", &s.email2);

            printf("\n\nWe have these services\n");
            printf("1. Service 1 cost 100000\n");
            printf("2. Service 2 cost 100000\n ");
            printf("3. Service 3 cost 200000\n");
            printf("4. Service 4 cost 200000\n");
            printf("5. Service 5 cost 400000\n");
            printf("\nNote: if you choose service 1 and 2 just type \" 1_1_0_0_0 \" with \"_\" mean space, \"0\" mean you don't want \n");
            printf("Your option: ");
            int a = 1;
            while (a <= 5){
                scanf("%d", &s.service_in_use2[a]);
                a++;
            }		
            // fseek(f, size, SEEK_CUR);  //to go to desired position infile
            fprintf(t, "%d, %d, %d/%d/%d, %d/%d/%d,", 
            s.room2,
            s.longstay2,
            s.checkin2.dd, s.checkin2.mm, s.checkin2.yy,
            s.checkout2.dd, s.checkout2.mm, s.checkout2.yy);

            fprintf(t, "%s, %d/%d/%d, %s, %d, %s, ", 
            s.name2,
            s.birth2.dd, s.birth2.mm, s.birth2.yy,
            s.sex2,
            s.phone2,
            s.email2);

            for (int a = 0; a < 5; a++) 
                fprintf(t, "%d, ", s.service_in_use2[a]);

            if (s.room2 >= 1 && s.room2 <= 5) {
                price_per_night2 = 500000;
            } else if (s.room2 >= 6 && s.room2 <= 10) {
                price_per_night2 = 700000;
            } else if (s.room2 >= 11 && s.room2 <= 15) {
                price_per_night2 = 900000;
            } else if (s.room2 >= 16 && s.room2 <= 20) {
                price_per_night2 = 1100000;
            }
            
			s.total_pay2 = s.longstay2 * (price_per_night2 + s.service_in_use2[1] + s.service_in_use2[2] + s.service_in_use2[3] + s.service_in_use2[4] + s.service_in_use2[5]);
            fprintf(t, "%d\n", s.total_pay2);
            // break;
		} else {
			// Print to "temp.txt"
            fprintf(t, "%s", line2);
		}
	}

    if (k == 1)
        printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
    else
        printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");

    
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
 

