#include <fstream>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#define no_show 0
#define show 1
#define active 1
#define inactive 0
using namespace std;
enum
{
  /* This function is used to assign numbers
     for the colors to used by the
     SetTextAttribute command */
  black,
  dark_blue,
  dark_green,
  dark_cyan,
  dark_red,
  dark_magenta,
  dark_yellow,
  light_gray,
  dark_gray,
  light_blue,
  light_green,
  light_cyan,
  light_red,
  light_magenta,
  light_yellow,
  white
};
void welcome()
{
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
        <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t    ";
    srand(time(NULL));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((rand()%13)+1));
    Sleep(75);cout<<"P";Sleep(75);cout<<"O";Sleep(75);cout<<"R";Sleep(75);cout<<"T";
    Sleep(75);cout<<" ";
    Sleep(75);cout<<"M";Sleep(75);cout<<"A";Sleep(75);cout<<"N";
    Sleep(75);cout<<"A";Sleep(75);cout<<"G";Sleep(75);cout<<"E";
    Sleep(75);cout<<"M";Sleep(75);cout<<"E";Sleep(75);cout<<"N";
    Sleep(75);cout<<"T";Sleep(75);cout<<" ";Sleep(75);cout<<"S";
    Sleep(75);cout<<"Y";Sleep(75);cout<<"S";Sleep(75);cout<<"T";
    Sleep(75);cout<<"E";Sleep(75);cout<<"M";Sleep(75);
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
        <<endl<<endl<<"\t\t\t\t\t\t\t";
    cout<<"B";Sleep(75);cout<<"Y";Sleep(75);cout<<" ";Sleep(75);
    cout<<"-";Sleep(75);cout<<" ";Sleep(75);cout<<"A";Sleep(75);
    cout<<"N";Sleep(75);cout<<"M";Sleep(75);cout<<"O";Sleep(75);
    cout<<"L";Sleep(75);cout<<" ";Sleep(75);cout<<"C";Sleep(75);
    cout<<"H";Sleep(75);cout<<"A";Sleep(75);cout<<"W";Sleep(75);
    cout<<"L";Sleep(75);cout<<"A";cout<<endl<<"\t\t\t\t\t\t\t      ";
    Sleep(75);cout<<"X";Sleep(75);cout<<"I";Sleep(75);cout<<"I";
    Sleep(75);cout<<" ";Sleep(75);cout<<"-";Sleep(75);cout<<" ";
    Sleep(75);cout<<"A";Sleep(1300);
}
void wait()
{
    /* This function is used to display the loading screen with the
        spinning animation */
    srand(time(NULL));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((rand()%13)+1));
    cout<<endl<<"Loading ...  ";
    for (int i=0;i<12;i++)
    {
        Sleep(25);
        cout << "\b\\"<<flush;
        Sleep(25);
        cout << "\b|"<<flush;
        Sleep(25);
        cout << "\b/"<<flush;
        Sleep(25);
        cout << "\b-"<<flush;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
}
void loading()
{
    /* This function is used to display the loading screen with moving
        line animation */
    cout<<endl<<"Loading"<<endl;
    srand(time(NULL));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((rand()%13)+1));
    for (int i=0;i<80;++i)
    {
        for (int j=0;j<5000000;++j);
        cout<<"_";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
}
void HUD_header()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),light_blue);
    cout<<endl<<"\t\t\t\tThe Dockyard"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),dark_blue);
    cout<<endl<<"########################################"
              <<"########################################";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
    cout<<"\t\tThis is the central part of the program."<<endl;
    cout<<"\tListed below are the records of ships currently out for sailing."<<endl;
    cout<<"\tGiven below the list are options to modify the ship records and"<<endl;
    cout<<"\t\t\tthe list of companies associated."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),dark_blue);
    cout<<"########################################"
        <<"########################################";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
}
void manager_menu()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),light_yellow);
    cout<<endl<<"Please choose the operation you want to perform :"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),dark_yellow);
    cout<<"1. Enter the list of companies and ships"<<endl;
    cout<<"2. View the list of companies and ships"<<endl;
    cout<<"3. Edit the list of companies"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
    cout<<endl<<"Enter the number of the desired option :";
}
void main_menu()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),light_yellow);
    cout<<endl<<"Administrative tasks -";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),dark_yellow);
    cout<<endl<<"1. Manage the records of ships";
    cout<<endl<<"2. Manage the list of companies";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
    cout<<endl<<endl<<"Enter the number corresponding to the task to be performed :";
}
void HUD_menu()
{
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),light_yellow);
    cout<<endl<<"Operations that can be performed -";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),dark_yellow);
    cout<<endl<<"1. Add records of ships";
    cout<<endl<<"2. Delete records of ships";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
    cout<<endl<<endl<<"Enter the number corresponding to "
        <<"the operation to be performed :";
}
char* job_type()
{
    /* This function assigns the specified character string
        to the job variable of class Ship */
    int choice;
    char buffer[20];
    cout<<endl<<"Choose the type of task :";
    cout<<endl<<"1. Bulk cargo";
    cout<<endl<<"2. Containers";
    cout<<endl<<"3. Fluids";
    cout<<endl<<"4. Cruise";
    X:
    cout<<endl<<"Enter the corresponding number:";
    cin>>choice;
    switch(choice)
    {
        case 1 : strcpy(buffer,"Bulk cargo");
                 break;
        case 2 : strcpy(buffer,"Containers");
                 break;
        case 3 : strcpy(buffer,"Fluids");
                 break;
        case 4 : strcpy(buffer,"Cruise");
                 break;
        default : cout<<endl<<"Incorrect choice";
                  goto X;
    }
    return buffer;
}
char* ship_type()
{
    /* This function assigns the specified character string
        to the type variable of class Ship */
    int choice;
    char buffer[20];
    cout<<"Choose the type of task :";
    cout<<endl<<"1. Bulk carrier";
    cout<<endl<<"2. Container ship";
    cout<<endl<<"3. Tanker";
    cout<<endl<<"4. Cruise ship";
    cout<<endl<<"5. Multi-purpose ship";
    X:
    cout<<endl<<"Enter the corresponding number:";
    cin>>choice;
    switch(choice)
    {
        case 1 : strcpy(buffer,"Bulk carrier");
                 break;
        case 2 : strcpy(buffer,"Container ship");
                 break;
        case 3 : strcpy(buffer,"Tanker");
                 break;
        case 4 : strcpy(buffer,"Cruise ship");
                 break;
        case 5 : strcpy(buffer,"Multi-purpose ship");
                 break;
        default : cout<<endl<<"Incorrect choice";
                  goto X;
    }
    return buffer;
}
void menu_edit()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),light_yellow);
    cout<<endl<<"Please choose the editing task you want to perform :"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),dark_yellow);
    cout<<"1. Add a company and its ships"<<endl;
    cout<<"2. Delete a company"<<endl;
    cout<<"3. Add ships of a company"<<endl;
    cout<<"4. Delete a ship of a company"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
    cout<<"Enter the number of the desired option :";
}
int warning()
{
    /* This function is used to display a warning before resetting
        all the data */
    system("cls");
    cout<<endl<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),light_red);
    cout<<"\t        ###############################################"<<endl;
    cout<<"\t        #                                             #"<<endl;
    cout<<"\t        # Choosing this option will reset the entire  #"<<endl;
    cout<<"\t        # database. Are you sure you want to continue?#"<<endl;
    cout<<"\t        #                                             #"<<endl;
    cout<<"\t        ###############################################"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
    char choice;
    cin>>choice;
    if (choice=='y'||choice=='Y')
        return 0;
    return -1;
}
char* time_set()
{
    /* This function is used to obtain the current system time and
        return it as a string */
    time_t t;
    struct tm *info;
    char buffer [100];
    time(&t);
    info = localtime(&t);
    strcpy(buffer,asctime(info));
    return buffer;
}
struct HUD
{
    char company_name[100];
    char ship_name[100];
    char type[100];
    char job[300];
    char date[100];
};
class Ships
{
    char name[100];
    char type[100];
    char job[300];
    char date[100];
    int status;
public:
    Ships()
    {
        strcpy(name,"NULL");
        strcpy(type,"NULL");
        strcpy(job,"NULL");
        strcpy(date,"NULL");
        status=0;
    }
    void Ships_input(int i)
    {
        cin.ignore();
        cout<<"Ship "<<(i+1)<<" -"<<endl;
        cout<<"Enter the name of the ship :";
        gets(name);
        strcpy(type,ship_type());
    }
    void Ships_output(int i)
    {
        if (status==active)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),light_red);
            cout<<(i+1)<<"."<<left<<setw(20)<<name<<setw(40)<<type<<"Active"<<endl;

        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),light_green);
            cout<<(i+1)<<"."<<left<<setw(20)<<name<<setw(40)<<type<<"Inactive"<<endl;
        }

    }
    void set_ship(HUD *H,int no_of_ships,char* company_name)
    {
        strcpy(job,job_type());
        strcpy(date,time_set());
        status=active;
        strcpy(H[no_of_ships].company_name,company_name);
        strcpy(H[no_of_ships].ship_name,name);
        strcpy(H[no_of_ships].type,type);
        strcpy(H[no_of_ships].job,job);
        strcpy(H[no_of_ships].date,date);
    }
    void set_inactive()
    {
        status=inactive;
    }
    int return_status()
    {
        return status;
    }
    char* return_name()
    {
        return name;
    }
};
class Companies : public Ships
{
    char Name[100];
    int ships_no;
    int jobs_no;
public:
    void Company_input(int i)
    {
        cout<<endl<<"Enter the name of the shipping company "<<(i+1)<<" :";
        gets(Name);
        cout<<"Enter the number of ships :";
        cin>>ships_no;
        Enter_Ships();
    }
    void Company_output(int status=show)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),light_cyan);
        cout<<left<<setw(59)<<Name<<ships_no<<endl;
        if (status==show)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),dark_blue);
            cout<<endl<<"------------------------------- COMAPANY "
                      <<"SHIPS ---------------------------------";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),light_blue);
            cout<<endl<<left<<setw(23)<<"Name"<<setw(40)<<"Type"<<"Status"<<endl;
            Display_Ships();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),dark_blue);
            cout<<endl<<endl<<"-----------------------------------"
                <<"---------------------------------------------";
            cout<<endl<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
        }
    }
    void Enter_Ships()
    {
        int i=0;
        char filename[100];
        Ships *ships;
        ships = new Ships [ships_no];
        strcpy(filename,"Data\\");
        strcat(filename,Name);
        strcat(filename,".dat");
        ofstream ship;
        ship.open(filename);
        while (i<ships_no)
        {
            ships[i].Ships_input(i);
            ship.write((char *)&ships[i],sizeof(Ships));
            ++i;
        }
        ship.close();
    }
    void Display_Ships()
    {
        int i=0;
        char filename[100];
        Ships *ships;
        ships = new Ships [ships_no];
        strcpy(filename,"Data\\");
        strcat(filename,Name);
        strcat(filename,".dat");
        ifstream ship;
        ship.open(filename);
        while (i<ships_no)
        {
            ship.read((char *)&ships[i],sizeof(Ships));
            ships[i].Ships_output(i);
            ++i;
        }
        ship.close();
    }
    void deletion()
    {
        char filename[100];
        strcpy(filename,"Data\\");
        strcat(filename,Name);
        strcat(filename,".dat");
        remove(filename);
    }
    void set_ships(int no_ship,HUD *H,int no_of_ships)
    {
        /* This function is used to set the status of a ship
            active */
        char filename[100];
        int i=0;
        strcpy(filename,"Data\\");
        strcat(filename,Name);
        strcat(filename,".dat");
        fstream ship;
        ship.open(filename, ios::in|ios::out);
        Ships *ships;
        ships = new Ships [ships_no];
        fstream temp;
        temp.open("Data//Temp.dat", ios::out);
        while (i<ships_no)
        {
            ship.read((char *)&ships[i],sizeof(Ships));
            if (i==no_ship)
                ships[i].set_ship(H,no_of_ships,Name);
            temp.write((char *)&ships[i],sizeof(Ships));
            i++;
        }
        temp.close();
        ship.close();
        remove(filename);
        rename("Data//Temp.dat",filename);
        delete ships;
    }
    void set_ships_inactive(int no_ship)
    {
        /* This function is used to set the status of a ship
            inactive */
        char filename[100];
        int i=0;
        strcpy(filename,"Data\\");
        strcat(filename,Name);
        strcat(filename,".dat");
        fstream ship;
        ship.open(filename, ios::in|ios::out);
        Ships *ships;
        ships = new Ships [ships_no];
        fstream temp;
        temp.open("Data//Temp.dat", ios::out);
        while (i<ships_no)
        {
            ship.read((char *)&ships[i],sizeof(Ships));
            if (i==no_ship)
                ships[i].set_inactive();
            temp.write((char *)&ships[i],sizeof(Ships));
            i++;
        }
        temp.close();
        ship.close();
        remove(filename);
        rename("Data//Temp.dat",filename);
        delete ships;
    }
    int find_ship(HUD *H,int no)
    {
        /* This function is used to find the
            index number of a particular ship */
        char filename[100];
        int i=0,no_of_ship,j=0;
        strcpy(filename,"Data\\");
        strcat(filename,Name);
        strcat(filename,".dat");
        fstream ship;
        ship.open(filename, ios::in|ios::out);
        Ships *ships;
        ships = new Ships [ships_no];
        fstream nos;
        nos.open("NOS.dat", ios::in | ios::out);
        nos>>no_of_ship;
        H=new HUD[no_of_ship];
        ifstream in;
        in.open("Data//HUD.dat");
        while (j<no_of_ship)
        {
            in.read((char*)&H[j],sizeof(H[j]));
            j++;
        }
        while (i<ships_no)
        {
            ship.read((char *)&ships[i],sizeof(ships[i]));
            if (strcmp(ships[i].return_name(),H[no].ship_name)==0)
                break;
            i++;
        }
        ship.close();
        nos.close();
        in.close();
        delete ships;
        delete H;
        return i;
    }
    void addShips(int add)
    {
        /* This function is used to add new ships
            for a particular existing company */
        int i=0;
        ships_no+=add;
        char filename[100];
        Ships *ships;
        ships = new Ships [ships_no];
        strcpy(filename,"Data\\");
        strcat(filename,Name);
        strcat(filename,".dat");
        ifstream ship;
        ship.open(filename);
        fstream temp;
        temp.open("Data//Temp.dat", ios::out);
        while (i<ships_no)
        {
            if (i<(ships_no-add))
            {
                ship.read((char *)&ships[i],sizeof(ships[i]));
                temp.write((char *)&ships[i],sizeof(ships[i]));
                i++;
            }
            else
            {
                ships[i].Ships_input(i);
                temp.write((char *)&ships[i],sizeof(ships[i]));
                i++;
            }
        }
        ship.close();
        remove(filename);
        temp.close();
        rename("Data//Temp.dat",filename);
        delete ships;
    }
    void delships()
    {
          /* This function is used to delete ships
            for a particular existing company */
        int i=0,number;
        char filename[100];
        Ships *ships;
        ships = new Ships [ships_no];
        strcpy(filename,"Data\\");
        strcat(filename,Name);
        strcat(filename,".dat");
        ifstream ship;
        ship.open(filename);
        cout<<endl<<left<<setw(23)<<"Name"<<setw(40)<<"Type"<<"Status"<<endl;
        while (i<ships_no)
        {
            ship.read((char *)&ships[i],sizeof(ships[i]));
            ships[i].Ships_output(i);
            i++;
        }
        cout<<"Enter the number of the ship to be deleted :";
        cin>>number;
        number--;
        fstream temp;
        temp.open("Data//Temp.dat", ios::out);
        i=0;
        ship.clear();
        ship.seekg(0,ios::beg);
        while (i<ships_no)
        {
            ship.read((char *)&ships[i],sizeof(ships[i]));
            if (i!=number)
            {
                temp.write((char *)&ships[i],sizeof(ships[i]));
            }
            i++;
        }
        temp.close();
        ship.close();
        remove(filename);
        rename("Data//Temp.dat",filename);
        delete ship;
        ships_no--;
    }
    int ret_ship()
    {
        return ships_no;
    }
    int ret_status(int no_ship)
    {
        char filename[100];
        Ships *ships;
        ships = new Ships [ships_no];
        strcpy(filename,"Data\\");
        strcat(filename,Name);
        strcat(filename,".dat");
        fstream ship;
        ship.open(filename, ios::in);
        ship.seekp(no_ship*sizeof(ships[0]));
        ship.read((char *)&ships[no_ship],sizeof(ships[no_ship]));
        return ships[no_ship].return_status();
    }
    char* ret_name()
    {
        return Name;
    }
};
void input()
{
    /* This function is used to make a
        new list of companies from scratch */
    system("cls");
    int number;
    remove("Data//HUD.dat");
    fstream nos;
    nos.open("NOS.dat", ios::in | ios::out);
    nos.seekg(0,ios::beg);
    nos<<0;
    nos.close();
    ofstream of;
    of.open("Data//Companies.dat");
    Companies *Company;
    cout<<endl<<"Enter the number of companies :";
    cin>>number;
    cin.ignore();
    ofstream no;
    no.open("NOC.dat", ios::trunc);
    no<<number;
    no.close();
    Company = new Companies[number];
    int i=0;
    while (i<number)
    {
        Company[i].Company_input(i);
        cin.ignore();
        of.write((char*)&Company[i],sizeof(Company[i]));
        i++;
    }
    of.close();
    delete Company;
}
void output(int status = show)
{
    /* This function is used to display the Companies
        and the ships under them, if required */
    system("cls");
    int number;
    ifstream in;
    in.open("Data//Companies.dat");
    Companies *Company;
    ifstream no;
    no.open("NOC.dat");
    no>>number;
    Company = new Companies[number];
    int i=0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),light_yellow);
    cout<<"Company\t\t\t\t\t\t\tNo. of Ships"<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
    while (i<number)
    {
        in.read((char*)&Company[i],sizeof(Company[i]));
        cout<<i+1<<".";
        Company[i].Company_output(status);
        i++;
    }
    no.close();
    in.close();
    delete Company;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
}
void Company_add()
{
    /* This function is used to add a new
        company along with its ships to
        the current list of companies */
    system("cls");
    int number,add,i=0;
    ifstream in;
    in.open("Data//Companies.dat");
    fstream noc;
    noc.open("NOC.dat", ios::in|ios::out);
    noc>>number;
    cout<<endl<<"Enter the number of companies to be added :";
    cin>>add;
    cin.ignore();
    number+=add;
    noc.seekg(0,ios::beg);
    noc<<number;
    Companies *Company = new Companies [number];
    fstream temp;
    temp.open("Data//Temp.dat", ios::out);
    while (i<number)
    {
        if (i<(number-add))
        {
          in.read((char *)&Company[i],sizeof(Company[i]));
          temp.write((char *)&Company[i],sizeof(Company[i]));
          i++;
        }
        else
        {
            Company[i].Company_input(number-1);
            temp.write((char *)&Company[i],sizeof(Company[i]));
            i++;
        }
    }
    in.close();
    temp.close();
    remove("Data//Companies.dat");
    rename("Data//Temp.dat","Data//Companies.dat");
    noc.close();
    delete Company;
}
void Company_remove()
{
    /* This function is used to remove a
        specified company from the list of companies */
    system("cls");
    int i=0,choice,number;
    output(no_show);
    cout<<endl<<"Enter the number of the company to be deleted :"<<endl;
    cin>>choice;
    choice--;
    ifstream in;
    in.open("Data//Companies.dat");
    fstream noc;
    noc.open("NOC.dat", ios::in | ios::out);
    noc>>number;
    if (number<1)
    {
        cout<<endl<<"No companies left to delete"<<endl;;
        system("pause");
        return;
    }
    noc.seekg(0,ios::beg);
    noc<<(number-1);
    Companies *Company = new Companies [number];
    fstream temp;
    temp.open("Data//Temp.dat", ios::out);
    while (i<number)
    {
        in.read((char *)&Company[i],sizeof(Company[i]));
        if (i!=choice)
        {
            temp.write((char *)&Company[i],sizeof(Company[i]));
        }
        i++;
    }
    temp.close();
    in.close();
    remove("Data//Companies.dat");
    rename("Data//Temp.dat","Data//Companies.dat");
    Company[choice].deletion();
    noc.close();
    delete Company;

}
void Ship_add()
{
    /* This function is used to add new ships
        for a particular existing company */
    system("cls");
    int number,add,com,i=0;
    ifstream in;
    in.open("Data//Companies.dat");
    fstream noc;
    noc.open("NOC.dat", ios::in|ios::out);
    noc>>number;
    cin.ignore();
    Companies *Company = new Companies [number];
    while (i<number)
    {
        in.read((char *)&Company[i],sizeof(Company[i]));
        i++;
    }
    output(no_show);
    cout<<endl<<"Enter the number corresponding to the company whose ship you need to add :";
    cin>>com;
    com--;
    cout<<"Enter the number of ships to be addded :";
    cin>>add;
    Company[com].addShips(add);
    i=0;
    fstream temp;
    temp.open("Data//Temp.dat", ios::out);
    while (i<number)
    {
        temp.write((char *)&Company[i],sizeof(Company[i]));
        i++;
    }
    in.close();
    temp.close();
    remove("Data//Companies.dat");
    rename("Data//Temp.dat","Data//Companies.dat");
    noc.close();
    delete Company;
}
void Ship_delete()
{
    /* This function is used to add new ships
       for a particular existing company */
    system("cls");
    int number,add,com,i=0;
    ifstream in;
    in.open("Data//Companies.dat");
    fstream noc;
    noc.open("NOC.dat", ios::in|ios::out);
    noc>>number;
    cin.ignore();
    Companies *Company = new Companies [number];
    while (i<number)
    {
        in.read((char *)&Company[i],sizeof(Company[i]));
        i++;
    }
    output(no_show);
    cout<<endl<<"Enter the number corresponding to the company whose ship you need to delete :";
    cin>>com;
    com--;
    Company[com].delships();
    fstream temp;
    temp.open("Data//Temp.dat", ios::out);
    i=0;
    in.seekg(0,ios::beg);
    while (i<number)
    {
        temp.write((char *)&Company[i],sizeof(Company[i]));
        i++;
    }
    in.close();
    temp.close();
    remove("Data//Companies.dat");
    rename("Data//Temp.dat","Data//Companies.dat");
    noc.close();
    delete Company;
}
void edit()
{
    int choice;
    char cont;
    do {
            X:
            menu_edit();
            cin>>choice;
            switch(choice)
            {
                case 1 : loading();
                         Company_add();
                         break;
                case 2 : loading();
                         Company_remove();
                         break;
                case 3 : loading();
                         Ship_add();
                         break;
                case 4 : loading();
                         Ship_delete();
                         break;
                default : cout<<endl<<"You have entered an invalid option"<<endl;
                          system("pause");
                          system("cls");
                          goto X;
            }
            cout<<endl<<"Anymore editing task to be performed?";
            cin>>cont;
    }while (cont=='Y'|| cont=='y');
}
void Manager()
{
    int choice;
    char desire;
    do{
        X:
        system("cls");
        manager_menu();
        cin>>choice;
        switch (choice)
        {
            case 1 : wait();
                     system("cls");
                     if (warning())
                        break;
                     else
                        input();
                     break;
            case 2 : wait();
                     system("cls");
                     output();
                     break;
            case 3 : wait();
                     system("cls");
                     edit();
                     break;
           default : cout<<endl<<"You have entered an invalid option"<<endl;
                     system("pause");
                     system("cls");
                     goto X;
        }
        cout<<endl<<"Do you want to perform any other operation?";
        cin>>desire;
    }while (desire == 'Y' || desire == 'y');
}
void HUD_output()
{
    /* This function is used to show the main screen
        of the program which displays all the
        currently active ships details */
    ifstream in;
    in.open("Data//HUD.dat");
    ifstream nos;
    nos.open("NOS.dat");
    int no_of_ships,i=0;;
    nos>>no_of_ships;
    if (no_of_ships<1)
    {
        cout<<endl<<"There are no records to display"<<endl;
        system("pause");
        return;
    }
    HUD *H=new HUD[no_of_ships];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),light_yellow);
    cout<<endl<<"     "<<left<<setw(20)<<"COMPANY"
        <<setw(15)<<"SHIP"<<setw(21)<<"TASK"<<"DATE";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),light_cyan);
    while (i<no_of_ships)
    {
        in.read((char*)&H[i],sizeof(H[i]));
        cout<<endl<<(i+1)<<"."<<left<<setw(23)<<H[i].company_name<<setw(15)
            <<H[i].ship_name<<setw(15)<<H[i].job<<H[i].date;
        i++;
    }
    nos.close();
    in.close();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),white);
}
void set_HUD_details()
{
    /* This function is used to set a companies ship
        as active along with the required assigning
        of job and date */
    char choice;
    do {
            system("cls");
            output(no_show);
            int no,number,no_ship,i=0,no_of_ships;
            fstream nos;
            ifstream noc;
            noc.open("NOC.dat");
            noc>>number;
            nos.open("NOS.dat", ios::in | ios::out);
            nos>>no_of_ships;
            cout<<"Enter the number of the company whose ship's "
                <<"record is to be entered :";
            cin>>no;
            Companies *Company = new Companies [number];
            no--;
            if (no>number)
            {
                cout<<endl<<"The company does not exist";
                system("pause");
                return;
            }
            ifstream com;
            com.open("Data//Companies.dat");
            while (i<number)
            {
                com.read((char *)&Company[i],sizeof(Company[i]));
                if (i==no)
                {
                    Company[i].Company_output();
                    break;
                }
                i++;
            }
            cout<<"Enter the number of the ship whose record is to be entered :";
            cin>>no_ship;
            no_ship--;
            if (no_ship>Company[i].ret_ship())
            {
                cout<<endl<<"The entered ship does not exist";
                return;
            }
            if (Company[i].ret_status(no_ship)==active)
            {
                cout<<endl<<"The ship is already assigned a task";
                return;
            }
            nos.clear();
            no_of_ships++;
            nos.seekp(0,ios::beg);
            nos<<no_of_ships;
            HUD *H;
            H=new HUD [no_of_ships];
            Company[no].set_ships(no_ship,H,(no_of_ships-1));
            ofstream out;
            out.open("Data//HUD.dat", ios::app);
            out.write((char*)&H[no_of_ships-1],sizeof(H[no_of_ships-1]));
            noc.close();
            nos.close();
            com.close();
            out.close();
            delete H;
            cout<<endl<<"Anymore records to be added?";
            cin>>choice;
    }while(choice=='y'||choice=='Y');
}
void delete_HUD_details()
{
    /* This function is used to set a company's
        ship inactive as well as delete it from
        list of ships in the HUD */
    char choice;
    do {
            system("cls");
            HUD_output();
            fstream nos;
            nos.open("NOS.dat", ios::in | ios::out);
            int no_of_ships,number,no_ship,no,i=0,j=0,flag=0;
            nos>>no_of_ships;
            if (no_of_ships<1)
            {
                cout<<endl<<"No ship record left to delete"<<endl;;
                system("pause");
                return;
            }
            HUD *H=new HUD[no_of_ships];
            ifstream in;
            in.open("Data//HUD.dat");
            while (j<no_of_ships)
            {
                in.read((char*)&H[j],sizeof(H[j]));
                j++;
            }
            cout<<endl<<"Enter the number of the ship record to be removed :";
            cin>>no;
            no--;
            ifstream noc;
            noc.open("NOC.dat");
            noc>>number;
            ifstream com;
            com.open("Data//Companies.dat");
            Companies *Company = new Companies [number];
            while (i<number)
            {
                com.read((char *)&Company[i],sizeof(Company[i]));
                if(strcmp(Company[i].ret_name(),H[no].company_name)==0)
                    break;
                i++;
            }
            no_ship=Company[i].find_ship(H,no);
            Company[i].set_ships_inactive(no_ship);
            nos.seekg(0,ios::beg);
            nos<<(no_of_ships-1);
            fstream temp;
            temp.open("Data//Temp.dat", ios::out);
            i=0;
            while (i<no_of_ships)
            {
                in.read((char *)&H[i],sizeof(H[i]));
                if (i!=no)
                {
                    temp.write((char *)&H[i],sizeof(H[i]));
                }
                i++;
            }
            temp.close();
            in.close();
            remove("Data//HUD.dat");
            rename("Data//Temp.dat","Data//HUD.dat");
            nos.close();
            com.close();
            delete H;
            cout<<endl<<"Do you want to delete any more records?";
            cin>>choice;
       }while(choice=='y'||choice=='Y');
}
int HUD_operations(int HUD_action)
{
    switch(HUD_action)
    {
        case 1 : set_HUD_details();
                 break;
        case 2 : delete_HUD_details();
                 break;
       default : cout<<endl<<"You have entered an invalid option"<<endl;
                 system("pause");
                 return -1;
    }
    return 1;
}
void HUD()
{
    /* This function manages the required function calls
        for the specific actions required */
    welcome();
    int choice,HUD_action,check;
    char cont;
    do {
            X:
            system("cls");
            HUD_header();
            HUD_output();
            main_menu();
            cin>>choice;
            switch(choice)
            {
                case 1 : system("cls");
                         loading();
                         HUD_menu();
                         cin>>HUD_action;
                         check=HUD_operations(HUD_action);
                         if (check!=1)
                            goto X;
                         break;
                case 2 : system("cls");
                         loading();
                         Manager();
                         break;
               default : cout<<endl<<"You have entered an invalid option"<<endl;
                         system("pause");
                         goto X;
                         break;
            }
            cout<<endl<<"Return to main screen?";
            cin>>cont;
    }while(cont=='y' || cont=='Y');
}
int main()
{
    /* The MoveWindow command is used to maximize the
        window and also to align it to left side
        of the screen. The main is also used to call
        HUD function */
    HWND console = GetConsoleWindow();
    MoveWindow(console, 0, 0, 800, 745, TRUE);
    HUD();
    return 0;
}
