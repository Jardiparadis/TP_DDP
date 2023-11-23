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
	float getToDepart();
	float getToArrive();
	float getCoutSomme();
	void setToDepart(float coutG);
	void setToArrive(float coutH);
	void setCoutSomme(float coutF);

private:
	float coutToDepart;
	float coutToArrive;
	float coutSomme;

	Point* parent;
};
