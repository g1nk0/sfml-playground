#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.hpp"

class Game
{
public:
  Game();
  void run();

private:
  void loadResources();
  void initActors();
  
private:
  sf::RenderWindow m_window;
  Player m_player;
  std::vector<sf::Sprite> m_actors;
};
