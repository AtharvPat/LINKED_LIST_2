



#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
//---------------------------------------------------------RECURSIVE APPROACH
Node *reverseLinkedListRec(Node *head)
{
    //write your recursive code here
  if(head==NULL || head ->next ==NULL)
      return head;
    
    Node* smallans=reverseLinkedListRec(head->next);
    Node*tail= head->next;
    tail->next=head;
    head ->next =NULL;
    
    return smallans;
                                         
}

//-------------------------------------------------------------ITERATIVE APPORACH

Node *reverseLinkedList(Node *head) {
    // Write your code here
    
 if(head == NULL)
 {
     return head;
 }

Node* c =head;
    Node* prev = NULL;
    Node* n = c->next;
    
    while(c !=NULL)
    {
        if(n!=NULL)
        {
        c -> next = prev;
        prev = c;
        c = n;
        n = n->next;
        }
        else
        {
            c -> next = prev;
        prev = c;
        c = n;
        }
    }
    return prev;
}

//-----------------------------------------------------------------

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}
