#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <functional>
#include <numeric>
#include <string>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <list>
using namespace std;

//*************************************Graphs****************************************/

class Graph
{
public:
    map<int, list<int>> AdjacencyList;
    vector<vector<int>> AdjacencyMatrix;
    int Vertices;
    bool Directed;

    // Graph(int v)
    // {
    //     Vertices = v;
    //     AdjencyMatrix.resize(v, vector<int>(v, 0));
    // }

    void Add_Edge_In_The_Graph(int u, int v, int direction, int weight = 1)
    {
        if (direction == 1)
        {
            Directed = true;
        }
        else
        {
            Directed = false;
        }

        // Direction = 0 -> Undirected Graph
        // Direction = 1 -> Directed Graph

        // Add edge from u to v
        AdjacencyList[u].push_back(v);
        // AdjencyMatrix[u][v] = weight;

        if (direction == 0)
        {
            // If Direction is 0 i.e. Undirected Graph
            // Then also add edge from v to u
            AdjacencyList[v].push_back(u);
            // AdjencyMatrix[v][u] = weight;
        }
    }

    void Print_Adjacency_List()
    {

        for (auto i : AdjacencyList)
        {
            cout << i.first << " -> ";
            for (auto k : i.second)
            {
                cout << k << " ";
            }
            cout << endl;
        }
    }

    int Starting_Value_For_BFS_and_DFS()
    {

        return AdjacencyList.begin()->first;
    }

    void Breadth_First_Search_Helper(int source, unordered_map<int, bool> &Visited)
    {
        queue<int> q;

        Visited[source] = true;
        q.push(source);

        while (!q.empty())
        {
            int FrontNode = q.front();
            q.pop();

            cout << FrontNode << " ";

            for (int Neighbor : AdjacencyList[FrontNode])
            {
                if (Visited[Neighbor] == false)
                {
                    Visited[Neighbor] = true;
                    q.push(Neighbor);
                }
            }
        }
    }

    void Breadth_First_Search()
    {
        unordered_map<int, bool> Visited;

        for (auto x : AdjacencyList)
        {
            if (Visited[x.first] == false)
            {
                Breadth_First_Search_Helper(x.first, Visited);
            }
        }
    }

    void Depth_First_Search_Helper(int Node, unordered_map<int, bool> &Visited)
    {
        Visited[Node] = true;

        cout << Node << " ";

        for (int Neighbor : AdjacencyList[Node])
        {
            if (Visited[Neighbor] == false)
            {
                Depth_First_Search_Helper(Neighbor, Visited);
            }
        }
    }

    void Depth_First_Search(int start)
    {
        unordered_map<int, bool> Visited;

        for (auto x : AdjacencyList)
        {
            if (Visited[x.first] == false)
                Depth_First_Search_Helper(x.first, Visited);
        }
    }

    void Breadth_First_Search_For_Cycle_Detection_In_Undirected_Graph(int source, unordered_map<int, bool> &Visited, bool &cycle_Present)
    {
        unordered_map<int, int> Parent;

        Parent[source] = -1;
        Visited[source] = true;

        queue<int> q;

        q.push(source);

        while (!q.empty())
        {
            int FrontNode = q.front();
            q.pop();

            for (int i : AdjacencyList[FrontNode])
            {
                if (Visited[i] == true && Parent[FrontNode] != i)
                {
                    cycle_Present = true;
                    return;
                }
                else if (Visited[i] == false)
                {
                    Visited[i] = true;
                    q.push(i);
                    Parent[i] = FrontNode;
                }
            }
        }
    }

    void Cycle_Detection_In_Undirected_Graph_Using_Breadth_First_Search()
    {
        if (Directed == true)
        {
            return;
        }

        bool Cycle_Present = false;
        unordered_map<int, bool> Visited;

        for (auto i : AdjacencyList)
        {
            if (Visited[i.first] == false)
            {
                Breadth_First_Search_For_Cycle_Detection_In_Undirected_Graph(i.first, Visited, Cycle_Present);
            }
        }
        cout << "Using Breadth First Search in Undirected Graph: ";
        cout << (Cycle_Present == true ? "Cycle is Present" : "Cycle is not Present") << endl;
    }

    map<int, list<int>> GetAdjacencyList()
    {
        return AdjacencyList;
    }

