#include "MainApp.h"

//Need this line to make the console window disappear.
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main(void)
{
   App::MainApp app;
   app.Run();

   return 0;
}