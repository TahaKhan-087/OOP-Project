#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#define max 100
using namespace std;

int count=0;

class Customer
{
public:
    char name[max];
    char address[max];
    char phone[12];
    char from_date[20];
    char to_date[20];
    float payment_advance;
    int booking_id;  
}; 

class Menus
{
    public:
    void Main_Menu_Title();
    void Login_Title();
    void Room_Title();
    void ManageRooms();
    void user_menu();
    void main_menu();// login k baad (admin side py)
    void menu(); //1
    int login(); //agar admin
};

class Room
{  
public:  
    char stype;
    char ac;
    int roomNumber;
    int rent;
    int flag;
	Customer cust;
    void DisplayRoom(Room tempRoom);
    void searchRoom(int rno);
    Room AddRoom(int rno)
    {
        Room R1;  
        R1.roomNumber = rno;  
        cout << "\nType AC/Non-AC (A/N) : ";  
        cin >> R1.ac;
        cout << "\nType Size (B/S) : ";  
        cin >> R1.stype;  
        cout << "\nDaily Rent : ";  
        cin >> R1.rent;  
        R1.flag = 0;

        cout << "\n Room Added Successfully!";  
        getch();  
        return R1;
    }
};

class Hotel_Management :protected Room
{
    public:  
    void checkIn();  
    void getAvailRoom();  
    void searchCustomer(char *);  
    void checkOut(int);  
    void guestSummaryReport();
};

int main()
{
    Menus A1;
    A1.menu();
}

class Room Kamra[max];

void Room::searchRoom(int rno)
    {
        int i, found = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (Kamra[i].roomNumber == rno)  
        {  
            found = 1;  
            break;
        }  
    }  
    if (found == 1) 
    {  
        cout << "Room Details\n";  
        if (Kamra[i].flag == 1)  
        {  
            cout << "\nRoom is Reserved";  
        }  
        else
        {  
            cout << "\nRoom is available";  
        }  
        DisplayRoom(Kamra[i]);  
        getch();
    }  
    else  
    {  
        cout << "\nRoom not found";  
        getch();  
    } 
    }

void Room::DisplayRoom(Room tempRoom)
    {
        cout << "\nRoom Number: \t" << tempRoom.roomNumber;  
        cout << "\nType AC/Non-AC (A/N) " << tempRoom.ac;  
        cout << "\nType Size (B/S) " << tempRoom.stype;  
        cout << "\nRent: " << tempRoom.rent; 
    }


void Hotel_Management::guestSummaryReport()
{
    int i;
    if (count == 0)  
    {  
        cout << "\n No Guest in Hotel !!";  
    }
    else
    {
    for (i = 0; i < count; i++)  
    {  
        if (Kamra[i].flag == 1)  
        {  
            cout << "\n Customer First Name : " << Kamra[i].cust.name;  
            cout << "\n Room Number : " << Kamra[i].roomNumber;
            cout << "\n Address (only city) : " << Kamra[i].cust.address;  
            cout << "\n Phone : " << Kamra[i].cust.phone;  
            cout << "\n---------------------------------------";  
        }
    }
    }
    getch();  
}

void Hotel_Management::searchCustomer(char *pname)
{
    int i, found = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (Kamra[i].flag == 1 && stricmp(Kamra[i].cust.name, pname) == 0)  
        {  
            cout << "\nCustomer Name: " << Kamra[i].cust.name;  
            cout << "\nRoom Number: " << Kamra[i].roomNumber;

            cout << "\n\nPress enter for next record";  
            found = 1;  
            getch();  
        }  
    }  
    if (found == 0)  
    {  
        cout << "\nPerson not found.";  
        getch();  
    }  
}
void Hotel_Management::checkOut(int RoomNum)
{
    int i,found,days,rno;
    found=0;
    float BillAmount=0;
    for(i=0; i<count; i++)
    {
        if(Kamra[i].flag==1 && Kamra[i].roomNumber==RoomNum)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        cout<<"Enter number of days: ";
        cin>> days;
        BillAmount=days* Kamra[i].rent;

        cout<<endl<<endl;
        cout<<system("cls");

        cout<<("==========================================\n");
        cout<<("             CHECKOUT DETAILS          \n");
        cout<<("==========================================\n");

        cout<<"Customer Name: "<< Kamra[i].cust.name <<endl;
        cout<<"Room Number: "<<Kamra[i].roomNumber <<endl;
        cout<<"Address: "<<Kamra[i].cust.address<<endl;
        cout << "\nPhone : " << Kamra[i].cust.phone<<endl;
        cout << "\nTotal Amount Due : " <<BillAmount <<endl;  
        cout << "\nAdvance Paid: " <<Kamra[i].cust.payment_advance <<endl;  
        cout << "\n*** Total Payable: " <<BillAmount - Kamra[i].cust.payment_advance <<endl;

        Kamra[i].flag = 0;
    }  
    getch();
}

