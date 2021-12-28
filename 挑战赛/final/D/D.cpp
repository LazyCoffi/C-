#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

const int N = 1e3 + 7;

int n;

struct Ent{
	string s;
	char type;
	string id;
	int x, y;
} cli[N], ser[N];

struct Fin{
	string cid, sid;
	double dis;
	bool operator < (const Fin a) const{
		return dis > a.dis;
	}
};

double getDis(Ent a, Ent b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void print(Fin ans) {
	cout << ans.cid << " " << ans.sid << " ";
	printf("%.2f\n", ans.dis);
}

int main() {
	freopen("D.in", "r", stdin);

	cin >> n;
	int ctot = 0, stot = 0;
	for (int i = 1; i <= 2 * n; i ++) {
		Ent newEnt;
		cin >> newEnt.s >> newEnt.type >> newEnt.id;
		cin >> newEnt.x >> newEnt.y;		
		if (newEnt.type == 'C') cli[++ ctot] = newEnt;
		else ser[++ stot] = newEnt;
	}
	
	priority_queue<Fin> ans;
	
	for (int i = 1; i <= ctot; i ++) {
		for (int j = 1; j <= stot; j ++) {
			if (cli[i].s == ser[j].s) {
				ans.push((Fin){cli[i].id, ser[j].id, getDis(cli[i], ser[j])});
			}
		}
	}
	while (!ans.empty()) {
		print(ans.top());
		ans.pop();
	}
}