    void Depth_First_Search_For_Cycle_Detection_In_Undirected_Graph(int source, unordered_map<int, bool> &Visited, int parent, bool &Cycle_Present)
    {
        Visited[source] = true;

        for (auto x : AdjacencyList[source])
        {
            if (Visited[x] == false)
            {
                Depth_First_Search_For_Cycle_Detection_In_Undirected_Graph(x, Visited, source, Cycle_Present);
            }
            else
            {
                if (x != parent)
                {
                    Cycle_Present = true;
                    return;
                }
            }
        }
    }

    void Cycle_Detection_In_Undirected_Graph_Using_Depth_First_Search()
    {
        if (Directed == true)
        {
            return;
        }

        bool Cycle_Present = false;
        unordered_map<int, bool> Visited;

        for (auto x : AdjacencyList)
        {
            if (Visited[x.first] == false)
            {
                Depth_First_Search_For_Cycle_Detection_In_Undirected_Graph(x.first, Visited, -1, Cycle_Present);
            }
        }

        cout << "Using Depth First Search in Undirected Graph: ";
        cout << (Cycle_Present == true ? "Cycle is Present" : "Cycle is Not Presetn") << endl;
    }

    void Depth_First_Search_For_Cycle_Detection_In_Directed_Graph(int Source_Node, bool &CyclePresent, unordered_map<int, bool> &DFS_Visited, unordered_map<int, bool> &Visited, map<int, list<int>> &ADJLIST)
    {
        Visited[Source_Node] = true;
        DFS_Visited[Source_Node] = true;

        for (auto Neighbour : ADJLIST[Source_Node])
        {
            if (Visited[Neighbour] == false)
            {
                Depth_First_Search_For_Cycle_Detection_In_Directed_Graph(Neighbour, CyclePresent, DFS_Visited, Visited, ADJLIST);
                if (CyclePresent)
                    return;
            }
            else if (Visited[Neighbour] == true && DFS_Visited[Neighbour] == true)
            {
                CyclePresent = true;
                return;
            }
        }

        DFS_Visited[Source_Node] = false;
    }

    void Cycle_Detection_In_Directed_Graph_Using_Depth_First_Search()
    {
        if (Directed == false)
        {
            return;
        }

        unordered_map<int, bool> Visited;
        unordered_map<int, bool> DFS_Visited;

        bool CyclePresent = false;

        for (auto X : AdjacencyList)
        {
            if (Visited[X.first] == false)
            {
                Depth_First_Search_For_Cycle_Detection_In_Directed_Graph(X.first, CyclePresent, DFS_Visited, Visited, AdjacencyList);
                if (CyclePresent)
                    break;
            }
        }

        cout << (CyclePresent == true ? "Cycle is Present in Directed Graph using DFS" : "Cycle is Not Present in Directed Graph using DFS") << endl;
    }

    void Cycle_Detection_In_Directed_Graph_Using_Breadth_First_Search_Kahns_Algorithm()
    {
        if (Directed == false)
        {
            return;
        }

        unordered_map<int, int> InDegree_Of_Nodes;

        for (auto i : AdjacencyList)
        {
            for (auto j : i.second)
            {
                InDegree_Of_Nodes[j]++;
            }
        }

        queue<int> Nodes;

        for (auto x : AdjacencyList)
        {
            if (InDegree_Of_Nodes[x.first] == 0)
            {
                Nodes.push(x.first);
            }
        }

        int Count = 0;

        while (Nodes.empty() == false)
        {
            int FrontNode = Nodes.front();
            Nodes.pop();

            Count++;

            for (auto X : AdjacencyList[FrontNode])
            {
                InDegree_Of_Nodes[X]--;

                if (InDegree_Of_Nodes[X] == 0)
                {
                    Nodes.push(X);
                }
            }
        }

        cout << (Count != AdjacencyList.size() ? "Cycle is Present in Directed Graph using Kahn's BFS" : "Cycle is Not Present in Directed Graph using Kahn's BFS") << endl;
    }

    void Depth_First_Search_For_Topological_Sort(int SourceNode, unordered_map<int, bool> &Visited, map<int, list<int>> &AdjList, stack<int> &Topological_Order)
    {
        Visited[SourceNode] = true;

        for (auto Neigh : AdjList[SourceNode])
        {
            if (Visited[Neigh] == false)
            {
                Depth_First_Search_For_Topological_Sort(Neigh, Visited, AdjList, Topological_Order);
            }
        }

        Topological_Order.push(SourceNode);
    }

