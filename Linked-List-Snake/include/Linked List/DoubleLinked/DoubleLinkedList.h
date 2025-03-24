#pragma once

#include "../LinkedListBase.h"
#include "../Node.h"
#include <SFML/System/Vector2.hpp>

namespace LinkedList
{
	namespace DoubleList
	{
		class DoubleLinkedList : public LinkedListBase
		{
		protected:
			Node* CreateNode() override;

		public:
			DoubleLinkedList();
			~DoubleLinkedList();

			virtual void InsertNodeAtTail() override;
			virtual void InsertNodeAtHead() override;
			virtual void InsertNodeAtMiddle() override;
			virtual void InsertNodeAtIndex(int index) override;
			void ShiftNodeAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);

			virtual void RemoveNodeAtTail() override;
			virtual void RemoveNodeAtHead() override;
			virtual void RemoveNodeAtMiddle() override;
			virtual void RemoveNodeAt(int index) override;
			void RemoveNodeAtIndex(int index);
			virtual void RemoveAllNodes() override;
			virtual void RemoveHalfNodes() override;
			void ShiftNodeAfterRemoval(Node* cur_node);

			virtual Direction Reverse() override;
		};
	}
}

