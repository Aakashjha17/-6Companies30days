class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        //putting the bank in a set for searching purpose
        unordered_set<string> ban;
        for(int i=0;i<bank.size();i++){
            ban.insert(bank[i]);
        }
        //if the endgene is not the valid mutation that the endgene is not present in bank return -1
        if(ban.find(endGene)==ban.end()){
            return -1;
        }
        //creating the list of char that we can use to mutate
        vector<char> available= {'A', 'C', 'G', 'T'};
        //perform bfs to search the endgene is generated while performing mutation
        queue<pair<string,int>> q;
        //pushing the startgene and to achieve that we have done 0 mutation
        q.push({startGene,0});
        unordered_set<string> vis;
        vis.insert(startGene);
        while(!q.empty()){
            string gene=q.front().first;
            int level=q.front().second;//level represent number of mutation
            q.pop();
            //if the current gene is the endgene then return the level
            if(gene==endGene){
                return level;
            }
            // mutate the gene the if the current gene is not the end gene 
            //since every gene is 8 char long we are running loop for eight times
            for(int i=0;i<8;i++){
                //storing the orgininal char that we are going to change
                char original=gene[i];
                //for eveery char there are 4 possible changes i.e 'A' 'C' 'G' 'T'
                for(int j=0;j<4;j++){
                    //changing the char with the first char
                    gene[i]=available[j];
                    //checking if the mutateed gene is present in bank or not
                    if(ban.find(gene)!=ban.end()){
                        //if it valid gene then we are checking that the current gene is already visited or not
                        if(vis.find(gene)==vis.end()){
                            //if the current mutated gene is not visited the push in queue and mark visited
                            q.push({gene,level+1});
                            vis.insert(gene);
                        }
                    }
                }
                //change back to the original gene for next char mutation 
                gene[i] = original;
            }
        }
        //if the while loop is completed and queue is empty that means we cannot achieve the end mutation 
        return -1;
    }
};
