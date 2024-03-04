#include "MainApp.h"
#include <imgui_stdlib.h>

#include "FirstWindow.h"

void App::MainApp::Startup()
{
  // Here's where you do all your start up stuff that needs to happen
}

void App::MainApp::Update()
{
  this->ShowDockWindow();
  this->ShowMainWindow();
  
  // Show the first window
  App::ShowFirstWindow( this->m_sampleData, show_first_window );
}

void App::MainApp::Cleanup()
{
  // Clean up everything you did in start up here
}

void App::MainApp::ShowDockWindow()
{
  ImGui::DockSpaceOverViewport( ImGui::GetMainViewport() );
}

void App::MainApp::ShowMainWindow()
{
  ImGui::SetNextWindowSize( ImVec2( 800, 600 ), ImGuiCond_FirstUseEver );
  static ImGuiWindowFlags flags =
      ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings;
  const ImGuiViewport* viewport = ImGui::GetMainViewport();

  // Make the menu bar
  if( ImGui::BeginMainMenuBar() ) {
    if( ImGui::BeginMenu( "File" ) ) {
      ImGui::MenuItem( "##FileMenu", NULL, false, false );
      if( ImGui::MenuItem( "Close", "Ctrl+O" ) ) {
      }
      ImGui::EndMenu();
    }
    if( ImGui::BeginMenu( "View" ) ) {
      ImGui::MenuItem( "Sample Data Window", NULL, &this->show_first_window );
      ImGui::EndMenu();
    }
    ImGui::EndMainMenuBar();
  }
}