#include "field.hpp"

namespace Othello {

Field::Field()
{
  tile = std::vector<std::vector<char>>(8, std::vector<char>(8, ' '));

  tile[3][3] = 'W';
  tile[4][4] = 'W';
  tile[4][3] = 'B';
  tile[3][4] = 'B';
}

void Field::dispField()
{
  std::cout << "|---+---+---+---+---+---+---+---|" << std::endl;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      std::cout << "|" << " " << tile[i][j] << " ";
    }
    std::cout << "|" << std::endl;
    std::cout << "|---+---+---+---+---+---+---+---|" << std::endl;
  }
}

}; // namespace Othello
