#include <iostream>
#include <fstream>

using namespace std;

class student {
    int roll_no;
    char Name[30];
    char Division[5];
    char Address[50];

public:
    // Function to accept student details
    void accept() {
        cout << "\nEnter Roll Number: ";
        cin >> roll_no;
        cout << "\nEnter Name: ";
        cin.ignore();
        cin.getline(Name, 30);
        cout << "\nEnter Division: ";
        cin >> Division;
        cout << "\nEnter Address: ";
        cin >> Address;
        cout << "\n";
    }

    // Function to display student details
    void display() {
        cout << "\n " << roll_no << "\t " << Name << " \t\t " << Division << "\t " << Address;
    }

    // Function to get the roll number
    int rollno() {
        return roll_no;
    }
};

// Function to create a student database
void create() {
    student s;
    int n, i;
    ofstream out("Student.txt");

    cout << "\nHow many records do you want to enter?: ";
    cin >> n;

    // Accept and write student records to file
    for (i = 0; i < n; i++) {
        s.accept();
        out.write((char *)&s, sizeof(s));
    }

    out.close();
}

// Function to search for a student record by roll number
void search() {
    int n, flag = 0;

    cout << "\nEnter Roll Number To Be Searched: ";
    cin >> n;

    ifstream infile("Student.txt");
    student s;

    // Search for the record in the file
    while (infile.read((char *)&s, sizeof(s))) {
        if (s.rollno() == n) {
            cout << "\nRecord Found\n";
            cout << "\nRoll Number Name Division Address";
            s.display();
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        cout << "\nRecord Not Found.";
    }

    infile.close();
}

// Function to display all student records
void display() {
    student s;
    ifstream infile("Student.txt");

    // Display all records in the file
    while (infile.read((char *)&s, sizeof(s))) {
        s.display();
    }

    infile.close();
}

// Function to add a new record to the database
void add_record() {
    student s;
    ofstream outfile("Student.txt", ios::app);

    // Accept and append a new student record to the file
    s.accept();
    outfile.write((char *)&s, sizeof(s));
    outfile.close();

    cout << "Record Successfully Added.";
}

// Function to delete a student record by roll number
void delete_record() {
    int n, flag = 0;

    cout << "\nEnter Roll Number Whose Record To Be Deleted:";
    cin >> n;

    ifstream infile("student.txt"); // to read from source file
    ofstream temp("temp.txt");      // to write in the destination file (temporary file)
    student s;

    // Copy records to the temporary file, excluding the record to be deleted
    while (infile.read((char *)&s, sizeof(s))) {
        if (s.rollno() != n) {
            temp.write((char *)&s, sizeof(s));
        } else {
            flag = 1;
            cout << "\nRecord Successfully Deleted.";
        }
    }

    if (flag == 0) {
        cout << "\nRecord Not Found.";
    }

    infile.close();
    temp.close();

    // Remove the original file and rename the temporary file
    remove("Student.txt");
    rename("temp.txt", "Student.txt");
}

int main() {
    int choice;

    // Create an empty file named "Student.txt"
    ofstream out("Student.txt");
    out.close();

    do {
        cout << "\nMenu:\n1) Create Database.\n2) Display.\n3) Add record.\n4) Search Record.\n5) Delete Record.\n6) Exit.";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n";
                create();
                break;
            case 2:
                cout << "\n";
                cout << "\nRoll Number Name Division Address";
                display();
                break;
            case 3:
                cout << "\n";
                add_record();
                break;
            case 4:
                cout << "\n";
                search();
                break;
            case 5:
                cout << "\n";
                delete_record();
                break;
            case 6:
                cout << "\n";
                cout << "You Have Successfully Exited...";
                break;
        }
    } while (choice != 6);

    return 0;
}