    void Topological_Sort_Using_Depth_First_Search()
    {
        if (Directed == false)
        {
            return;
        }

        unordered_map<int, bool> Visited;
        stack<int> Topological_Order;

        for (auto X : AdjacencyList)
        {
            if (Visited[X.first] == false)
            {
                Depth_First_Search_For_Topological_Sort(X.first, Visited, AdjacencyList, Topological_Order);
            }
        }

        cout << "Topological Order Using Depth First Search: ";

        while (Topological_Order.empty() == false)
        {
            cout << Topological_Order.top() << " ";
            Topological_Order.pop();
        }

        cout << endl;
    }

    void Topological_Sort_Using_Breadth_First_Search_Kahns_Algorithm()
    {
        if (Directed == false)
        {
            return;
        }

        unordered_map<int, int> Indegree_of_Nodes;

        vector<int> Topological_Order;

        for (auto i : AdjacencyList)
        {
            for (auto j : i.second)
            {
                Indegree_of_Nodes[j]++;
            }
        }

        queue<int> Nodes;

        for (auto X : AdjacencyList)
        {
            if (Indegree_of_Nodes[X.first] == 0)
            {
                Nodes.push(X.first);
            }
        }

        while (Nodes.empty() == false)
        {
            int FrontNode = Nodes.front();
            Nodes.pop();

            Topological_Order.push_back(FrontNode);

            for (auto Neighbour : AdjacencyList[FrontNode])
            {
                Indegree_of_Nodes[Neighbour]--;

                if (Indegree_of_Nodes[Neighbour] == 0)
                {
                    Nodes.push(Neighbour);
                }
            }
        }

        cout << "Topological Order Using Breadth First Search(Kahn's Algorithm): ";

        for (int T : Topological_Order)
        {
            cout << T << " ";
        }

        cout << endl;
    }

    void Shortest_Path_From_Source_Node_To_Destination_Node_In_Undirected_Graph_Using_Breadth_First_Search(int SourceNode, int DestinationNode)
    {
        if (Directed == true)
        {
            return;
        }

        if (AdjacencyList.find(SourceNode) == AdjacencyList.end())
        {
            cout << "Source Node is not Availble in the Graph." << endl;
            return;
        }

        if (AdjacencyList.find(DestinationNode) == AdjacencyList.end())
        {
            cout << "Destination Node is not Availble in the Graph." << endl;
            return;
        }
        +unordered_map<int, bool> Visited;
        unordered_map<int, int> Parents_of_Nodes;

        Parents_of_Nodes[SourceNode] = -1;
        Visited[SourceNode] = true;

        queue<int> Nodes;
        Nodes.push(SourceNode);

        while (!Nodes.empty())
        {
            int FrontNode = Nodes.front();
            Nodes.pop();

            for (auto Neighbour : AdjacencyList[FrontNode])
            {
                if (Visited[Neighbour] == false)
                {
                    Parents_of_Nodes[Neighbour] = FrontNode;
                    Visited[Neighbour] = true;
                    Nodes.push(Neighbour);
                }
            }
        }

        if (Visited[DestinationNode] == false)
        {
            cout << "No path exists between Source Node and Destination Node." << endl;
            return;
        }

        int TempNode = DestinationNode;
        vector<int> Shortest_Path;
        Shortest_Path.push_back(DestinationNode);

        while (TempNode != SourceNode)
        {
            TempNode = Parents_of_Nodes[TempNode];
            Shortest_Path.push_back(TempNode);
        }

        reverse(Shortest_Path.begin(), Shortest_Path.end());

        cout << "Using BFS in Undirected Graph" << endl;

        cout << "Shortest Path from Source Node to Destination Node: ";

        for (int i = 0; i < Shortest_Path.size(); i++)
        {
            cout << Shortest_Path[i] << " ";

            if (i != Shortest_Path.size() - 1)
            {
                cout << "-> ";
            }
        }

        cout << endl;
    }

