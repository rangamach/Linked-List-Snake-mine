#pragma once

#include "../Node.h"

namespace LinkedList
{
	namespace DoubleList
	{
		struct DoubleNode : public Node
		{
			Node* prev = nullptr;
		};
	}
}

