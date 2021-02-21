#include <iostream>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *head;

struct Node* createNewNode(int value) {
	struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = value;
	ptr->next = NULL;
	return ptr;
}

int lengthOfList() {
	struct Node *temp;
	temp = head;
	int count = 0;
	while(temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

void addAtBeginning(int value) {
	struct Node *ptr = createNewNode(value);
	if(head == NULL) {
		head = ptr;
		return;
	}
	ptr->next = head;
	head = ptr;
}

void addAtEnd(int value) {
	struct Node *ptr = createNewNode(value);
	if(head == NULL) {
		head = ptr;
		return;
	}
	struct Node *temp;
	temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = ptr;
}


void addAtSpecificPosition(int value, int position) {
	if(position <= 0) {
		std::cout<<"Position must be greater than 0";
		return;
	}

	if(position > lengthOfList()+1) {
		std::cout<<"The current list is of length "<<lengthOfList();
		std::cout<<"\nMaximum value you can enter is 'length of list + 1'";
		return;
	}

	struct Node *ptr = createNewNode(value);

	if(position == 1) {
		ptr->next = head;
		head = ptr;
		return;
	}

	int pos = 1;
	struct Node *temp;
	temp = head;
	while(pos < position-1) {
		temp = temp->next;
		++pos;
	}
	ptr->next = temp->next;
	temp->next = ptr;
}

void deleteAtBeginning() {
	if(head == NULL) {
		std::cout<<"List is empty";
		return;
	}
	struct Node *temp = head;
	head = head->next;
	free(temp);
}

void deleteAtEnd() {
	if(head == NULL) {
		std::cout<<"List is empty";
		return;
	}
	if(head->next == NULL) {
		struct Node *temp = head;
		head = head->next;
		free(temp);
		return;
	}
	struct Node *temp = head;
	while(temp->next->next != NULL) temp = temp->next;
	
	struct Node *temp2 = temp->next;
	temp->next = NULL;
	free(temp2);
}

void deleteAtSpecificPosition(int position) {
	if(position <= 0) {
		std::cout<<"Position must be greater than 0";
		return;
	}

	if(position > lengthOfList()+1) {
		std::cout<<"The current list is of length "<<lengthOfList();
		std::cout<<"\nMaximum value you can enter is 'length of list + 1'";
		return;
	}

	if(position == 1) {
		struct Node *temp = head;
	  	head = head->next;
	  	free(temp);
	  	return;
	}
	int pos = 1;
	struct Node *temp = head;
	while(pos < position-1) {
		temp = temp->next;
		++pos;
	}
	struct Node *temp2 = temp->next;
	temp->next = temp->next->next;
	free(temp2);

}

void displayList() {
	if(head == NULL) {
		std::cout<<"List is empty";
		return;
	}
	struct Node *temp;
	temp = head;
	while(temp != NULL) {
		std::cout<<temp->data<<" ";
		temp = temp->next;
	}
	std::cout<<'\n';
}

int main() {
	while(1) {
		std::cout<<"Enter number between 0 to 7";
		int no, value, position;

		std::cout<<"\n    0. ------> Exit from Program";
		std::cout<<"\n    1. ------> Add at the Begninnig";
		std::cout<<"\n    2. ------> Add at the End";
		std::cout<<"\n    3. ------> Add at the Specific Position";
		std::cout<<"\n    4. ------> Delete at the Begninnig";
		std::cout<<"\n    5. ------> Delete at the End";
		std::cout<<"\n    6. ------> Delete at the Specific Position";
		std::cout<<"\n    7. ------> Display List\n\n";
		std::cin>>no;

		switch(no) {
		case 0 : exit(0);

		case 1 : std::cout<<"Enter value to enter";
				 std::cin>>value;
				 addAtBeginning(value);
				 break;

		case 2 : std::cout<<"Enter value to enter";
				 std::cin>>value;
				 addAtEnd(value);
				 break;

		case 3 : std::cout<<"Enter value to enter";
				 std::cin>>value;
				 std::cout<<"\nand also position";
				 std::cin>>position;
				 addAtSpecificPosition(value, position);
				 break;

		case 4 : deleteAtBeginning();
				 break;

		case 5 : deleteAtEnd();
				 break;

		case 6 : std::cout<<"\nEnter position";
				 std::cin>>position;
				 deleteAtSpecificPosition(position);
				 break;

		case 7 : displayList();
				 break;

		default : std::cout<<"Try to enter between 0 to 7";
				  break;
	}
	}
	
	return 0;
}