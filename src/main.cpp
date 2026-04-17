#include "raylib.h"
#include "raymath.h"

#include "imgui.h"
#include "rlImGui.h"


int main(int argc, char* argv[])
{
	int screenWidth = 1280;
	int screenHeight = 800;

	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(screenWidth, screenHeight, "LD59 - Mindrage");
	rlImGuiSetup(true);

	while (!WindowShouldClose()) 
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		rlImGuiBegin();

		ImGui::ShowDemoWindow();

		rlImGuiEnd();
		EndDrawing();
	}

    rlImGuiShutdown();
	CloseWindow();
	return 0;
}