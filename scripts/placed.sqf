_mine = _this select 0;
_pos = getPos _mine;

waitUntil {isNull _mine};
[_pos] spawn HEHU_TripFlare_fnc_Activate;
