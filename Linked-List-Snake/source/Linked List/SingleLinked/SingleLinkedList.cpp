#include "../../include/Linked List/SingleLinked/SingleLinkedList.h"
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

int SingleLinkedList::FindMiddleNode()
{
	Node* slow = head_node;
	Node* fast = head_node;
	int mid_ind = 0;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
		mid_ind++;
	}
	return mid_ind;
}

Node* SingleLinkedList::FindNodeAtIndex(int index)
{
	int cur_ind = 0;
	Node* cur_node = head_node;
	Node* prev_node = nullptr;
	while (cur_node != nullptr && cur_ind <= index)
	{
		prev_node = cur_node;
		cur_node = cur_node->next;
		cur_ind++;
	}
	return prev_node;
}

Direction SingleLinkedList::GetReverseDirection(Direction ref_dir)
{
	switch (ref_dir)
	{
	case Direction::Up:
		return Direction::Down;
	case Direction::Down:
		return Direction::Up;
	case Direction::Left:
		return Direction::Right;
	case Direction::Right:
		return Direction::Left;
	}
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
	while (cur_node->next != nullptr)
		cur_node = cur_node->next;
	cur_node->next = new_node;
	InitializeNode(new_node,cur_node,Operation::Tail);
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

void SingleLinkedList::InsertNodeAtIndex(int index)
{
	if (index < 0 || index >= linked_list_size) return;
	if (index == 0)
	{
		InsertNodeAtHead();
		return;
	}
	Node* new_node = CreateNode();
	int cur_index = 0;
	Node* cur_node = head_node;
	Node* prev_node = nullptr;
	while (cur_node != nullptr && cur_index < index)
	{
		prev_node = cur_node;
		cur_node = cur_node->next;
		cur_index++;
	}
	prev_node->next = new_node;
	new_node->next = cur_node;
	InitializeNode(new_node, prev_node, Operation::Tail);
	linked_list_size++;
	ShiftNodeAfterInsertion(new_node, cur_node, prev_node);
}

void SingleLinkedList::ShiftNodeAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
{
	Node* next_node = cur_node;
	while (cur_node != nullptr && next_node != nullptr)
	{
		cur_node->body_part.SetPosition(next_node->body_part.GetPosition());
		cur_node->body_part.SetDirection(next_node->body_part.GetDirection());

		prev_node = cur_node;
		cur_node = next_node;
		next_node = next_node->next;
	}
	InitializeNode(cur_node, prev_node, Operation::Tail);
}

void SingleLinkedList::InsertNodeAtMiddle()
{
	if (head_node == nullptr)
	{
		InsertNodeAtHead();
		return;
	}
	int mid_index = FindMiddleNode();
	InsertNodeAtIndex(mid_index);
}

void SingleLinkedList::RemoveNodeAtHead()
{
	Node* cur_node = head_node;
	head_node = head_node->next;
	cur_node->next = nullptr;
	delete(cur_node);
	linked_list_size--;
}

void SingleLinkedList::ShiftNodeAfterRemoval(Node* cur_node)
{
	sf::Vector2i prev_node_pos = cur_node->body_part.GetPosition();
	Direction prev_node_dir = cur_node->body_part.GetDirection();
	cur_node = cur_node->next;
	while (cur_node != nullptr)
	{
		sf::Vector2i temp_node_pos = cur_node->body_part.GetPosition();
		Direction temp_node_dir = cur_node->body_part.GetDirection();
		cur_node->body_part.SetPosition(prev_node_pos);
		cur_node->body_part.SetDirection(prev_node_dir);
		cur_node = cur_node->next;
		prev_node_pos = temp_node_pos;
		prev_node_dir = temp_node_dir;
	}
}

void SingleLinkedList::RemoveNodeAtIndex(int index)
{
	int cur_ind = 0;
	Node* cur_node = head_node;
	Node* prev_node = nullptr;
	while (cur_node != nullptr && cur_ind < index)
	{
		prev_node = cur_node;
		cur_node = cur_node->next;
		cur_ind++;
	}
	prev_node->next = cur_node->next;
	ShiftNodeAfterRemoval(cur_node);
	delete(cur_node);
	linked_list_size--;
}

void LinkedList::SingleLinkedList::RemoveNodeAt(int index)
{
	if (index < 0 || index >= linked_list_size) return;
	if (index == 0)
	{
		RemoveNodeAtHead();
	}
	else
	{
		RemoveNodeAtIndex(index);
	}
}

void SingleLinkedList::RemoveNodeAtMiddle()
{
	if (head_node == nullptr) return;
	int mid_ind = FindMiddleNode();
	RemoveNodeAt(mid_ind);
}

void SingleLinkedList::RemoveNodeAtTail()
{
	if (head_node == nullptr) return;
	Node* cur_node = head_node;
	if (cur_node->next == nullptr)
	{
		RemoveNodeAtHead();
		return;
	}
	while (cur_node->next->next != nullptr)
	{
		cur_node = cur_node->next;
	}
	delete(cur_node->next);
	linked_list_size--;
	cur_node->next = nullptr;
}

void SingleLinkedList::RemoveHalfNodes()
{
	if (linked_list_size <= 1) return;
	int half_length = linked_list_size / 2;
	int new_tail_index = half_length - 1;
	Node* prev_node = FindNodeAtIndex(new_tail_index);
	Node* cur_node = prev_node->next;
	while (cur_node != nullptr)
	{
		Node* node_to_delete = cur_node;
		cur_node = cur_node->next;
		delete(node_to_delete);
		linked_list_size--;
	}
	prev_node->next = nullptr;
}

void SingleLinkedList::RemoveAllNodes()
{
	if (head_node == nullptr) return;
	while (head_node != nullptr)
	{
		RemoveNodeAtHead();
	}
}

Direction SingleLinkedList::Reverse()
{
	Node* cur_node = head_node;
	Node* prev_node = nullptr;
	Node* next_node = nullptr;

	while (cur_node != nullptr)
	{
		next_node = cur_node->next;
		cur_node->next = prev_node;
		prev_node = cur_node;
		cur_node = next_node;
	}
	head_node = prev_node;
	ReverseNodeDirection();
	return	head_node->body_part.GetDirection();
}

void SingleLinkedList::ReverseNodeDirection()
{
	Node* cur_node = head_node;
	while (cur_node != nullptr)
	{
		cur_node->body_part.SetDirection(GetReverseDirection(cur_node->body_part.GetPreviousDirection()));
		cur_node = cur_node->next;
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

int LinkedList::SingleLinkedList::GetSnakeSize()
{
	return linked_list_size;
}
