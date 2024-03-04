#include "SampleData.h"

#include <vector>

// Entity Implementation Below

// Constructor
Data::Entity::Entity( unsigned int objectID ) : m_ObjectID( objectID )
{
}

// Destructor
Data::Entity::~Entity()
{
}

// Copy Constructor
Data::Entity::Entity( const Data::Entity& other )
{
  // Perform a deep copy of resources here.
  Name = other.Name;
  Age = other.Age;
}

// Copy Assignment Operator
Data::Entity& Data::Entity::operator=( const Entity& other )
{
  // Avoid self-assignment.
  if( this != &other ) {
    Name = other.Name;
    Age = other.Age;
  }
  return *this;
}

// Move Constructor
Data::Entity::Entity( Entity&& other ) noexcept
{
  // Transfer ownership of resources here.
  Name = std::move( other.Name );
  Age = std::move( other.Age );
}

// Move Assignment Operator
Data::Entity& Data::Entity::operator=( Entity&& other ) noexcept
{
  if( this != &other ) {
    // Avoid self-assignment.
    Name = std::move( other.Name );
    Age = std::move( other.Age );
  }
  return *this;
}

unsigned int Data::Entity::GetObjectID()
{
  return this->m_ObjectID;
}
// End of Entity Implementation

// DataStore Implementation Below
// Constructor
Data::DataStore::DataStore() : m_Next_ObjectID( 0 )
{
  // Here's where I load some sample data
  this->LoadSampleData();
}

// Destructor
Data::DataStore::~DataStore()
{
  // Remove all Entities from storage that were created
  for( auto& entity : this->Storage ) {
    delete entity;
    entity = nullptr;
  }
}

void Data::DataStore::LoadSampleData()
{
  // Initialize data store with 3 Entities
  Data::Entity* entity = this->AddEntity();
  entity->Name = "Chuck";
  entity->Age = 20;

  entity = this->AddEntity();
  entity->Name = "Buck";
  entity->Age = 22;

  entity = this->AddEntity();
  entity->Name = "Bill";
  entity->Age = 24;
}

Data::Entity* Data::DataStore::AddEntity()
{
  // Increment the next object ID for the Data Store
  this->m_Next_ObjectID++;
  // Create the new entity
  Data::Entity* entity = new Entity( m_Next_ObjectID );
  // Push the entity into the storage
  this->Storage.push_back( entity );
  // The entity is a pointer, so return the pointer
  return entity;
}

void Data::DataStore::RemoveEntity( Data::Entity* entityToRemove )
{
  // Remove entity from storage
  std::erase( this->Storage, entityToRemove );

  // Delete the heap data used by the entity
  delete entityToRemove;
  entityToRemove = nullptr;
}

// End of DataStore Implementation