    void Depth_First_Search_To_Find_Path_From_Source_Node_To_Destination_Node_In_Undirected_Graph(int SourceNode, int DestinationNode, int Parent, unordered_map<int, int> &Parents_of_Nodes, unordered_map<int, bool> &Visited, map<int, list<int>> &AdjList, bool &PathFound)
    {
        Parents_of_Nodes[SourceNode] = Parent;
        Visited[SourceNode] = true;

        if (SourceNode == DestinationNode)
        {
            PathFound = true;
            return;
        }

        for (auto Neighbours : AdjList[SourceNode])
        {

            if (Visited[Neighbours] == false)
            {
                Depth_First_Search_To_Find_Path_From_Source_Node_To_Destination_Node_In_Undirected_Graph(Neighbours, DestinationNode, SourceNode, Parents_of_Nodes, Visited, AdjList, PathFound);

                if (PathFound == true)
                {
                    return;
                }
            }
        }
    }

    void Path_From_Source_Node_To_Destination_Node_In_Undirected_Graph_Using_Depth_First_Search(int SourceNode, int DestinationNode)
    {
        /*
        DFS Still Doesn’t Guarantee Shortest Path:
        For an unweighted graph, DFS won’t necessarily find the shortest path,
        especially if the destination node is reachable through multiple paths.
        BFS should be used for finding the shortest path in unweighted graphs.
        */

        if (Directed == true)
        {
            return;
        }

        if (AdjacencyList.find(SourceNode) == AdjacencyList.end())
        {
            cout << "Source Node is not Availble in the Graph." << endl;
            return;
        }

        if (AdjacencyList.find(DestinationNode) == AdjacencyList.end())
        {
            cout << "Destination Node is not Availble in the Graph." << endl;
            return;
        }

        unordered_map<int, bool> Visited;
        unordered_map<int, int> Parents_of_Nodes;
        bool PathFound = false;

        Depth_First_Search_To_Find_Path_From_Source_Node_To_Destination_Node_In_Undirected_Graph(SourceNode, DestinationNode, -1, Parents_of_Nodes, Visited, AdjacencyList, PathFound);

        if (PathFound == false)
        {
            cout << "No path exists between Source Node and Destination Node." << endl;
            return;
        }

        int TempNode = DestinationNode;
        vector<int> Shortest_Path;
        Shortest_Path.push_back(DestinationNode);

        while (TempNode != SourceNode)
        {
            TempNode = Parents_of_Nodes[TempNode];
            Shortest_Path.push_back(TempNode);
        }

        reverse(Shortest_Path.begin(), Shortest_Path.end());

        cout << "Using DFS in Undirected Graph" << endl;

        cout << "Path from Source Node to Destination Node: ";

        for (int i = 0; i < Shortest_Path.size(); i++)
        {
            cout << Shortest_Path[i] << " ";

            if (i != Shortest_Path.size() - 1)
            {
                cout << "-> ";
            }
        }

        cout << endl;
    }

