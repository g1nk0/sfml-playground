#include <iostream>
#include "Game.hpp"
#include "ResourceManager.hpp"

Game::Game() : m_window(sf::VideoMode(640, 480), "RougeLike"),
	       m_view(sf::FloatRect(0, 0, 640, 480)),
	       m_player(2, 2)
{
  m_window.setVerticalSyncEnabled(true);
  loadResources();
  initActors();
  m_time_since_last_press = -0.1f;
}

void Game::loadResources()
{
  theResource.loadTexture("./assets/images/floor_tile_2.png", "floor_0");
  theResource.loadTexture("./assets/images/floor_tile.png", "floor_1");
  theResource.loadTexture("./assets/images/cultist.png", "cultist");
}

void Game::initActors()
{
  for (int i = 0; i < 640 / 32; i++)
    {
      for (int j = 0; j < 480 / 32; j++)
	{
	  sf::Sprite s(theResource.getTexture("floor_" + std::to_string((i + j) % 2)));
	  s.setPosition(32.0f * i, 32.0f * j);

	  m_actors.push_back(s);
	}
    }
  m_player.myinit();
  m_view.setCenter(m_player.getPosition());
  m_window.setView(m_view);
}

void Game::update(float dt)
{ 
  if (m_time_since_last_press > 0)
    {
      m_time_since_last_press -= dt;
    }
}

void Game::processEvents()
{
  sf::Event event;
  while (m_window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	{
	  m_window.close();
	}
      if (event.type == sf::Event::KeyPressed && m_time_since_last_press <= 0)
	{
	  m_time_since_last_press = 0.14f;
	  switch (event.key.code)
	    {
	    case sf::Keyboard::Q:
	      m_window.close();
	      break;

	    case sf::Keyboard::A:
	      m_player.mmove(-1, 0);
	      break;

	    case sf::Keyboard::D:
	      m_player.mmove(1, 0);
	      break;

	    case sf::Keyboard::W:
	      m_player.mmove(0, -1);
	      break;

	    case sf::Keyboard::S:
	      m_player.mmove(0, 1);
	      break;

	    }
	  m_view.setCenter(m_player.getPosition());
	}
    }
}

void Game::render()
{
  m_window.clear();
  m_window.setView(m_view);
  for (auto& x : m_actors)
    {
      m_window.draw(x);
    }
  m_window.draw(m_player);
  m_window.display();
}

void Game::run()
{
  sf::Clock clock;
  sf::Time dt;
  while (m_window.isOpen())
    {
      dt = clock.restart();
      processEvents();
      update(dt.asSeconds());
      render();
    }
}
