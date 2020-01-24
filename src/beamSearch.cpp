#include "beamSearch.hpp"

namespace Othello {

Node::Node()
{
  field = Field();
}


Node::Node(Node *previous, POS pos, bool player)
{
  previousNode = previous;

  field = Field(previous->field.tile, pos.second, pos.first, !player);
}

}; // namespace Othello
