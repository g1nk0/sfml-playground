#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
class ResourceManager : public sf::NonCopyable
{
public:
  static ResourceManager& getInstance();
  void loadTexture(const std::string& file, const std::string& name);
  const sf::Texture& getTexture(const std::string& name);
  
private:
  std::map<std::string, sf::Texture> m_textures;
};

#define theResource ResourceManager::getInstance()
