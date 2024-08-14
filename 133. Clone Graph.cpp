/*
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.


Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.
An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.


Example 1:


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).


Example 2:

Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.


Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
 

Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        //We will perform a bfs on the given tree and clone each node encountered.
        //To keep track of the correspondance, we will use a map.
        //Complexity: O(V + E) (where V is the number of vertices and E of edges)

      
        // A map to keep track of the original node and its corresponding clone
        map<Node*, Node*> m;
        // A queue to perform BFS traversal of the graph
        queue<Node*> q;

        // If the input node is NULL, return NULL as there is nothing to clone
        if(node == NULL)
            return NULL;

        // Create a new node (clone) with the same value as the input node
        Node* newNode = new Node(node->val);

        // Store the mapping of the original node to its clone
        m[node] = newNode;
        // Push the original node onto the queue to start BFS
        q.push(node);

        // Perform BFS to clone the entire graph
        while(!q.empty())
        {
            // Get the front node from the queue
            Node* n = q.front();
            q.pop();

            // Iterate through all the neighbors of the current node
            for(Node* neighbour : n->neighbors)
            {
                // If the neighbor has not been cloned yet
                if(m[neighbour] == NULL)
                {
                    // Create a new node (clone) for the neighbor
                    Node* newNode = new Node(neighbour->val);
                    // Store the mapping of the original neighbor to its clone
                    m[neighbour] = newNode;
                    // Push the neighbor onto the queue to clone its neighbors later
                    q.push(neighbour);
                }
                // Add the clone of the neighbor to the neighbor list of the current node's clone
                m[n]->neighbors.push_back(m[neighbour]);
            }
        }
        // Return the clone of the original node
        return m[node];
    }
};













