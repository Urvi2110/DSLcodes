#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int roll;
    string name, division, address;

    void getData() {
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Address: ";
        cin >> address;
    }

    void display() {
        cout << "\nRoll: " << roll << "\nName: " << name
             << "\nDivision: " << division << "\nAddress: " << address << endl;
    }
};
void addStudent() {
    Student s;
    ofstream out("student.txt", ios::app);
    s.getData();
    out << s.roll << " " << s.name << " " << s.division << " " << s.address << "\n";
    out.close();
    cout << "Record added.\n";
}
void searchStudent() {
    int roll, found = 0;
    Student s;
    ifstream in("student.txt");
    cout << "Enter roll number to search: ";
    cin >> roll;
    while (in >> s.roll >> s.name >> s.division >> s.address) {
        if (s.roll == roll) {
            s.display();
            found = 1;
            break;
        }
    }
    if (!found)
        cout << "Record not found.\n";
    in.close();
}
void deleteStudent() {
    int roll;
    Student s;
    ifstream in("student.txt");
    ofstream out("temp.txt");
    cout << "Enter roll number to delete: ";
    cin >> roll;
    bool found = false;

    while (in >> s.roll >> s.name >> s.division >> s.address) {
        if (s.roll == roll) {
            found = true;
            continue; 
        }
        out << s.roll << " " << s.name << " " << s.division << " " << s.address << "\n";
    }
    in.close();
    out.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        cout << "Record deleted.\n";
    else
        cout << "Record not found.\n";
}
int main() {
    int ch;
    do {
        cout << "\n--- Student Information System ---\n";
        cout << "\n1. Add Student";
        cout<<"\n2. Search Student";
        cout<<"\n3. Delete Student";
        cout<<"\n4. Exit";
        cout<<"\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: 
             addStudent(); 
             break;
            case 2: 
             searchStudent(); 
             break;
            case 3: 
             deleteStudent(); 
             break;
            case 4: 
             cout << "Exiting...\n"; 
             break;
            default: 
             cout << "Invalid choice!\n";
        }
    } while (ch != 4);
    return 0;
}