    void Dijkstra_Algorithm(int Source, int Nodes, vector<vector<int>> Graph)
    {
        unordered_map<int, list<pair<int, int>>> AdjacencyList;

        for (vector<int> Weighted_Edge : Graph)
        {
            int From = Weighted_Edge[0];
            int To = Weighted_Edge[1];
            int Weight = Weighted_Edge[2];

            AdjacencyList[From].push_back({To, Weight});
        }

        vector<int> Distances(Nodes + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Min_Heap;

        Distances[Source] = 0;

        Min_Heap.push({Distances[Source], Source});

        while (!Min_Heap.empty())
        {
            int u = Min_Heap.top().second;
            int u_Weight = Min_Heap.top().first;
            Min_Heap.pop();

            for (auto Neighbour : AdjacencyList[u])
            {
                int v = Neighbour.first;
                int v_weight = Neighbour.second;

                if (Distances[u] + v_weight < Distances[v])
                {
                    Distances[v] = Distances[u] + v_weight;
                    Min_Heap.push({Distances[v], v});
                }
            }
        }

        cout << "From Source Node " << Source << " :" << endl;

        for (int i = 0; i < Distances.size(); i++)
        {
            if (i == Source)
                continue;

            if (Distances[i] == INT_MAX)
            {
                cout << "Shortest Distance is INT_MAX to reach Node " << i << endl;
            }
            else
                cout << "Shortest Distance is " << Distances[i] << " to reach Node " << i << endl;
        }
    }

    void Prims_Spanning_Alogrithm(unordered_map<int, list<pair<int, int>>> AdjacenecyList)
    {
        int Vertices = AdjacenecyList.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> MinHeap;

        vector<int> Key(Vertices, INT_MAX);
        vector<bool> MST_SET(Vertices, false);
        vector<int> Parents(Vertices, -1);

        int Starting_Node = 0;

        Key[Starting_Node] = 0;
        MinHeap.push({0, Starting_Node});

        while (!MinHeap.empty())
        {
            int u = MinHeap.top().second;
            MinHeap.pop();

            if (MST_SET[u])
                continue;

            MST_SET[u] = true;

            for (auto [v, weight] : AdjacenecyList[u])
            {
                if (MST_SET[v] == false && weight < Key[v])
                {
                    Key[v] = weight;
                    Parents[v] = u;
                    MinHeap.push({Key[v], v});
                }
            }
        }

        cout << "Edge \tWeight\n";
        for (int i = 1; i < Vertices; i++)
        {
            cout << Parents[i] << " - " << i << "\t" << Key[i] << endl;
        }
    }

    // void PrintAdjencyMatrix()
    // {
    //     for (int i = 0; i < Vertices; i++)
    //     {
    //         for (int j = 0; j < Vertices; j++)
    //         {
    //             cout << AdjencyMatrix[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    int FindingParents(vector<int> &Parents, int Node)
    {
        if (Parents[Node] == Node)
        {
            return Node;
        }

        return Parents[Node] = FindingParents(Parents, Parents[Node]);
    }

    void UnionSet(int U, int V, vector<int> &Parents, vector<int> &Ranks)
    {
        int U_Parent = FindingParents(Parents, U);
        int V_Parent = FindingParents(Parents, V);

        if (U_Parent != V_Parent)
        {
            if (Ranks[U_Parent] < Ranks[V_Parent])
            {
                Parents[U_Parent] = V_Parent;
            }
            else if (Ranks[U_Parent] > Ranks[V_Parent])
            {
                Parents[V_Parent] = U_Parent;
            }
            else
            {
                Parents[U_Parent] = V_Parent;
                Ranks[V_Parent]++;
            }
        }
    }

    void Kruskals_Algorithm(vector<vector<int>> Edges, int Total_Nodes)
    {
        vector<int> Parents(Total_Nodes);
        vector<int> Ranks(Total_Nodes, 0);

        for (int i = 0; i < Total_Nodes; i++)
        {
            Parents[i] = i;
        }

        sort(Edges.begin(), Edges.end(), [](vector<int> A, vector<int> B)
             { return A[2] < B[2]; });

        int Total_Minimum_Weight = 0;

        for (int i = 0; i < Edges.size(); i++)
        {
            int Parent_of_U = FindingParents(Parents, Edges[i][0]);
            int Parent_of_V = FindingParents(Parents, Edges[i][1]);
            int Weight = Edges[i][2];

            if (Parent_of_U != Parent_of_V)
            {
                Total_Minimum_Weight += Weight;
                UnionSet(Edges[i][0], Edges[i][1], Parents, Ranks);
            }
        }

        cout << Total_Minimum_Weight << endl;

        // Test Cases:

        // vector<vector<int>> Edges;

        // Edges.push_back({0, 1, 10});
        // Edges.push_back({0, 2, 6});
        // Edges.push_back({0, 3, 5});
        // Edges.push_back({1, 3, 15});
        // Edges.push_back({2, 3, 4});

        // Kruskals_Algorithm(Edges, 4);
    }
};

class Topological_Sort_And_Relaxation_Algorithm_To_Find_Shortest_Path_From_Source_Node_to_All_Other_Nodes_in_DAG
{
public:
    unordered_map<int, list<pair<int, int>>> AdjacencyList;

    void AddEdge(int u, int v, int weight)
    {
        AdjacencyList[u].push_back({v, weight});
    }

    void Print()
    {
        for (auto i : AdjacencyList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "( " << j.first << " , " << j.second << " ) , ";
            }
            cout << endl;
        }
    }

    void DFS(int source, unordered_map<int, bool> &Visited, stack<int> &Res)
    {
        Visited[source] = true;

        for (auto Neighbour : AdjacencyList[source])
        {
            if (!Visited[Neighbour.first])
            {
                DFS(Neighbour.first, Visited, Res);
            }
        }

        Res.push(source);
    }

