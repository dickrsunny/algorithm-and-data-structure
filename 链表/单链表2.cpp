#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct list{
    int num;
    struct list* next;
}List;

/**
*func：初始化链表。
*由于函数中调用malloc。记得free。防止内存泄露
*return：链表指针
*/
static List* initList()
{
    List* list = NULL;
    list = (List *)malloc(sizeof(List));

    if(list == NULL)
    {
        printf("[initList]malloc list failed!\n");
        return NULL;
    }

    list->next = NULL;

    return list;
}

/**
*func：打印链表信息
*param：链表头结点
*return：NULL
*/
static void priList(List* list)
{
    if(list == NULL)
        return ;
    printf("----------------------\n");
    while(list->next)
    {
        printf("%d,\n", list->next->num);
        list = list->next;
    }
    printf("----------------------\n");
}

/**
*func:根据num大小插入链表节点
*param：list - 头结点，num - 插入的数据(可根据类型扩展)
*return：0 insert success. -1 insert error
*/
static int insertList(List* list, int num)
{
    List* now = NULL;
    List* head = list;

    now = initList();
    if(now == NULL)
        return -1;

    now->num = num;

    while(head->next && num >= head->next->num)
        head = head->next;

    //插入在第一个位置和最后一个位置
    if(head->next == NULL)
        head->next = now;
        //插入到中间位置
    else
    {
        now->next = head->next;
        head->next = now;
    }

    return 0;
}

/**
*func:计算链表的长度
*param：li - 头结点
*return：NULL
*/
static int numList(List* head)
{
    int len = 0;
    while(head && head->next)
    {
        len++;
        head = head->next;
    }

    return len;
}

/**
*func：调用free逐个释放链表节点
*param：list - 链表头结点
*return：NULL
*/
static void freeList(List* list)
{
    List* head = list;
    List* p = NULL;
    while(head)
    {
        p = head;
        head = head->next;
        free(p);
    }

    printf("free List ok\n");
}

/**
*func：删除相应位置的链表节点
*param：list - 链表头结点，w - 删除位置(should >0 & < sizeof(list))
*return: 0 success delete. -1 success failed.
*/
static int deleteList(List* list, int location)
{
    List* head = list;
    List* p = NULL;
    int i = 1;

    if(location <= 0 || location > numList(head))
        return -1;

    while(i++ < location && head->next)
        head = head->next;

    p = head->next;
    head->next = p->next;

    free((void *)p);
    p = NULL;

    return 0;
}

int main(int argc, char** argv)
{
    // 需要修改指针指向的变量的值
    List* head = NULL;
    int i = 0;
    head = initList();
    if(head == NULL)
        return -1;

    insertList(head, 2);
    insertList(head, 4);
    insertList(head, 6);
    insertList(head, 3);
    insertList(head, 1);

    priList(head);

    deleteList(head, 1);
    priList(head);

    deleteList(head, 2);
    priList(head);

    deleteList(head, 3);
    priList(head);

    freeList(head);

    return 0;
}