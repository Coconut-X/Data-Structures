#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#include<unordered_map>

using namespace std;




class graphMatrix
{

    public:
    vector<vector<int>> adjMatrix;
    vector<bool>visited;
    vector<int>distance;
    vector<int>parent;
    vector<int> path;
    unordered_map<int,int> connectedComponents;

    graphMatrix(int n)
    {
        adjMatrix.resize(n,vector<int>(n,0));
        visited.resize(n,0);
        parent.resize(adjMatrix.size(),-1);
    }

    void addEdgeUndirectedUnweighted(int x, int y)
    {
         adjMatrix[x][y]=1;
         adjMatrix[y][x]=1;
         connectedComponents[x]=1;
         connectedComponents[y]=1;
    }

    void reset()
    {
        visited.clear();
        visited.resize(adjMatrix.size(),0);
        distance.clear();
        parent.clear();
        parent.resize(adjMatrix.size(),-1);
        path.clear();
        //connectedComponents.clear();
    }

   void addEdgeDirectedUnweighted(int x, int y)
   {
       adjMatrix[x][y]=1;
       connectedComponents[x]=1;
   }


    void addEdgeDirectedWeighted(int x, int y, int w)
    {
        adjMatrix[x][y]=w;
        connectedComponents[x]=1;
    }

    void addEdgeUndirectedWeighted(int x, int y, int w)
    {
        adjMatrix[x][y]=w;
        adjMatrix[y][x]=w;
        connectedComponents[x]=1;
        connectedComponents[y]=1;
    }

    void dfsTraversel(int s)
    {
        visited[s]=true;
        cout<<s<<"  ";

        for(int i=0;i<adjMatrix[s].size();i++)
        {
            if(!visited[i] and adjMatrix[s][i]!=0)
            {
                dfsTraversel(i);
            }

        }

    }

