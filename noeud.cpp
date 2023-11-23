#include <math.h>
#include "point.h"
#include "noeud.h"

float Noeud::getCoutPointDepartNoeudSuivant()
{
	return coutPointDepartNoeudSuivant;
}
float Noeud::getCoutNoeudSuivantPointArrive()
{
	return coutNoeudSuivantPointArrive;
}
float Noeud::getCoutSomme()
{
	return coutSomme;
}
void Noeud::setCoutPointDepartNoeudSuivant(float coutG)
{
	coutPointDepartNoeudSuivant = coutG;
}
void Noeud::setCoutNoeudSuivantPointArrive(float coutH)
{
	coutNoeudSuivantPointArrive = coutH;
}
void Noeud::setCoutSomme(float coutF)
{
	coutSomme = coutF;
}