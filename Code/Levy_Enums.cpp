#pragma once

/* Here Levy-specific enums can be placed.

*/

//Used partially for identification but also for simplified creation
enum UnitType {
	Peasant = 0,
	Levy = 1,
	ManAtArms = 2,
	Soldier = 3,
	Knight = 4,
	Retinue = 5
};


//Attack mechanics. OBS: Not same as attack type
enum AttackMech {
	ShortMelee, //Swords, axes etc
	LongMelee, //Pikes, halberds, greatweapons
	Thrown, //Javelin, rocks
	Bow, //Duh
	Crossbow, //Once again, duh. Also Ballistae
	Rifle //If I ever get around to implementing it.
};

enum DamageType {
	Slashing, //Swords, axes
	Piercing, //Pikes, halberds, arrows
	Bludgeoning, //Clubs, maces, rocks
	Fire, //Fire arrows, flaming oil
	Shock //Cavalry charges, siege weapons
};