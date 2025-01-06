#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <variant>
#include <limits>
using namespace std;
//base valuses
vector<variant<int, string>> ft;
vector<variant<int, string>> reserved;
vector<variant<int, string>> cancled;
vector<variant<int, string>> tmpvec;
string user = "",fullname = "";
string fId = "F00",tId = "T10";
int fId2 = 10000, tId2 = 10000;

void adminagain();
void valshow();
void del();
void add();
void admin();
void search();
void passenger();

int main(){
    char b;
    system("cls");
    cout<<"Welcome to transportion app!\nPls enter your username\n>> ";
    while(true){
        cin.clear();
        cin>>user;
        if(!cin.fail() && user == "admin"){
            admin();
            break;
        }else if(!cin.fail() && !(int(user[0])>31 && int(user[0])<65) && !(int(user[0])>90 && int(user[0])<97) && !(int(user[0])>122 && int(user[0])<127)){
            system("cls");
            cout<<"Pls enter your name\n>> ";
            while(true){

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,fullname);

                if(!cin.fail() && !(int(fullname[0])>31 && int(fullname[0])<65) && !(int(fullname[0])>90 && int(fullname[0])<97) && !(int(fullname[0])>122 && int(fullname[0])<127)){
                    break;}
                else{
                            system("cls");
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout<<"Pls enter a valid name that is not start with character or a number\n>> ";
                    }}
            passenger();
            break;
        }else{
            system("cls");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Pls enter a valid username that is not start with character or a number\n>> ";}
    }


    return 0;
}


void adminagain(){
    char ask;
    cin>>ask;
    if(!cin.fail() && (ask == 'y' || ask == 'Y')){
        admin();
    }else if(!cin.fail() && (ask == 'n' || ask == 'N')){
        system("cls");
        cout<<"Have nice time!\n";
        main();
    }else if(cin.fail()){
        cout<<"Wrong input, Try again\n>> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        adminagain();
    }else{
        cout<<"Invalid input, Try again\n>> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        adminagain();
    }
}

void valshow(vector<variant<int, string>> vec){
    int j = 1;
    system("cls");
    for(int i = 0;i<vec.size();i+=7){
        cout<<"List of all Flights/Trains\n"<<j<<")ID: "<<get<string>(vec[i])<<get<int>(vec[i+1])<<" ------ Type: "<<get<string>(vec[i+2])<<" ------ From: "
    <<get<string>(vec[i+3])<<" ------ To: "<<get<string>(vec[i+4])<<" ------ Empty seats: "<<get<int>(vec[i+5])<<" ------ Move at: "<<get<string>(vec[i+6])<<endl;
    j++;}
    j = 1;
}

void del(){
    int a;
    bool ok = false;
    if(ft.empty() == false){
    valshow(ft);
    cout<<"Pls enter the Flight/Train number\n>> ";
    while(true){
        cin>>a;
        if(cin.fail() || a<0){
            cout<<"Pls enter a valid number\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else{
            break;
        }
    }
    for(int i = 0;i<ft.size();i+=7){
        if(i == a - 1){
            for(int j = 0;j<7;j++){
            ft.erase(ft.begin()+i);}
            ok = true;
            break;
        }
    }
    valshow(ft);
    if(ok != true){
        cout<<"Flight/Train did't remove due to inexistance or invalid input number\n";
    }else{
        cout<<"***The Flight/Train removed successfully***\n";
    }
    }else{
        system("cls");
        cout<<"There is no Flights/Trains\n";
    }
    
    cout<<"Do you like to do another thing Sir?(y/n)>> ";
    adminagain();
}
void search();

