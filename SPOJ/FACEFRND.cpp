#include <cstdio>
#include <set>

using namespace std;
int main(){
	int n, m, id;
	set<int> f;
	set<int> fof;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &id);
		f.insert(id);
		scanf("%d", &m);
		if(fof.end()!=fof.find(id))
			fof.erase(id);
		while(m--){
			scanf("%d", &id);
			if(f.end()==f.find(id))
				fof.insert(id);
		}
	}
	printf("%ld\n", fof.size());
}