    void bfsTraversal(int s)
    {

        queue<int> q;
        q.push(s);
        visited[s]=true;
        while(!q.empty())
        {

            int node=q.front();
            cout<<node<<"  ";
            q.pop();

            for(int i=0;i<adjMatrix[node].size();i++)
            {
                if(adjMatrix[node][i] and !visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }

    void displayPath(int end)
    {
        for(int at=end;at!=-1;at=parent[at]) 
        {
            path.push_back(at);
        }

        for(int i=path.size()-1;i>=0;i--)
            cout<<path[i]<<"  ";
    }


    void shortestPathUnweigted(int start, int end)
    {
        reset();
        queue<pair<int,int>> q;
        vector<int> path;

        visited[start]=true;
       // int dist=0;
        q.push({start,0});

        while(!q.empty())
        {
            int node=q.front().first;
            int dist=q.front().second;

            q.pop();

            if(node == end) 
            {
                cout<<"Distance: "<<dist<<endl;
                displayPath(end);
                return ;
            }

            for(int i=0;i<adjMatrix[node].size();i++)
            {
                if(adjMatrix[node][i] and !visited[i])
                {
                    q.push({i,dist+1});
                    parent[i]=node; //parent[neighbour]=current , store the parent of node at its index
                    visited[i]=true;
                }
            }
        }

        

        cout<<"No Path Found"<<endl;
    }


    void shortestPathWeighted(int start, int end)
    {

    }



    void countConnectedComponents()
    {
        int count=0;
        for(int i=0;i<connectedComponents.size();i++)
        {
            if(connectedComponents[i])
            {
                count++;
                cout<<"Connected component: "<<i<<endl;
            }
        }
        cout<<"Number of connected components: "<<count<<endl;
    }


    void unconnectedComponents()
    {
        int count=0;
        for(int i=0;i<connectedComponents.size();i++)
        {
            if(!connectedComponents[i])
            {
                count++;
                cout<<"Unconnected component: "<<i<<endl;
            }
        }
        cout<<"Number of unconnected components: "<<count<<endl;
    }

    void DFS(int s, vector<vector<int>> graph)
{
	stack<int> s1;
	unordered_map<int, bool> visited;

	s1.push(s);
	

	while (!s1.empty())
	{
		int u = s1.top();
		s1.pop();

		if (!visited[u]) {
            visited[u] = true; // Mark as visited
            cout << u << " "; // Process the current node
        }



		for (int i = 0; i < graph[u].size(); i++)
		{
			cout << graph[u][i] << "\t";

			if (!visited[graph[u][i]])
			{

				s1.push(graph[u][i]);
			}
		}


	}
}

};



class graphList
{
    public:
    vector<vector<pair<int,int>>> adjList;
    vector<bool>visited;
    vector<int>distance;
    vector<int>parent;
    vector<int> path;
    unordered_map<int,int> connectedComponents;

    graphList(int n)
    {
        adjList.resize(n);
        visited.resize(n,0);
    }

    void addEdgeUndirectedUnweighted(int x, int y)
    {
        adjList[x].push_back({y,1});
        adjList[y].push_back({x,1});
        connectedComponents[x]=1;
        connectedComponents[y]=1;
    }

    void addEdgeDirectedUnweighted(int x, int y)
    {
        adjList[x].push_back({y,1});
        connectedComponents[x]=1;
    }

    void addEdgeDirectedWeighted(int x, int y, int w)
    {
        adjList[x].push_back({y,w});
        connectedComponents[x]=1;
    }

    void addEdgeUndirectedWeighted(int x, int y, int w)
    {
        adjList[x].push_back({y,w});
        adjList[y].push_back({x,w});
        connectedComponents[x]=1;
        connectedComponents[y]=1;
    }

    void reset()
    {
        visited.clear();
        visited.resize(adjList.size(),0);
        distance.clear();
        parent.clear();
        parent.resize(adjList.size(),-1);
        path.clear();
        //connectedComponents.clear();
    }

    void dfsTraversal(int s)
    {
        visited[s]=true;
        cout<<s<<"  ";

        for(int i=0;i<adjList[s].size();i++)
        {
            if(adjList[s][i].second and !visited[adjList[s][i].first])
            {   
                dfsTraversal(adjList[s][i].first);
            }
        }
    }
    
    void bfsTraversal(int s)
    {
        queue<int> q;
        q.push (s);
        visited[s]=true;

        while(!q.empty())
        {
            int node=q.front();
            cout<<node<<"  ";
            q.pop();

            for(int i=0;i<adjList[node].size();i++)
            {
                if(adjList[node][i].second and !visited[adjList[node][i].first])
                {
                    q.push(adjList[node][i].first);
                    visited[adjList[node][i].first]=true;
                }
            }
        }
    }


    void displayPath(int end)
    {
        for( int i=end; i!=-1; i=parent[i])
        {
            path.push_back(i);
        }

        for(auto it=path.rbegin();it!=path.rend();it++)
        {
            cout<<*it<<"  ";
        }
    }

    void shortestPathUnweighted(int start, int end)
    {
        reset();

        queue<pair<int,int>> q;
        q.push({start,0});
        visited[start]=true;


        while(!q.empty())
        {
            int node=q.front().first;
            int dist=q.front().second;
            q.pop();

            if(node==end)
            {
                cout<<"Distance: "<<dist<<endl;
                displayPath(end);
                return;
            }

            for(int i=0;i<adjList[node].size();i++)
            {
                if(adjList[node][i].second and !visited[adjList[node][i].first])
                {
                    q.push({adjList[node][i].first, dist+1});
                    parent[adjList[node][i].first]=node;
                    visited[adjList[node][i].first]=true;
                }
            }
        }

    }

};




int main()
{

    graphMatrix g(9);


     // Add edges for the given graph
    g.addEdgeUndirectedUnweighted(1, 8);
    g.addEdgeUndirectedUnweighted(1, 5);
    g.addEdgeUndirectedUnweighted(1, 4);
    g.addEdgeUndirectedUnweighted(3, 4);
    g.addEdgeUndirectedUnweighted(2, 4);

    g.addEdgeUndirectedUnweighted(3, 2);
    g.addEdgeUndirectedUnweighted(3, 7);
    g.addEdgeUndirectedUnweighted(2, 5);
    g.addEdgeUndirectedUnweighted(0, 7);

    g.addEdgeUndirectedUnweighted(2, 0);

    g.bfsTraversal(5);

    // cout<<" FOR GRAPH MATRIX"<<endl<<endl;

    // graphMatrix g(9);
    // g.addEdgeUndirectedWeighted(0, 1, 4);
    // g.addEdgeUndirectedWeighted(0, 7, 8);
    // g.addEdgeUndirectedWeighted(1, 2, 8);
    // g.addEdgeUndirectedWeighted(1, 7, 11);
    // g.addEdgeUndirectedWeighted(2, 3, 7);
    // g.addEdgeUndirectedWeighted(2, 8, 2);
    // g.addEdgeUndirectedWeighted(2, 5, 4);
    // g.addEdgeUndirectedWeighted(3, 4, 9);
    // g.addEdgeUndirectedWeighted(3, 5, 14);
    // g.addEdgeUndirectedWeighted(4, 5, 10);
    // g.addEdgeUndirectedWeighted(5, 6, 2);
    // g.addEdgeUndirectedWeighted(6, 7, 1);
    // g.addEdgeUndirectedWeighted(6, 8, 6);
    // g.addEdgeUndirectedWeighted(7, 8, 7);

    // g.shortestPathUnweigted(0,4);

    //link to the graph https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

    // cout<<"DFS Traversal: ";
    // g.dfsTraversel(8);

    // cout<<endl;

    // cout<<"BFS Traversal: ";
    // g.reset();
    // g.bfsTraversal(8);



    // graphMatrix g1(6);
    // g1.addEdgeUndirectedUnweighted(0,3);
    // g1.addEdgeUndirectedUnweighted(3,5);
    // g1.addEdgeUndirectedUnweighted(2,5);
    // cout<<endl;

    // g1.countConnectedComponents();
    // g1.unconnectedComponents();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    // cout<<" FOR GRAPH LIST"<<endl<<endl;

    // graphList g2(9);
    // g2.addEdgeUndirectedWeighted(0, 1, 4);
    // g2.addEdgeUndirectedWeighted(0, 7, 8);
    // g2.addEdgeUndirectedWeighted(1, 2, 8);
    // g2.addEdgeUndirectedWeighted(1, 7, 11);
    // g2.addEdgeUndirectedWeighted(2, 3, 7);
    // g2.addEdgeUndirectedWeighted(2, 8, 2);
    // g2.addEdgeUndirectedWeighted(2, 5, 4);
    // g2.addEdgeUndirectedWeighted(3, 4, 9);
    // g2.addEdgeUndirectedWeighted(3, 5, 14);
    // g2.addEdgeUndirectedWeighted(4, 5, 10);
    // g2.addEdgeUndirectedWeighted(5, 6, 2);
    // g2.addEdgeUndirectedWeighted(6, 7, 1);
    // g2.addEdgeUndirectedWeighted(6, 8, 6);
    // g2.addEdgeUndirectedWeighted(7, 8, 7);


    // g2.shortestPathUnweighted(0,4);

    // cout<<"DFS Traversal: ";
    // g2.dfsTraversal(8);
    // cout<<"BFS Traversal: ";
    // g2.reset();
    // g2.bfsTraversal(8);



    return 0;
}
