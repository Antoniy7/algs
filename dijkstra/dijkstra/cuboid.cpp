#include<iostream>
using namespace std;

struct Point
	{
		double x;
		double y;
		double z;
	};
class Cuboid
{
private:
	Point A; 
	Point B;  
	Point C; 
	Point D;
	Point E;
	Point F;
	Point G;
	Point H;

public:
	Cuboid(Point A, Point G)
	{
		this->A = A;
		this->G = G;
		BuildCuboid(); // 
	}
private:
	void BuildCuboid()
	{
		//B
		B.y = A.y;
		B.z = A.z;
		B.x = G.x;

		//C
		C.y = A.y;
		C.z = G.z;
		C.x = G.x;

		//D
		D.y = A.y;
		D.x = A.x;
		D.z = G.z;

		//E
		E.x = A.x;
		E.y = G.y;
		E.z = A.z;

		//F
		F.x = G.x;
		F.y = G.y;
		F.z = A.z;

		//H
		H.x = A.x;
		H.z = G.z;
		H.y = G.y;

	}

public:

	Point makeVector(Point firstPoint, Point secondPoint)   
	{
		Point temp;
		
		temp.x = secondPoint.x - firstPoint.x;
		temp.y = secondPoint.y - firstPoint.y;
		temp.z = secondPoint.z - firstPoint.z;
	
		return temp;
	}

	double dotProduct(Point firstVector, Point secondVector)
	{
		double sum = 0;

		sum += (firstVector.x*secondVector.x);
		sum += (firstVector.y*secondVector.y);
		sum += (firstVector.z*secondVector.z);

		return sum;
	}

	bool checkIsInCuboid(Point M) // 
	{

		Point BA = makeVector(B, A); // BA
		Point BC = makeVector(B, C); // BC
		Point BM = makeVector(B, M); // BM
		Point BH = makeVector(B, H);// BH 
		Point BF = makeVector(B, F);// 

		double BH_BH = dotProduct(BH, BH);// BH.BH
		double BA_BA = dotProduct(BA, BA);// BA.BA
		double BC_BC = dotProduct(BC, BC);// BC.BC
		double BF_BF = dotProduct(BF, BF);// BC.BC
		double BM_BF = dotProduct(BM, BF);

		double BM_BH = dotProduct(BM, BH);//BM.BH
		double BM_BA = dotProduct(BM, BA);//BM.BA
		double BM_BC = dotProduct(BM, BC);//BM.BC

		if ((0 <= BM_BH && BM_BH <= BH_BH) && (0 <= BM_BA && BM_BA <= BA_BA) && (0 <= BM_BC && BM_BC <= BC_BC) && (0<=BM_BF && BM_BF<=BF_BF)) 
			return true;
		else
			return false;
	}

};
int main()
{
	Point A, B, C, D;
	cin >> A.x;
	cin >> A.y;
	cin >> A.z;
	cin >> B.x;
	cin >> B.y;
	cin >> B.z;

	Cuboid cub(A, B);

	Point testerCheker;
	cin >> testerCheker.x;
	cin >> testerCheker.y;
	cin >> testerCheker.z;
	

	if (cub.checkIsInCuboid(testerCheker))
		cout << ":) " << endl;

	else
		cout << ";(" << endl;

	

	system("pause");
	return 0;
}