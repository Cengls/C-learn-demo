#include <iostream>
/*
    *Linklist Simple Demo

        *Zhanmin Su  
  
            *2023.07.06 20:07

            *2024.03.22 10:47 revise 1


*/

using namespace std;

#define LIST_INIT_SIZE 100; 

typedef struct{
    char name[8];
    
}ListItem;

typedef struct List
{
    //定义指针以为动态分配地址
   ListItem ListItem;

   struct List* prev;
    
   struct List* next;

}List;




//建表
List* createList(ListItem item){

    List* list= new List;

   if(list==NULL) {cout<< "Error:" ; return NULL; }
   else{
        list -> ListItem = item;
        list -> next = NULL;
        list -> prev = NULL;

        return list;
    }

    
}

//初始化链表
List* intiList(List* L){
    //生成一个空数据体
    ListItem listitem= { ""};

    L = createList(listitem);
    //等于本身
    L -> next = L;
    L -> prev = L;
    return L;
}

//头部插入元素
void pushfrontList(List *L ,ListItem item ){
    //判断是否定义范围内
    
    List* newlist = createList(item);
    //tail指向l的后继
    List* tail = L -> next;
    //l的后继的前驱指向新的元素
    tail -> prev = newlist;
    //l的后继等于新的元素
    L -> next = newlist;

    newlist-> next = tail;
    newlist-> prev = L;

}

//尾部插入元素
void pushbackList(List *L ,ListItem item ){
    //判断是否定义范围内
    
    List* newlist = createList(item);
    //tail指向l的前驱
    List* tail = L -> prev;
    //l的前驱的后继指向新的元素
    tail -> next = newlist;
    //l的前驱等于新的元素
    L -> prev = newlist;

    newlist-> next = L;
    newlist-> prev = tail;

}

//弹出尾部元素
void popbackList(List *L){
     //tail指向l的前驱
    List* tail = L -> prev;
     //指向tail的前驱
    List* prev = tail -> prev;
    //l的前驱变为 prev (l的前驱 的前驱)
    L->prev = prev;
    // prev 的后继变为 L
    prev-> next = L;
    free(tail);
    tail = NULL;

}

//弹出头部元素
void popfrontList(List *L){
     //tail指向l的后继
    List* tail = L -> next;
     //指向tail的后继
    List* next = tail -> next;
    //l的后继变为 next (l的后继 的后继)
    L->next = next;
    // prev 的前驱变为 L
    next-> prev = L;
    free(tail);
    tail = NULL;

}

//获取表内是否含有指定元素，有则返回
List* getListItem(List *L, ListItem item){
    List* pos = L-> next;
    //遍历不等于本身的话继续
    while (pos != L)
    {
       if (pos->ListItem.name == item.name)
       {
        /* code */
        return pos;
       }
       pos = pos->next;
    }
    
    return NULL;
}

//表判空

bool isEmpty(List *L){

    return (L->next==NULL ? true : false);
    
}


//获取表长度
int getlistSize(List *L){
    int n = 0;
    List* p = L -> next;
    while (p!=L)
    {
         n+=1;
        p = p->next;
    }

    //若是包含头节点则+1 
    return n+1;

}


//清除表并释放内存

void clearList(List *L){

 
    L -> next = NULL;
    free(L);


}


int main(){
    //动态存储分配
    List* list = intiList(list);

    //添加元素到表中
    ListItem listItem = {"abc"};
    
    pushfrontList(list,listItem);
        //添加元素到表中
    ListItem listItem2 = {"def"};
    pushfrontList(list,listItem2);
        //添加元素到表中
    ListItem listItem3 = {"ghi"};
    pushfrontList(list,listItem3);


    
   //查找元素
   if(getListItem(list,listItem3) != NULL) cout << "CANT FIND";

    //遍历输出列表元素

    List* p = list->next;
    while (p!=list)
    {
         cout<< p->ListItem.name ;

        p = p->next;
    }

    //获取列表长度
    cout<< getlistSize(list);

    clearList(list);
    free(list);
    
    return 0;
}