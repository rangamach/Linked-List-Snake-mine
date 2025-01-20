#include "../../include/Linked List/SingleLinkedList.h"

using namespace LinkedList;

Node* SingleLinkedList::CreateNode()
{
	return new Node();
}

sf::Vector2i SingleLinkedList::GetNewNodePosition(Node* ref_node)
{
	Direction ref_direction = ref_node->body_part.GetDirection();
	sf::Vector2i ref_position = ref_node->body_part.GetPosition();

	switch (ref_direction)
	{
	case Direction::Up:
		return sf::Vector2i(ref_position.x, ref_position.y - 1);
		break;
	case Direction::Down:
		return sf::Vector2i(ref_position.x, ref_position.y + 1);
		break;
	case Direction::Left:
		return sf::Vector2i(ref_position.x + 1, ref_position.y);
		break;
	case Direction::Right:
		return sf::Vector2i(ref_position.x - 1, ref_position.y);
		break;
	}
	return default_position;
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
	//head_node->body_part.Render();

	Node* current_node = head_node;
	while (current_node != nullptr)
	{
		current_node->body_part.Render();
		current_node = current_node->next;
	}
}

//void SingleLinkedList::CreateHeadNode()
//{
//	head_node = CreateNode();
//	head_node->body_part.Initialize(node_width, node_height, default_position, defaul_direction);
//	return;
//}

void SingleLinkedList::InsertNodeAtTail()
{
	Node* new_node = CreateNode();
	Node* current_node = head_node;

	if (current_node == nullptr)
	{
		head_node = new_node;
		new_node->body_part.Initialize(node_width, node_height, default_position, defaul_direction);
		return;
	}
	while (current_node->next != nullptr)
		current_node = current_node->next;
	current_node->next = new_node;
	new_node->body_part.Initialize(node_width, node_height, GetNewNodePosition(current_node), current_node->body_part.GetDirection());
}
