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
		Direction defaul_direction;

		Node* CreateNode();

	public:
		SingleLinkedList();
		~SingleLinkedList();
		void Initialize(float width, float height, sf::Vector2i position, Direction direction);
		void Render();

		void CreateHeadNode();
			
	};
}

