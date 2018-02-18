#include "ResourceManager.hpp"

ResourceManager& ResourceManager::getInstance()
{
  static ResourceManager instance;
  return instance;
}

void ResourceManager::loadTexture(const std::string& file, const std::string& name)
{
  sf::Texture tex;
  if (tex.loadFromFile(file))
    {
      m_textures[name] = tex;
    }
  else
    {
      throw std::runtime_error("ResourceManager::loadTexture -- can't load file");
    }
}

const sf::Texture& ResourceManager::getTexture(const std::string& name)
{
  return m_textures[name];
}
