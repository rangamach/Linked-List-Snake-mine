#pragma once

#include "../LinkedList_Base.h"

namespace LinkedList
{
	class DoubleLinkedList : public LinkedList_Base
	{
	protected:
		virtual Node* CreateNode() override;
	public:
		DoubleLinkedList();
		~DoubleLinkedList();

		void InsertNodeAtTail() override;
		void InsertNodeAtHead() override;
		void InsertNodeAtMiddle() override;
		void InsertNodeAtIndex(int index) override;
		void ShiftNodeAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);
		void RemoveNodeAtTail() override;
		void RemoveNodeAtHead() override;
		void RemoveNodeAtMiddle() override;
		void RemoveNodeAt(int index) override;
		void RemoveAllNodes() override;
		void RemoveHalfNodes() override;
		void ShiftNodeAfterRemoval(Node* cur_node);
		Direction Reverse() override;
	};
}