    void FindShortest_Path_Using_Topological_Sort_and_Relaxation_Algorithm()
    {
        unordered_map<int, bool> Visited;
        stack<int> Topological_Order;

        for (auto x : AdjacencyList)
        {
            if (!Visited[x.first])
                DFS(x.first, Visited, Topological_Order);
        }

        int Source = 1;

        vector<int> Distances(6, INT_MAX);

        Distances[Source] = 0;

        while (!Topological_Order.empty())
        {
            int StackTopNode = Topological_Order.top();
            Topological_Order.pop();

            if (Distances[StackTopNode] != INT_MAX)
            {
                for (auto NeighbouringNodes : AdjacencyList[StackTopNode])
                {
                    if (Distances[StackTopNode] + NeighbouringNodes.second < Distances[NeighbouringNodes.first])
                    {
                        Distances[NeighbouringNodes.first] = Distances[StackTopNode] + NeighbouringNodes.second;
                    }
                }
            }
        }

        for (int d : Distances)
            cout << d << " ";
    }

    /*
        Directed_Graph DAG;
    DAG.AddEdge(0, 1, 5);
    DAG.AddEdge(0, 2, 3);
    DAG.AddEdge(1, 2, 2);
    DAG.AddEdge(1, 3, 6);
    DAG.AddEdge(2, 3, 7);
    DAG.AddEdge(2, 4, 4);
    DAG.AddEdge(2, 5, 2);
    DAG.AddEdge(3, 4, -1);
    DAG.AddEdge(4, 5, -2);

    DAG.FindShortest_Path_Using_Topological_Sort_and_Relaxation_Algorithm();

    */
};

