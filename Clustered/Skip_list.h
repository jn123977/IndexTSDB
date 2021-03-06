//
// Created by cola on 2021/2/5.
//

#ifndef TEST_SKIP_LIST_H
#define TEST_SKIP_LIST_H


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <map>
#include <string.h>

#define MAX_LEVEL 30

using namespace std;
typedef list<char *> CHARLIST;

typedef struct node {
    node *right;  //后驱
    node *down;   //下驱
    char * key;       //Key  timestame
    CHARLIST list;  //Value 数据容器
} data_node;

struct skip_list {
    data_node **header;    //头指针
    int max_level;    //最大层数
    int size;   //基本链表中的节点数
    int tID;    //tableID
};
static map<int, skip_list *> tableMap;      //存放调表


//获取随机层
int get_current_level();

//初始化跳表
skip_list *skip_list_init(int tableId);

//查找值
data_node *find_x_from_skip_list(skip_list *sl, char * x);

//把数据插入到跳表中
data_node *insert_x_into_list(node *head, char * x, char *data);

int insert_x_into_skip_list(skip_list *sl, char * x, char *data);

//删除调表的数据
int remove_data_from_list(node *head, char * x);

int remove_x_from_skip_list(skip_list *sl, char * key);

//输出调表
int print_list(skip_list *sl);

//返回list中所有的元素
void put_CharList(CHARLIST list);

//返回数据给源语
skip_list *all_data(int dataID);


#endif //TEST_SKIP_LIST_H
