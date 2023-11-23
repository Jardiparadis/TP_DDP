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
	void setToDepart(Noeud n, int x1, int y1);
	void setToArrive(int x1, int y1, int x2, int y2);
	void setCoutSomme(float coutToDepart, float coutSomme);

private:
	float coutToDepart;
	float coutToArrive;
	float coutSomme;

	Point* parent;
};
