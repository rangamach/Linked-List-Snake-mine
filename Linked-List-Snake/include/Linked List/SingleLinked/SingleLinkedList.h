#pragma once

#include "../LinkedList_Base.h"
#include "../Node.h"
#include <SFML/System/Vector2.hpp>

namespace LinkedList
{
	//enum class Operation
	//{
	//	Head,
	//	Middle,
	//	Tail,
	//};
	class SingleLinkedList : public LinkedList_Base
	{
	protected:
		virtual Node* CreateNode() override;

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
		void RemoveHalfNodes() override;
		void ShiftNodeAfterRemoval(Node* cur_node);
		Direction Reverse() override;
		void ReverseNodeDirection();
	//protected:
	//	Node* head_node;
	//	float node_width;
	//	float node_height;
	//	sf::Vector2i default_position;
	//	Direction default_direction;
	//	int linked_list_size;

	//	virtual Node* CreateNode() override;
	//	sf::Vector2i GetNewNodePosition(Node* ref_node, Operation operation);
	//	void InitializeNode(Node* new_node, Node* ref_node, Operation operation);
	//	int FindMiddleNode();
	//	Node* FindNodeAtIndex(int index);
	//	Direction GetReverseDirection(Direction ref_dir);

	//public:
	//	SingleLinkedList();
	//	~SingleLinkedList();
	//	void Initialize(float width, float height, sf::Vector2i position, Direction direction);
	//	void Render();

	//	void InsertNodeAtTail();
	//	void InsertNodeAtHead();
	//	void InsertNodeAtIndex(int index);
	//	void ShiftNodeAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);
	//	void InsertNodeAtMiddle();
	//	void RemoveNodeAtHead();
	//	void ShiftNodeAfterRemoval(Node* cur_node);
	//	void RemoveNodeAtIndex(int index);
	//	void RemoveNodeAt(int index);
	//	void RemoveNodeAtMiddle();
	//	void RemoveNodeAtTail();
	//	void RemoveHalfNodes();
	//	void RemoveAllNodes();
	//	Direction Reverse();
	//	void ReverseNodeDirection();
	//	void UpdateNodeDirection(Direction new_direction);
	//	void UpdateNodePosition();
	//	bool ProcessNodeCollision();
	//	std::vector<sf::Vector2i> GetNodePositionsList();
	//	Node* GetHeadNode();
	//	int GetSnakeSize();
			
	};
}

