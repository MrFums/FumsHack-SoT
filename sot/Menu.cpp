#include "Menu.h"


cMenu* Menu = new cMenu();

void cMenu::DrawMenu()
{

}

void cDrawing::Draw()
{
	Cheat->readData();
	//
	static int counter = 0;
	static float colors[3] = { 1.f, 0.f, 0.f };

	if (colors[counter] >= 1.0f)
	{
		colors[counter] = 1.0f;
		counter += 1;
		if (counter > 2)
			counter = 0;
	}
	else
	{
		int prev = counter - 1;
		if (prev < 0) prev = 2;
		colors[prev] -= 0.05f;
		colors[counter] += 0.05f;
	}
	//
	String(std::string("FumsHack External v1.1.0").c_str(), 10, Process->Size[1] - 20, D3DCOLOR_XRGB(255, 223, 0), false, "small");

	if (Vars.ESP.MenuV2.MenuActive)
		String(std::string("HOME » Active  » Menu").c_str(), 135, Process->Size[1] - 20, D3DCOLOR_XRGB(61, 168, 71), false, "small");
	else
		String(std::string("HOME » Disabled » Menu").c_str(), 135, Process->Size[1] - 20, D3DCOLOR_XRGB(171, 58, 75), false, "small");

	String(std::string("END » Terminate Menu").c_str(), 255, Process->Size[1] - 20, D3DCOLOR_XRGB(255, 0, 0), false, "small");
	//FPS
	String(std::to_string(directX->frames).c_str(), Process->Size[0] - 80, Process->Size[1] - 20, D3DCOLOR_XRGB(228, 86, 60), false, "small");
	String(std::string("ACTUAL FPS").c_str(), Process->Size[0] - 63, Process->Size[1] - 20, D3DCOLOR_XRGB(255, 0, 0), false, "small");

	//


	if (Vars.GUI)
	{
		//MAIN MENU
		if (Vars.ESP.MenuV2.MenuActive && !Vars.ESP.MenuV2.F1 && !Vars.ESP.MenuV2.F2 && !Vars.ESP.MenuV2.F3 && !Vars.ESP.MenuV2.F4 && !Vars.ESP.MenuV2.F5 && !Vars.ESP.MenuV2.F6 && !Vars.ESP.MenuV2.F7)
		{
			String(std::string("F1 » Show » General").c_str(), 10, 100, D3DCOLOR_XRGB(255, 255, 153), false, "small");
			String(std::string("F2 » Show » Entity ESP").c_str(), 10, 115, D3DCOLOR_XRGB(255, 255, 153), false, "small");
			String(std::string("F3 » Show » Treasures").c_str(), 10, 130, D3DCOLOR_XRGB(255, 255, 153), false, "small");
			String(std::string("F4 » Show » Events").c_str(), 10, 145, D3DCOLOR_XRGB(255, 255, 153), false, "small");
			String(std::string("F5 » Show » Ships").c_str(), 10, 160, D3DCOLOR_XRGB(255, 255, 153), false, "small");
		}

		//F1
		if (Vars.ESP.MenuV2.MenuActive && Vars.ESP.MenuV2.F1)
		{
			if (Vars.ESP.MenuV2.F1)
				String(std::string("« F1 » Return").c_str(), 10, 100, D3DCOLOR_XRGB(128, 128, 128), false, "small");

			if (Menu->menuOpen)
				String(std::string("1 » Active  » Player List Table").c_str(), 10, 115, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("1 » Disabled » Player List Table").c_str(), 10, 115, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.MapPins)
				String(std::string("2 » Active  » Map Pins").c_str(), 10, 130, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("2 » Disabled » Map Pins").c_str(), 10, 130, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.LoreBooks)
				String(std::string("3 » Active  » Journals").c_str(), 10, 145, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("3 » Disabled » Journals").c_str(), 10, 145, D3DCOLOR_XRGB(171, 58, 75), false, "small");
			
			if (Vars.ESP.MenuTake.ObjectsWrecks)
				String(std::string("4 » Active  » Ship Wrecks").c_str(), 10, 160, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("4 » Disabled » Ship Wrecks").c_str(), 10, 160, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuV2.F1)
				String(std::string("5 » Save Config").c_str(), 10, 175, D3DCOLOR_XRGB(163, 116, 219), false, "small");

			if (Vars.ESP.MenuV2.F1)
				String(std::string("6 » Reload Config").c_str(), 10, 190, D3DCOLOR_XRGB(163, 116, 219), false, "small");

		}

		//F2
		if (Vars.ESP.MenuV2.MenuActive && Vars.ESP.MenuV2.F2)
		{
			if (Vars.ESP.MenuV2.F2)
				String(std::string("« F2 » Return").c_str(), 10, 100, D3DCOLOR_XRGB(128, 128, 128), false, "small");

			if (Vars.ESP.MenuTake.PlayerEnemy)
				String(std::string("1 » Active  » Enemies ESP").c_str(), 10, 115, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("1 » Disabled » Enemies ESP").c_str(), 10, 115, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.PlayerAlly)
				String(std::string("2 » Active  » Allies ESP").c_str(), 10, 130, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("2 » Disabled » Allies ESP").c_str(), 10, 130, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.PlayerHPBar)
				String(std::string("3 » Active  » Player's Health Bar").c_str(), 10, 145, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("3 » Disabled » Player's Health Bar").c_str(), 10, 145, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.PlayerName)
				String(std::string("4 » Active  » Player's Name").c_str(), 10, 160, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("4 » Disabled » Player's Name").c_str(), 10, 160, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.PlayerItem)
				String(std::string("5 » Active  » Player's Current Item").c_str(), 10, 175, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("5 » Disabled » Player's Current Item").c_str(), 10, 175, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.Skeleton)
				String(std::string("6 » Active  » Skeletons ESP").c_str(), 10, 190, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("6 » Disabled » Skeletons ESP").c_str(), 10, 190, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.SkeletonName)
				String(std::string("7 » Active  » Skeleton's Name").c_str(), 10, 205, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("7 » Disabled » Skeleton's Name").c_str(), 10, 205, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.SkeletonItem)
				String(std::string("8 » Active  » Skeleton's Current Item").c_str(), 10, 220, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("8 » Disabled » Skeleton's Current Item").c_str(), 10, 220, D3DCOLOR_XRGB(171, 58, 75), false, "small");

		}

	

		//F3
		if (Vars.ESP.MenuV2.MenuActive && Vars.ESP.MenuV2.F3)
		{
			if (Vars.ESP.MenuV2.F3)
				String(std::string("« F3 » Return").c_str(), 10, 100, D3DCOLOR_XRGB(128, 128, 128), false, "small");

			if (Vars.ESP.MenuTake.ItemsUtility)
				String(std::string("1 » Active  » Gunpowder Barrels").c_str(), 10, 115, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("1 » Disabled » Gunpowder Barrels").c_str(), 10, 115, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.ItemsBarrels)
				String(std::string("2 » Active  » Barrels in Water").c_str(), 10, 130, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("2 » Disabled » Barrels in Water").c_str(), 10, 130, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.ItemsOther)
				String(std::string("3 » Active  » Others (e.g. Ammo Crate)").c_str(), 10, 145, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("3 » Disabled » Others (e.g. Ammo Crate)").c_str(), 10, 145, D3DCOLOR_XRGB(171, 58, 75), false, "small");
		}
		
		//F4
		if (Vars.ESP.MenuV2.MenuActive && Vars.ESP.MenuV2.F4)
		{
			if (Vars.ESP.MenuV2.F4)
				String(std::string("« F4 » Return").c_str(), 10, 100, D3DCOLOR_XRGB(128, 128, 128), false, "small");

			if (Vars.ESP.MenuTake.EventsFort)
				String(std::string("1 » Active  » World Events").c_str(), 10, 115, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("1 » Disabled » World Events").c_str(), 10, 115, D3DCOLOR_XRGB(171, 58, 75), false, "small");
		}
		
		//F5
		if (Vars.ESP.MenuV2.MenuActive && Vars.ESP.MenuV2.F5)
		{
			if (Vars.ESP.MenuV2.F5)
				String(std::string("« F5 » Return").c_str(), 10, 100, D3DCOLOR_XRGB(128, 128, 128), false, "small");

			if (Vars.ESP.MenuTake.ShipsEnemy)
				String(std::string("1 » Active  » Enemy Ships").c_str(), 10, 115, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("1 » Disabled » Enemy Ships").c_str(), 10, 115, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.ShipsAlly)
				String(std::string("2 » Active  » Ally Ships").c_str(), 10, 130, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("2 » Disabled » Ally Ships").c_str(), 10, 130, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.ShipsRowboat)
				String(std::string("3 » Active  » Rowboats").c_str(), 10, 145, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("3 » Disabled » Rowboats").c_str(), 10, 145, D3DCOLOR_XRGB(171, 58, 75), false, "small");

			if (Vars.ESP.MenuTake.ShipsGhost)
				String(std::string("4 » Active  » Ghost Ships").c_str(), 10, 160, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			else
				String(std::string("4 » Disabled » Ghost Ships").c_str(), 10, 160, D3DCOLOR_XRGB(171, 58, 75), false, "small");
		}
	

		//LEGEND
		//if (Vars.ESP.MenuTake.ColorsLegend) {);
		//	String(std::string("» Enemies").c_str(), 10, Process->Size[1] - 65, D3DCOLOR_XRGB(Vars.ESP.MenuTake.EnemyColor[0], Vars.ESP.MenuTake.EnemyColor[1], Vars.ESP.MenuTake.EnemyColor[2], Vars.ESP.MenuTake.EnemyColor[3]), false, "small");
		//}
	}

	/*
	if (Vars.GUI)
	{
		if (Menu->menuOpen)
			String(std::string("F1 » Active  » Players List").c_str(), 10, 10, D3DCOLOR_XRGB(61, 168, 71), false, "small");
		else
			String(std::string("F1 » Disabled » Players List").c_str(), 10, 10, D3DCOLOR_XRGB(171, 58, 75), false, "small");

		if (Vars.ESP.Animals.bActive)
			String(std::string("F2 » Active  » Animals").c_str(), 10, 25, D3DCOLOR_XRGB(61, 168, 71), false, "small");
		else
			String(std::string("F2 » Disabled » Animals").c_str(), 10, 25, D3DCOLOR_XRGB(171, 58, 75), false, "small");

		if (Vars.ESP.Player.bActive)
			String(std::string("F3 » Active  » Players").c_str(), 10, 40, D3DCOLOR_XRGB(61, 168, 71), false, "small");
		else
			String(std::string("F3 » Disabled » Players").c_str(), 10, 40, D3DCOLOR_XRGB(171, 58, 75), false, "small");

		if (Vars.ESP.Ships.bActive)
			String(std::string("F4 » Active  » Ships").c_str(), 10, 55, D3DCOLOR_XRGB(61, 168, 71), false, "small");
		else
			String(std::string("F4 » Disabled » Ships").c_str(), 10, 55, D3DCOLOR_XRGB(171, 58, 75), false, "small");

		if (Vars.ESP.Treasure.bActive)
			String(std::string("F5 » Active  » Treasures").c_str(), 10, 70, D3DCOLOR_XRGB(61, 168, 71), false, "small");
		else
			String(std::string("F5 » Disabled » Treasures").c_str(), 10, 70, D3DCOLOR_XRGB(171, 58, 75), false, "small");

		if (Vars.ESP.Objects.bActive)
			String(std::string("F6 » Active  » Objects").c_str(), 10, 85, D3DCOLOR_XRGB(61, 168, 71), false, "small");
		else
			String(std::string("F6 » Disabled » Objects").c_str(), 10, 85, D3DCOLOR_XRGB(171, 58, 75), false, "small");

		if (Vars.ESP.Legend.bActive) {
			String(std::string("F7 » Active  » Colors Legend").c_str(), 10, 100, D3DCOLOR_XRGB(61, 168, 71), false, "small");
			String(std::string("» Common").c_str(), 24, 113, D3DCOLOR_XRGB(Vars.ESP.colorCommon[0], Vars.ESP.colorCommon[1], Vars.ESP.colorCommon[2], Vars.ESP.colorCommon[3]), false, "small");
			String(std::string("» Rare").c_str(), 24, 125, D3DCOLOR_XRGB(Vars.ESP.colorRare[0], Vars.ESP.colorRare[1], Vars.ESP.colorRare[2], Vars.ESP.colorRare[3]), false, "small");
			String(std::string("» Mythical").c_str(), 24, 137, D3DCOLOR_XRGB(Vars.ESP.colorMythical[0], Vars.ESP.colorMythical[1], Vars.ESP.colorMythical[2], Vars.ESP.colorMythical[3]), false, "small");
			String(std::string("» Legendary").c_str(), 24, 149, D3DCOLOR_XRGB(Vars.ESP.colorLegendary[0], Vars.ESP.colorLegendary[1], Vars.ESP.colorLegendary[2], Vars.ESP.colorLegendary[3]), false, "small");
			String(std::string("» Special").c_str(), 24, 161, D3DCOLOR_XRGB(Vars.ESP.colorSpecial[0], Vars.ESP.colorSpecial[1], Vars.ESP.colorSpecial[2], Vars.ESP.colorSpecial[3]), false, "small");
			String(std::string("» Other").c_str(), 24, 173, D3DCOLOR_XRGB(Vars.ESP.colorOther[0], Vars.ESP.colorOther[1], Vars.ESP.colorOther[2], Vars.ESP.colorOther[3]), false, "small");
			String(std::string("» Ghost Ship").c_str(), 24, 185, D3DCOLOR_XRGB(Vars.ESP.colorGhostShip[0], Vars.ESP.colorGhostShip[1], Vars.ESP.colorGhostShip[2], Vars.ESP.colorGhostShip[3]), false, "small");
			String(std::string("» Objects").c_str(), 24, 197, D3DCOLOR_XRGB(Vars.ESP.Objects.colorObjects[0], Vars.ESP.Objects.colorObjects[1], Vars.ESP.Objects.colorObjects[2], Vars.ESP.Objects.colorObjects[3]), false, "small");
			String(std::string("» Map Pin").c_str(), 24, 209, D3DCOLOR_XRGB(Vars.ESP.colorPins[0], Vars.ESP.colorPins[1], Vars.ESP.colorPins[2], Vars.ESP.colorPins[3]), false, "small");
		}
		else {
			String(std::string("F7 » Disabled » Colors Legend").c_str(), 10, 100, D3DCOLOR_XRGB(171, 58, 75), false, "small");
		}
		*/

	Line(Process->Size[0]/2 - 5, Process->Size[1]/2, Process->Size[0]/2 + 5, Process->Size[1]/2, D3DCOLOR_XRGB(171, 58, 75));
	Line(Process->Size[0]/2, Process->Size[1]/2-5, Process->Size[0]/2, Process->Size[1]/2+5, D3DCOLOR_XRGB(171, 58, 75));

	if (Menu->menuOpen)
	DrawScoreBoard(Process->Size[0]-300, Process->Size[1] - 380, Cheat->Crews);

	Menu->DrawMenu();
}
