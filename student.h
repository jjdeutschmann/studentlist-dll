//****************************************************************************************************
//
//     File: student.h
//
//     Author: Jennifer Deutschmann
//
//     The definition for the structure Student.
//			 
//****************************************************************************************************

#ifndef STUDENT_H
#define STUDEHT_H

//****************************************************************************************************

#include <iostream>

using namespace std;

//****************************************************************************************************

struct Student
{
	int id;
	char name[50];
	char citystate[50];
	int phone;
	char gender;
	int year;
	int credits;
	float gpa;
	char major[6];

	friend ostream & operator << ( ostream & out, const Student & data );

	bool operator == ( const Student & rhs ) const;
	bool operator != ( const Student & rhs ) const;
	bool operator < ( const Student & rhs ) const;
	bool operator > ( const Student & rhs ) const;
	bool operator <= ( const Student & rhs ) const;
	bool operator >= ( const Student & rhs ) const;

};

//****************************************************************************************************

ostream & operator << ( ostream & out, const Student & data )
{
	return out << data.id << "\t" << data.name << endl;
}

//****************************************************************************************************

bool Student :: operator == ( const Student & rhs ) const
{
	return ( this -> id == rhs.id );
}

//****************************************************************************************************

bool Student :: operator != ( const Student & rhs ) const
{
	return ( this -> id != rhs.id );
}

//****************************************************************************************************

bool Student :: operator < ( const Student & rhs ) const
{
	return ( this -> id < rhs.id );
}

//****************************************************************************************************

bool Student :: operator > ( const Student & rhs ) const
{
	return ( this -> id > rhs.id );
}

//****************************************************************************************************

bool Student :: operator <= ( const Student & rhs ) const
{
	return ( this -> id <= rhs.id );
}

//****************************************************************************************************

bool Student :: operator >= ( const Student & rhs ) const
{
	return ( this -> id >= rhs.id );
}

//****************************************************************************************************

#endif

//****************************************************************************************************