# KOSARAJU'S ALGORITHM EXPLICATION

## 1. Introduction
It is an algorithm that finds all strongly connected components in a directed graph in linear time. It uses DFS (Depth First Search) to find the strongly connected components in a graph. It is based on the fact that if we reverse a graph, the strongly connected components remain the same.

## 2. Steps
To follow the steps we will use the following graph:(draw it so it is easier to understand)
1 2
2 3
3 1
4 2
4 5
5 6
6 4
7 3
7 8
8 9
9 7
3 10
10 11
11 12
12 10

we have 4 strongly connected components: {1,2,3}, {4,5,6}, {7,8,9} and {10,11,12} noted as A,B,C and D respectively.(in the condensed component graph)

### 2.1. Step 1: TOPOLIGICAL SORT
It is true that topological sort works for DAG (Directed Acyclic Graphs), but we use it in this case so we can determine the source node and the next source node.

After applying topological sort we can get the following order:(depending on the input)
7 8 9 4 2 3 10 11 12 1 5 6

**Observation:** 
7 is the first to appear,it is in node C, so C is a source node.
8 belongs to C which ia already "visited" so we skip it.
9 belongs to C which is already "visited" so we skip it.
4 belongs to B,so B may be a source node or node that comes after C.(in this case it is a source node),but most importantly if we remove C,B will be a source node because of the property **A condensed component graph is a DAG,so it has at least one source node and one sink node**.
2 belongs to A which is not "visited",so same login apply on A as on B.(If we remove C and B, A will be a source node)
3 belongs to A which is already "visited" so we skip it.
10 belongs to D which is not "visited",so same login apply on D as on A.(If we remove C,B and A, D will be a source node)
11 belongs to D which is already "visited" so we skip it.
12 belongs to D which is already "visited" so we skip it.
1 belongs to A which is already "visited" so we skip it.
5 belongs to B which is already "visited" so we skip it.
6 belongs to B which is already "visited" so we skip it.

**Conclusion:**
The order of the source nodes is C,B,A,D in condensed component graph.
This step is crucial because it will give the order of source nodes in the condensed component graph.

### 2.2. Step 2: REVERSE THE GRAPH
This step should be done before step 1, but it is easier to explain it after step 1.
We create this graph by reversing the edges of the original graph.
**Property: The original graph and the reversed graph have the same strongly connected components.(cycles remain the same)**
The sources of the origianl CCG become sinks in the reversed CCG and vice versa.
So the order of the source nodes in the reversed CCG is D,A,B,C.

**Note:**
The goal of STEP 1 is to find the sources nodes so in the reversed CCG we can start from the sinks and find the strongly connected components.
We cannot directly find the sinks nodes from the first step: the last nodes are not always sinks, and the above example is a perfect 
counter-example.

### 2.3. Step 3: DFS
We start from the sink nodes and we apply DFS on the reversed Graph.

Let's apply on the example:
This is our topologycal order: 7 8 9 4 2 3 10 11 12 1 5 6

We start our DFS from 7,we will visit 7,8,9 , we mark these 3 vertices as a SSC and we will not visit 3 because remember that we are on the reversed graph,we are at a sink node,there is no outgoing edge from any vertex in this node to any other vertex in another node.We will always visit 7,8,9 because cycle always remain the same in the reversed graph.

We won't apply dfs on 8,9 because they are already visited.

**Note:**
We will never visit any vertex of this node (C), so it as if we removed this node from the graph.
What happens if we remove a sink node from CCG? the next node (B) will become for sure a sink node.
We will keep doing this until we visit all the nodes.

We apply DFS on 4, we will visit 4,5,6 ,we mark these 3 vertices as a SSC and we will not visit 2 (remember we are at a sink node).
We apply DFS on 2, we will visit 2,3,1 ,we mark these 3 vertices as a SSC and we will not visit 7 or 4 because they are already visited, this is why it is like we remove the previous sink nodes from the graph,so the actual sink node only traverse its vertices.

3 is already visited so we skip it.
We apply DFS on 10, we will visit 10,11,12 ,we mark these 3 vertices as a SSC and we will not visit 3 for the same reason.

The rest of the nodes are already visited so we skip them.


## Conclusion
The Kosaraju's algorithm is a linear time algorithm that finds all strongly connected components in a directed graph.
It is based on the fact that if we reverse a graph, the strongly connected components remain the same.
It tries at first to find the sinks nodes in the reversed graph, then it applies DFS on these nodes and mark the vertices as a SSC.
