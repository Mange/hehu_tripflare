if (_this select 4 == "HEHU_FlareTripMine_Wire_Ammo") then {
	// TODO: Broadcast this to every player!
	_mine = _this select 6;
	[_mine] spawn HEHU_TripFlare_fnc_Placed;
};
