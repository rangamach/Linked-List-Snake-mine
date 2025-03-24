#pragma once

#include "../LinkedListBase.h"
#include "../Node.h"
#include <SFML/System/Vector2.hpp>

namespace LinkedList
{
	namespace SingleList
	{
		class SingleLinkedList : public LinkedListBase
		{
		protected:
			Node* CreateNode() override;

		public:
			SingleLinkedList();
			~SingleLinkedList();

			void InsertNodeAtTail() override;
			void InsertNodeAtHead() override;
			void InsertNodeAtMiddle() override;
			void InsertNodeAtIndex(int index) override;

			void ShiftNodeAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);

			void RemoveNodeAtTail() override;
			void RemoveNodeAtHead() override;
			void RemoveNodeAtMiddle() override;
			void RemoveNodeAt(int index) override;
			void RemoveNodeAtIndex(int index);
			void RemoveAllNodes() override;
			void RemoveHalfNodes() override;

			void ShiftNodeAfterRemoval(Node* cur_node);

			Direction Reverse() override;
		};
	}
}

