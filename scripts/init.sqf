if !(hasInterface) exitWith{};

waitUntil {!isNull(findDisplay 46)};
waitUntil {!isNull player};

player addEventHandler ["fired", {_this spawn HEHU_TripFlare_fnc_Fired;}];