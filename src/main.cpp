#include <rw.h>
#include <skeleton.h>
#include <assert.h>
#include <stdio.h> // For printf
#include "PhysicsTestApp.h"

rw::V3d zero = { 0.0f, 0.0f, 0.0f };
struct SceneGlobals {
	rw::World* world;
	rw::Camera* camera;
} Scene;
rw::EngineOpenParams engineOpenParams;

int selectedOption = 0;
const char* menuItems[] = {
	"Physics Test",
	"Option 2",
	"Option 3"
};
const int numMenuItems = sizeof(menuItems) / sizeof(menuItems[0]);
bool menuActive = true;

typedef sk::EventStatus(*CurrentAppEventHandler)(sk::Event e, void* param);
CurrentAppEventHandler currentAppEventHandler = nullptr;

// --- Callback Functions ---
void OptionPhysicsTest()
{
	menuActive = false;
	currentAppEventHandler = PhysicsTestApp::AppEventHandler;
	currentAppEventHandler(sk::INITIALIZE, nullptr);
}

void Option2()
{
}

void Option3()
{
	//sk::globals.quit = 1; // Quit the application
}

// Helper to call the correct callback
void TriggerSelectedAction(int optionIndex) {
	if (!menuActive) return; // Only trigger if menu is active

	printf("Action triggered for option: %s\n", menuItems[optionIndex]);
	switch (optionIndex) {
	case 0:
		OptionPhysicsTest();
		break;
	case 1:
		Option2();
		break;
	case 2:
		Option3();
		break;
	default:
		printf("Warning: Unknown option index %d\n", optionIndex);
		break;
	}
}


void
Init(void)
{
	sk::globals.windowtitle = "B3";
	sk::globals.width = 1280;
	sk::globals.height = 800;
	sk::globals.quit = 0;
}

bool
attachPlugins(void)
{
	rw::ps2::registerPDSPlugin(40);
	rw::ps2::registerPluginPDSPipes();

	rw::registerMeshPlugin();
	rw::registerNativeDataPlugin();
	rw::registerAtomicRightsPlugin();
	rw::registerMaterialRightsPlugin();
	rw::xbox::registerVertexFormatPlugin();
	rw::registerSkinPlugin();
	rw::registerUserDataPlugin();
	rw::registerHAnimPlugin();
	rw::registerMatFXPlugin();
	rw::registerUVAnimPlugin();
	rw::ps2::registerADCPlugin();
	return true;
}

bool
InitRW(void)
{
	if (!sk::InitRW())
		return false;

	Scene.world = rw::World::create();

	//rw::Light* ambient = rw::Light::create(rw::Light::AMBIENT);
	//ambient->setColor(0.3f, 0.3f, 0.3f); // Slightly brighter ambient
	//Scene.world->addLight(ambient);

	//rw::V3d xaxis = { 1.0f, 0.0f, 0.0f };
	//rw::Light* direct = rw::Light::create(rw::Light::DIRECTIONAL);
	//direct->setColor(0.7f, 0.7f, 0.7f); // Slightly dimmer direct
	//direct->setFrame(rw::Frame::create());
	//direct->getFrame()->rotate(&xaxis, 180.0f, rw::COMBINEREPLACE);
	//Scene.world->addLight(direct);

	Scene.camera = sk::CameraCreate(sk::globals.width, sk::globals.height, 1);
	Scene.world->addCamera(Scene.camera);

	ImGui_ImplRW_Init();
	ImGui::StyleColorsDark(); // Using Dark style for a change

	return true;
}

