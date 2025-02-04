#include "../../include/Linked List/LinkedList_Base.h"

using namespace LinkedList;

int LinkedList_Base::FindMiddleNode()
{
	Node* slow = head_node;
	Node* fast = head_node;
	int mid_ind = 0;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
		mid_ind++;
	}
	return mid_ind;
}
