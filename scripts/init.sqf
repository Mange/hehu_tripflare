if !(hasInterface) exitWith{};

waitUntil {!isNull(findDisplay 46)};
waitUntil {!isNull player};

player addEventHandler ["fired", {_this spawn HEHU_TripFlare_fnc_Fired;}];

// Activate mines already on the map!
[] spawn {
	// Scan for mines this far away from each player.
	_radius = 1500;
	{
		[_x] spawn HEHU_TripFlare_fnc_Placed;
	} foreach (player nearObjects ["HEHU_FlareTripMine_Wire_Ammo", _radius]);
};