void
Draw(float timeDelta)
{
	static ImVec4 clear_color = ImVec4(0.1f, 0.1f, 0.15f, 1.00f); // Darker background
	rw::RGBA clearcol = rw::makeRGBA(clear_color.x * 255, clear_color.y * 255, clear_color.z * 255, clear_color.w * 255);

	Scene.camera->clear(&clearcol, rw::Camera::CLEARIMAGE | rw::Camera::CLEARZ);
	Scene.camera->beginUpdate();

	ImGui_ImplRW_NewFrame(timeDelta);

	if (menuActive) {
		ImGuiIO& io = ImGui::GetIO();
		ImVec2 window_pos = ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f);
		ImVec2 window_pos_pivot = ImVec2(0.5f, 0.5f);
		ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
		ImGui::SetNextWindowBgAlpha(0.85f); // Slightly transparent background

		ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar |
			ImGuiWindowFlags_NoResize |
			ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_AlwaysAutoResize |
			ImGuiWindowFlags_NoSavedSettings |
			ImGuiWindowFlags_NoFocusOnAppearing | // Don't steal focus initially
			ImGuiWindowFlags_NoNav;               // We handle nav manually

		if (ImGui::Begin("Main Menu", &menuActive, window_flags)) {
			ImGui::Text("Main Menu");
			ImGui::Separator();

			for (int i = 0; i < numMenuItems; ++i) {
				// Add " > " prefix to the selected item for visual cue
				char Aitem_label[128];
				if (selectedOption == i) {
					snprintf(Aitem_label, sizeof(Aitem_label), "> %s <", menuItems[i]);
				}
				else {
					snprintf(Aitem_label, sizeof(Aitem_label), "  %s  ", menuItems[i]);
				}


				if (ImGui::Selectable(Aitem_label, selectedOption == i, ImGuiSelectableFlags_DontClosePopups)) {
					selectedOption = i; // Update selection on click
					TriggerSelectedAction(selectedOption);
				}
				if (selectedOption == i) {
					ImGui::SetItemDefaultFocus(); // Important for ImGui's own focus logic if we were using it more
				}
			}
			ImGui::Separator();
			ImGui::Text("Use UP/DOWN Arrows & ENTER");

		}
		ImGui::End();
	}
	else {
		// If menu is not active, you could draw other ImGui elements or game UI
		ImGui::Begin("Game Active (Placeholder)");
		ImGui::Text("Menu is hidden. Game would be running here.");
		if (ImGui::Button("Show Menu")) {
			menuActive = true;
			selectedOption = 0; // Reset selection when showing menu again
		}
		ImGui::End();
	}


	ImGui::EndFrame();
	ImGui::Render();

	ImGui_ImplRW_RenderDrawLists(ImGui::GetDrawData());

	Scene.camera->endUpdate();
	Scene.camera->showRaster(0);
}


void
KeyUp(int key)
{
	// Not used in this example for menu navigation
}

void
KeyDown(int key)
{
	if (!menuActive) { // If menu is not active, handle other keys or pass through
		if (key == sk::KEY_ESC) sk::globals.quit = 1;
		return;
	}

	switch (key) {
	case sk::KEY_ESC:
		// OptionExit(); // Or just toggle menuActive
		menuActive = false; // Example: ESC hides the menu
		break;
	case sk::KEY_UP:
		selectedOption--;
		if (selectedOption < 0) {
			selectedOption = numMenuItems - 1;
		}
		printf("Key UP, selected: %d\n", selectedOption);
		break;
	case sk::KEY_DOWN:
		selectedOption++;
		if (selectedOption >= numMenuItems) {
			selectedOption = 0;
		}
		printf("Key DOWN, selected: %d\n", selectedOption);
		break;
	case sk::KEY_ENTER:
		printf("Key ENTER/SPACE on option: %d\n", selectedOption);
		TriggerSelectedAction(selectedOption);
		break;
	}
}

sk::EventStatus
AppEventHandler(sk::Event e, void* param)
{
	using namespace sk;
	Rect* r;

	// Allow ImGui to handle its events first (e.g., mouse input for its widgets)
	// But be careful, as it might consume key events we want for menu navigation.
	// For this specific menu, we handle keys directly in KeyDown.
	// If you had text input fields in ImGui, you'd want ImGui to get those key events.
	//if (ImGui_ImplRW_ProcessEvent(e, param)) {
		// If ImGui consumed the event, and it was a keyboard/mouse event
		// relevant to an active ImGui widget (like a text box), we might want to return.
		// For simple selectables and our manual navigation, this is less critical.
	//}

	sk::EventStatus       result;
	sk::EventStatus       es;

	if (currentAppEventHandler)
	{
		result = currentAppEventHandler(e, param);
		if (result == sk::EVENTPROCESSED) {
			return result;
		}
		else if (result == sk::EVENTERROR) {
			return result;
		}
	}

	/*
	 * We never allow the app to replace the quit behaviour,
	 * only to intercept...
	 */
	 //if (e == rsQUITAPP)
	 //{
	 //	/*
	 //	 * Set the flag which causes the event loop to exit...
	 //	 */
	 //	sk::globals.quit = 1;
	 //}


	switch (e) {
	case INITIALIZE:
		Init();
		return EVENTPROCESSED;
	case RWINITIALIZE:
		return ::InitRW() ? EVENTPROCESSED : EVENTERROR;
	case PLUGINATTACH:
		return attachPlugins() ? EVENTPROCESSED : EVENTERROR;
	case KEYDOWN:
		KeyDown(*(int*)param);
		return EVENTPROCESSED;
	case KEYUP:
		KeyUp(*(int*)param);
		return EVENTPROCESSED;
	case RESIZE:
		r = (Rect*)param;
		if (r->w == 0) r->w = 1;
		if (r->h == 0) r->h = 1;

		/*sk::globals.width = r->w;
		sk::globals.height = r->h;
		if (Scene.camera)
			sk::CameraSize(Scene.camera, r);*/
		break;
	case IDLE:
		Draw(*(float*)param);
		return EVENTPROCESSED;
	}
	return sk::EVENTNOTPROCESSED;
}