#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>
//#include "../../include/Element/ElementData.h"

namespace Element
{
	class Obstacle;
	struct ElementData;
	class ElementService
	{
	private:
		std::vector<Obstacle*> obstacle_list;

		void SpawnObstacle(sf::Vector2i position, float cell_width, float cell_height);

	public:
		ElementService();
		~ElementService();

		void Initialize();
		void Update();
		void Render();

		const void SpawnElements(std::vector<ElementData>& element_data_list, float cell_width, float cell_height);
	};
}

