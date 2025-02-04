#pragma once

#include "Node.h"

namespace LinkedList
{
	enum class Operation
	{
		Head,
		Middle,
		Tail,
	};
	class LinkedList_Base
	{
	protected:
		Node* head_node;
		float node_width;
		float node_height;
		sf::Vector2i default_position;
		Direction default_direction;
		int linked_list_size;

		virtual Node* CreateNode();
		sf::Vector2i GetNewNodePosition(Node* reference_node, Operation operation);
		Direction GetReverseDirection(Direction reference_direction);
		int FindMiddleNode();
		Node* FindNodeAtIndex(int index);
		void InitializeNode(Node* new_node, Node* reference_node, Operation operation);

	public:
		LinkedList_Base();
		virtual ~LinkedList_Base();

		void Initialize();
		void Render();

		virtual void InsertNodeAtTail() = 0;
		virtual void InsertNodeAtHead() = 0;
		virtual void InsertNodeAtMiddle() = 0;
		virtual void InsertNodeAtIndex(int index) = 0;
		virtual void RemoveNodeAtTail() = 0;
		virtual void RemoveNodeAtHead() = 0;
		virtual void RemoveNodeAtMiddle() = 0;
		virtual void RemoveNodeAt(int index) = 0;
		virtual void RemoveHalfNodes() = 0;
		virtual void RemoveAllNodes() = 0;
		virtual Direction Reverse() = 0;
		virtual void UpdateNodePosition() = 0;
		virtual void UpdateNodeDirection() = 0;

		Node* GetHeadNode();
		int GetLinkedListSize();
		bool ProcessNodeCollision();
		void ReverseNodeDirection();
		std::vector<sf::Vector2i> GetNodesPositionList();
	};
}

