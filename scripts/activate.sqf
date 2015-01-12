_pos = _this select 0;
_flare = _this select 1;

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