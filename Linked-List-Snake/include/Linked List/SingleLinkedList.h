#pragma once

#include "Node.h"
#include <SFML/System/Vector2.hpp>

namespace LinkedList
{
	class SingleLinkedList
	{
	private:
		Node* head_node;
		float node_width;
		float node_height;
		sf::Vector2i default_position;
		Direction default_direction;

		Node* CreateNode();
		sf::Vector2i GetNewNodePosition(Node* ref_node);

	public:
		SingleLinkedList();
		~SingleLinkedList();
		void Initialize(float width, float height, sf::Vector2i position, Direction direction);
		void Render();

		void InsertNodeAtTail();
		void RemoveNodeAtHead();
		void RemoveAllNodes();
		void UpdateNodeDirection(Direction new_direction);
		void UpdateNodePosition();
		bool ProcessNodeCollision();
		std::vector<sf::Vector2i> GetNodePositionsList();
		Node* GetHeadNode();
			
	};
}

