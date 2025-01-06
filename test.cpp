#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
//base valuses

vector<int> ft;
vector<string> users;
vector<int> cancled;


int login(string username){}

void reg(){
    string tmp,username;
    system("cls");
    cout<<"Pls enter your username"<<endl;
    cin>>username;
    users.push_back(username);
    cout<<"Pls enter your ID number"<<endl;
    cin>>tmp;
    users.push_back(tmp);
    cout<<"Pls enter your password"<<endl;
    cin>>tmp;
    users.push_back(tmp);
    cout<<"User '"<<username<<"' ";
    login(username);
}


int login(string username){
    string password = "  ";
    char b;
    int a = 0;
    for(int i = 0;i<users.size();i+=3){
        if(username == users[i]){
            cout<<"Enter password:"<<endl;
            cin>>password;
            if(password == users[i+2]){
                system("cls");
                cout<<"Login seccessful!\n";
                a = 1;
                break;
            }else{
                cout<<"Password incorrect!";
                a = 2;
                break;  
            }
        }
        if(a == 0){
            do{
            system("cls");
            cout<<"Username '"<<username<<"' not found!\nDo you want to add this username?(y/n):\n";
            cin>>b;
            if( b == 'y' || b == 'Y'){
                reg();
            }}while((b != 'n' || b != 'N') && (b != 'y' || b != 'Y'));}
        
    }
    return a;
}








int main(){
    users.push_back("admin");
    users.push_back("admin");
    users.push_back("admin");
    string username;
    int logaccept = 0,prelog = 0;
    char a;
    cout<<"Welcome to transportion app!\nPls enter your username:\n";
    cin>>username;
    prelog = login(username);
    if(prelog == 1){
    logaccept = 1;
    system("cls");
    cout<<"Login seccessful!\n";
    }else if(prelog == 2){
        cout<<"Username '"<<username<<"' not found!\nDo you want to add this username?(y/n):\n";
        cin>>a;
        if( a == 'y' || a == 'Y'){
            reg();
        }
    }
    
    


    return 0;
}