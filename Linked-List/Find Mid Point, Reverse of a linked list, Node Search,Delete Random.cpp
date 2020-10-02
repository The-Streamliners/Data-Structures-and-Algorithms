#include <iostream>

using namespace std;

class node {
public:
	int data;
	node* next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

void inserthead(node* &head, int data) {
	node* n = new node(data);
	n->next = head;
	head = n;
}

void inserttail(node* &head, int data) {
	if (head == NULL) {
		head = new node(data);
		return;
	}
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;

	}
	temp->next = new node(data);
	return;
}

int length(node* head) {
	int cnt = 0;
	while (head != NULL) {
		head = head->next;
		cnt++;
	}
	return cnt;
}

void insertmidddle(node* &head, int data, int pos) {
	if (head == NULL || pos == 0) {
		inserthead(head, data);
	} else if (pos > length(head)) {
		inserttail(head, data);
	} else {
		int jumps = 1;
		node* temp = head;
		node* n = new node(data);

		while (jumps <= pos - 1) {
			temp = temp->next;
			jumps++;
		}
		n->next = temp->next;
		temp->next = n;

	}
}


void print(node* head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "-->";
		temp = temp-> next;
	}
}

void deletehead(node* &head) {
	if (head == NULL) {
		return;
	}
	node* temp = head;
	head = head->next;
	delete temp;
	return;
}

void deletetail(node* &head) {
	node* temp = head;
	node* prev = NULL;

	while (temp->next != NULL) {
		prev = temp;
		temp = temp -> next;
	}

	delete temp;
	prev -> next = NULL;
	return;
}

void deleterandom(node* &head, int pos) {
	node*prev = NULL;
	node* temp = head;

	int jumps = 0;
	while (jumps <= pos) {
		prev = temp;
		temp = temp->next;
		jumps ++;
	}

	prev->next = temp->next;
	delete temp;
}

void nodesearchiterative(node* head, int data) {
	for (int i = 0; i < length(head); i++) {
		int p = -1;
		if (head == NULL) {
			cout <<  p;
		}
		if (head->data == data) {
			cout << i;
		}
		else {
			cout << p;
		}
		head = head -> next;
	}



}

bool nodesearch(node* head, int data) {
	if (head == NULL) {
		return false;
	}
	if (head->data == data) {
		return true;
	} else {
		head = head->next;
		nodesearch(head->next, data);
	}

}

void buildlist(node* &head) {
	int data;
	cin >> data;

	while (data != -1) {
		inserttail(head, data);
		cin >> data;

	}
}

void reverse(node* &head) {
	node* C = head;
	node* P = NULL;
	node* N = NULL;

	while (C != NULL) {
		// initialising the Pointer
		N = C -> next;
		// Here C is getting connected to Previous direction pointer p
		C -> next = P;
		// Updating and Pushing the Pointer inside the Pointer in back direction but moving the P pointer so that C Becomes NULL

		P = C;
		C = N;
	}
	head = P;
}

istream& operator>>(istream &is, node* &head) {
	buildlist(head);
	return is;
}

ostream& operator<<(ostream &os, node* head) {
	print(head);
	return os;
}

void printreverse(node* head) {
	node* c = head;
	node* p = NULL;
	node* n = NULL;

	while (c != NULL) {
		n = c->next;
		c->next = p;

		p = c;
		c = n;
	}
	head = p;
}




int main()
{
	node* head = NULL;

	cin >> head;
	print(head);
	cout << endl;

	printreverse(head);
	print(head);
	cout << endl;




	return 0;
}
