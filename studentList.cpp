//****************************************************************************************************
//
//     File: studentList.cpp
//
//     Author: Jennifer Deutschmann
//
//     This program stores Students in a doubly linked list and uses a menu to do different
//	   operations to the student list.	 
//
//     Other files needed:
//	   1. student.h
//	   2. node.h
//	   3. DLList.h
//
//****************************************************************************************************

#include <iostream>
#include <fstream>

using namespace std;

#include "student.h"
#include "DLList.h"

//****************************************************************************************************

char getChoice ();
void process ( DLList<Student> & studentList );
void displayStudents ( DLList<Student> & studentList );
void displayStudentsRev ( DLList<Student> & studentList );

void countStudents ( DLList<Student> & studentList );
void addNewStudent ( DLList<Student> & studentList );
void removeStudent ( DLList<Student> & studentList );
void findStudent ( DLList<Student> & studentList );

//****************************************************************************************************

int main ()
{
	DLList<Student> studentList;

	process ( studentList );

	return 0;
}

//****************************************************************************************************

char getChoice ()
{
	char choice;
	bool valid;

	cout << "======== MENU ========\n"
		<< " A:    Add a new Student \n"
		<< " F:    Find a Student Record \n"
		<< " R:    Remove a Student \n"
		<< " C:    Count students \n"
		<< " D:    Display all Students \n"
		<< " V:    Display all Students in reverse order \n"
		<< " Q:    Quit \n\n";

	do
	{
		cin >> choice;
		choice = toupper (choice);

		switch ( choice )
		{
			case 'A': 
			case 'F':
			case 'R':
			case 'C':
			case 'D':
			case 'V':
			case 'Q':	valid = true;
						break;
			default:	valid = false;
						cout << "\aInvalid choice\n"
							<< "Please try again: ";
						break;
		}
	}
	while ( !valid );

	return choice;
}

//****************************************************************************************************

void process ( DLList<Student> & studentList )
{
	char choice;

	do
	{
		choice = getChoice();

		switch ( choice )
		{
			case 'A': 	addNewStudent (studentList);
						break;
			case 'F': 	findStudent (studentList);
						break;
			case 'R': 	removeStudent (studentList);
						break;
			case 'C':   countStudents(studentList);
						break;
			case 'D': 	displayStudents (studentList);
						break;
			case 'V':   displayStudentsRev (studentList);
						break;
			case 'Q': 	break;
		}
	}
	while (choice != 'Q');
}

//****************************************************************************************************

void displayStudents ( DLList<Student> & studentList )
{
	if ( studentList.isEmpty() )
		cout << "No student information has been entered." << endl;
	else
	{
		cout << "--- Student List ---\n";
		studentList.display();
	}
}

//****************************************************************************************************

void displayStudentsRev ( DLList<Student> & studentList )
{
	if ( studentList.isEmpty() )
		cout << "No student information has been entered." << endl;
	else
	{
		cout << "--- Student List Reversed ---\n";
		studentList.displayReverse();
	}		
}

//****************************************************************************************************

void countStudents ( DLList<Student> & studentList )
{
	cout << "There are " << studentList.getSize() << " students in the list.\n\n";
}

//****************************************************************************************************

void addNewStudent ( DLList<Student> & studentList )
{
	Student newStudent;

	cin.ignore();
	cout << "Enter valid information for a new Student.\nEnter ID: ";
	cin >> newStudent.id;
	cin.ignore();

	cout << "Enter the name: ";
	cin.getline(newStudent.name, 80);

	cout << "Enter the city and state: ";
	cin.getline(newStudent.citystate, 80);

	cout << "Enter the phone number (formatted as 1234567890): ";
	cin >> newStudent.phone;

	cout << "Enter the gender (formatted as M or F): ";
	cin >> newStudent.gender;

	cout << "Enter the year: ";
	cin >> newStudent.year;

	cout << "Enter the credits: ";
	cin >> newStudent.credits;

	cout << "Enter the GPA: ";
	cin >> newStudent.gpa;
	cin.ignore();

	cout << "Enter the major: ";
	cin.getline(newStudent.major, 80);

	studentList.insert ( newStudent );
	cout << "Student Added.\n"
		<< "--- Student's Info ---\n" << newStudent << endl;

}

//****************************************************************************************************

void removeStudent ( DLList<Student> & studentList )
{
	if ( studentList.isEmpty() )
		cout << "No student information has been entered." << endl;
	else
	{
		Student delStudent;
	
		cout << "Enter the ID of the student you want to remove: ";
		cin >> delStudent.id;

		if ( studentList.remove(delStudent) )
		{
			cout << "Student Removed.\n"
				<< "--- Student's Info ---\n" << delStudent << endl;
		}
		else
			cout << "No Student with that ID was found.\n\n";
	}
}

//****************************************************************************************************

void findStudent ( DLList<Student> & studentList )
{
	if ( studentList.isEmpty() )
		cout << "No student information has been entered." << endl;
	else
	{
		Student searchStudent;

		cout << "Enter the ID of the Student you want to find: ";
		cin >> searchStudent.id;

		if ( studentList.retrieve(searchStudent) )
		{
			cout << "Student Found.\n"
				<< "--- Student's Info ---\n" << searchStudent << endl;
		}
		else
			cout << "No student with that ID was found.\n\n";
	}
}

//****************************************************************************************************