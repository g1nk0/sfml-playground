#include <iostream>
#include "Game.hpp"
#include "ResourceManager.hpp"

Game::Game() : m_window(sf::VideoMode(640, 480), "RougeLike"),
	       m_player(2, 2)
{
  loadResources();
  initActors();
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
  m_actors.push_back(m_player);
}

void Game::run()
{
  while (m_window.isOpen())
    {
      sf::Event event;
      while (m_window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    {
	      m_window.close();
	    }
	  if (event.type == sf::Event::KeyReleased)
	    {
	      switch (event.key.code)
		{
		case sf::Keyboard::A:
		  std::cout << "key a was pressed" << std::endl;
		  m_player.mmove(-1, 0);
		  break;

		case sf::Keyboard::D:
		  std::cout << "key 'd' was pressed" << std::endl;
		  m_player.mmove(1, 0);
		  break;

		case sf::Keyboard::Q:
		  m_window.close();
		  break;
		}
	    }
	}

      m_player.move(10.0f, 10.0f);
      m_window.clear();
      for (const auto& x : m_actors)
	{
	  m_window.draw(x);
	}

      m_window.display();
    }
}
