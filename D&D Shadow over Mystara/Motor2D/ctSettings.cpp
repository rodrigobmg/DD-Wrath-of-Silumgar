#include "ctDefs.h"
#include "ctLog.h"
#include "ctApp.h"
#include "ctInput.h"
#include "ctTextures.h"
#include "ctAudio.h"
#include "ctRender.h"
#include "ctWindow.h"
#include "ctEntities.h"
#include "ctCombat.h"
#include "ctMainMenu.h"
#include "ctAbout.h"


#include "ctSettings.h"

#include "ctFadeToBlack.h"



ctSettings::ctSettings() : ctModule()
{
	name = "main_menu";
}

// Destructor
ctSettings::~ctSettings()
{}

// Called before render is available

bool ctSettings::Awake()
{
	LOG("Loading Main Menu");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool ctSettings::Start()
{
	bool ret = true;
	
	//music_volume = App->gui->AddUILabel(40, 45, "Music volume", { 255,255,255,255 }, nullptr);
	//fx_volume = App->gui->AddUILabel(40, 90, "Fx volume", { 255,255,255,255 }, nullptr);
	//if (!App->audio->PlayMusic("audio/music/Visager_End_Credits.ogg")) {
	//	//ret = false;
	//	LOG("Error playing music in j1MainMenu Start");
	//}

	return ret;
}

// Called each loop iteration
bool ctSettings::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool ctSettings::Update(float dt)
{
	if (App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		this->quit_pressed = true;

	if (first_update == true)
	{
		music_volume = App->gui->AddUILabel(40, 45, "Music volume", { 255,255,255,255 }, nullptr);
		fx_volume = App->gui->AddUILabel(40, 90, "Fx volume", { 255,255,255,255 }, nullptr);
		back = App->gui->AddUILabel(40, 135, "Back", { 255,255,255,255 }, nullptr);

		first_update = false;

	}
	//if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN && App->fadeToBlack->FadeIsOver())
	//App->fadeToBlack->FadeToBlackBetweenModules(this, this, 1.0f);

	return true;
}

// Called each loop iteration
bool ctSettings::PostUpdate()
{
	bool ret = true;

	if (quit_pressed)
		ret = false;

	return ret;
}

// Called before quitting
bool ctSettings::CleanUp()
{
	LOG("Freeing main_menu");

	return true;
}

bool ctSettings::Load(pugi::xml_node& load)
{
	bool ret = true;

	return ret;
}

bool ctSettings::Save(pugi::xml_node& save) const
{
	bool ret = true;

	return ret;
}

void ctSettings::OnUITrigger(UIElement* elementTriggered, UI_State ui_state)
{

}