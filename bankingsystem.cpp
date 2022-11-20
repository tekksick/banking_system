#include<iostream>
using namespace std;

class user {
    public:
    string ID;
    string PWD;
    string Name;
    double balance=0;
};

user accs[3000];
int noofusers=0;  

void line() {
     cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;

}
void start ();

void action (user *x) {
    int k;
    double amt;
    line();
    cout << "Hello " <<x->Name << "!" <<endl;
    cout << "Press the corresponding serial number\n";
    cout << "1. Deposit\n" << "2. Withdrawl\n" << "3. Check balance\n" << "4. Transfer" <<endl ;
    cin >> k;
    if (k==1) {      //deposit
        cout << "Enter amount :";
        cin >> amt;
        x->balance+=amt;
        cout << "Successfully deposited " << amt << endl << "Currently your balance is " << x->balance << endl;
        start();
    }
    if (k==2) {      //withdrawl
        cout << "Enter amount :";
        cin >> amt;
        if(x->balance>=amt) {
            x->balance-=amt;
            cout << "Successfully withdrawn " << amt << endl;
            start();
        }
        else {
            cout << "Insufficient balance" << endl;
            start();
        }
    }
    if (k==3) {      //check balance
        cout << "Your account currently has " << x->balance <<endl;
        start();
    }
    if (k==4) {       //transfer
        cout << "Enter the user ID :";
        string id;
        int found=0;
        cin >> id;
        for (auto u : accs) {
            if(u.ID==id) {
                found=1;
                cout << "Enter the amount :";
                cin >> amt;
                x->balance-=amt;
                u.ID+=amt;
                cout <<amt << " has been successfully transfered to " << u.ID <<" ; " << u.Name <<endl ;
                start();
            }
            else {
                continue;
            }
        }
        if (found==0) {
            cout << "User ID does not exist" << endl;
            start();
        }
    }
}

void signup () {
    line();
    cout << "Enter user ID :";
    string id;
    cin >> id;
    int found=0;
    for (auto i : accs) {
        if (i.ID==id) {
            found=1;
            cout << "This user name is already taken" << endl;
            start ();
        } 
        else {
            continue;
        }
    }
    if (found==0) {
        noofusers++;
        accs[noofusers].ID = id;
        cout << "Enter your name :";
        string name, pwd;
        cin >> name;
        accs[noofusers].Name = name;
        cout << "Set a password :";
        cin >> pwd;
        accs[noofusers].PWD = pwd;
        start();
    }
}

void login () {
    string id, pwd;
    int found=0,k=1;
    line();
    cout << "Enter your ID :";
    cin >> id;
    while (k <= noofusers) {
        if(id==accs[k].ID) {
            found=1;
            cout << "Enter your password :";
            cin >> pwd;
            if(pwd==accs[k].PWD) {
                cout <<accs[k].Name << ", your login is successful" <<endl;
                action (&accs[k]);
            }
            else {
                cout << "Your password is incorrect" << endl;
                start ();
            }
        }
        else {
            k++;
            continue;
        }
    }
    if (found==0) {
        cout << "User ID does not exist" <<endl;
        start ();
    }
}

void start () {
    int k;
    line();
    line();
    cout << "Press 1 for login" << endl << "Press 2 for signup" << endl << "Press 3 to exit" << endl;
    cin >> k;
    if (k==1) {login (); }
    if (k==2) {signup (); }
    if (k==3) {
        return;
    }
}

int main () {
    start ();
    return 0;
}