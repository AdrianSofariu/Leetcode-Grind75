/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree,
you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h.
Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
Return a list of all MHTs' root labels. You can return the answer in any order.
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 
Example 1:

Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.


Example 2:

Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
 

Constraints:

1 <= n <= 2 * 10^4
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.

*/



class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //We will do something akin to khan's topological sort
        //As a graph can only have at maximum 2 roots for a MHT,
        //(because they are the middle nodes of the longest path in the tree)
        //we remove leaf nodes until we are left with at maximum 2 nodes
        //Complexity: O(n) time. O(n) space

        if(n == 1) return {0};

        vector<pair<int, int>> graph(n);

        //we need to know the degree of each node
        for(auto &edge : edges){
            //add all neighbours in the first variable of the pair for each node
            graph[edge[0]].first += edge[1];
            graph[edge[1]].first += edge[0];

            //increase degree in the second
            graph[edge[0]].second++;
            graph[edge[1]].second++;
        }

        //store all leaves in an array
        vector<int> current_leaves;
        for(int i = 0; i < n; i++)
            if(graph[i].second == 1)
                current_leaves.push_back(i);


        vector<int> next_leaves;
        int neighbor = 0;

        //while we have more than 2 candidates for the root
        while(n > 2){

            //remove all the leaves from the candidate list
            n -= current_leaves.size();
            next_leaves.clear();

            //for each leaf
            for(int& leaf : current_leaves){

                //remove it from its parents neighbours (a leaf will have exactly 1 parent)
                //this means that the first variable in the pair is exactly its parent
                neighbor = graph[leaf].first;
                graph[neighbor].first -= leaf;

                //decrease degree of parent
                graph[neighbor].second--;

                //save the parent node if it became a leaf
                if(graph[neighbor].second == 1)
                    next_leaves.push_back(neighbor);
            }

            //update leaves
            current_leaves = next_leaves;
        }

        return current_leaves;
    }
};
