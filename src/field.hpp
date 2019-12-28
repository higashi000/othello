#ifndef FIELD_HPP_
#define FIELD_HPP_

#include <vector>
#include <iostream>

namespace Othello {

#define POS std::pair<int, int>

class Field {
  private:
    std::vector<std::vector<POS>> canPut;
    std::vector<std::vector<char>> tile;

  public:
    Field();
    void searchPutPos(bool player);
    void calcPoint();
    void dispField();
};

}; // namespace Othello

#endif // include guard field.hpp
