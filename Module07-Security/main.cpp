#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Record {
    int id;
    string name;
};

int binarySearch(vector<Record>& r, int id) {
    int l=0, h=r.size()-1;
    while(l<=h) {
        int m=(l+h)/2;
        if(r[m].id==id) return m;
        if(r[m].id<id) l=m+1;
          
        else h=m-1;
    }
    return -1;
}
class User {
protected:
    string username;
public:
    User(string n) { username=n; }
    virtual void menu()=0;
};

class Admin: public User {
public:
    Admin(string n):User(n) {}
    void menu() override {
        cout<<"Admin: "<<username<<endl;
        cout<<"Can add, delete and search records."<<endl;
    }
    void add(vector<Record>& r,int id,string n) {
        if(binarySearch(r,id)!=-1) {
            cout<<"ID already exists"<<endl;
            return;
        }
        r.push_back({id,n});
        sort(r.begin(),r.end(),[](Record a,Record b){return a.id<b.id;});
        cout<<"Record added"<<endl;
    }
    void remove(vector<Record>& r,int id) {
        int i=binarySearch(r,id);
      
        if(i==-1) cout<<"Record not found"<<endl;
        else {
            r.erase(r.begin()+i);
            cout<<"Record deleted"<<endl;
        }
    }
};

class RegularUser: public User {
public:
    RegularUser(string n):User(n) {}
    void menu() override {
        cout<<"User: "<<username<<endl;
        cout<<"Can only search records."<<endl;
    }
};

void search(vector<Record>& r,int id) {
    int i=binarySearch(r,id);

  
    if(i==-1) cout<<"Record not found"<<endl;
    else cout<<r[i].id<<" "<<r[i].name<<endl;
}

int main() {
    vector<Record> records={{105,"Alex"},{101,"Emma"},{103,"Ryan"}};
  
    sort(records.begin(),records.end(),[](Record a,Record b){return a.id<b.id;});

    Admin a("Morgan");
    RegularUser u("Taylor");

    a.menu();
    a.add(records,102,"Jordan");
    a.remove(records,105);


  
    cout<<endl;
    u.menu();
    search(records,103);
    return 0;
}
