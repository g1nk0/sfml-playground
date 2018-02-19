#include <iostream>
#include "Player.hpp"
#include "ResourceManager.hpp"

Player::Player(int x, int y)
{
  m_row = y;
  m_col = x;
}

void Player::myinit()
{
  setTexture(theResource.getTexture("cultist"));
  setPosition(32.0f * m_col, 32.0f * m_row);
}

void Player::mmove(int x, int y)
{
  m_row += y;
  m_col += x;
  setPosition(32.0f * m_col, 32.0f * m_row);
}
