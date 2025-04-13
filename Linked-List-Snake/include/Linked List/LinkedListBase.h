#pragma once

#include <SFML/System/Vector2.hpp>
#include "Node.h"
#include <vector>

namespace LinkedList
{
	enum class Operation
	{
		Head,
		Middle,
		Tail,
	};
	class LinkedListBase
	{
	protected:
		Node* head_node;
		float node_width;
		float node_height;
		sf::Vector2i default_position;
		Direction default_direction;
		int linked_list_size;

		virtual Node* CreateNode() = 0;
		sf::Vector2i GetNewNodePosition(Node* ref_node, Operation operation);
		Direction GetReverseDirection(Direction ref_dir);
		int FindMiddleNode();
		Node* FindNodeAtIndex(int index);
		void InitializeNode(Node* new_node, Node* ref_node, Operation operation);

	public:
		LinkedListBase();
		virtual ~LinkedListBase();

		void Initialize(float width, float height, sf::Vector2i position, Direction direction);
		void Render();

		virtual void InsertNodeAtTail() = 0;
		virtual void InsertNodeAtHead() = 0;
		virtual void InsertNodeAtMiddle() = 0;
		virtual void InsertNodeAtIndex(int index) = 0;

		virtual void RemoveNodeAtTail() = 0;
		virtual void RemoveNodeAtHead() = 0;
		virtual void RemoveNodeAtMiddle() = 0;
		virtual void RemoveNodeAt(int index) = 0;
		virtual void RemoveAllNodes() = 0;
		virtual void RemoveHalfNodes() = 0;

		virtual Direction Reverse() = 0;

		virtual void UpdateNodePosition();
		virtual void UpdateNodeDirection(Direction new_direction);

		Node* GetHeadNode();
		int GetSnakeSize();
		bool ProcessNodeCollision();
		void ReverseNodeDirection();

		std::vector<sf::Vector2i> GetNodePositionsList();
	};
}