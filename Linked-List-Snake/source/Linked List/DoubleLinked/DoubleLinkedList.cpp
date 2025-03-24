#include "../../include/Linked List/DoubleLinked/DoubleLinkedList.h"
#include "../../include/Linked List/DoubleLinked/DoubleNode.h"

namespace LinkedList
{
	namespace DoubleList
	{
		Node* DoubleLinkedList::CreateNode()
		{
			return new DoubleNode();
		}
		DoubleLinkedList::DoubleLinkedList() = default;
		DoubleLinkedList::~DoubleLinkedList() = default;
		void DoubleLinkedList::InsertNodeAtTail()
		{
		}
		void DoubleLinkedList::InsertNodeAtHead()
		{
			linked_list_size++;
			Node* new_node = CreateNode();
			Node* cur_node = head_node;
			if (cur_node == nullptr)
			{
				head_node = new_node;
				static_cast<DoubleNode*>(new_node)->prev = nullptr;
				InitializeNode(new_node, nullptr, Operation::Tail);
				return;
			}
			InitializeNode(new_node, head_node, Operation::Head);
			new_node->next = head_node;
			static_cast<DoubleNode*>(head_node)->prev = new_node;

			head_node = new_node;
		}
		void DoubleLinkedList::InsertNodeAtMiddle()
		{
		}
		void DoubleLinkedList::InsertNodeAtIndex(int index)
		{
		}
		void DoubleLinkedList::ShiftNodeAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
		{
		}
		void DoubleLinkedList::RemoveNodeAtTail()
		{
		}
		void DoubleLinkedList::RemoveNodeAtHead()
		{
		}
		void DoubleLinkedList::RemoveNodeAtMiddle()
		{
		}
		void DoubleLinkedList::RemoveNodeAt(int index)
		{
		}
		void DoubleLinkedList::RemoveNodeAtIndex(int index)
		{
		}
		void DoubleLinkedList::RemoveAllNodes()
		{
		}
		void DoubleLinkedList::RemoveHalfNodes()
		{
		}
		void DoubleLinkedList::ShiftNodeAfterRemoval(Node* cur_node)
		{
		}
		Direction DoubleLinkedList::Reverse()
		{
			return Direction();
		}
	}
}
