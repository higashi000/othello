#ifndef BEAMSEARCH_HPP_
#define BEAMSEARCH_HPP_

#include "field.hpp"
#include "vector"

namespace Othello {

struct Node {
  Node *previousNode;
  std::vector<Node*> nextNode;
  Field field;

  Node();
  Node(Node *previous, POS pos, bool player);
};

}; // namespace Othello

#endif BEAMSEARCH_HPP_ //include guard beamSearch.hpp
