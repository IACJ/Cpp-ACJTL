#include <iostream>  
#include <cstdio>  
#include <list>  
#include <vector>  
#include <queue>  
using namespace std;
int n;
vector< list<int> > graph;
bool visited[100] = { 0 };
void dfs(int v)
{
	list<int>::iterator it;
	visited[v] = true;
	printf("%5d", v);
	for (it = graph[v].begin(); it != graph[v].end(); ++it)
		if (!visited[*it])
			dfs(*it);
}
void bfs(int v)
{
	list<int>::iterator it;
	printf("%5d", v);
	visited[v] = true;
	queue<int> t;
	t.push(v);
	while (!t.empty())
	{
		v = t.front();
		t.pop();
		for (it = graph[v].begin(); it != graph[v].end(); ++it)
			if (!visited[*it])
			{
				printf("%5d", *it);
				t.push(*it);
				visited[*it] = true;
			}
	}
	cout << endl;
}
//int  main()
//{
//	//freopen("in.txt", "r", stdin);  
//	cout << "input the vertex num:" << endl;
//	cin >> n;
//	vector< list<int> >::iterator it;
//	for (int i = 0; i < n; ++i)
//	{
//		list<int> il;
//		int t;
//		while (cin >> t && t != n)
//			il.push_back(t);
//		graph.push_back(il);
//	}
//	cout << "result for bfs:" << endl;
//	bfs(0);
//	memset(visited, 0, sizeof(visited));                   //重新初始化标志数组  
//	cout << "result for dfs:" << endl;
//	dfs(0);
//	return 0;
//}