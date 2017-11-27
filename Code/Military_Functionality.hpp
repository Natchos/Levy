#pragma once

#include "Levy_Enums.cpp"

/* Contains information and charasteristics relating to a units military functionality
*/

class Military_Functionality
{
public:
	Military_Functionality(int bDamage, AttackMech aMech, DamageType dType, int bRange, double aArc, int bRecharge);

	int getBaseDamage();
	void setBaseDamage(int bDamage);
	AttackMech getAtkMech();
	void setAtkMech(AttackMech bMech);
	DamageType getDmgType();
	void setdmgType(DamageType bType);
	int getRange();
	void setRange(int bRange);
	double getAttackArc();
	void setAttackArc(double bArc);
	int getRecharge();
	void setRecharge(int bRecharge);

private:
	int baseDamage;
	AttackMech atkMech;
	DamageType dmgType;
	int range;
	double attackArc; //How far around its facing a unit can attack.
	int recharge; //In millis

};
