#include "Tree.h"


// ==================== k>d tree ======================
kdTree::kdTree()
{
    root = nullptr;
}

void kdTree::insert(kdNode* &root, int arr[], int dim)
{
    if (root == nullptr)
    {
        root = new kdNode;
        root->nodedim = dim;
        root->key[0] = arr[0];
        root->key[1] = arr[1];
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    else
    {
        if (root->key[0] == arr[0] && root->key[1] == arr[1]) return;   
        if (arr[dim] < root->key[dim]) insert(root->left, arr, 1 - dim);
        else insert(root->right, arr, 1 - dim);
    }
}

kdNode* kdTree::search(kdNode* root, int arr[], int dim)
{
    if (root == nullptr) return NULL;
    else
    {
        if (root->key[0] == arr[0] && root->key[1] == arr[1]) return root;
        if (arr[dim] < root->key[dim]) search(root->left, arr, 1 - root->nodedim);
        else search(root->right, arr, 1 - root->nodedim);
    }

}

void kdTree::remove(kdNode* &root, int arr[], int dim)
{
    if (root == nullptr) return;
    else
    {
        kdNode* deleted = root;
        kdNode* parent = nullptr;
        while (deleted != nullptr)
        {
            if (arr[dim] < deleted->key[dim])
            {
                parent = deleted;
                deleted = deleted->left;
            }
            else if (arr[dim] > deleted->key[dim])
            {
                parent = deleted;
                deleted = deleted->right;
            }
            else break;
        }
       
        if (deleted->left == nullptr && deleted->right == nullptr)
        {
            if (parent->left == deleted) parent->left = nullptr;
            if (parent->right == deleted) parent->right = nullptr;
            deleted = nullptr;
            delete deleted;  
            return;
        }
        else if (deleted->right != nullptr)
        {
            kdNode* replacer;
            replacer = findMin(deleted->right, deleted->nodedim, 1 - deleted->nodedim);
            root->key[0] = replacer->key[0];
            root->key[1] = replacer->key[1];
            remove(replacer, replacer->key, replacer->nodedim);
        }
        else
        {
            kdNode* replacer;
            replacer = findMax(deleted->left, deleted->nodedim, 1 - deleted->nodedim);
            root->key[0] = replacer->key[0];
            root->key[1] = replacer->key[1];
            remove(replacer, replacer->key, replacer->nodedim);
        }
    }


}

kdNode* kdTree::findMin(kdNode* root, int dimCmp, int dim)
{
    if (root == nullptr) return NULL;
    if (root->left == nullptr && root->right == nullptr) return root;
    else
    {
        kdNode* min = nullptr;
        if(root->left != nullptr) min = findMin(root->left, dimCmp, 1 - root->nodedim);
        if (dimCmp != dim)
        {
            kdNode* rightmin = findMin(root->right, dimCmp, 1 - root->nodedim);
            if (min == nullptr) min = rightmin;
            else if (rightmin != nullptr) min = min->key[dimCmp] < rightmin->key[dimCmp] ? min : rightmin;
        }
        return min->key[dimCmp] < root->key[dimCmp] ? min : root;
    }
}

kdNode* kdTree::findMax(kdNode* root, int dimCmp, int dim)
{
    if (root == nullptr) return NULL;
    if (root->left == nullptr && root->right == nullptr) return root;
    else
    {
        kdNode* max = nullptr;
        if (root->right != nullptr) max = findMax(root->right, dimCmp, 1 - root->nodedim);
        if (dimCmp != dim)
        {
            kdNode* leftmax = findMax(root->left, dimCmp, 1 - root->nodedim);
            if (max == nullptr) max = leftmax;
            else if (leftmax != nullptr) max = max->key[dimCmp] > leftmax->key[dimCmp] ? max : leftmax;
        }
        return max->key[dimCmp] < root->key[dimCmp] ? max : root;
    }
}

vector<struct kdNode*> kdTree::rangeSearch(kdNode* root, int dim, int lower_bound[], int upper_bound[])
{
    vector<struct kdNode*> nodesfound;
    if (root == nullptr) return nodesfound;
    else
    {
        if (root->key[0] >= lower_bound[0] && root->key[1] >= lower_bound[1] && root->key[0] <= upper_bound[0] && root->key[1] <= upper_bound[1])
        {
            nodesfound.push_back(root);
        }
        if (root->left != nullptr)
        {
            vector<struct kdNode*> leftfound;
            leftfound = rangeSearch(root->left, 1 - root->nodedim, lower_bound, upper_bound);
            nodesfound.insert(nodesfound.end(), leftfound.begin(), leftfound.end());
        }
        if (root->right != nullptr)
        {
            vector<struct kdNode*> rightfound;
            rightfound = rangeSearch(root->right, 1 - root->nodedim, lower_bound, upper_bound);
            nodesfound.insert(nodesfound.end(), rightfound.begin(), rightfound.end());
        }
        return nodesfound;
    }
}


// ==================== trie (prefix tree) ======================
Trie::Trie() 
{
    root = new TrieNode;
    root->flag = true;
}

void Trie::insert(string word) 
{
    map<char, TrieNode*>::iterator iter;
    map<char, TrieNode*> *p = &(root->next);
    TrieNode* node = root;
    int len = word.length();
    int n = 0;
    char ch = word[n];
    while (true)
    {
        bool isexist = false;
        for (iter = p->begin(); iter != p->end(); iter++)
        {
            if (iter->first == ch)
            {
                isexist = true;
                node = iter->second;
                break;
            }
        }
        if (isexist)
        {
            if (n < len - 1)
            {
                n++;
                ch = word[n];
                p = &(node->next);
            }
            else
            {
                n++;
                ch = '$';
                p = &(node->next);
            }
        }
        else
        {
            if (!node->flag || node == root)
            {
                node->flag = false;
                TrieNode* leaf = new TrieNode;
                leaf->flag = true;
                leaf->word = word;
                p->insert(pair<char, TrieNode*>(ch, leaf));
                //p = &(root->next);
                break;
            }
            else
            {
                string str = node->word;
                while (str[n] == ch && n < len && n < str.length())
                {
                    node->word.clear();
                    node->flag = false;
                    TrieNode* leaf = new TrieNode;
                    leaf->flag = true;
                    leaf->word = word;
                    p->insert(pair<char, TrieNode*>(ch, leaf));
                    node = leaf;
                    p = &(node->next);
                    n++;
                    ch = word[n];
                }
                node->word.clear();
                node->flag = false;
                TrieNode* leaf1 = new TrieNode;
                TrieNode* leaf2 = new TrieNode;
                leaf1->flag = true;
                leaf2->flag = true; 
                leaf1->word = str;
                leaf2->word = word;
                if (n == len)
                {
                    p->insert(pair<char, TrieNode*>(str[n], leaf1));
                    p->insert(pair<char, TrieNode*>('$', leaf2));
                   
                }
                else if (n == str.length())
                {
                    p->insert(pair<char, TrieNode*>('$', leaf1));
                    p->insert(pair<char, TrieNode*>(word[n], leaf2));
                }
                else if(str[n] != word[n])
                {

                    p->insert(pair<char, TrieNode*>(str[n], leaf1));
                    p->insert(pair<char, TrieNode*>(word[n], leaf2));
                }

                //p = &(root->next);
                break;
            }
        }
    }
}


bool Trie::search(string word) 
{
    map<char, TrieNode*>::iterator iter;
    map<char, TrieNode*> *p = &(root->next);
    TrieNode* node = root;
    int n = 0;
    int len = word.length();
    char ch = word[n];
    while (true)
    {
        bool isexist = false;
        for (iter = p->begin(); iter != p->end(); iter++)
        {
            if (iter->first == '$')
            {
                if (iter->second->word == word) return true;
            }
            if (iter->first == ch)
            {
                isexist = true;
                node = iter->second;
                //break;
            }
        }
        if (!isexist)
        {
            if (node->flag)
            {
                if (node->word == word) return true;
            }
            return false;
        }
        if (n >= len - 1)
        {
            if (node->flag)
            {
                if(node->word == word) return true;
            }
            n++;
            ch = '$';
            p = &(node->next);
        }
        else
        {
            n++;
            ch = word[n];
            p = &(node->next);
        }
    }
}


bool Trie::startsWith(string prefix) 
{
    map<char, TrieNode*>::iterator iter;
    map<char, TrieNode*> *p = &(root->next);
    TrieNode* node = root;
    int n = 0;
    int len = prefix.length();
    char ch = prefix[n];
    while (true)
    {
        bool isexist = false;
        for (iter = p->begin(); iter != p->end(); iter++)
        {
            if (iter->first == '$')
            {
                if (node->word.find(prefix) == 0) return true;
            }
            if (iter->first == ch)
            {
                isexist = true;
                node = iter->second;
                //break;
            }
        }
        if (!isexist)
        {
            if (node->flag)
            {
                if (node->word.find(prefix) == 0) return true;
            }
            return false;
        }
        if (n >= len - 1)
        {
            return true;
        }
        else
        {
            n++;
            ch = prefix[n];
            p = &(node->next);
        }
    }
}
