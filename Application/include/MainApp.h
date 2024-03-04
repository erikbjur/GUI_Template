#pragma once

#include "BaseApplication.h"

#include "SampleData.h"

namespace App
{

class MainApp : public App::BaseApplication<MainApp>
{
 public:
  MainApp() = default;
  ~MainApp() = default;

  // Inherited via App but use CRTP to avoid virtual methods
  void Startup();
  void Update();
  void Cleanup();

 private:
  // State of what windows are open
  bool show_first_window = true;

  // Here the sample storage object
  Data::DataStore m_sampleData;

  void ShowDockWindow();
  void ShowMainWindow();

  // Show a floating window loaded with sample data
  void ShowFirstWindow();
};

}  // namespace App