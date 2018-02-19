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
  void update(float dt);
  void processEvents();
  void render();
  
private:
  sf::RenderWindow m_window;
  sf::View m_view;
  Player m_player;
  std::vector<sf::Sprite> m_actors;
  float m_time_since_last_press;
};
