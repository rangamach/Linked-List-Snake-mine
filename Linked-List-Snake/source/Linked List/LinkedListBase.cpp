#include "../../include/Linked List/LinkedListBase.h"
#include "../../include/Level/LevelView.h"
#include "../../include/Global/Config.h"

namespace LinkedList
{
	Node* LinkedListBase::CreateNode()
	{
		return new Node();
	}

	sf::Vector2i LinkedListBase::GetNewNodePosition(Node* ref_node, Operation operation)
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

	Direction LinkedListBase::GetReverseDirection(Direction ref_dir)
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

	int LinkedListBase::FindMiddleNode()
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

	Node* LinkedListBase::FindNodeAtIndex(int index)
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

	void LinkedListBase::InitializeNode(Node* new_node, Node* ref_node, Operation operation)
	{
		if (ref_node == nullptr)
		{
			new_node->body_part.Initialize(node_width, node_height, default_position, default_direction);
			return;
		}
		sf::Vector2i position = GetNewNodePosition(ref_node, operation);
		new_node->body_part.Initialize(node_width, node_height, position, ref_node->body_part.GetDirection());
	}

	LinkedListBase::LinkedListBase()
	{
		head_node = nullptr;
	}

	LinkedListBase::~LinkedListBase() = default;

	void LinkedListBase::Initialize(float width, float height, sf::Vector2i position, Direction direction)
	{
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
		linked_list_size = 0;
	}

	void LinkedListBase::Render()
	{
		Node* current_node = head_node;
		while (current_node != nullptr)
		{
			current_node->body_part.Render();
			current_node = current_node->next;
		}
	}

	void LinkedListBase::UpdateNodePosition()
	{
		Node* current_node = head_node;
		while (current_node != nullptr)
		{
			current_node->body_part.UpdatePosition();
			current_node = current_node->next;
		}
	}
	void LinkedListBase::UpdateNodeDirection(Direction new_direction)
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

	Node* LinkedListBase::GetHeadNode()
	{
		return head_node;
	}

	int LinkedListBase::GetSnakeSize()
	{
		return linked_list_size;
	}

	bool LinkedListBase::ProcessNodeCollision()
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

	void LinkedListBase::ReverseNodeDirection()
	{
		Node* cur_node = head_node;
		while (cur_node != nullptr)
		{
			cur_node->body_part.SetDirection(GetReverseDirection(cur_node->body_part.GetPreviousDirection()));
			cur_node = cur_node->next;
		}
	}

	std::vector<sf::Vector2i> LinkedListBase::GetNodePositionsList()
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
}