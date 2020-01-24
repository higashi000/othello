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

Field::Field(std::vector<std::vector<char>> beforTile, int x, int y, bool player)
{
  tile = std::vector<std::vector<char>>(8, std::vector<char>(8, ' '));
  display = std::vector<std::vector<char>>(8, std::vector<char>(8, ' '));

  std::copy(beforTile.begin(), beforTile.end(), tile.begin());

  tile[y][x] = (whichPlayer ? 'B' : 'W');
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

  if (canPutPos.size() < 1) {
    std::cout << "0: pass" << std::endl;
  } else {
    int cnt = 1;
    for (auto i: canPutPos) {
      std::cout << cnt << ": " << i.second << " " << i.first << std::endl;
      cnt++;
    }
  }
}

void Field::searchPutPos(bool player)
{
  canPutPos = std::vector<POS>(0);
  std::copy(tile.begin(), tile.end(), display.begin());
  char cnt = '1';

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
      if (tile[y + tmpDY][x + tmpDX] == playerPice && !flg) break;
      if (tile[y + tmpDY][x + tmpDX] == enemyPice) flg = true;
      if (tile[y + tmpDY][x + tmpDX] == playerPice && flg) return true;

      tmpDX += dx[i];
      tmpDY += dy[i];
    }
  }

  return false;
}

std::vector<int> Field::reverseDir(int y, int x, bool player)
{
  char playerPice = (player ? 'B' : 'W');
  char enemyPice = (!player ? 'B' : 'W');

  std::vector<int> canPutDir;

  int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
  int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

  for (int i = 0; i < 8; ++i) {
    int tmpDX = dx[i];
    int tmpDY = dy[i];
    bool flg = false;
    while (1) {
      if (0 > x + tmpDX || x + tmpDX >= 8 || 0 > y + tmpDY || y + tmpDY >= 8) break;
      if (tile[y + tmpDY][x + tmpDX] == ' ') break;
      if (tile[y + tmpDY][x + tmpDX] == playerPice && !flg) break;
      if (tile[y + tmpDY][x + tmpDX] == enemyPice) flg = true;
      if (tile[y + tmpDY][x + tmpDX] == playerPice && flg) {
        canPutDir.push_back(i);
        break;
      }

      tmpDX += dx[i];
      tmpDY += dy[i];
    }
  }

  return canPutDir;
}

void Field::reversePice(int num, bool player)
{
  if (num < 0 || canPutPos.size() <= num) return;

  auto canPutDir = reverseDir(canPutPos[num].first, canPutPos[num].second, player);
  int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
  int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
  char playerPice = (player ? 'B' : 'W');
  char enemyPice = (!player ? 'B' : 'W');

  tile[canPutPos[num].first][canPutPos[num].second] = playerPice;

  for (auto i: canPutDir) {
    int tmpDX = dx[i] + canPutPos[num].second;
    int tmpDY = dy[i] + canPutPos[num].first;

    while (1) {
      if (tile[tmpDY][tmpDX] == playerPice) break;

      tile[tmpDY][tmpDX] = playerPice;

      tmpDX += dx[i];
      tmpDY += dy[i];
    }
  }
}

bool Field::checkFinish()
{
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (tile[i][j] == ' ') return false;
    }
  }

  return true;
}

POINT Field::calcPoint()
{
  POINT point;

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (tile[i][j] == 'B') point.first++;
      if (tile[i][j] == 'W') point.second++;
    }
  }

  return point;
}

}; // namespace Othello
