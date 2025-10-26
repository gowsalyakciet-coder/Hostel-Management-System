
# Hostel Management System

Description:
This C program manages hostel student allotments using a singly linked list. It allows adding and removing students, searching by name or room, displaying all allotments, displaying by block, reverse displaying, counting students by block, and cloning the list. Each record contains Student ID, Name, Room Number, and Block.

Features:
1. Add Allotment – Add a student with ID, Name, Room Number, and Block.
2. Remove Student – Remove a student record by Student ID.
3. Search by Name – Find a student using their name.
4. Search by Room – Find a student assigned to a specific room.
5. Display All – Show all student allotments.
6. Display by Block – View all students in a specific block.
7. Reverse Display – Display all students from last to first using recursion.
8. Count by Block – Count the number of students in a specific block.
9. Clone List – Create a temporary clone of the current list.
10. Exit – Close the program.

How it Works:
- Uses a struct Hostel with fields: Student ID, Name, Room Number, Block, and pointer to the next node.
- Linked list dynamically stores student allotment records.
- New allotments are added to the head of the list.
- Menu-driven interface allows easy operation.
- Recursive function is used for reverse display.

Compilation and Execution:
gcc studentsrecord_hostel.c -o studentsrecord_hostel
./studentsrecord_hostel

Sample Input/Output:
Choice: 1
Enter Student ID: 101
Enter Student Name: Alice
Enter Room Number: 201
Enter Block: A
Allotment added successfully!

Choice: 5
All Allotments:
101 | Alice | 201 | A
