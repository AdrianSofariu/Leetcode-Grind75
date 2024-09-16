/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts.
Note that even if two accounts have the same name, they may belong to different people as people could have the same name.
A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order.
The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.


Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 

Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j].length <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.
*/


class Solution {
public:

    //We will use Union-Find
    //N - number of accounts, K - maximum length of an account
    //Complexity: O(NKα(N)+NKlogNK) - time, where  α(N) is the inverse Ackermann function
    //O(NK) - space

    //return the parent of a given node with path compression
    int find(int node, vector<int>& parent){
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node], parent);
    }

    //merge two sets of nodes using ranks
    void unify(int i, int j, vector<int>& parent, vector<int>& rank){
        int iRoot = find(i, parent);
        int jRoot = find(j, parent);

        if(iRoot != jRoot){
            if(rank[iRoot] > rank[jRoot]){
                parent[jRoot] = iRoot;
            }
            else if(rank[iRoot] < rank[jRoot]){
                parent[iRoot] = jRoot;
            }
            else{
                parent[jRoot] = iRoot;
                rank[iRoot]++;
            }
        }
    }

    //main function
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        //initialize parent vector
        int n = accounts.size();
        vector<int> parent(n), rank(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        //map to store emails and ids
        unordered_map<string, int> emailToAcc;

        //iterate though all string and put them in the map if it not seen until now,
        //else merge the 2 IDs.
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];

                //if not found, add
                if(emailToAcc.find(email) == emailToAcc.end())
                    emailToAcc[email] = i;
                //if duplicate, merge
                else
                    unify(emailToAcc[email], i, parent, rank);

            }
        }

        //group mails by the ultimate parent account
        unordered_map<int, vector<string>> accountToEmails;

        for(auto& [email, acc] : emailToAcc){
            int usr = find(acc, parent);
            accountToEmails[usr].push_back(email);
        }


        //put data in final answer
        vector<vector<string>> ans;

        for(auto& [acc, emails] : accountToEmails){
            vector<string> mergedAccount;
            //add name
            mergedAccount.push_back(accounts[acc][0]);
            //sort mails and add them
            sort(emails.begin(), emails.end());
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end());
            //push to answer
            ans.push_back(mergedAccount);
        }

        return ans;
    }
};


/*
This can make programs faster if they dont need keyboard input and console output.
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
*/
