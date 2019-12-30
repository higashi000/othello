#include "field.hpp"

namespace Othello {

Field::Field()
{
  tile = std::vector<std::vector<char>>(8, std::vector<char>(8, ' '));
  display = std::vector<std::vector<char>>(8, std::vector<char>(8, ' '));

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
      std::cout << "|" << " " << display[i][j] << " ";
    }
    std::cout << "|" << std::endl;
    std::cout << "|---+---+---+---+---+---+---+---|" << std::endl;
  }

  char cnt = 'a';
  for (auto i: canPutPos) {
    std::cout << cnt << ": " << i.second << " " << i.first << std::endl;
    cnt++;
  }
}

void Field::searchPutPos(bool player)
{
  std::copy(tile.begin(), tile.end(), display.begin());
  char cnt = 'a';

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      POS pos = POS(i, j);
      if (tile[i][j] == ' ') {
        if (canPut(i, j, player)) {
          canPutPos.push_back(pos);
          display[i][j] = cnt;
          cnt++;
        }
      }
    }
  }
}

bool Field::canPut(int y, int x, bool player)
{
  char playerPice = (player ? 'B' : 'W');
  char enemyPice = (!player ? 'B' : 'W');


  int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
  int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

  for (int i = 0; i < 8; ++i) {
    int tmpDX = dx[i];
    int tmpDY = dy[i];
    bool flg = false;
    while (1) {
      if (0 > x + tmpDX || x + tmpDX >= 8 || 0 > y + tmpDY || y + tmpDY >= 8) break;
      if (tile[y + tmpDY][x + tmpDX] == ' ') break;
      if (tile[y + tmpDY][x + tmpDX] == enemyPice) flg = true;
      if (tile[y + tmpDY][x + tmpDX] == playerPice && flg) return true;

      tmpDX += dx[i];
      tmpDY += dy[i];
    }
  }

  return false;
}

}; // namespace Othello
