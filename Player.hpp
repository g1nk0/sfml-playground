#pragma once
#include <SFML/Graphics.hpp>

class Player : public sf::Sprite
{
public:
  Player(int x, int y);
  void myinit();
  void mmove(int x, int y);

private:
  int m_row;
  int m_col;
};
