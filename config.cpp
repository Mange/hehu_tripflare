class CfgPatches
{
	class HEHU_TripFlare
	{
		units[]=
		{
			"HEHU_FlareTripMine"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Weapons_F_Explosives"
		};
	};
};

class CfgFunctions {
	class HEHU_TripFlare {
		class HEHU {
			class TripFlare_init {
				postInit=1;
				file = "hehu_tripflare\scripts\init.sqf";
			};
			class Fired {
				file = "hehu_tripflare\scripts\fired.sqf";
			};
			class Activate {
				file = "hehu_tripflare\scripts\activate.sqf";
			};
		};
	};
};

class CfgVehicles
{
	class APERSTripMine;
	class HEHU_FlareTripMine: APERSTripMine
	{
		author="Magnus Bergmark";
		_generalMacro="APERSTripMine";
		scope=2;
		ammo="HEHU_FlareTripMine_Wire_Ammo";
		displayName="Trip flare";
		icon="iconExplosiveAP";
		picture="\A3\Weapons_F\Data\clear_empty.paa";
		descriptionShort="$STR_A3_cfgMagazines_ClassicMineWireMagazine1";
		class Library
		{
			libTextDesc="$STR_A3_cfgMagazines_ClassicMineWireMagazine_Library0";
		};
	};
};

class cfgAmmo
{
	class PipeBombBase;
	class HEHU_FlareTripMine_Wire_Ammo: PipeBombBase
	{
		// Mine effect is triggered by script.

		hit=0;
		indirectHit=0;
		indirectHitRange=0;
		
		model="\A3\Weapons_F\explosives\mine_AP_tripwire";
		mineModelDisabled="\A3\Weapons_F\explosives\mine_AP_tripwire_d";

		defaultMagazine="HEHU_FlareTripMine_Wire_Mag";
		soundHit[]=
		{
			"A3\Sounds_F\weapons\mines\mine_3",
			3.1622777,
			1,
			1500
		};

		//explosionEffects="BoundingFlareExplosion";
		explosionEffects="";
		
		//CraterEffects="BoundingMineCrater";
		CraterEffects="";

		//mineJumpEffects="MineJumpEffect";
		whistleDist=60;
		cost=300;
		
		//mineBoundingTime=1.30000001;
		//mineBoundingDist=60;

		mineTrigger="WireTrigger";
		mineInconspicuousness=50;
	};
};

class cfgMagazines
{
	class ATMine_Range_Mag;
	class HEHU_FlareTripMine_Wire_Mag: ATMine_Range_Mag
	{
		mass=15;
		ammo="HEHU_FlareTripMine_Wire_Ammo";
		displayName="Trip flare";
		picture="\A3\Weapons_F\Data\UI\gear_mine_AP_tripwire_CA.paa";
		model="\A3\Weapons_F\explosives\mine_AP_tripwire_i";
		descriptionShort="Tripmine which ejects a flare with a small rocket.";
		// class Library
		// {
		// 	libTextDesc="$STR_A3_cfgMagazines_ClassicMineWireMagazine_Library0";
		// };
		descriptionUse="$STR_A3_use_mine";
		allowedSlots[]={901,701};
	};
};

class BoundingFlareExplosion {
	class LightExp {
		intensity = 0.001;
		interval = 1;
		lifetime = 0.5;
		position[] = {0, 1.5, 0};
		simulation = "light";
		type = "ExploLight";
	};
	// class Explosion1 {
	// 	intensity = 3;
	// 	interval = 1;
	// 	lifetime = 0.25;
	// 	position[] = {0, 0, 0};
	// 	simulation = "particles";
	// 	type = "MineExplosionParticles";
	// };
	class SmallSmoke1 {
		intensity = 1;
		interval = 1;
		lifetime = 1;
		position[] = {0, 0, 0};
		simulation = "particles";
		type = "CloudSmallLight1";
	};
	class FireSparksSmall1 {
		intensity = 1;
		interval = 1;
		lifetime = 1;
		position[] = {0, 0, 0};
		simulation = "particles";
		type = "FireSparksSmall1";
	};
};

// class BoundingMineExplosion {
// 	class LightExp {
// 		intensity = 0.001;
// 		interval = 1;
// 		lifetime = 0.5;
// 		position[] = {0, 1.5, 0};
// 		simulation = "light";
// 		type = "ExploLight";
// 	};
// 	class Explosion1 {
// 		intensity = 3;
// 		interval = 1;
// 		lifetime = 0.25;
// 		position[] = {0, 0, 0};
// 		simulation = "particles";
// 		type = "MineExplosionParticles";
// 	};
// 	class SmallSmoke1 {
// 		intensity = 1;
// 		interval = 1;
// 		lifetime = 1;
// 		position[] = {0, 0, 0};
// 		simulation = "particles";
// 		type = "CloudSmallLight1";
// 	};
// 	class FireSparksSmall1 {
// 		intensity = 1;
// 		interval = 1;
// 		lifetime = 1;
// 		position[] = {0, 0, 0};
// 		simulation = "particles";
// 		type = "FireSparksSmall1";
// 	};
// };