#define cleanschedule main

void cleanschedule(){
	
	FILE *clean ;
	if((clean = fopen("Clean room.txt", "a+")) == NULL){
		printf("ERROR\n");
		exit(1);
	}
	
	clean = NULL;
	char h[50];
	clean = fopen("Clean room.txt", "a+");
	while(fgets(h, 50, clean) != NULL)
	{
		printf("%s", h);
	}
	fclose(fp);
}