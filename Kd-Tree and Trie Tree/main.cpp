#include <iostream>
#include "tree.h"
using namespace std;


int main(int argc, const char *argv[]){
    // ============================== Test main for k-d tree =========================
    const int k = 2;
    kdTree* obj = new kdTree();
    int points[][k] = {{30, 40}, {5, 25}, {70, 70}, {10, 12}, {50, 30}, {35, 45}};

    /********************initial insert************************/
    obj->insert(obj->root, points[0], 0);
    obj->insert(obj->root, points[1], 0);
    obj->insert(obj->root, points[2], 0);
    obj->insert(obj->root, points[3], 0);
    kdNode* res1 = obj->search(obj->root, points[2], 0);
    /********************verify res1: 70 70****************/
    if(res1 == NULL)
        cout << "error!" << endl;
    else
        cout << res1->key[0] << " " << res1->key[1] << endl;

    obj->remove(obj->root, points[2], 0);
    kdNode* res2 = obj->search(obj->root, points[2], 0);
    /********************verify res2: NULL*****************/
    if(res2 != NULL)
        cout << "error!" << endl;
    else
        cout << "ok!" << endl;

    kdNode* res3 = obj->findMin(obj->root, 1, 0);
    /********************verify res3: 10 12****************/
    if(res3 == NULL)
        cout << "error!" << endl;
    else
        cout << res3->key[0] << " " << res3->key[1] << endl;

    int bounds[][k] = {{6, 15}, {50, 50}};
    vector<kdNode*> res4 = obj->rangeSearch(obj->root, 0, bounds[0], bounds[1]);
    /********************verify res4: 30 40****************/
    for(int i=0; i<res4.size(); ++i)
        cout << res4[i]->key[0] << " " << res4[i]->key[1] << endl;

    
    // =============================== Test cases for trie ===========================
    // Case1: output = 1 0 1 1
    Trie* obj1 = new Trie();
    obj1->insert("apple");
    cout << obj1->search("apple") << ' ';
    cout << obj1->search("app") << ' ';  // =0 because "app" is not a word, but a prefix
    cout << obj1->startsWith("app") << ' ';
    obj1->insert("app");
    cout << obj1->search("app") << ' ';  // =1 because now "app" is a inserted word
    
    cout << endl;
    // Case2: output = 0 0 1 1 1
    Trie* obj2 = new Trie();
    obj2->insert("import");
    obj2->insert("important");
    obj2->insert("importance");
    cout << obj2->search("importantly") << ' ';
    cout << obj2->startsWith("impp") << ' ';
    cout << obj2->startsWith("import") << ' ';
    cout << obj2->startsWith("importan") << ' ';
    cout << obj2->search("import") << ' ';
    
    cout << endl;
    // Case3: output = 0 1 0 1
    Trie* obj3 = new Trie();
    cout << obj3->search("cat") << ' ';
    obj3->insert("cate");
    cout << obj3->startsWith("cat") << ' ';
    obj3->insert("category");
    cout << obj3->search("cater") << ' ';
    cout << obj3->search("category") << ' ';
    
    cout << endl;
    // Case4: output = 0 0 0
    Trie* obj4 = new Trie();
    obj4->insert("bad");
    obj4->insert("dad");
    obj4->insert("mad");
    cout << obj4->search("ad") << ' ';
    cout << obj4->startsWith("ad") << ' ';
    cout << obj4->search("pad") << ' ';
    
    cout << endl;
    // Case5: output = 0 1 0
    Trie* obj5 = new Trie();
    obj5->insert("go");
    cout << obj5->startsWith("goo") << ' ';
    obj5->insert("google");
    cout << obj5->startsWith("goo") << ' ';
    cout << obj5->search("goo") << ' ';

    return 0;
}