void Hotel_Management::checkIn()
{
    class Customer cust;
    int i, found = 0, rno;  
  
    cout << "\nEnter Room number : ";  
    cin >> rno;  
    for (i = 0; i < count; i++)  
    {  
        if (Kamra[i].roomNumber == rno)  
        {  
            found = 1;
            break;
        }
    }
    if (found == 1)  
    {  
        if (Kamra[i].flag == 1)  
        {  
            cout << "\nRoom is already Booked";  
            getch();  
            return;  
        }  
  
        cout << "\nEnter booking id: ";  
        cin >> Kamra[i].cust.booking_id;  
  
        cout << "\nEnter Customer Name (First Name): ";  
        cin >> Kamra[i].cust.name;  
  
        cout << "\nEnter Address (only city): ";  
        cin >> Kamra[i].cust.address;  
  
        cout << "\nEnter Phone: ";  
        cin >> Kamra[i].cust.phone;  
  
        cout << "\nEnter From Date: ";  
        cin >> Kamra[i].cust.from_date;  
  
        cout << "\nEnter to  Date: ";  
        cin >> Kamra[i].cust.to_date;  
  
        cout << "\nEnter Advance Payment: ";  
        cin >> Kamra[i].cust.payment_advance;  
  
        Kamra[i].flag = 1;  
  
        cout << "\n Customer Checked-in Successfully..";  
        getch();  
    }
    else 
    {
        cout<<"This Room is not available!\nPress any key to continue.";
        getch();
    }
}

void Hotel_Management::getAvailRoom()
{
    int i, found = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (Kamra[i].flag == 0)  
        {  
            DisplayRoom(Kamra[i]);  
            cout << "\n\nPress enter for next room";  
            found = 1;
            getch();
        }  
    }  
    if (found == 0)  
    {  
        cout << "\nAll rooms are reserved";
        getch();  
    }  
}

void Menus::menu()
{
    Menus A1;
    int o,correct;

    Home_Screen:
    system("cls");
    Main_Menu_Title();  
    cout<<"1. Admin"<<endl<<endl;
    cout<<"2. User"<<endl<<endl;
    cout<<"Press 1 for Admin "<<endl<<endl;
    cout<<"Press 2 for User "<<endl<<endl;
    cout<<"Enter an option: ";
    cin>> o;
    if(o==1)
    {
        wrong_pass:
        correct=login();
        if(correct==1)
        {
            //A1.login();
            A1.main_menu();
        }
        else
        {
            cout<<"Wrong input!";
            goto wrong_pass;
        }
    }
        else if(o==2)
        {
            system("cls");
            A1.user_menu();
        }
        else
        {
            goto Home_Screen;
            system("cls");
        }
};

void Menus::user_menu()
{
    Hotel_Management H1;
    int opt=0;
	
	while(opt!=1 || opt!=2 || opt!=3){
		system("cls");
            Main_Menu_Title();
			cout<<"1) Check-In Rooms\n"<<endl;
			cout<<"2) Home\n"<<endl;
			cout<<"3) Exit\n"<<endl;
			
			cout<<"\n Enter an option: ";
			cin>> opt;
			if(opt==1){
				H1.checkIn();
			}
			else if(opt==2){
				menu();
			}
			else if(opt==3){
				exit(1);
			}
	}
}

