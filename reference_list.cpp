#include <iostream>
#include <stdio.h>
#include <stdlib.h>
 
using namespace std;
 
#define MAXSIZE 100
#define ERROR 0
#define OK 1
 
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node,*LinkList;
 
void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}
 
#if 0
void CreateFormHead(LinkList L)
{
    Node *s;
    char c;
    int flag=1;
    int i=0,n;
    printf("请输入单链表元素个数: ");
    scanf("%d", &n);
    getchar();    /* for '\n' */
    while(flag&&i<n)
    {
        c=getchar();
        if(c != '$')
        {
            s=(Node *)malloc(sizeof(Node));
            s->data=c;
            s->next=L->next;
            L->next=s;
        }else
            flag=0;
        i++;
    }
}
#endif
 
int InsList(LinkList *L, int i, ElemType e)
{
    Node *pre,*s;
    int k;
 
    if(i <= 0)
        exit(0);
    pre = *L;
    k=0;
    while(pre && k < i-1)
    {
        pre = pre->next;
        k = k+1;
    }
    if(pre==NULL)
    {
        printf("插入位置不合理\n");
        return ERROR;
    }
    s = (Node*)malloc(sizeof(Node));
    s->data = e;
    s->next = pre->next;
    pre->next = s;
 
    return OK;
}
 
int DelList(LinkList *L,int i,ElemType *e)
{
    Node *pre,*r;
    int k = 0;
    pre = *L;
 
    k=0;
    while(pre->next && k<i-1)
    {
        pre = pre->next;
        k=k+1;
    }
    if(pre->next==NULL)
    {
        printf("删除结点的位置i不合理！");
        return ERROR;
    }
    r = pre->next;
    pre->next = r->next;
    *e = r->data;
    free(r);
    return OK;
}
int print(LinkList L)
{
    if (!L)
        return ERROR;
    Node *pre;
    pre = L->next;
    while(pre) {
        cout<<pre->data<<endl;
        pre=pre->next;
    }
 
    return OK;
}
int main()
{
    LinkList L;
    ElemType e;
    int pos, ret, ch;
    InitList(&L);
    //print(L);
 
    while (1) {
        printf("单链表操作顺序:(1.插入 2.删除, 3.exit)\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("请输入要插入的顺序表元素和位置: ");
                scanf("%d%d", &e, &pos);
                ret = InsList(&L, pos, e);
                if (ret) {
                    printf("插入后的顺序表为");
                    print(L);
                } else {
                    printf("插入失败！");
                }
                break;
 
            case 2:
                printf("请输入要删除的顺序表元素和位置: ");
                scanf("%d%d", &e, &pos);
                ret = DelList(&L, pos, &e);
                if (ret) {
                    printf("删除后的顺序表为: ");
                    print(L);
                } else {
                    printf("删除失败！\n");
                }
                break;
 
            case 3:
                return 0;
        }
    }
 
    return 0;
}
