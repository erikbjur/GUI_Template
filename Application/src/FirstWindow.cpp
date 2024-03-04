#include "FirstWindow.h"
#include <imgui.h>
#include <imgui_stdlib.h>

void App::ShowFirstWindow( Data::DataStore& dataStore,  bool& show_this_window ) {

   if( show_this_window ) {
      ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoCollapse;
      ImGui::SetNextWindowSize( ImVec2( 350, 300 ), ImGuiCond_FirstUseEver );

      ImGui::Begin( "First Window", &show_this_window, window_flags );
      const float TEXT_BASE_HEIGHT = ImGui::GetTextLineHeightWithSpacing();
      static ImGuiTableFlags flags = ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg
         | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV
         | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable
         | ImGuiTableFlags_Hideable;

      ImGui::Text( "Add a new Entity" );
      if( ImGui::Button( "Add" ) ) {
         // Add a new entity
      }

      if( ImGui::BeginTable( "Table of Entities", 3, flags ) ) {
         ImGui::TableSetupScrollFreeze( 0, 1 ); // Make top row always visible
         ImGui::TableSetupColumn( "Name", ImGuiTableColumnFlags_None );
         ImGui::TableSetupColumn( "Age", ImGuiTableColumnFlags_None );
         ImGui::TableSetupColumn( "X", ImGuiTableColumnFlags_None );
         ImGui::TableHeadersRow();

         //List Load Cases
         for( auto& entity : dataStore.Storage ) {
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::PushID( entity->GetObjectID() );
            ImGui::PushItemWidth( -1 );
            ImGui::InputText( "##Name", &entity->Name );
            ImGui::PopItemWidth();

            ImGui::TableNextColumn();
            ImGui::PushItemWidth( -1 );
            ImGui::InputInt( "##Age", &entity->Age );
            ImGui::PopItemWidth();

            ImGui::TableNextColumn();
            if( ImGui::Button( "X##DeleteEntity" ) ) {
               ImGui::OpenPopup( "Delete Entity" );
            }
            //Window location was defined in th center above.  Look for ImVec2 center
            if( ImGui::BeginPopupModal( "Delete Entity", NULL, ImGuiWindowFlags_AlwaysAutoResize ) ) {
               ImGui::Text( "Do you really want to delete this entity %s?\nOnce it's gone, it's really gone.", entity->Name.c_str() );
               ImGui::Separator();

               if( ImGui::Button( "OK", ImVec2( 120, 0 ) ) ) {
                  // Delete the entity
                  dataStore.RemoveEntity( entity );
                  // Close the popup window
                  ImGui::CloseCurrentPopup();
                  // We need to end the popup here because we're breaking out of the loop
                  ImGui::EndPopup();
                  // We need to pop the current row ID here because we're breaking out of the loop
                  ImGui::PopID();
                  // Break out of the loop
                  break;
               }
               ImGui::SameLine();
               if( ImGui::Button( "Cancel", ImVec2( 120, 0 ) ) ) {
                  ImGui::CloseCurrentPopup();
               }
               ImGui::EndPopup();
            }
            ImGui::PopID();
         }
         ImGui::EndTable();
      }
      ImGui::End();
   }
}