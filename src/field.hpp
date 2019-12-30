#ifndef FIELD_HPP_
#define FIELD_HPP_

#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

namespace Othello {

#define POS std::pair<int, int>
#define POINT std::pair<int, int>

class Field {
  private:
    std::vector<POS> canPutPos;
    std::vector<std::vector<char>> tile;
    std::vector<std::vector<char>> display;

  public:
    Field();
    void searchPutPos(bool player);
    bool canPut(int y, int x, bool player);
    POINT calcPoint();
    void dispField();
    std::vector<int> reverseDir(int y, int x, bool player);
    void reversePice(int num, bool player);
    bool checkFinish();
};

}; // namespace Othello

#endif // include guard field.hpp
