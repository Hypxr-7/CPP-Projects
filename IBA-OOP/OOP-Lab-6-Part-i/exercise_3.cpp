#include <iostream>
#include <string>

using std::cout, std::cin, std::endl, std::string;

class MyException{};

class Dummy {
public:
    string MyName;
    int level;

    void PrintMsg(string s) {
        cout << s << MyName << endl;
    }

    Dummy(string s) : MyName(s) {
        PrintMsg("Created Dummy:");
    }

    Dummy(const Dummy& other) : MyName(other.MyName) {
        PrintMsg("Copy created Dummy:");
    }

    ~Dummy() {
        PrintMsg("Destroyed Dummy:");
    }
};

void C(Dummy d, int i) {
    cout << "Entering FunctionC" << endl;
    d.MyName = " C";
    throw MyException();
    cout << "Exiting FunctionC" << endl;
}

void B(Dummy d, int i) {
    cout << "Entering FunctionB" << endl;
    d.MyName = " B";
    C(d, i + 1);
    cout << "Exiting FunctionB" << endl;
}

void A(Dummy d, int i) {
    cout << "Entering FunctionA" << endl;
    d.MyName = " A" ;
    // Dummy* pd = new Dummy("new Dummy"); //Not exception safe!!!
    B(d, i + 1);
    // delete pd;
    cout << "Exiting FunctionA" << endl;
}

int main() {
    cout << "Entering main" << endl;
    try {
        Dummy d(" M");
        A(d,1);
    }
    catch (MyException& e) {
        cout << "Caught an exception of type: " << typeid(e).name() << endl;
    }
    cout << "Exiting main." << endl;
    char c;
    cin >> c;
}