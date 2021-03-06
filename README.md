# @hehu_tripflare (Arma 3 addon)

> Trip-wire mines which shoots flares instead of 'asploading you.

## Why?

Use them to see enemy advancements instead of killing a few of them. A flare allows you to detect any number of units in a force, while an explosion is hard to locate and will only kill a handful at most.

## Status

This is my first Arma 3 mod. It's very much the work of an amateur.

There seems to be no way of detecting when a mine is detonated, so the script works in this way:

1. Find all mines on the map.
2. Spawn a function that waits for the mine to disappear.
	* When mine is gone, trigger detonation.
3. Attach event handler to player that repeats this on any newly placed mines.
	* This needs to be broadcast to every other player!

### Video

[![See video on YouTube.](http://img.youtube.com/vi/Q7QojMsZC7w/hqdefault.jpg)](https://www.youtube.com/watch?v=Q7QojMsZC7w)

### Problems

* When triggering a mine within 2 meters from a disabled mine, it does not fire a flare.
* Only the "owner" of the mine sees an explosion effect and hears the flare sound when a mine is triggered.

## Building

Check out the repository, make sure Arma 3 Tools from BIS is installed and copy `make.example.bat.txt` into `make.bat`, edit the paths in it and then run the batch file.

The finished mod will be placed in `target_directory` that you specify.

## Class names

### Magazine classes

Use them to add things to inventories.

`HEHU_FlareTripMine_Wire_Mag`
`HEHU_FlareTripMine_Red_Wire_Mag`
`HEHU_FlareTripMine_Yellow_Wire_Mag`
`HEHU_FlareTripMine_Green_Wire_Mag`
`HEHU_FlareTripMine_Blue_Wire_Mag`

### Ammo classes

Use them to find mines on the map, or to spawn them, I guess.

(Mines)
`HEHU_FlareTripMine_Wire_Ammo`
`HEHU_FlareTripMine_Red_Wire_Ammo`
`HEHU_FlareTripMine_Yellow_Wire_Ammo`
`HEHU_FlareTripMine_Green_Wire_Ammo`
`HEHU_FlareTripMine_Blue_Wire_Ammo`

(Flares)
`HEHU_TF_40mm_White`
`HEHU_TF_40mm_Red`
`HEHU_TF_40mm_Yellow`
`HEHU_TF_40mm_Green`
`HEHU_TF_40mm_Blue`

### Functions

**`HEHU_TripFlare_fnc_Placed`**

Call with the mine object inside an array to register a mine.

```sqf
[_mine] spawn HEHU_TripFlare_fnc_Placed;
```

**`HEHU_TripFlare_fnc_Activate`**

Fire a flare from the location provided.

```sqf
[getPos player, "HEHU_TF_40mm_Red"] spawn HEHU_TripFlare_fnc_Activate;
```

## Awknowledgements

Thanks to the following people, which I reverse-engineered stuff from:

* [Amit](http://forums.bistudio.com/member.php?130119-Amit): [[Tutorial] Simple Re-texturing Guide (From Start To Finish)](http://forums.bistudio.com/showthread.php?161027-Tutorial-Simple-Re-texturing-Guide-(From-Start-To-Finish)) - Thank you for telling me how to create a small addon, how to inherit the BIS stuff and patch them.
* [flyinpenguin](http://forums.bistudio.com/member.php?144624-flyinpenguin): [EMP Pack -WIP-](http://forums.bistudio.com/showthread.php?178067-EMP-Pack-WIP) - I would never have figured out how to run a script on mine detonation without this little addon. Thank you!

## Copyright

Uses assets from Bohemia Interactive. Everything belongs to them, as I claim no copyright over my work here.
