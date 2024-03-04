#pragma once
#include <string>
#include <vector>

namespace Data
{
class Entity
{
 public:
  
  std::string Name;
  int Age;

  explicit Entity( unsigned int objectID );
  ~Entity();
  Entity(const Data::Entity& other);
  Entity& operator=(const Entity& other);
  Entity(Entity&& other) noexcept;
  Entity& operator=(Entity&& other) noexcept;

  unsigned int GetObjectID();

private:
  unsigned int m_ObjectID;
};

class DataStore
{
 public:
  std::vector< Entity* > Storage;

  DataStore();
  ~DataStore();
  DataStore(const DataStore&) = delete; // no copies
  DataStore& operator=(const DataStore&) = delete; // no self-assignments

  void LoadSampleData();
  Data::Entity* AddEntity();
  void RemoveEntity( Data::Entity* entityToRemove );

 private:
  unsigned int m_Next_ObjectID;
};
}  // namespace App