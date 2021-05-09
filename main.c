#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct bt
{
    struct bt *lchild;
    struct bt *rchild;
    int data;
    int find;
}BTREE;

typedef struct  stack//建立栈来储存走过的路径
{
    struct  stack *next;
    BTREE *pointer;//保存复制树的数的结点的指针

}Stack;
int Push(Stack *head,BTREE *node);
int Pop(Stack *head);
BTREE * creat();
BTREE *search(BTREE *node,int x,Stack *head,int *i,BTREE *bt[]);
void delete(BTREE *node);

int main()
{
    BTREE *head;
    int x;
    int *i;//用于记录值为x的树的结点的个数
    *i=0;
    BTREE *bt[max]; //设立指针数组
    Stack *s = (Stack *)malloc(sizeof(Stack));//设置头结点,该头结点为遍历查找x时使用的栈
    s->next=NULL;//将新建的头结点初始化
    head=creat();//创建二叉树
    printf("please input the data of the node you want to delete:\n");
    scanf("%d",&x);
    search(head,x,s,i,bt);
    for (int j = 0; j < *i; j++)
    {
        delete(bt[j]);
    }
}

int Push(Stack *head,BTREE *node)//头插法插入结点
{
    Stack *t=(Stack*)malloc(sizeof(Stack));
    t->pointer=node;
    t->next=head->next;
    head->next=t;
}

int Pop(Stack *head)//不需要返回删除的值
{
    Stack *pr;
    pr=head->next;
    head->next=pr->next;
    free(pr);

}

BTREE * creat()//按照先序遍历的顺序创建二叉树
{
    BTREE *node;
    node=(BTREE*)malloc(sizeof(BTREE));//创建新的结点
    if (node==NULL)
    {
        printf("error");
        exit;
    }
    scanf("%d",&node->data);
    if (node->data==-1)//若结点为空，则将数据域设为-1
    {
        node=NULL;
    }
    else{
        node->lchild=creat();
        node->rchild=creat();
    }
    return(node);//返回head的指针用于之后继续调用函数 
}

BTREE *search(BTREE *node,int x,Stack *head,int *i,BTREE *bt[])
{
    while(node!=NULL)//保证走遍每一个结点
    {
        int last=0;//用于记录是否所有结点遍历
        while (node->data!=x&&node->lchild!=NULL)//向最左方向开始寻找目标结点
        {
            node->find=1;//每次寻找过的地方设为1
            node=node->lchild;
            Push(head,node);

        }
        if(node->lchild==NULL)
        {

            while (node->rchild==NULL||node->rchild->find==1)//直到找到右节点不为空的结点并向右走
            {
                Pop(head);
                if (head->next==NULL)//当所有结点都遍历以后，会找不到右节点不为空且没走过的结点，这时会一直pop直到栈空，搜索完毕可以退出程序
                {
                    last=1;
                    break;
                }

                node=head->next->pointer;//取栈顶元素指向的树的结点的指针
            }
            if (last==1)
            {
                break;
            }
            node=node->rchild;//将走过的右孩子进入栈
            node->find=1;
            Push(head,node);
        }
        if(node->data==x)
        {
            bt[*i]=node;
            *i++;
        }
    }
}

void delete(BTREE *node)
{
    if (node->lchild==NULL&&node->rchild==NULL)
    {
        free(node);//走到最底端可以删除该结点
    }
    while (node->lchild!=NULL)//后序遍历删除节点
    {
        delete(node->lchild);
    }
    while (node->rchild!=NULL)
    {
        delete(node->rchild);
    }

}


    