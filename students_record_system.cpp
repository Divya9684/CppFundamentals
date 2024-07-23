#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Student {
private:
    string id;
    string name;
    int marks[5];
    float average;
    char grade;

public:
    Student() {
        for (int i = 0; i < 5; i++) {
            marks[i] = 0;
        }
        average = 0.0;
        grade = 'F';
    }

    void setId(const string& id) { this->id = id; }
    void setName(const string& name) { this->name = name; }
    void setMarks(const int* marks) {
        for (int i = 0; i < 5; i++) {
            this->marks[i] = marks[i];
        }
    }

    string getId() const { return id; }
    string getName() const { return name; }
    float getAverage() const { return average; }
    char getGrade() const { return grade; }

    void calculateGrade() {
        average = 0;
        for (int i = 0; i < 5; i++) {
            average += marks[i];
        }
        average /= 5;

        if (average >= 90) grade = 'A';
        else if (average >= 80) grade = 'B';
        else if (average >= 70) grade = 'C';
        else if (average >= 60) grade = 'D';
        else grade = 'F';
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Average: " << average << ", Grade: " << grade << endl;
    }

    void saveToFile(ofstream& file) const {
        file << id << "," << name;
        for (int i = 0; i < 5; i++) {
            file << "," << marks[i];
        }
        file << endl;
    }

    void loadFromFile(const string& line) {
        stringstream ss(line);
        string temp;
        getline(ss, id, ',');
        getline(ss, name, ',');
        for (int i = 0; i < 5; i++) {
            getline(ss, temp, ',');
            marks[i] = stoi(temp);
        }
        calculateGrade();
    }
};

class StudentRecordSystem {
private:
    vector<Student> students;
    const string filename = "students.txt";

    void loadFromFile() {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Unable to open file for reading." << endl;
            return;
        }
        string line;
        while (getline(file, line)) {
            Student student;
            student.loadFromFile(line);
            students.push_back(student);
        }
        file.close();
    }

    void saveToFile() const {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Unable to open file for writing." << endl;
            return;
        }
        for (const auto& student : students) {
            student.saveToFile(file);
        }
        file.close();
    }

public:
    StudentRecordSystem() {
        loadFromFile();
    }

    ~StudentRecordSystem() {
        saveToFile();
    }

    void addStudent() {
        Student student;
        string id, name;
        int marks[5];

        cout << "Enter Student ID: ";
        cin >> id;
        student.setId(id);

        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
        student.setName(name);

        cout << "Enter marks for 5 subjects: ";
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
        }
        student.setMarks(marks);
        student.calculateGrade();

        students.push_back(student);
        cout << "Student added successfully." << endl;
    }

    void updateStudent() {
        string id;
        cout << "Enter Student ID to update: ";
        cin >> id;

        for (auto& student : students) {
            if (student.getId() == id) {
                string name;
                int marks[5];

                cout << "Enter new Student Name: ";
                cin.ignore();
                getline(cin, name);
                student.setName(name);

                cout << "Enter new marks for 5 subjects: ";
                for (int i = 0; i < 5; i++) {
                    cin >> marks[i];
                }
                student.setMarks(marks);
                student.calculateGrade();

                cout << "Student updated successfully." << endl;
                return;
            }
        }
        cout << "Student ID not found." << endl;
    }

    void deleteStudent() {
        string id;
        cout << "Enter Student ID to delete: ";
        cin >> id;

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getId() == id) {
                students.erase(it);
                cout << "Student deleted successfully." << endl;
                return;
            }
        }
        cout << "Student ID not found." << endl;
    }

    void viewStudent() const {
        string id;
        cout << "Enter Student ID to view: ";
        cin >> id;

        for (const auto& student : students) {
            if (student.getId() == id) {
                student.display();
                return;
            }
        }
        cout << "Student ID not found." << endl;
    }

    void generateReport() const {
        cout << "Student Report:" << endl;
        for (const auto& student : students) {
            student.display();
        }
    }
};

int main() {
    StudentRecordSystem srs;
    int choice;

    while (true) {
        cout << "\nStudent Record System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Update Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. View Student" << endl;
        cout << "5. Generate Report" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                srs.addStudent();
                break;
            case 2:
                srs.updateStudent();
                break;
            case 3:
                srs.deleteStudent();
                break;
            case 4:
                srs.viewStudent();
                break;
            case 5:
                srs.generateReport();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}
