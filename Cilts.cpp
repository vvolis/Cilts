#include <iostream>
#include <fstream>
using namespace std;

class Node
{
public:
	long PK;
	char Dzimums;
	char Vards[30];
	char Uzvards[30];
	long V1PK;
	long V2PK;
	long kids; //Dzimtas lieluma uzglabasanai
	long key; //Mezgla atrasanas vieta masiva

	//Norades uz vecakiem
	Node * V1;
	Node * V2;

	long lastVisited;

	Node();
	Node(fstream & file)
	{
		file >> PK;
		file >> Dzimums;
		file >> Vards;
		file >> Uzvards;
		file >> V1PK;
		file >> V2PK;
		V1 = NULL;
		V2 = NULL;
		kids = 1;
		lastVisited = -1;
	};
};

void countVisit(Node * vertex, Node * sencis, long vertexCount, Node ** vertices, long ** adjMatrix)
{
	if (vertex != NULL)
	{
		if (vertex->lastVisited!=sencis->key)
		{
			//DFS, par katru elementu originalajam vecakam palielinam dzimtas lielumu.
			//Darbojamies tikai ar katras dzimtas senako cilveku, tapec pa vidu neliekam
			for (long j = 0; j < vertexCount; j++)
			{
				//ja eksiste sads edge no vecaka uz bernu
				if (adjMatrix[vertex->key][j] == 1)
				{
					countVisit(vertices[j], sencis, vertexCount, vertices, adjMatrix);
					sencis->kids++;
				}
			}
			vertex->lastVisited = sencis->key;
		}
	}
}

int main()
{
	//------------------------------------------Ielasam visu info objektos masiva------------------------------------------
	fstream file;
	file.open("cilts.i20", ios::in);
	char temp[100];
	long vertexCount = 0;

	file.getline(temp, 100);
	//Saskaitam cik objekti faila
	while (temp[0] != '0')
	{
		file.getline(temp, 100);
		vertexCount++;
	}

	//Resetojam atrasanas vietu faila
	file.clear();
	file.seekg(0, ios::beg);

	//Izveidojam  pointeru masivu, kas noradis uz grafa virsotnem
	Node ** vertices = new Node*[vertexCount];
	//Aizpildam masivu
	for (long i = 0; i < vertexCount; i++)
	{
		vertices[i] = new Node(file);
		vertices[i]->key = i; //Ieglabajam mezgla atrasanas vietu masiva
	}

	//Sakartojam vecaku pointerus
	for (long i = 0; i < vertexCount; i++)
	{
		for (long j = 0; j < vertexCount; j++)
		{
			if (vertices[i]->V1PK == vertices[j]->PK)
			{
				vertices[i]->V1 = vertices[j];
			}

			if (vertices[i]->V2PK == vertices[j]->PK)
			{
				vertices[i]->V2 = vertices[j];
			}
		}
	}

	//------------------------------------------Ieliekam matrica, lai apgrieztu otradi------------------------------------------

	//Izveidojam matricu
	long **adjMatrix = new long *[vertexCount];
	for (long i = 0; i < vertexCount; i++)
	{
		adjMatrix[i] = new long[vertexCount];
		for (long j = 0; j < vertexCount; j++) adjMatrix[i][j] = 0;
	}

	//Aizpildam matricas info
	for (long i = 0; i < vertexCount; i++)
	{
		if (vertices[i]->V1 != NULL) adjMatrix[vertices[i]->V1->key][i] = 1;
		if (vertices[i]->V2 != NULL) adjMatrix[vertices[i]->V2->key][i] = 1;
	}

	//------------------------------------------Depth-first bernu skaitisana------------------------------------------
	//Apstaigajam visas virsotnes, kas ir kadas cilts senci (tam nav bernu)
	for (long i = 0; i<vertexCount; i++)
	{
		if (vertices[i]->V1 == NULL && vertices[i]->V2 == NULL)
		{
			countVisit(vertices[i], vertices[i], vertexCount, vertices, adjMatrix);
		}
	}

	//------------------------------------------Atrodam ar lielako bernu skaitu------------------------------------------
	long biggestKid = 0;
	for (long i = 0; i < vertexCount; i++)
	{
		if (vertices[i]->kids > vertices[biggestKid]->kids)
		{
			biggestKid = i;
		}
		else if ((vertices[i]->kids == vertices[biggestKid]->kids) && (vertices[i]->PK < vertices[biggestKid]->PK))
		{
			biggestKid = i;
		}
	}

	//--------------------------------------------------Izvadam datus-------------------------------------------------
	fstream file2;
	file2.open("cilts.out", fstream::out);
	if (vertexCount>0)
	{

		file2 << vertices[biggestKid]->kids << ' ';
		if (vertices[biggestKid]->Dzimums == 'V') file2 << "Ciltstevs" << ' ';
		else file2 << "Ciltsmate" << ' ';
		file2 << vertices[biggestKid]->Vards << ' ' << vertices[biggestKid]->Uzvards;
	}
	file2.close();
	file.close();

	//--------------------------------------------------Savacam atminu-------------------------------------------------
	for (long i = 0; i < vertexCount; i++)
	{
		delete vertices[i];
	}
	delete vertices;

	for (long i = 0; i < vertexCount; i++)
	{
		delete adjMatrix[i];
	}

	delete adjMatrix;
	return 0;


	return 0;
}
