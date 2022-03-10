typedef struct {
	int dd;
	int mm;
	int yy;
} date;

struct CustomerDetails   //STRUCTURE DECLARATION
{
	int longstay2;
 	date checkin2;
 	date checkout2;
	char name2[50];
	date birth2;
	char sex2[20];
	int phone2[15];
	char email2[100];	
	int service_in_use2[5];
	int total_pay2; 	 
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
    fgets(line, lineLength, filePointer)
	int i = 0;
	// Loop each parameters
	printf("%s\n", line);

	char * token = strtok(line, ", ");
	// loop through the string to extract all other tokens
	while( token != NULL ) {
		// printf( " %s\n", token); //printing each token
		s[i] = token; 
		i++;
		token = strtok(NULL, ", ");
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
