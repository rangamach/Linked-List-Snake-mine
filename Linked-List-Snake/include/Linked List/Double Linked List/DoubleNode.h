#pragma once

#include "../Node.h"

namespace LinkedList
{
	namespace DoubleLinked
	{
		struct DoubleNode : public Node
		{
			Node* previous = nullptr;
		};
	}
}

