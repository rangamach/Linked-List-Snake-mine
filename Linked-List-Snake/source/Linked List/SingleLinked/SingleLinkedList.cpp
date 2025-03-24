#include "../../include/Linked List/SingleLinked/SingleLinkedList.h"
#include "../../include/Linked List/SingleLinked/SingleNode.h"
#include "../../include/Player/BodyPart.h"

namespace LinkedList
{
	namespace SingleList
	{
		Node* SingleLinkedList::CreateNode()
		{
			return new SingleNode();
		}

		SingleLinkedList::SingleLinkedList() = default;

		SingleLinkedList::~SingleLinkedList() = default;

		void SingleLinkedList::InsertNodeAtTail()
		{
			linked_list_size++;
			Node* new_node = CreateNode();
			Node* cur_node = head_node;
			if (cur_node == nullptr)
			{
				head_node = new_node;
				InitializeNode(new_node, nullptr, Operation::Tail);
				return;
			}
			while (cur_node->next != nullptr)
				cur_node = cur_node->next;
			cur_node->next = new_node;
			InitializeNode(new_node, cur_node, Operation::Tail);
		}

		void SingleLinkedList::InsertNodeAtHead()
		{
			linked_list_size++;
			Node* new_node = CreateNode();
			if (head_node == nullptr)
			{
				head_node = new_node;
				InitializeNode(new_node, nullptr, Operation::Head);
				return;
			}
			InitializeNode(new_node, head_node, Operation::Head);
			new_node->next = head_node;
			head_node = new_node;
		}

		void SingleLinkedList::InsertNodeAtIndex(int index)
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
			new_node->next = cur_node;
			InitializeNode(new_node, prev_node, Operation::Tail);
			linked_list_size++;
			ShiftNodeAfterInsertion(new_node, cur_node, prev_node);
		}

		void SingleLinkedList::ShiftNodeAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
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

		void SingleLinkedList::InsertNodeAtMiddle()
		{
			if (head_node == nullptr)
			{
				InsertNodeAtHead();
				return;
			}
			int mid_index = FindMiddleNode();
			InsertNodeAtIndex(mid_index);
		}

		void SingleLinkedList::RemoveNodeAtHead()
		{
			Node* cur_node = head_node;
			head_node = head_node->next;
			cur_node->next = nullptr;
			delete(cur_node);
			linked_list_size--;
		}

		void SingleLinkedList::ShiftNodeAfterRemoval(Node* cur_node)
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

		void SingleLinkedList::RemoveNodeAtIndex(int index)
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
			prev_node->next = cur_node->next;
			ShiftNodeAfterRemoval(cur_node);
			delete(cur_node);
			linked_list_size--;
		}

		void SingleLinkedList::RemoveNodeAt(int index)
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

		void SingleLinkedList::RemoveNodeAtMiddle()
		{
			if (head_node == nullptr) return;
			int mid_ind = FindMiddleNode();
			RemoveNodeAt(mid_ind);
		}

		void SingleLinkedList::RemoveNodeAtTail()
		{
			if (head_node == nullptr) return;
			Node* cur_node = head_node;
			if (cur_node->next == nullptr)
			{
				RemoveNodeAtHead();
				return;
			}
			while (cur_node->next->next != nullptr)
			{
				cur_node = cur_node->next;
			}
			delete(cur_node->next);
			linked_list_size--;
			cur_node->next = nullptr;
		}

		void SingleLinkedList::RemoveHalfNodes()
		{
			if (linked_list_size <= 1) return;
			int half_length = linked_list_size / 2;
			int new_tail_index = half_length - 1;
			Node* prev_node = FindNodeAtIndex(new_tail_index);
			Node* cur_node = prev_node->next;
			while (cur_node != nullptr)
			{
				Node* node_to_delete = cur_node;
				cur_node = cur_node->next;
				delete(node_to_delete);
				linked_list_size--;
			}
			prev_node->next = nullptr;
		}

		void SingleLinkedList::RemoveAllNodes()
		{
			if (head_node == nullptr) return;
			while (head_node != nullptr)
			{
				RemoveNodeAtHead();
			}
		}

		Direction SingleLinkedList::Reverse()
		{
			Node* cur_node = head_node;
			Node* prev_node = nullptr;
			Node* next_node = nullptr;

			while (cur_node != nullptr)
			{
				next_node = cur_node->next;
				cur_node->next = prev_node;
				prev_node = cur_node;
				cur_node = next_node;
			}
			head_node = prev_node;
			ReverseNodeDirection();
			return	head_node->body_part.GetDirection();
		}
	}
}