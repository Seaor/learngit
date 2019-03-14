
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <sstream>
#include <stack>
#include <queue>
#include<unordered_map>
using namespace std;
#include<cmath>
#include<limits.h>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//二叉树的构建，先序遍历，深度优先遍历（DFS），广度优先遍历（BFS）
class Solution{
public:
    TreeNode* creatTree(vector<string> t,int &i){
        if(t[i][0]=='#'){
            i++;
            return NULL;
        }
        stringstream ss(t[i]);
        int val=0;
        ss>>val;
        i++;
        TreeNode* root= new TreeNode(val);
        root->left = creatTree(t,i);
        root->right = creatTree(t,i);
        return root;
    }
    void preorder(TreeNode* root){
        if(root==NULL) return;
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    //深度优先遍历
    void DFS(TreeNode* root){
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            cout<<node->val<<" ";
            st.pop();
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);

        }
    }
    //广度优先遍历
    void BFS(TreeNode* root){
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* node=qu.front();
            cout<<node->val<<" ";
            qu.pop();
            if(node->left) qu.push(node->left);
            if(node->right) qu.push(node->right);

        }
    }
};
//给定分母、分子，然后输出这个分数除完的小数（以字符串的形式）
//两个整数相除，结果只有可能是有限不循环小数或者无限循环小数，将无限循环小数的循环部分用括号括住输出


string fractionToDecimal(int numerator, int denominator) {
    if(numerator==INT_MIN,denominator==-1) return "2147483648";//溢出的情况
    if(numerator==0) return "0";//分子为0的情况
    //if(numerator==-1,denominator=INT_MAX) return "";
    string ret;
    if(numerator<0 ^ denominator<0) ret+="-";//记录符号
    numerator = abs(numerator);
    denominator = abs(denominator);
    int shang = numerator/denominator;
    int yushu = numerator%denominator;
    ret += to_string(shang);
    if(yushu==0) return ret;//如果正好整除就返回商
    ret += ".";//否则就有小数，要加小数点
    unordered_map<int,int> m;//记录余数和出现的位置
    while(yushu){
        
        yushu *= 10;//余数×10作为新的被除数
        if(m.count(yushu)){//如果有这个余数了就记录循环并输出
            int start=m[yushu];
            int end = ret.size()-1;
            ret = ret.substr(0,start)+"("+ret.substr(start,end-start+1)+")";
            return ret;
            
        }
        m[yushu] = ret.size();
        shang = yushu/denominator;
        yushu = yushu%denominator;
        ret += to_string(shang); 
    }
    return ret;
}
int findPeakElement(vector<int>& nums) {
        //二分法
        int left = 0;
        int right = nums.size()-1;
        int mid = left+(right-left)/2;
        //左边或者右边有任何一方比中点大就说明那边有坡
        while(left<=right){
            //最后的情况，左边跟右边相邻，且左边大于左边，右边大于右边，取二者最大的那个；
            if(mid == left) return nums[left]>nums[right]?left:right;
            if(nums[mid]<nums[mid+1]) left = mid;
            else if(nums[mid]>nums[mid+1]) right = mid;
            mid = left +(right-left)/2;
        }
        return 0;
        
}
int main()
{
    /* vector<string> t = {"2","-1","4","#","#","7","#","#","3","#","#"};
    Solution s;
    TreeNode* root;
    int i=0;
    root = s.creatTree(t,i);
    cout<<"先序遍历"<<endl;
    s.preorder(root);
    cout<<endl;
    cout<<"广度优先遍历"<<endl;
    s.BFS(root);
    cout<<endl;
    cout<<"深度优先遍历"<<endl;
    s.DFS(root);
    cout<<endl; */
    vector<int> nums ={1,2,3,1};
    findPeakElement(nums);
    vector<int> ret(nums.size(),0);

    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<" ";

    }
    return 0;
}