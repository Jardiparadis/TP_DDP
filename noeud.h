#pragma once

class Noeud
{
public:
	Noeud() 
	{
		float coutG;
		float coutH;
		float coutF;
	}
	~Noeud() {}
	float getCoutPointDepartNoeudSuivant();
	float getCoutNoeudSuivantPointArrive();
	float getCoutSomme();
	void setCoutPointDepartNoeudSuivant(float coutG);
	void setCoutNoeudSuivantPointArrive(float coutH);
	void setCoutSomme(float coutF);

private:
	float coutPointDepartNoeudSuivant;
	float coutNoeudSuivantPointArrive;
	float coutSomme;

	Point* parent;
};
