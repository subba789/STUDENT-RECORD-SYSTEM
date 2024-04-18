#include<iostream>
#include<vector>
#include<list>
using namespace std;
// Define a Student structure
struct Student {
    int studentID;
    string name;
    vector<string> courses;
    vector<int> marks;
};

// Hash Table with Chaining (Linked Lists)
const int TABLE_SIZE = 100;
list<Student> hashTable[TABLE_SIZE];
// Hash Function
int Hash(int studentID) {
    return studentID % TABLE_SIZE;
}
// Function to add a new student
void addStudent() {
    Student newStudent;
    cout << "Enter student ID: ";
    cin >> newStudent.studentID;
    cin.ignore();
    cout << "Enter student name: ";
    getline(cin,newStudent.name);

    // Add courses and marks
    while (true) {
        string course;
        int mark;
        cout << "Enter course (or type 'done' to finish): ";
        cin.ignore();
        getline(cin,course);
        if (course == "done") {
            break;
        }
        newStudent.courses.push_back(course);
        cout << "Enter mark for " << course << ": ";
        cin >> mark;
        newStudent.marks.push_back(mark);
    }

    int index = Hash(newStudent.studentID);
    hashTable[index].push_back(newStudent);
    cout << "Student added successfully." << endl;
}
// Function to retrieve a student by ID
Student* getStudent(int studentID) {
    int index = Hash(studentID);
    for (auto& student : hashTable[index]) {
        if (student.studentID == studentID) {
            return &student;
        }
    }
    return nullptr; // Student not found
}



// Function to update student information
void updateStudent(int studentID) {
    Student* student = getStudent(studentID);
    if (student) {
        cout << "Enter new student name: ";
        cin.ignore();
        getline(cin,student->name);

        // Update courses and marks
        student->courses.clear();
        student->marks.clear();

        while (true) {
            string course;
            int mark;
            cout << "Enter course (or type 'done' to finish): ";
            cin.ignore();
            getline(cin,course);
            if (course == "done") {
                break;
            }
            student->courses.push_back(course);
            cout << "Enter mark for " << course << ": ";
            cin >> mark;
            student->marks.push_back(mark);
        }

        cout << "Student information updated successfully." << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

// Function to delete a student by ID
void deleteStudent(int studentID) {
    int index = Hash(studentID);
    for (auto it = hashTable[index].begin(); it != hashTable[index].end(); ++it) {
        if (it->studentID == studentID) {
            hashTable[index].erase(it);
            cout << "Student deleted successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

// Function to display student information
void displayStudentInfo(const Student& student) {
    cout << "Student ID: " << student.studentID << endl;
    cout << "Name: " << student.name << endl;
    cout << "Courses and Marks:" << endl;
    for (size_t i = 0; i < student.courses.size(); i++) {
        cout << student.courses[i] << ": " << student.marks[i] << endl;
    }
}
int main(){
    while (true) {
        cout << "Student Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Retrieve Student" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 5) {
            cout<<"Exit";
            break;
        }

        switch (choice) {
    case 1:
        addStudent();
        break;

    case 2: {
        int searchID;
        cout << "Enter student ID to retrieve: ";
        cin >> searchID;
        Student* retrievedStudent = getStudent(searchID);
        if (retrievedStudent) {
            displayStudentInfo(*retrievedStudent);
        } else {
            cout << "Student not found." << endl;
        }
        break;
    }
    case 3: {
        int updateID;
        cout << "Enter student ID to update: ";
        cin >> updateID;
        updateStudent(updateID);
        break;
    }
    case 4: {
        int deleteID;
        cout << "Enter student ID to delete: ";
        cin >> deleteID;
        deleteStudent(deleteID);
        break;
    }

    default:
        cout << "Invalid choice. Please try again." << endl;
}

    }

    return 0;
}