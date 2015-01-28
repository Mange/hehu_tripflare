if !(isDedicated) then {
	waitUntil {!isNull(findDisplay 46)};
	waitUntil {!isNull player};
	player addEventHandler ["fired", {_this spawn HEHU_TripFlare_fnc_Fired;}];
};

// Activate mines already on the map!
if (isServer) then {
	[] spawn {
		{ [_x] spawn HEHU_TripFlare_fnc_Placed; } foreach (allMissionObjects "HEHU_FlareTripMine_Wire_Ammo");
	};
};