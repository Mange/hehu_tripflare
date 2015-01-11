hint str _this;

if (_this select 4 == "HEHU_FlareTripMine_Wire_Ammo") then {
	_mine = _this select 6;
	_pos = getPos _mine;

	[_pos] spawn HEHU_TripMine_fnc_Activate;
};