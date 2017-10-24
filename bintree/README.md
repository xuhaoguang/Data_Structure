# 有关二叉树的常见考点
1. 数据结构  
    二叉树通常结构通常由二叉树节点和二叉树构成 
    * 树节点
    ``` c++
    class BinTreeNode{
    public:
        BinTreeNode(const int &item,
                    BinTreeNode *lPtr = NULL,
                    BinTreeNode *rPtr = NULL
                    ) : data(item), left(lPtr), right(rPtr){
        };

        ~BinTreeNode(){
            delete left;
            delete right;
        }

    private:
        int data;
        BinTreeNode *left, *right;
    };
    ```

    * 二叉树
    ``` c++
    class BinTree{
    public:
        BinTree(BinTreeNode *t = NULL) : root(t){
        };

        ~BinTree(){
            delete root;
        }
    
    private:
        BinTreeNode *root;
    };
    ```

2. 树的操作
    
    ``` c++
    //@briefs: 递归创建二叉树
    //@parmas：
    //@return：BinTreeNode 根节点
    BinTreeNode* BinTree::create_tree(){
        char item;
        BinTreeNode *t, *t_l, *t_r;
        cin >> item; //61#23#4#
    
        if(item != '#'){// '#' means none node
            BinTreeNode *tmp = new BinTreeNode(item - 48);
            t = tmp;
            t_l = create_tree();
            t->set_left(t_l);
            t_r = create_tree();
            t->set_right(t_r);
            return t;
        }else{
            t = NULL;
            return t;
        }
    }
    
    //@briefs: 前序遍历二叉树
    //@parmas：BinTreeNode*
    //@return：
    void BinTree::pre_order(BinTreeNode *t) const{
       BinTreeNode* tmpNode = t;
       if(tmpNode != NULL){
           cout << tmpNode->get_data() << " ";
           pre_order(tmpNode->get_left());
           pre_order(tmpNode->get_right());
       }
    }
    
    //@briefs: 中序遍历二叉树
    //@parmas：BinTreeNode*
    //@return：
    void BinTree::in_order(BinTreeNode *t) const{
       BinTreeNode* tmpNode = t;
       if(tmpNode != NULL){
           in_order(tmpNode->get_left());
           cout << tmpNode->get_data() << " ";
           in_order(tmpNode->get_right());
       }
    }
    
    //@briefs: 后序遍历二叉树
    //@parmas：BinTreeNode*
    //@return：
    void BinTree::post_order(BinTreeNode *t) const{
       BinTreeNode* tmpNode = t;
       if(tmpNode != NULL){
           post_order(tmpNode->get_left());
           post_order(tmpNode->get_right());
           cout << tmpNode->get_data() << " ";
       }
    }
    
    //@briefs: 层次遍历二叉树
    //@parmas：BinTreeNode*
    //@return：
    void BinTree::level_order(BinTreeNode *t) const{
        if(t == NULL){
            return;
        }
    
        deque<BinTreeNode*> q;
        q.push_back(t);
    
        while(!q.empty()){
            BinTreeNode* pTmpNode = q.front();
            cout << pTmpNode->get_data() << " ";
            q.pop_front();
    
            if(pTmpNode->get_left() != NULL){
                q.push_back(pTmpNode->get_left());
            }
    
            if(pTmpNode->get_right() != NULL){
                q.push_back(pTmpNode->get_right());
            }
        }
    }
    
    //@briefs: 求二叉树叶子节点个数
    //@parmas：BinTreeNode*
    //@return：int
    int BinTree::get_leaf_num(BinTreeNode *t) const{
        if(t == NULL){
            return 0;
        }
    
        if(t->get_left() == NULL && t->get_right() == NULL){
            return 1;
        }
    
        return get_leaf_num(t->get_left()) + get_leaf_num(t->get_right());
    }
    
    //@briefs: 求二叉树树的高度
    //@parmas：BinTreeNode*
    //@return：int
    int BinTree::get_tree_height(BinTreeNode *t) const{
        if(t == NULL){
            return 0;
        }
    
        if(t->get_left() == NULL && t->get_right() == NULL){
            return 1;
        }
    
        int l_height = get_tree_height(t->get_left());
        int r_height = get_tree_height(t->get_right());
    
        return l_height >= r_height ? l_height+1 : r_height+1;
    }
    
    //@briefs: 交换二叉树左右子树
    //@parmas：BinTreeNode*
    //@return：
    void BinTree::swap_left_right(BinTreeNode *t){
        if(t == NULL){
            return;
        }
    
        BinTreeNode *pTmpNode = t->get_left();
        t->set_left(t->get_right());
        t->set_right(pTmpNode);
    
        swap_left_right(t->get_left());
        swap_left_right(t->get_right());
    }
    
    //@briefs: 判断节点是否在二叉树中
    //@parmas：BinTreeNode*, BinTreeNode*
    //@return：bool
    bool BinTree::is_in_tree(BinTreeNode *r, BinTreeNode *t) const{
        if(r == NULL){
            return false;
        }else if(r == t){
            return true;
        }else{
            bool has = false;
            if(r->get_left() != NULL){
                has = is_in_tree(r->get_left(), t);
            }
    
            if(r->get_right() != NULL){
                has = is_in_tree(r->get_right(), t);
            }
    
            return has;
        }
    }
    
    //@briefs: 获取二叉树中两个节点的最近公共祖先
    //@parmas：BinTreeNode*, BinTreeNode*, BinTreeNode*,
    //@return：BinTreeNode*
    BinTreeNode* BinTree::get_nearest_common_father(BinTreeNode *r, BinTreeNode *p1, BinTreeNode *p2) const{
        if(is_in_tree(p1, p2)){
            return p1;
        }
    
        if(is_in_tree(p2, p1)){
            return p1;
        }
    
        bool p1_in_left, p1_in_right, p2_in_left, p2_in_right;
        p1_in_left = is_in_tree(r->get_left(), p1);
        p1_in_right = is_in_tree(r->get_right(), p1);
        p2_in_left = is_in_tree(r->get_left(), p2);
        p2_in_right = is_in_tree(r->get_right(), p2);
    
        if((p1_in_left && p2_in_right) || (p2_in_left && p1_in_right)){
            return r;
        }else if(p1_in_left && p2_in_left){
            return get_nearest_common_father(r->get_left(), p1, p2);
        }else if(p1_in_right && p2_in_right){
            return get_nearest_common_father(r->get_right(), p1, p2);
        }else{
            return NULL;
        }
    }
    
    //@briefs: 打印路径，满足路径中节点的value之和为sum
    //@parmas：BinTreeNode*, int
    //@return：
    stack<BinTreeNode *>dfs_s;
    stack<BinTreeNode *>print_s;
    void BinTree::print_rout(BinTreeNode *r,int sum)const{
        if(r == NULL)
        {
            return;
        }
        sum -= r->get_data();
        dfs_s.push(r);
        if(sum <= 0)
        {
            if(sum == 0)
            {
                while(!dfs_s.empty())
                {
                    print_s.push(dfs_s.top());
                    dfs_s.pop();
                }
                while(!print_s.empty())
                {
                    cout<<print_s.top()->get_data()<<" ";
                    dfs_s.push(print_s.top());
                    print_s.pop();
                }
                cout<<endl;
            }
            sum += r->get_data();
            dfs_s.pop();
            return;
        }
     	print_rout(r->get_left(),sum);
     	print_rout(r->get_right(),sum);
        sum += r->get_data();
        dfs_s.pop();
    }

    ```