void add(){
    int tmp2,i = 0;
    char ask;
    string tmp = "  ";
        system("cls");
        cout<<"Pls enter the number Sir\n1)Flight\n2)Train\n>> ";
    while(true){
        cin>>tmp2;
        if(!cin.fail() && tmp2 == 1){
        tmp = "Flight";
        ft.push_back(fId);
        ft.push_back(fId2);
        fId2++;
        break;
        }else if(!cin.fail() && tmp2 == 2){
        tmp = "Train";
        ft.push_back(tId);
        ft.push_back(tId2);
        tId2++;
        break;}else{
            cout<<"Wrong input, Try again\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }}

    ft.push_back(tmp);
    system("cls");
    cout<<"Pls type the start point>> ";
    cin>>tmp;
    ft.push_back(tmp);
    system("cls");
    cout<<"Pls type the destenation>> ";
    cin>>tmp;
    ft.push_back(tmp);
    system("cls");
    cout<<"Pls type the count of seats>> ";
    while(true){
        cin>>tmp2;
        if(cin.fail() || tmp2<0){
            cout<<"Seats should be a positive number\nPls try again\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else{
            break;
        }
    }
    ft.push_back(tmp2);
    system("cls");
    cout<<"Pls type the start time by this format 'hh:mm(pm/am)'>> ";
    cin>>tmp;
    ft.push_back(tmp);
    system("cls");
    cout<<"***Flight/Train added successfully***\nDo you like to do another thing Sir?(y/n)>> ";
    adminagain();

}

void admin(){
    int a = 3;
    system("cls");
    cout<<"Welcome back Sir\n1)Adding a new Fligh/Train\n2)Removing a Flight/Train\n0)Exit\n>> ";
    do{
        cin>>a;
        if(!cin.fail() && a == 1){
            add();
            break;
        }else if(!cin.fail() && a == 2){
            del();
            break;
        }else if(cin.fail()){
            cout<<"Wrong input, Try again\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            a = 3;
        }else if(!cin.fail() && a == 0){
            system("cls");
            cout<<"Have nice time!\n";
            main();
            break;}else{
            cout<<"Invalid input, Try again\n>> ";
        }
    }while(true);
} 

void reserve(){
    int a;
    char ask;
    cout<<"Pls enter the number of Flight/Train\n>> ";
    cin>>a;
    for(int i = 0;i<tmpvec.size();i+=9){
        if(a-1 == i){
                reserved.push_back(tmpvec[i]);
                reserved.push_back(tmpvec[i+1]);
                reserved.push_back(tmpvec[i+2]);
                reserved.push_back(tmpvec[i+3]);
                reserved.push_back(tmpvec[i+4]);
                reserved.push_back(tmpvec[i+5]);
                reserved.push_back(tmpvec[i+6]);
                reserved.push_back(fullname);
                reserved.push_back(user);
                cout<<"Ticket added successfully!";
                break;
        }
    }
    cout<<"Do you want to continue?(y/n)>> ";
    while(true){
        cin>>ask;
        if(!cin.fail() && (ask == 'y' || ask == 'Y')){
            passenger();
            break;
        }else if(!cin.fail() && (ask == 'n' || ask == 'N')){
            system("cls");
            cout<<"Have nice time!\n";
            main();
            break;
        }else if(cin.fail()){
            cout<<"Wrong input, Try again\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Do you want to continue?(y/n)>> ";
        }else{
            cout<<"Invalid input, Try again\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

}}

void search(){
    string a;
    int b;
    int j = 1,pow = 1;
    system("cls");
    cout<<"Pls enter the Flight/Train's ID or destenation\n>> ";
    cin>>a;
    if((a[0] == 'F' && a[1] == '0' && a[2] == '0') || (a[0] == 'F' && a[1] == '0' && a[2] == '0')){
        a = a.substr(3);
        cout<<"List of all Flights/Trains\n";
        for(int i = 0;i<ft.size();i+=7){
            if(a == to_string(get<int>(ft[i+1]))){
                cout<<j<<")ID: "<<get<string>(ft[i])<<get<int>(ft[i+1])<<" ------ Type: "<<get<string>(ft[i+2])<<" ------ From: "
                    <<get<string>(ft[i+3])<<" ------ To: "<<get<string>(ft[i+4])<<" ------ Empty seats: "<<get<int>(ft[i+5])<<" ------ Move at: "<<get<string>(ft[i+6])<<endl;
                tmpvec.push_back(ft[i]);
                tmpvec.push_back(ft[i+1]);
                tmpvec.push_back(ft[i+2]);
                tmpvec.push_back(ft[i+3]);
                tmpvec.push_back(ft[i+4]);
                tmpvec.push_back(ft[i+5]);
                tmpvec.push_back(ft[i+6]);
                j++;
            }
        }
        j = 1;
    }else{
        cout<<"List of all Flights/Trains\n";
        for(int i = 0;i<ft.size();i+=7){
        if(a == get<string>(ft[i+4])){
            cout<<j<<")ID: "<<get<string>(ft[i])<<get<int>(ft[i+1])<<" ------ Type: "<<get<string>(ft[i+2])<<" ------ From: "
                <<get<string>(ft[i+3])<<" ------ To: "<<get<string>(ft[i+4])<<" ------ Empty seats: "<<get<int>(ft[i+5])<<" ------ Move at: "<<get<string>(ft[i+6])<<endl;
                tmpvec.push_back(ft[i]);
                tmpvec.push_back(ft[i+1]);
                tmpvec.push_back(ft[i+2]);
                tmpvec.push_back(ft[i+3]);
                tmpvec.push_back(ft[i+4]);
                tmpvec.push_back(ft[i+5]);
                tmpvec.push_back(ft[i+6]);            
            j++;
            }
        }
        j = 1;
    }
    cout<<"Pls enter the number of these options\n1)Reserving ticket\n2)Search again\n0)Exit\n>> ";
    while(true){
        cin>>b;
        if(!cin.fail() && b == 1){
            reserve();
            break;
        }else if(!cin.fail() && b == 2){
            search();
            tmpvec.clear();
            break;
        }else if(cin.fail()){
            cout<<"Wrong input, Try again\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            a = 4;
        }else if(!cin.fail() && b == 0){
            system("cls");
            tmpvec.clear();
            passenger();
            break;
        }else{
            cout<<"Invalid input, Try again\n>> ";
        }
    }

}

void showres(){
    int j = 1,a;
    system("cls");
    cout<<"List of all Flights/Trains that reserved by '"<<user<<"'";
    for(int i = 0;i<reserved.size();i+=9){
        cout<<"\n"<<j<<")ID: "<<get<string>(reserved[i])<<get<int>(reserved[i+1])<<" ------ Type: "<<get<string>(reserved[i+2])<<" ------ From: "
        <<get<string>(reserved[i+3])<<" ------ To: "<<get<string>(reserved[i+4])<<" ------ Seat number: "<<get<int>(reserved[i+5])
        <<" ------ Move at: "<<get<string>(reserved[i+6])<<" ------ Reserved by: "<<get<string>(reserved[i+7])<<endl;
        j++;}
    j = 1;
    cout<<"Pls enter the number of one option\n1)Cancleing a ticket\n0)Exit\n>> ";
    while(true){
        cin>>a;
        if(!cin.fail() && a == 1){
            add();
            break;
        }else if(cin.fail()){
            cout<<"Wrong input, Try again\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else if(!cin.fail() && a == 0){
            system("cls");
            cout<<"Have nice time!\n";
            main();
            break;
        }else{
            cout<<"Invalid input, Try again\n>> ";
        }
    }
}

void passenger(){
    int a = 4;
    system("cls");
    cout<<"Pls enter the number of one option\n1)Searchig tickets\n2)Cancleing a ticket\n3)See tickets that reserved by '"<<user<<"'\n0)Exit\n>> ";
    while(true){
        cin>>a;
        if(!cin.fail() && a == 1){
            search();
            break;
        }else if(!cin.fail() && a == 2){
            // cancle();
            break;
        }else if(!cin.fail() && a == 3){
            showres();
            break;
        }else if(cin.fail()){
            cout<<"Wrong input, Try again\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            a = 4;
        }else if(!cin.fail() && a == 0){
            system("cls");
            cout<<"Have nice time!\n";
            main();
            break;
        }else{
            cout<<"Invalid input, Try again\n>> ";
        }
    }
}



