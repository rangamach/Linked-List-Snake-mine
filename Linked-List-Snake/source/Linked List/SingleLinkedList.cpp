#include "../../include/Linked List/SingleLinkedList.h"
#include "../../include/Player/BodyPart.h"

using namespace LinkedList;

Node* SingleLinkedList::CreateNode()
{
	return new Node();
}

sf::Vector2i SingleLinkedList::GetNewNodePosition(Node* ref_node, Operation operation)
{
	switch (operation)
	{
	case Operation::Head:
		return ref_node->body_part.GetNextPosition();
	case Operation::Tail:
		return ref_node->body_part.GetPrevPosition();
	}
	return default_position;
}

void SingleLinkedList::InitializeNode(Node* new_node, Node* ref_node, Operation operation)
{
	if (ref_node == nullptr)
	{
		new_node->body_part.Initialize(node_width, node_height, default_position, default_direction);
		return;
	}
	sf::Vector2i position = GetNewNodePosition(ref_node, operation);
	new_node->body_part.Initialize(node_width, node_height, position, ref_node->body_part.GetDirection());
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
	default_direction = direction;
	linked_list_size = 0;
}

void SingleLinkedList::Render()
{
	Node* current_node = head_node;
	while (current_node != nullptr)
	{
		current_node->body_part.Render();
		current_node = current_node->next;
	}
}

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
	while (cur_node == nullptr)
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
		InitializeNode(new_node,nullptr,Operation::Head);
		return;
	}
	InitializeNode(new_node, head_node, Operation::Head);
	new_node->next = head_node;
	head_node = new_node;
}

void SingleLinkedList::RemoveNodeAtHead()
{
	Node* cur_node = head_node;
	head_node = head_node->next;
	cur_node->next = nullptr;
	delete(cur_node);
}

void SingleLinkedList::RemoveAllNodes()
{
	if (head_node == nullptr) return;
	while (head_node != nullptr)
	{
		RemoveNodeAtHead();
	}
}

void SingleLinkedList::UpdateNodeDirection(Direction new_direction)
{
	Node* current_node = head_node;

	while (current_node != nullptr)
	{
		Direction prev_direction = current_node->body_part.GetDirection();
		current_node->body_part.SetDirection(new_direction);
		new_direction = prev_direction;
		current_node = current_node->next;
	}
}

void SingleLinkedList::UpdateNodePosition()
{
	Node* current_node = head_node;

	while (current_node != nullptr)
	{
		current_node->body_part.UpdatePosition();
		current_node = current_node->next;
	}
}

bool SingleLinkedList::ProcessNodeCollision()
{
	if (head_node == nullptr) return false;
	
	sf::Vector2i predicted_pos = head_node->body_part.GetNextPosition();
	Node* cur_node = head_node->next;
	while (cur_node != nullptr)
	{
		if (cur_node->body_part.GetNextPosition() == predicted_pos) return true;
		cur_node = cur_node->next;
	}
	return false;
}

std::vector<sf::Vector2i> SingleLinkedList::GetNodePositionsList()
{
	std::vector<sf::Vector2i> nodes_position_list;
	Node* current_node = head_node;

	while (current_node != nullptr)
	{
		nodes_position_list.push_back(current_node->body_part.GetPosition());
		current_node = current_node->next;
	}
	return nodes_position_list;
}

Node* SingleLinkedList::GetHeadNode()
{
	return head_node;
}
