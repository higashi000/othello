#include <iostream>
#include "field.hpp"

using namespace Othello;

int main() {
  Field f;

  bool player = true;

  while (1) {
    f.searchPutPos(player);
    f.dispField();

    int num;
    char playerPice = (player ? 'B' : 'W');
    std::cout << "Now Player >> " << playerPice << std::endl << std::endl;
    std::cout << "Please input your choice >>";
    std::cin >> num;
    f.reversePice(num - 1, player);


    if (f.checkFinish()) {
      auto point = f.calcPoint();

      std::cout << "BLACK: " << point.first << std::endl;
      std::cout << "WHITE: " << point.second << std::endl;

      if (point.first > point.second) std::cout << "Winner: BLACK" << std::endl;
      else if (point.first < point.second) std::cout << "Winner: WHITE" << std::endl;
      else std::cout << "draw" << std::endl;

      break;
    }

    player = !player;
  }
}
