#include "../../include/Element/ElementService.h"
#include "../../include/Element/Obstacle.h"
#include "../../include/Element/ElementData.h"
#include "Linked List/Node.h"

using namespace Element;

void ElementService::SpawnObstacle(sf::Vector2i position, float cell_width, float cell_height)
{
	Obstacle* obstacle = new Obstacle();

	obstacle->Initialize(position,cell_width,cell_height);
	obstacle_list.push_back(obstacle);
}

ElementService::ElementService() = default;

ElementService::~ElementService() = default;

void ElementService::Initialize()
{
}

void ElementService::Update()
{
	for (int i = 0; i < obstacle_list.size(); i++)
	{
		obstacle_list[i]->Update();
	}
}

void ElementService::Render()
{
	for (int i = 0; i < obstacle_list.size(); i++)
	{
		obstacle_list[i]->Render();
	}
}

const void ElementService::SpawnElements(std::vector<ElementData>& element_data_list, float cell_width, float cell_height)
{
	for (int i = 0; i < element_data_list.size(); i++)
	{
		switch (element_data_list[i].element_type)
		{
		case ElementType::Obstacle:
			SpawnObstacle(element_data_list[i].position, cell_width, cell_height);
			break;
		}
	}
}

std::vector<sf::Vector2i> ElementService::GetElementPositionsList()
{
	std::vector<sf::Vector2i> elements_position_list;

	for (int i = 0; i < obstacle_list.size(); i++)
	{
		elements_position_list.push_back(obstacle_list[i]->GetObstaclePosition());
	}
	return elements_position_list;
}

bool Element::ElementService::ProcessElementCollision(LinkedList::Node* head_node)
{
	for (int i = 0; i < obstacle_list.size(); i++)
	{
		if (obstacle_list[i]->GetObstaclePosition() == head_node->body_part.GetNextPosition() || obstacle_list[i]->GetObstaclePosition() == head_node->body_part.GetPosition())
		{
			return true;
		}
	}
	return false;
}
