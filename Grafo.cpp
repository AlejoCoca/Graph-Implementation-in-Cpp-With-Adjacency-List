#include<math.h>
#include <vector>

using namespace std;

class Grafo{
	public:
	Grafo(vector<int> &v, vector< pair<int, int> > &a);
};

Grafo::Grafo(vector<int> &v, vector< pair<int, int> > &a)
{
	vector< int > _v=v;
	vector< pair<int, int> > _a=a;
}
