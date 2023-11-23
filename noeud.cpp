#include <math.h>
#include "point.h"
#include "noeud.h"

float Noeud::getToDepart()
{
	return coutToDepart;
}
float Noeud::getToArrive()
{
	return coutToArrive;
}
float Noeud::getCoutSomme()
{
	return coutSomme;
}
void Noeud::setToDepart(float coutG)
{
	coutToDepart = coutG;
}
void Noeud::setToArrive(float coutH)
{
	coutToArrive = coutH;
}
void Noeud::setCoutSomme(float coutF)
{
	coutSomme = coutF;
}