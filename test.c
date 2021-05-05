#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 10000
/** 函数参数：数组A，最后一个下标n，下标i，j，公共祖先结点anc的编号和值：anc，anc_data*/
/** 调用函数：向下取整函数,对数函数，需要头文件<math.h>*/
int co_ancestor(int A[], int n, int i, int j, int *anc, int *anc_data) {
    if (i == 1 || j == 1) {
        /** 如果其中一个是根节点，则无需查找，最近的公共结点为根节点 */
        *anc = 1;
        *anc_data = A[0];//假设数组是从0开始存储的
        return 0;
    }

    /** 祖先数组的创建*/
    int L1, L2;
    L1 = (int) floor(log((i))/log((2)))+1 + 1;//数组长度
    L2 = (int) floor(log((j))/log((2)))+1 + 1;
    //用动态分配内存的方式创建
    int *ancpi = (int *) calloc(L1, sizeof(int));
    int *ancpj = (int *) calloc(L2, sizeof(int));

    int anc_i = i, anc_j = j;
    int p = 0, q = 0;//计数
    while (anc_i != 1) {
        anc_i = anc_i / 2;//找父结点
        *(ancpi + p) = anc_i;//存入祖先数组
        p++;
    }
    while (anc_j != 1) {
        anc_j = anc_j / 2;//找父结点
        *(ancpj + q) = anc_j;//存入祖先数组
        q++;
    }

    /** 祖先数组的比对 */
    for (int a = 0; a < p; a++) {
        for (int b = 0; b < q; b++) {
            if (*(ancpi + a) == *(ancpj + b)) {
                *anc = *(ancpi + a);
                *anc_data = A[*anc - 1];
                free(ancpi);//记得释放内存
                free(ancpj);
                return 0;
            }
        }
    }
}

int main() {
    int A[10] = {10, 9, 13, 24, 15, 7, 8, 2, 36, 9};//预设的一个完全二叉树
    int n = 10;
    int i, j;
    int anc, anc_data;
    i = 8;
    j = 10;
    co_ancestor(A, n, i, j, &anc, &anc_data);
    printf("最近的公共结点编号是%d,值为%d", anc, anc_data);
    return 0;
}
