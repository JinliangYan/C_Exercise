//
// Created by Kokomi on 2022/11/24.
//

#ifndef TREE_SEARCHTREE_H
#define TREE_SEARCHTREE_H
struct TreeNode;
struct ElementType;
typedef struct ElementType Item;
typedef struct TreeNode *SearchTree;
typedef struct TreeNode *Position;

SearchTree MakeEmpty(SearchTree T);//初始化
Position Find(Item item, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(Item item, SearchTree T);
SearchTree Delete(Item item, SearchTree T);
Item Retrieve(Position position);
void traverse(SearchTree T, void (*fp)(Item item));
#endif //TREE_SEARCHTREE_H

struct ElementType {
    int num;
};

struct TreeNode {
    Item item;
    SearchTree left;
    SearchTree right;
};
