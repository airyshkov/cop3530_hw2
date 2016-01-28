#include <iostream>

// ------------------------------------------------------------------------------------------------------
/*
 The following linked list implementation is originally from SourceTricks; it is not entirely my own code.
 I have modified it as necessary for this project.
 http://www.sourcetricks.com/2008/07/c-singly-linked-lists.html#.Vqfwibx5hE4
 */

void PRINT_DEBUG(int dbg)
{
	std::cout << "DEBUG: " << dbg << "\n";
}

// Node class
class Node {
	int data;
	Node* next;
	
public:
	Node() {};
	void SetData(int aData) { data = aData; };
	void SetNext(Node* aNext) { next = aNext; };
	int Data() { return data; };
	Node* Next() { return next; };
};

// List class
class List {
	Node *head;
public:
	List() { head = NULL; };
	void Print();
	int ReturnData();
	void stepOne();
	bool NextNodeNull();
	void Append(int data);
	void Delete(int data);
	void DeleteAll();
	bool isEmpty();
};

// check for empty list
bool List::isEmpty()
{
	Node *tmp = head; // temp pointer
	//check for empty nodes:
	if ( tmp == NULL ) {
		return true;
	} else { return false; }
}

// return the list's value and step through the list
int List::ReturnData()
{
	if(head != NULL) {
		return head->Data();
	}else{
		return 0;
	}
}

void List::stepOne()
{
	if (head != NULL)
		head = head->Next();
}

bool List::NextNodeNull()
{
	if (head == NULL)
		return true;
	return false;
}

// Print the contents of the list
void List::Print() {
	
	using namespace std;
	
	Node *tmp = head; // Temp pointer
	
	// No nodes
	if ( isEmpty() ) {
		cout << "EMPTY" << endl;
		return;
	}
	
	// One node in the list
	if ( tmp->Next() == NULL ) {
		cout << tmp->Data() << endl;
		//		cout << tmp->Data();
		//		cout << " --> ";
		//		cout << "NULL" << endl;
	}
	else {
		// Parse and print the list
		do {
			cout << tmp->Data() << " ";
			//			cout << tmp->Data();
			//			cout << " --> ";
			tmp = tmp->Next();
		}
		while ( tmp != NULL );
		
		cout << endl;
		//		cout << "NULL" << endl;
	}
}

// Append a node to the linked list
void List::Append(int data) {
	
	// Create a new node
	Node* newNode = new Node();
	newNode->SetData(data);
	newNode->SetNext(NULL);
	
	Node *tmp = head; // Create a temp pointer
	
	if ( tmp != NULL ) {
		// Nodes already present in the list
		// Parse to end of list
		while ( tmp->Next() != NULL ) {
			tmp = tmp->Next();
		}
		tmp->SetNext(newNode); // Point the last node to the new node
	}
	else {
		head = newNode; // First node in the list
	}
}

// Delete a node from the list
void List::Delete(int data) {
	
	Node *tmp = head; // Create a temp pointer
	
	// No nodes
	if ( tmp == NULL )
		return;
	
	// Last node of the list
	if ( tmp->Next() == NULL ) {
		delete tmp;
		head = NULL;
	}
	else {
		// Parse thru the nodes
		Node *prev;
		do {
			if ( tmp->Data() == data ) break;
			prev = tmp;
			tmp = tmp->Next();
		} while ( tmp != NULL );
		
		prev->SetNext(tmp->Next()); // Adjust the pointers
		
		delete tmp; // Delete the current node
	}
}

void List::DeleteAll()
{
//	Node *tmp = head;
//	Node *prev;
//	do {
//		
//		prev = tmp;
//		tmp = tmp->Next();
//	} while ( tmp != NULL );
//	
//	prev->SetNext(tmp->Next()); // Adjust the pointers
//	
//	delete tmp; // Delete the current node
	head = NULL;
}

/*
 END OF LINKED LIST IMPLEMENTATION
 */
