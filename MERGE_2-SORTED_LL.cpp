


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
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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


Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if(head1 ==NULL)
    {
        return head2;
    }
    else if(head2 == NULL)
    {
        return head1;
    } 
    // Write your code here

    Node *h1 = head1;
    Node *h2 = head2;
    Node *Fh = NULL;
    Node *Ft = NULL;

    if (h1->data < h2->data)
    {
        Fh = h1;
        Ft = h1;
        h1 = h1->next;
    }

    else
    {
        Fh = h2;
        Ft = h2;
        h2 = h2->next;
    }

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data > h2->data)
        {
            Ft->next = h2;
            Ft = h2;
            h2 = h2->next;
        }
        else
        {
            Ft->next = h1;
            Ft = h1;
            h1 = h1->next;
        }
    }

    if(h2==NULL)
    {
        Ft->next = h1;
        return Fh;
    }
    else if (h1 == NULL)
    {
        Ft -> next = h2;
        return Fh;
    }
    return Fh;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}
