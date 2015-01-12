_pos = _this select 0;

_initialSpeed = 50;
_gravityEffect = -8.9;
_terminalSpeed = -15;


_flare = "HEHU_TF_40mm_White" createVehicle [_pos select 0, _pos select 1, (_pos select 2) + 2];

_speed = _initialSpeed;
_flare setVelocity [0, 0, _speed];

while { _speed >= _terminalSpeed } do {
	_speed = _speed + (_gravityEffect / 10.0);
	_flare setVelocity [0, 0, _speed];
	sleep 0.1;
};