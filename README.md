# STUDENT-RECORD-SYSTEM
Developed a C++ Student Management System utilizing hash tables for efficient data storage, enabling seamless addition, retrieval, updating, and deletion of studentrecords using file management system.

The Student Management System is designed to manage student information efficiently, including adding, retrieving, updating, and deleting student records. It utilizes a hash table with chaining (linked lists) to store student records.

Components:

1. Student Structure:
   - The `Student` structure represents a student and contains:
     - `studentID`: An integer representing the unique identifier for the student.
     - `name`: A string representing the name of the student.
     - `courses`: A vector of strings representing the courses taken by the student.
     - `marks`: A vector of integers representing the corresponding marks obtained by the student in each course.

2. Hash Table:
   - The hash table is used to store student records, with each bucket containing a linked list of students with the same hash value (collision resolution using chaining).
   - The size of the hash table is defined as `TABLE_SIZE`.

3. Functions:
   - `Hash(int studentID)`: A hash function that calculates the hash value for a given student ID.
   - `addStudent()`: Function to add a new student record to the system, including their ID, name, courses, and marks.
   - `getStudent(int studentID)`: Function to retrieve a student record by their ID.
   - `updateStudent(int studentID)`: Function to update the information of an existing student, including their name, courses, and marks.
   - `deleteStudent(int studentID)`: Function to delete a student record by their ID.
   - `displayStudentInfo(const Student& student)`: Function to display the information of a student, including their ID, name, courses, and marks.

4. Main Function:
   - The main function provides a menu-driven interface for users to interact with the Student Management System.
   - Users can choose from options to add, retrieve, update, or delete student records.
   - The program continues running until the user chooses to exit.

Features:
- Add Student: Users can add new student records by providing their ID, name, courses, and corresponding marks.
- Retrieve Student: Users can retrieve student records by providing their ID.
- Update Student: Users can update the information of existing student records, including their name, courses, and marks.
- Delete Student: Users can delete student records by providing their ID.
- Collision Resolution: Collision resolution is implemented using chaining, ensuring efficient storage and retrieval of student records.
- Menu-Driven Interface: The program provides a user-friendly menu interface for easy navigation and interaction.
