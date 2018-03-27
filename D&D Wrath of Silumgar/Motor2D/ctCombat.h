#ifndef __ctCOMBAT_H__
#define __ctCOMBAT_H__

#include "ctModule.h"

#include <string>

using namespace std;


class ctCombat : public ctModule
{
public:

	ctCombat();

	// Destructor
	virtual ~ctCombat();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	bool Load(pugi::xml_node&);

	bool Save(pugi::xml_node&) const;

	void OnUITrigger(UIElement* elementTriggered, UI_State ui_state);
	uint CalculatedDamage(Entity* attacker, Entity* defender);

public:

	void SetSceneName(string new_scene_name);

private:

	string scene_name;

};


#endif // __ctCOMBAT_H__