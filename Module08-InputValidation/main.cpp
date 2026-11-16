#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct Record {
    int id;
    string name;
};

// Validate positive integer input
int getPositiveNumber() {
    int n;

    while (!(cin >> n) || n <= 0) {
        cout << "Invalid input. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return n;
}

// Validate non-empty names
string getName() {
    string n;

    while (true) {
        getline(cin, n);

        if (n.find_first_not_of(" \t") != string::npos)
            return n;

        cout << "Invalid name. Try again: ";
    }
}

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

        auto pos = lower_bound(r.begin(),r.end(),id,
            [](Record a,int id){return a.id<id;});

        r.insert(pos,{id,n});

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

    cout<<"Enter ID to add: ";
    int id=getPositiveNumber();

    cout<<"Enter name: ";
    string name=getName();

    a.add(records,id,name);

    cout<<"Enter ID to delete: ";
    a.remove(records,getPositiveNumber());

    cout<<endl;
    u.menu();

    cout<<"Enter ID to search: ";
    search(records,getPositiveNumber());

    return 0;
}
