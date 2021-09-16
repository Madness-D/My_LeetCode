/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
struct TrieNode {
    string word;
    unordered_map<char,TrieNode *> children;
    TrieNode() {
        this->word = "";
    }   
};

void insertTrie(TrieNode * root,const string & word) {
    TrieNode * node = root;
    for (auto c : word){
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word;
}

class Solution {
public:

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;

        int m=board.size(),n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        bool find=false;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                backtracking(i,j,board,word,find,visited,0);
            }
        }
        return find;

    }

    void  backtracking(int i,int j,vector<vector<char>> &board,string & word,bool& find,vector<vector<bool>> &visited,int pos){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()){//如果i或j超出范围
            return ;
        }
        if(visited[i][j]||find||board[i][j]!=word[pos]){
            //如果board[i][j]已经被访问、或者已经找齐了单词、或者该位置不是想要的字母
            return ;
        }
        if(pos==word.size()-1){
            //该字母是单词的最后一个字母，则将find置为true，return
            find=true;
            return;
        }

        visited[i][j]=true;//标记已经访问
        
        //递归访问相邻字符
        backtracking(i+1,j,board,word,find,visited,pos+1);
        backtracking(i-1,j,board,word,find,visited,pos+1);
        backtracking(i,j+1,board,word,find,visited,pos+1);
        backtracking(i,j-1,board,word,find,visited,pos+1);
        visited[i][j]=false;// 将当前结点的状态改成未访问
    } 


 int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode * root, set<string> & res) {
        char ch = board[x][y];        
        if (!root->children.count(ch)) {
            return false;
        }
        root = root->children[ch];
        if (root->word.size() > 0) {
            res.insert(root->word);
        }

        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if (board[nx][ny] != '#') {
                    dfs(board, nx, ny, root,res);
                }
            }
        }
        board[x][y] = ch;

        return true;      
    }

    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        // //直接调用79的两个函数，通过用例41/42,超时
        // vector<string> res;
        // for(int i=0;i<words.size();i++){
        //     if(exist(board,words[i])){
        //         res.push_back(words[i]);
        //     }
        // }
        // return res;


        //回溯 + 字典树
        TrieNode * root = new TrieNode();
        set<string> res;
        vector<string> ans;

        for (auto & word: words){
            insertTrie(root,word);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, res);
            }
        }        
        for (auto & word: res) {
            ans.emplace_back(word);
        }
        return ans;      

    }
};
// @lc code=end

