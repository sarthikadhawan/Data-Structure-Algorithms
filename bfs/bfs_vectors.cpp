#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n,e,k,a,b;

vector <int> friends[10000];
bool visited[10000];
void bfs(int src)
{
	int v=0;
	memset(visited,0,sizeof(visited));
	queue < pair <int,int> > q;
	q.push(make_pair(src,0));
	int count = 0;
	
	// mark current node as marked
	visited[src] = true;
	while(!q.empty())
	{
		pair<int,int> current = q.front();
		q.pop();
		v++;
		// loop over adjacent nodes of popped node
		for(int j=0 ; j<friends[current.first].size();j++)
		{
			int i = friends[current.first][j];
			if(!visited[i] && current.second+1<=k)
			{
				visited[i] = true;
				q.push({i,current.second+1});
			}
		}
	}

	cout << v - friends[src].size() - 1 << endl;
}

int main()
{

	cin >> n >> e >> k;

	int ctr[n] = {};
	// creating graph
	for(int i=0;i<e;i++)
	{
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);

	}

	for(int i=1;i<=n;i++)
	{
		bfs(i);
	}

	return 0;
}
