//****************************************************************************************************
//
//     File: DLL.h
//
//     Author: Jennifer Deutschmann
//
//     The definition for the class DDL (doubly linked list).
//
//	   Other files needed:
//	   1. node.h	 
//		
//****************************************************************************************************

#ifndef DLLIST_H
#define DLLIST_H

//****************************************************************************************************

#include <iostream>

#include "node.h"

//****************************************************************************************************

template <typename TYPE>
class DLList
{
	private:
		Node<TYPE> * front;
		Node<TYPE> * rear;
	public:
		DLList ();
		~DLList ();
		bool insert ( const TYPE & dataIn );
		bool remove ( TYPE & dataOut );
		bool retrieve ( TYPE & dataOut ) const;
		void display () const;
		void displayReverse () const;
		int getSize () const;
		bool isEmpty () const;
		bool isFull () const;
};

//****************************************************************************************************

template <typename TYPE>
DLList<TYPE> :: DLList ()
{
	front = NULL;
	rear = NULL;
}

//****************************************************************************************************

template <typename TYPE>
DLList<TYPE> :: ~DLList()
{
	Node<TYPE> * pTemp;

	while ( front )
	{
		pTemp = front -> next;
		delete front;
		front = pTemp;
	}

	rear = NULL;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> :: insert ( const TYPE & dataIn )
{
	bool success = false;
	Node<TYPE> * pBefore = NULL;
	Node<TYPE> * pAfter = front;
	Node<TYPE> * pNew;

	while ( ( pAfter ) && ( ( pAfter -> data) < dataIn ) )
		pAfter = pAfter -> next;

	pBefore = ( pAfter ? pAfter -> prev : rear );

	pNew = new (nothrow) Node<TYPE> ( dataIn, pAfter, pBefore );

	if ( pNew )
	{
		if ( pBefore )
			pBefore -> next = pNew;
		else
			front = pNew;

		if ( pAfter )
			pAfter -> prev = pNew;
		else
			rear = pNew;

		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> :: remove ( TYPE & dataOut )
{
	bool success = false;
	Node<TYPE> * pDel = front;

	while ( ( pDel ) && ( pDel -> data < dataOut ) )
		pDel = pDel -> next;

	if ( ( pDel ) && ( pDel -> data == dataOut) )
	{
		dataOut = pDel -> data;

		if ( pDel -> prev )
			pDel -> prev -> next = pDel -> next;
		else
			front = pDel -> next;

		if ( pDel -> next )
			pDel -> next -> prev = pDel -> prev;
		else
			rear = pDel -> prev;

		delete pDel;

		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> :: retrieve ( TYPE & dataOut ) const
{
	bool success = false;
	Node<TYPE> * pGet = front;

	while ( ( pGet ) && ( pGet -> data < dataOut ) )
		pGet = pGet -> next;

	if ( ( pGet ) && ( pGet -> data == dataOut) )
	{
		dataOut = pGet -> data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
void DLList<TYPE> :: display () const
{
	Node<TYPE> * pTemp = front;

	while ( pTemp )
	{
		cout << pTemp -> data;
		pTemp = pTemp -> next;
	};

	if ( front )
		cout << endl;
}

//****************************************************************************************************

template <typename TYPE>
void DLList<TYPE> :: displayReverse () const
{
	Node<TYPE> * pTemp = rear;

	while ( pTemp )
	{
		cout << pTemp -> data;
		pTemp = pTemp -> prev;
	};

	if ( rear )
		cout << endl;
}

//****************************************************************************************************

template <typename TYPE>
int DLList<TYPE> :: getSize () const
{
	Node<TYPE> * pTemp = front;
	int size = 0;

	while ( pTemp )
	{
		pTemp = pTemp -> next;
		size++;
	};

	return size;
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> :: isEmpty () const
{
	return ( front == NULL );
}

//****************************************************************************************************

template <typename TYPE>
bool DLList<TYPE> :: isFull () const
{
	bool full = false;
	Node<TYPE> * pTest = new (nothrow) Node<TYPE>;

	if ( !pTest )
	{
		full = true;
		delete pTest;
	}

	return full;
}

//****************************************************************************************************

#endif

//****************************************************************************************************