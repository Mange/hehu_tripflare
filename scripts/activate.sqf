_pos = _this select 0;
_flare = _this select 1;

// First, determine the mine disappeared because it was triggered and not that it was disarmed.
// To do this, we need to find "weaponholders" which is the class used for items laying on the ground.
_deactivatedMinesPresent = false;
_safetyRadius = 2;
{
	// For each weaponholder, make sure none of them contain any mine.
	if ("HEHU_FlareTripMine_Wire_Mag" in magazineCargo _x) exitWith { _deactivatedMinesPresent = true; };
} foreach (_pos nearObjects ["weaponholder", _safetyRadius]);

if (_deactivatedMinesPresent) exitWith {};

_initialSpeed = 50;
_gravityEffect = -8.9;
_terminalSpeed = -12;


_flare = _flare createVehicle [_pos select 0, _pos select 1, (_pos select 2) + 2];

_speed = _initialSpeed;
_flare setVelocity [0, 0, _speed];

while { _speed >= _terminalSpeed } do {
	_speed = _speed + (_gravityEffect / 10.0);
	_flare setVelocity [0, 0, _speed];
	sleep 0.1;
};