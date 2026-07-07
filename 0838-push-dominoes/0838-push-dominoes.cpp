class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        vector<int>pos;
        vector<char>force;

        pos.push_back(-1);
        force.push_back('L');

        for(int i=0;i<n;i++){
            if(dominoes[i]!='.'){
                pos.push_back(i);
                force.push_back(dominoes[i]);
            }
        }
        pos.push_back(n);
        force.push_back('R');
        for(int k =0;k+1<pos.size();k++){
            int i =pos[k];
            int j=pos[k+1];

            char left =force[k];
            char right = force[k+1];
            
            if(left == right){
                for(int x =i+1;x<j;x++){
                    dominoes[x] = left;
                }

            }   
            else if(left == 'R' && right == 'L'){
                int l = i+1;
                int r = j-1;

                while(l<r){
                    dominoes[l++] = 'R';
                    dominoes[r--] = 'L';
                }

            }     }
            return dominoes;
    }
};