// ------------------------------------------------------------------------------------------------------


// Take the list for a drive
void testList()
{
	// New list
	List list;
	
	// Append nodes to the list
	list.Append(100);
	list.Print();
	list.Append(200);
	list.Print();
	list.Append(300);
	list.Print();
	list.Append(400);
	list.Print();
	list.Append(500);
	list.Print();
	
	// Delete nodes from the list
	list.Delete(400);
	list.Print();
	list.Delete(300);
	list.Print();
	list.Delete(200);
	list.Print();
	list.Delete(500);
	list.Print();
	list.Delete(100);
	list.Print();
}

// create list
List createList(int numOfElements)
{
	using namespace std;
	
	List temp;
	int data;
	
	for (int i=0; i<numOfElements; i++) {
		cin >> data;
		temp.Append(data);
	}
	
	return temp;
}

int main()
{
	using namespace std;

	// Creating the initial list
	List templist,list1,finalList,listx;
	int tempElements, numOfElements;
	cin >> tempElements;
	templist = createList(tempElements); // initial list; will be interleaved with additional lists
//	templist.Print();						// DEBUG PRINT STATEMENT
	
	// Creating additional lists
	
	// Get number of additional lists
	int numLists = 0;
	int step = 0;
	int list1Length = 0;
	cin >> numLists;
	
	// Run a loop to get and interleave numLists lists
	for (int n = 0; n < numLists; n++)
	{
//		cout << "list number" << n+1 << "\n"; // DEBUG
		
		// Interleave procedure for all lists inside here
		
		// Get step size for next list
		cin >> step;
		
		// Get values for next list
		cin >> numOfElements;
		listx = createList(numOfElements);
		
		// New list length before interleaving
		
//		cout << "tempElements before: " << tempElements << "\n"; // DEBUG
//		cout << "numOfElements: " << numOfElements << "\n"; // DEBUG
		
		list1Length = tempElements + numOfElements;
		tempElements = list1Length; // set future templist length to new length for future lists
		
//		cout << "list1Length: " << list1Length << "\n"; // DEBUG
//		cout << "tempElements after: " << tempElements << "\n"; // DEBUG
		
		// Interleave listx into templist by building list1
		
		//	templist.ReturnData(); // DEBUG
		for (int i=0; i < list1Length; i++) // loop until list1 is built
		{
			for (int j=0; j < step; j++) // loop for the step size
			{
//				cout << "j=" << j << "\n"; // DEBUG
//				cout << "templist.ReturnData(): "; cout << templist.ReturnData(); cout << "\n"; // DEBUG
				if (!templist.NextNodeNull()) {
					list1.Append(templist.ReturnData());
					templist.stepOne();
				}
//				list1.Append(templist.ReturnData()); // add the data from the original list
//				cout << "list1.Append(templist.ReturnData()): "; list1.Print(); // DEBUG

			}
//			cout << "listx.ReturnData(): "; cout << listx.ReturnData(); cout << "\n"; // DEBUG
//			cout << "i=" << i << "\n"; // DEBUG

			if (!listx.NextNodeNull()) {
				list1.Append(listx.ReturnData());
				listx.stepOne();
			}
//			list1.Append(listx.ReturnData()); // building list1 step by step
//			cout << "list1.Append(listx.ReturnData()): "; list1.Print(); // DEBUG
		}
		templist = list1; // save the interleaved list into templist to build on top of in the next loop
		
		// Delete everything in list1 to reconstruct the next list
//		cout << "list1.Delete(0): "; list1.Print(); // DEBUG
//		cout << "list1 before delete: "; list1.Print(); // DEBUG
		list1.DeleteAll(); // clear list1 to construct the next list
//		cout << "list1 after delete: "; list1.Print(); // DEBUG
	}
	finalList = templist;
//	cout << "finalList: "; // DEBUG
	finalList.Print();
	
	//testList(); // testing the linked list code from List.h
}
