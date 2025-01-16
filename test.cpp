#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
//base valuses
vector <int> a;

int main(){
    a.push_back(10);
    a.push_back(11);
    a.push_back(12);
    a.push_back(13);
    a.push_back(14);
    a.push_back(15);
    a.push_back(16);
    a.push_back(17);
    a.erase(a.begin()+2,a.begin()+5);
    for(int i = 0;i<a.size();i++){
        cout<<a[i]<<endl;
    }


    return 0;
}