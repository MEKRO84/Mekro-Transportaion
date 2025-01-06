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
string user,fullname;
string fId = "F00",tId = "T10";
int fId2 = 10000, tId2 = 10000;


void admin();
void adminagain(){
    char ask;
    cin>>ask;
    if(!cin.fail() && (ask == 'y' || ask == 'Y')){
        admin();
    }else if(!cin.fail() && (ask == 'n' || ask == 'N')){
        system("cls");
        cout<<"Have nice time!";
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
        }else if(a == 0){
            system("cls");
            cout<<"Have nice time!";
            break;}else{
            cout<<"Invalid input, Try again\n>> ";
        }
    }while(true);
} 

int main(){
    bool accept = false;
    cout<<"Welcome to transportion app!\nPls enter your username\n>> ";
    while(true){
    cin>>user;
    if(!cin.fail() && user == "admin"){
        admin();
        break;
    }else if(!cin.fail() && !(int(user[0])>31 && int(user[0])<65) && !(int(user[0])>90 && int(user[0])<97) && !(int(user[0])>122 && int(user[0])<127)){
        system("cls");
        cout<<"Pls enter your name\n>> ";
        while(true){
            cin>>fullname;
            if(!cin.fail() && !(int(fullname[0])>31 && int(fullname[0])<65) && !(int(fullname[0])>90 && int(fullname[0])<97) && !(int(fullname[0])>122 && int(fullname[0])<127)){
                accept = true;
                break;}
            else{
                        system("cls");
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout<<"Pls enter a valid name that is not start with character or a number\n>> ";
                }}
        break;
    }else{
        system("cls");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Pls enter a valid username that is not start with character or a number\n>> ";}
    }


    return 0;
}



