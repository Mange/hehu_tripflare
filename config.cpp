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
			"A3_Weapons_F_Explosives",
			"A3_Modules_F_Sites"
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
			class Placed {
				file = "hehu_tripflare\scripts\placed.sqf";
			};
			class Activate {
				file = "hehu_tripflare\scripts\activate.sqf";
			};
		};
	};
};

class CfgWeapons {
	class Default;
	class Put: Default
	{
		class ClassicMineRangeMuzzle;
		class ClassicMineWireMuzzle: ClassicMineRangeMuzzle
		{
			magazines[]= {
				"APERSTripMine_Wire_Mag",
				"HEHU_FlareTripMine_Wire_Mag"
			};
			displayName="$STR_A3_cfgMagazines_ClassicMineWireMagazine0";
		};
	};
};

class CfgVehicles
{
	class APERSTripMine;
	class Module_F;

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

	class Site_Minefield: Module_F
	{
		class Arguments
		{
			class minesType
			{
				class values
				{
					class HEHU_FlareTripMine
					{
						name="Trip flare";
						value="HEHU_FlareTripMine";
						default=0;
					};
				};
			};
		};
	};
};

class cfgAmmo
{
	class PipeBombBase;
	class F_40mm_White;

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
			//"A3\Sounds_F\weapons\mines\mine_3",
			"A3\Sounds_F\weapons\Flare_Gun\flaregun_1_shoot",
			3.1622777,
			1,
			1500
		};

		explosionEffects="BoundingFlareExplosion";
		
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

	class HEHU_TF_40mm_White: F_40mm_White
	{
		//model="\A3\Weapons_F\Ammo\UGL_Flare";
		//lightColor[]={0.5,0.5,0.5,0.5};
		//useFlare=1;
		//deflecting=30;
		//smokeColor[]={1,1,1,0.5};
		//effectFlare="CounterMeasureFlare";
		//brightness=12;
		//size=1;
		triggerTime=0.1;
		//triggerSpeedCoef=1;

		// From FlareBase:
		//timeToLive=25;
		timeToLive=50;
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