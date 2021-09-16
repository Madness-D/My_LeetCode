/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    //一个想法，把中序遍历和前/后序遍历结果存储为一个string，据此恢复二叉树
    //又,其实一个遍历就可以了,把空节点标记为null
    //需要在节点间有分隔符,如',',否则无法区分12 和1 2
    //前序遍历

    //https://support.leetcode-cn.com/hc/kb/article/1194353/

    // Encodes a tree to a single string.

    void  fse(TreeNode* root, string& str){
        if(root==nullptr){
            str+="null,";//如果是空节点,存为null
            }else{
                str+=to_string(root->val)+',';
                fse(root->left,str);
                fse(root->right,str);

            }
    }

    string serialize(TreeNode* root) {
        string res;
        fse(root,res);
        return res;
    }

    // Decodes your encoded data to tree.
  TreeNode* rdeserialize(list<string>& dataArray) {
        if (dataArray.front() == "null") {//如果是null,删除
            dataArray.erase(dataArray.begin());
            return nullptr;
        }
        //stoi,将string转换为int,
        //atoi的参数是const char *,
        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }

    TreeNode* deserialize(string data) {
        list<string> dataArray;//改成vector的话会超时
        //可能的解释,list的插入删除更高效
        string str;
        //将字符串根据',' 拆分成一个个string
        for (auto& ch : data) {
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }

        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }

        return rdeserialize(dataArray);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