void Bellman_Ford_Algorithm(vector<vector<int>> Graph, int SourceNode, int DestinationNode)
{
    int No_of_Nodes = Graph.size();
    vector<int> Distances(No_of_Nodes, INT_MAX);
    Distances[SourceNode] = 0;

    for (int i = 1; i <= No_of_Nodes - 1; i++)
    {
        for (auto Edge : Graph)
        {
            int u = Edge[0];
            int v = Edge[1];
            int weight = Edge[2];

            if (Distances[u] == INT_MAX)
                continue;

            if (Distances[u] + weight < Distances[v])
            {
                Distances[v] = Distances[u] + weight;
            }
        }
    }

    for (auto Edge : Graph)
    {
        int u = Edge[0];
        int v = Edge[1];
        int weight = Edge[2];

        if (Distances[u] == INT_MAX)
            continue;

        if (Distances[u] + weight < Distances[v])
        {
            cout << "Negative Cycle Detected!" << endl;
            return;
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < Distances.size(); i++)
    {
        cout << i << "\t" << (Distances[i] == INT_MAX ? "INF" : to_string(Distances[i])) << "\n";
    }

    //     // Graph with No Negative Cycle:
    // vector<vector<int>> Graph = {{0, 1, 5}, {1, 2, 1}, {1, 3, 2}, {2, 4, 1}, {4, 3, -1}};
    // Bellman_Ford_Algorithm(Graph,0,3);

    // // Graph with Negative Cycle:
    // vector<vector<int>> Graph0 = {{0, 1,4}, {1, 2, -6}, {2, 3, 5}, {3, 1, -2}};
    // Bellman_Ford_Algorithm(Graph0,0,3);
}

void DFS(int Source, unordered_map<int, list<int>> &AdjacencyList, unordered_map<int, bool> &Visited, stack<int> &stk)
{
    Visited[Source] = true;

    for (auto Neighbour : AdjacencyList[Source])
    {
        if (!Visited[Neighbour])
        {
            DFS(Neighbour, AdjacencyList, Visited, stk);
        }
    }

    stk.push(Source);
}

void DFS1(int Source, unordered_map<int, list<int>> &Transpose, unordered_map<int, bool> &Visited, vector<int> &Component)
{
    Visited[Source] = true;
    Component.push_back(Source);

    for (auto Neighbour : Transpose[Source])
    {
        if (!Visited[Neighbour])
        {
            DFS1(Neighbour, Transpose, Visited, Component);
        }
    }
}

void Kosarajus_Alogrithm_for_Scc(vector<vector<int>> Graph)
{
    unordered_map<int, list<int>> AdjacencyList;

    for (vector<int> Edge : Graph)
    {
        AdjacencyList[Edge[0]].push_back(Edge[1]);
    }

    stack<int> Topological_Order;
    unordered_map<int, bool> Visited;
    

    for (auto X : AdjacencyList)
    {
        if (!Visited[X.first])
        {
            DFS(X.first, AdjacencyList, Visited, Topological_Order);
        }
    }

    Visited.clear();

    unordered_map<int, list<int>> Transpose;

    for (auto i : AdjacencyList)
    {
        for (auto j : i.second)
        {
            Transpose[j].push_back(i.first);
        }
    }

    vector<vector<int>> Strong_Connected_Componenets;

    while (!Topological_Order.empty())
    {
        int Node = Topological_Order.top();
        Topological_Order.pop();

        if (!Visited[Node])
        {
            vector<int> Componenet;
            DFS1(Node, Transpose, Visited, Componenet);

            if (!Componenet.empty())
                Strong_Connected_Componenets.push_back(Componenet);
        }
    }

    PrintMatrixVector(Strong_Connected_Componenets);

    /*
        vector<vector<int>> Graph = {{1, 2}, {2, 3}, {2, 4}, {3, 4}, {3, 6}, {4, 1}, {4, 5}, {5, 6}, {6, 7}, {7, 5}};
    Kosarajus_Alogrithm_for_Scc(Graph);
    */
}

int main()
{
    // int Vertices;
    // cout << "Enter No. of Vertices: ";
    // cin >> Vertices;

    // int edges;
    // cout << "Enter No. of edges: ";
    // cin >> edges;

    // int direction;
    // cout << "Enter 0 for Undirected Graph and 1 for Directed Graph: ";
    // cin >> direction;

    // Graph G1;

    // // Creating Edges:

    // for (int i = 1; i <= edges; i++)
    // {
    //     int u, v;
    //     cout << "Enter nodes(vertices) (u,v) data: ";
    //     cin >> u >> v;

    //     cout << "Adding edge from " << u << " to " << v << endl;
    //     G1.Add_Edge_In_The_Graph(u, v, direction);

    //     // if (u >= 0 && u < Vertices && v >= 0 && v < Vertices)
    //     // {
    //     //     cout << "Adding edge from " << u << " to " << v << endl;
    //     //     G1.Add_Edge_In_The_Graph(u, v, direction);
    //     // }
    //     // else
    //     // {
    //     //     cout <<"Invalid Node Data, Try Again !" << "Enter node data between 0 and" << Vertices - 1 << " ." << endl;
    //     //     i--;
    //     // }
    // }

    // Printing Created Graph:

    Graph G1;

    //                       u  v  d  w          U & V = Node , D = Direction , W = Weight
    G1.Add_Edge_In_The_Graph(1, 2, 0, 1);
    G1.Add_Edge_In_The_Graph(2, 0, 0, 1);
    G1.Add_Edge_In_The_Graph(1, 0, 0, 1);
    G1.Add_Edge_In_The_Graph(0, 3, 0, 1);
    G1.Add_Edge_In_The_Graph(3, 4, 0, 1);

    cout << "Adjacency List: " << endl;
    G1.Print_Adjacency_List();
    // cout << "Adjency Matrix: " << endl;
    // G1.PrintAdjencyMatrix();

    cout << "Breadth First Search: ";

    G1.Breadth_First_Search();

    cout << endl;

    cout << "Depth First Search: ";
    G1.Depth_First_Search(G1.Starting_Value_For_BFS_and_DFS());

    cout << endl;

    G1.Cycle_Detection_In_Undirected_Graph_Using_Breadth_First_Search();
    cout << endl;

    G1.Cycle_Detection_In_Undirected_Graph_Using_Depth_First_Search();
    cout << endl;

    G1.Cycle_Detection_In_Directed_Graph_Using_Depth_First_Search();
    cout << endl;

    G1.Topological_Sort_Using_Depth_First_Search();
    cout << endl;

    G1.Topological_Sort_Using_Breadth_First_Search_Kahns_Algorithm();
    cout << endl;

    G1.Cycle_Detection_In_Directed_Graph_Using_Breadth_First_Search_Kahns_Algorithm();
    cout << endl;

    G1.Shortest_Path_From_Source_Node_To_Destination_Node_In_Undirected_Graph_Using_Breadth_First_Search(1, 4);
    cout << endl;

    G1.Path_From_Source_Node_To_Destination_Node_In_Undirected_Graph_Using_Depth_First_Search(1, 4);
    cout << endl;

    return 0;
}