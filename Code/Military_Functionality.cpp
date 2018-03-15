#pragma once

#include "Military_Functionality.hpp"



Military_Functionality::Military_Functionality(int bDamage, AttackMech aMech, DamageType dType, int bRange, double aArc, int bRecharge) : baseDamage(bDamage), atkMech(aMech), dmgType(dType), range(bRange), attackArc(aArc), recharge(bRecharge)
{

}

Military_Functionality::Military_Functionality()
{
	baseDamage = 0;
	atkMech = AttackMech::ShortMelee;
	dmgType = DamageType::Bludgeoning;
	range = 1;
	attackArc = 1;
	recharge = 1000;
}

int Military_Functionality::getBaseDamage()
{
	return baseDamage;
}

void Military_Functionality::setBaseDamage(int bDamage)
{
	this->baseDamage = bDamage;
}

AttackMech Military_Functionality::getAtkMech()
{
	return atkMech;
}

void Military_Functionality::setAtkMech(AttackMech bMech)
{
	this->atkMech = bMech;

}

DamageType Military_Functionality::getDmgType()
{
	return dmgType;
}

void Military_Functionality::setdmgType(DamageType bType)
{
	this->dmgType = bType;
}

int Military_Functionality::getRange()
{
	return range;
}

void Military_Functionality::setRange(int bRange)
{
	this->range = bRange;
}

double Military_Functionality::getAttackArc()
{
	return attackArc;
}

void Military_Functionality::setAttackArc(double bArc)
{
	this->attackArc = bArc;
}

int Military_Functionality::getRecharge()
{
	return recharge;
}

void Military_Functionality::setRecharge(int bRecharge)
{
	this->recharge = bRecharge;
}