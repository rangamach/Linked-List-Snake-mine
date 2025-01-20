#include "../../include/Linked List/SingleLinkedList.h"

using namespace LinkedList;

Node* SingleLinkedList::CreateNode()
{
	return new Node();
}

SingleLinkedList::SingleLinkedList()
{
	head_node = nullptr;
}

SingleLinkedList::~SingleLinkedList() = default;

void SingleLinkedList::Initialize(float width, float height, sf::Vector2i position, Direction direction)
{
	node_width = width;
	node_height = height;
	default_position = position;
	defaul_direction = direction;
}

void SingleLinkedList::Render()
{
	head_node->body_part.Render();
}

void SingleLinkedList::CreateHeadNode()
{
	head_node = CreateNode();
	head_node->body_part.Initialize(node_width, node_height, default_position, defaul_direction);
	return;
}