void Menus::main_menu()
{
    char pname[max];
    char ch;
    int opt,i,j,rno;
    Hotel_Management H1;
    Menus A1;
    do 
    {
        system("cls");
        cout<<("============================================\n");
        cout<<("               HOTEL MANAGEMENT          \n");
        cout<<("============================================\n\n");  
        cout << "\n1. Manage Rooms";
        cout << "\n2. Check-In Room";
        cout << "\n3. Available Rooms";
        cout << "\n4. Search Customer";
        cout << "\n5. Check-Out Room";
        cout << "\n6. Guest Summary Report";
        cout << "\n7. Home";
        cout << "\n8. Exit";
        cout << "\n\nEnter Option: "; 
        cin >> opt;
        switch (opt)
        {
            case 1:
                A1.ManageRooms();
                break;
            case 2:
            if (count == 0)  
            {  
                cout << "\nRooms data is not available.\nPlease add the rooms first.";  
                getch();  
            }  
            else 
                H1.checkIn();
                break;
            case 3:
                if (count == 0)  
                {  
                    cout << "\nRooms data is not available.\nPlease add the rooms first.";  
                    getch();  
                }  
                else 
                    H1.getAvailRoom();
                break;
            case 4:
                if (count == 0)  
                {  
                    cout << "\nRooms are not available.\nPlease add the rooms first.";  
                    getch();  
                }  
                else  
                {  
                    cout << "Enter Customer Name: ";  
                    cin >> pname; 
                    H1.searchCustomer(pname);
                }
                break;
            case 5:
                if (count == 0)  
                {  
                    cout << "\nRooms are not available.\nPlease add the rooms first.";  
                    getch();  
                } 
                else  
                {  
                    cout << "Enter Room Number : ";  
                    cin >> rno;
                    H1.checkOut(rno);
                }
                break;
            case 6:
                H1.guestSummaryReport();
                break;
            case 7:
                A1.menu();
            case 8:
            cout << "\nTHANK YOU! FOR USING SOFTWARE";  
            break;  
        default:  
            cout << "\nPlease Enter correct option";  
            break;
        }
    }
    while(opt!=8);
    getch();
}

void Menus::Room_Title()
{
    cout<<("==========================================\n");
    cout<<("              MANAGE ROOMS          \n");
    cout<<("==========================================\n");
}

void Menus::Main_Menu_Title()
{
    cout<<("==========================================\n");
    cout<<("        WELCOME TO FOUR SEASON HOTEL          \n");
    cout<<("==========================================\n");
}


void Menus::Login_Title()
{
    cout<<("==========================================\n");
    cout<<("              ENTER PASSWORD          \n");
    cout<<("==========================================\n\n");
}

int Menus::login()
{
  system("cls");
  int ch;
	//ofstream koiNaam("username&password.txt");
	// start is a label which can be called using goto rather than using loop
start:
Login_Title();
string user,pass,a,b;	
	
cout<<"\nENTER ADMIN USERNAME : ";
cin >> user;
cout<<"\nENTER ADMIN PASSWORD : ";
ch = getch();
	
	// this while enters the characters until user does not press enter
while (ch !=13)

{
    //pushback keeps adding to the string by taking characters and printing * as outcome. cin is not efficient here
    pass.push_back(ch);
    cout << '*';
    ch = getch();
}
	
// filehandling for username & password only
string u,p;
ifstream obj; 

// scope resolution operator
obj.open("username&password.txt",ios::in);
obj>>u>>p;
obj.close();

if (user ==u && pass == p)
{
    return 1;
}

else
{
    cout<<"\n\nWRONG PASSWORD.\n\nPRESS ANY KEY TO TRY AGAIN.....\n";
    getch();
    system("cls");
    return 0;
}
}

void Menus::ManageRooms()
{
    Room R1;
    int option,rno,i,flag=0;
    char ch;
    do
    {
        system("cls");  
        Room_Title(); 
        cout << "\n1. Add Room"; 
        cout << "\n2. Search Room";
        cout << "\n3. Back to Main Menu";  
        cout << "\n\nEnter Option: "; 
        cin >> option;

        switch(option)
        {
            case 1:
                cout<<"Enter room number: ";
                cin>>rno;

                for(i=0;i<count;i++)
                {
                    if(Kamra[i].roomNumber == rno)
                    {
                        flag = 1;
                    }
                }
                if (flag == 1)  
                {  
                    cout << "\nRoom Number is Present.\nPlease enter unique Number";  
                    flag = 0;  
                    getch();  
                }
                else
                {
                    Kamra[count] = R1.AddRoom(rno);  
                    count++;
                }
            break;
        case 2:
            cout << "\nEnter room number: ";  
            cin >> rno;  
            R1.searchRoom(rno);  
            break;
        }
    }
    while(option!=3);
}