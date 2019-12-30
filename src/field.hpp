#ifndef FIELD_HPP_
#define FIELD_HPP_

#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

namespace Othello {

#define POS std::pair<int, int>

class Field {
  private:
    std::vector<POS> canPutPos;
    std::vector<std::vector<char>> tile;
    std::vector<std::vector<char>> display;

  public:
    Field();
    void searchPutPos(bool player);
    bool canPut(int y, int x, bool player);
    void calcPoint();
    void dispField();
};

}; // namespace Othello

#endif // include guard field.hpp
