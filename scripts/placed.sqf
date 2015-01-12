_mine = _this select 0;
_pos = getPos _mine;

_flare = switch(typeOf _mine) do {
	case "HEHU_FlareTripMine_Red_Wire_Ammo": { "HEHU_TF_40mm_Red" };
	case "HEHU_FlareTripMine_Yellow_Wire_Ammo": { "HEHU_TF_40mm_Yellow" };
	case "HEHU_FlareTripMine_Green_Wire_Ammo": { "HEHU_TF_40mm_Green" };
	case "HEHU_FlareTripMine_Blue_Wire_Ammo": { "HEHU_TF_40mm_Blue" };

	case "HEHU_FlareTripMine_Wire_Ammo";
	default { "HEHU_TF_40mm_White" };
};

waitUntil {isNull _mine};
[_pos, _flare] spawn HEHU_TripFlare_fnc_Activate;
