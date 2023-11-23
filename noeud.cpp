#include <math.h>
#include "point.h"
#include "noeud.h"

//calcule la distance entre les points(x1, y1) et(x2, y2)
float distance(int x1, int y1, int x2, int y2) 
{
	/* distance euclidienne */
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

//float calculCout(int x1, int y1, int x2, int y2)
//{
//	float coutPoint = distance(x1, y1, x2, y2);
//	return coutPoint;
//}


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
void Noeud::setToDepart(Noeud n, int x1, int y1)
{
	coutToDepart = n.coutToDepart + distance(x1, y1, n.parent->getX(), n.parent->getY());
}
void Noeud::setToArrive(int x1, int y1, int x2, int y2)
{
	coutToArrive = distance(x1, y1, x2, y2);
}
void Noeud::setCoutSomme(float coutToDepart, float coutToArrive)
{
	coutSomme = coutToDepart + coutToArrive;
}