// Struct for date 
typedef struct {
	int dd;
	int mm;
	int yy;
} date;

// Struct for time 
typedef struct {
	int hh;
	int mm;
} timing;

// Customer properties
typedef struct {
	char name[50];
	date birth;
	char sex;
	int phone;
	char email[100];	
} client_detail;

//room type 
struct category_room {
 	int max_people;
 	char type[50];
 	int price_per_night;	
} cost_room[4] = {  
	{2, "ROOM TYPE 1", 500000},
   	{5, "ROOM TYPE 2", 700000},
   	{8, "ROOM TYPE 3", 900000},
   	{11,"ROOM TYPE 4", 1100000}
};  

//services 
typedef struct{
	int id;
	char name_service[50];
	int price_service;
} service;

//hotel services cost
service list_service[5] = {
	{1, "service 1", 100000},
	{2, "service 2", 100000},
	{3, "service 3", 200000},
	{4, "service 4", 200000},
	{5, "service 5", 400000}
};

//Struct for a one room 
struct room_hotel {
    int id_room;
 	int numclient;  
 	client_detail client;
 	int longstay;
 	date checkin;
 	date checkout; 
 	int service_in_use[5];
 	int status; //0: available -  1: full
 	long int total_pay; 	 	
 } roomnumber[21]; // The number of a room is 20 room

//Speacial structure for handling "rooms.txt" file
 struct CustomerDetails   
{
	int room2;
	int longstay2;
	date checkin2;
	date checkout2;
	char name2[500];
	date birth2;
	char sex2[1];
	int phone2;
	char email2[100];	
	int service_in_use2[5];
	long int total_pay2; 	 
} s;

//Declare PROTOTYPES
void roomstatus(struct room_hotel *roomnumber);
void add(int h, int i);
int pay(struct room_hotel *roomnumber, int h);
void bookroom();
void view_all_room_has_book();
void view_services_in_use();
void home();
void view();
//void write(struct room_hotel *roomnumber);
void write();
void registration(void);
void mainMenu();
void cancel();
void search();
void edit();
void exiting();
void addCleaningSchedule();
void showCleaningSchedule();

 //Global variables
int h, i, k, num, isValid = 0, ch;
int cost_service[5];
FILE *fp, *fp2;