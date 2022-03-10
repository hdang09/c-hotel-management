
struct CustomerDetails   //STRUCTURE DECLARATION
{
	int longstay2[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
} s;

void cancel() {

	FILE *f, *t;
	int isHaveRoom = 0;
	char roomnumber[10];
	
	int lineLength = 255;
    char line[lineLength]; /* not ISO 90 compatible */

//  Check if files are available
	f = fopen("room list.txt","r");
	t = fopen("temp.txt","w");
	if (f == NULL || t == NULL) exit(0);

//  Input a room to cancel
	printf("Input a room number to cancle: ");
	fflush(stdin);
	scanf("%s", &roomnumber);




	// Loop each line
    while(fgets(line, lineLength, filePointer)) {
        // Loop each parameters
        printf("%s\n", line);

        char * token = strtok(line, ", ");
       printf("-----%s", token);
        // loop through the string to extract all other tokens
        while( token != NULL ) {
            printf( " %s\n", token); //printing each token
            token = strtok(NULL, ", ");
        }
    }



	
	while(fread(&s, sizeof(s), 1, f) != 0) {
		if (strcmp(roomnumber, s.roomnumber) == 0) {
			isHaveRoom = 1;
			//continue;
		} 
		else
			fwrite(&s, sizeof(s), 1, t);	
	}
	
//	Validate Notification
	if (isHaveRoom) 
		printf("Remove successfully!\n");
	else {
		printf("The room that you input doesn't exist\n");
		main();
	}
		
//	File handling
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt", "add.txt");
		
}
