/*
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

Example 1:

Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
Example 2:

Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
 

Constraints:

0 <= bank.length <= 10
startGene.length == endGene.length == bank[i].length == 8
startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].
*/
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        //bfs
        //credit to SuryaPSG
        //set holds all valid mutations
        unordered_set<string> set{bank.begin(), bank.end()};
        //edge case: endGene not in set
        if(!set.count(endGene))return -1;
        //start BFS by pushing startGene
        queue<string> q;
        q.push(startGene);
        int step = 0;
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                string cur = q.front();
                q.pop();
                //If we reach end mutation
                if(cur == endGene)return step;
                //We erase the cur mutation in order to avoid redundant checking
                set.erase(cur);
                //as the length of mutation is 8 and it can take A,C,G,T
			    //at each index we check the possibility of mutation by replcaing it with A,C,G,T
                for(int i = 0; i < 8; i++){
                    string temp = cur;
                    temp[i] = 'A';
                    if(set.count(temp))q.push(temp);
                    temp[i] = 'C';
                    if(set.count(temp))q.push(temp);
                    temp[i] = 'G';
                    if(set.count(temp))q.push(temp);
                    temp[i] = 'T';
                    if(set.count(temp))q.push(temp);
                }
            }
            step++;
        }
        return -1;
    }
};