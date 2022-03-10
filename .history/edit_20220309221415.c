void edit()
{
    system("cls");
    FILE *f;
    f = fopen("add.txt", "r+");
    if (f == NULL) exit(0);
    
    int k = 1;
    char roomNumber[20];
    long int size = sizeof(s);
    printf("Enter Room number of the customer to edit:\n\n");
    scanf("%[^\n]", roomNumber);
    fflush(stdin);
    while(fread(&s, sizeof(s), 1, f) == 1)
    {
        if(strcmp(s.roomNumber, roomNumber) == 0)
        {
            k = 0;
            printf("\nEnter Room Number     :");
            gets(s.roomNumber);
            printf("\nEnter Name    :");
            fflush(stdin);
            scanf("%s", &s.name);
            printf("\nEnter Address        :");
            scanf("%s", &s.address);
            printf("\nEnter Phone number :");
            scanf("%f", &s.phoneNumber);
            printf("\nEnter Nationality :");
            scanf("%s", &s.nationality);
            printf("\nEnter Email :");
            scanf("%s", &s.email);
            printf("\nEnter Period :");
            scanf("%s", &s.period);
            printf("\nEnter Arrival date :");
            scanf("%s", &s.arrivaldate);
            fseek(f, size, SEEK_CUR);  //to go to desired position infile
            fwrite(&s, sizeof(s), 1, f);
            break;
        }
    }
    if(k == 1){
        printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
        fclose(f);
        getch();
    }else{
    fclose(f);
    printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
    getch();
}
}
 

