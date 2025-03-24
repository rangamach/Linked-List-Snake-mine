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
			while (cur_node->next != nullptr)
				cur_node = cur_node->next;
			cur_node->next = new_node;
			static_cast<DoubleNode*>(new_node)->prev = cur_node;
			InitializeNode(new_node, cur_node, Operation::Tail);
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
			if (head_node == nullptr)
			{
				InsertNodeAtHead();
				return;
			}
			int mid_index = FindMiddleNode();
			InsertNodeAtIndex(mid_index);
		}
		void DoubleLinkedList::InsertNodeAtIndex(int index)
		{
			if (index < 0 || index >= linked_list_size) return;
			if (index == 0)
			{
				InsertNodeAtHead();
				return;
			}
			Node* new_node = CreateNode();
			int cur_index = 0;
			Node* cur_node = head_node;
			Node* prev_node = nullptr;
			while (cur_node != nullptr && cur_index < index)
			{
				prev_node = cur_node;
				cur_node = cur_node->next;
				cur_index++;
			}
			prev_node->next = new_node;
			static_cast<DoubleNode*>(new_node)->prev = prev_node;
			new_node->next = cur_node;
			static_cast<DoubleNode*>(cur_node)->prev = new_node;
			InitializeNode(new_node, prev_node, Operation::Tail);
			linked_list_size++;
			ShiftNodeAfterInsertion(new_node, cur_node, prev_node);
		}
		void DoubleLinkedList::ShiftNodeAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
		{
			Node* next_node = cur_node;

			while (cur_node != nullptr && next_node != nullptr)
			{
				cur_node->body_part.SetPosition(next_node->body_part.GetPosition());
				cur_node->body_part.SetDirection(next_node->body_part.GetDirection());

				prev_node = cur_node;
				cur_node = next_node;
				next_node = next_node->next;
			}
			InitializeNode(cur_node, prev_node, Operation::Tail);
		}
		void DoubleLinkedList::RemoveNodeAtTail()
		{
			Node* cur_node = head_node;
			while (cur_node != nullptr)
				cur_node = cur_node->next;
			Node* prev_node = static_cast<DoubleNode*>(cur_node)->prev;
			prev_node->next = nullptr;
			delete(cur_node);
		}
		void DoubleLinkedList::RemoveNodeAtHead()
		{
			Node* cur_node = head_node;
			head_node = head_node->next;
			if(head_node != nullptr)
				static_cast<DoubleNode*>(head_node)->prev = nullptr;
			cur_node->next = nullptr;
			delete(cur_node);
			linked_list_size--;
		}
		void DoubleLinkedList::RemoveNodeAtMiddle()
		{
			if (head_node == nullptr) return;
			int mid_ind = FindMiddleNode();
			RemoveNodeAt(mid_ind);
		}
		void DoubleLinkedList::RemoveNodeAt(int index)
		{
			if (index < 0 || index >= linked_list_size) return;
			if (index == 0)
			{
				RemoveNodeAtHead();
			}
			else
			{
				RemoveNodeAtIndex(index);
			}
		}
		void DoubleLinkedList::RemoveNodeAtIndex(int index)
		{
			int cur_ind = 0;
			Node* cur_node = head_node;
			Node* prev_node = nullptr;
			while (cur_node != nullptr && cur_ind < index)
			{
				prev_node = cur_node;
				cur_node = cur_node->next;
				cur_ind++;
			}
			if(prev_node != nullptr)
				prev_node->next = cur_node->next;
			if (cur_node->next != nullptr)
			{
				Node* next_node = cur_node->next;
				static_cast<DoubleNode*>(next_node)->prev = prev_node;
			}
			ShiftNodeAfterRemoval(cur_node);
			delete(cur_node);
			linked_list_size--;
		}
		void DoubleLinkedList::RemoveAllNodes()
		{
			if (head_node == nullptr) return;
			while (head_node != nullptr)
				RemoveNodeAtHead();
		}
		void DoubleLinkedList::RemoveHalfNodes()
		{
		}
		void DoubleLinkedList::ShiftNodeAfterRemoval(Node* cur_node)
		{
			sf::Vector2i prev_node_pos = cur_node->body_part.GetPosition();
			Direction prev_node_dir = cur_node->body_part.GetDirection();
			cur_node = cur_node->next;
			while (cur_node != nullptr)
			{
				sf::Vector2i temp_node_pos = cur_node->body_part.GetPosition();
				Direction temp_node_dir = cur_node->body_part.GetDirection();
				cur_node->body_part.SetPosition(prev_node_pos);
				cur_node->body_part.SetDirection(prev_node_dir);
				cur_node = cur_node->next;
				prev_node_pos = temp_node_pos;
				prev_node_dir = temp_node_dir;
			}
		}
		Direction DoubleLinkedList::Reverse()
		{
			return Direction();
		}
	}
}
