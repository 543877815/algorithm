#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n; 
    while(scanf("%d", &n) != EOF) { // 代理服务器
        char **str1 = (char **)malloc(sizeof(char*)*n);
        for (int i = 0; i < n; i++) {
            str1[i] = (char *)malloc(sizeof(char)*20);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", str1[i]);
        }
        
        // 要访问的服务器
        int m;
        scanf("%d", &m); 
        char **str2 = (char **)malloc(sizeof(char*)*m);
        for (int i = 0; i < m; i++) {
            str2[i] = (char *)malloc(sizeof(char)*20);
        }
        for (int i = 0; i < m; i++) {
            scanf("%s", str2[i]);
        }
        
        // 不符合情况 
        int flag = 0;
        if(n == 1) {
            for (int i = 0; i < m; i++) {
                if (strcmp(str2[i], str1[0]) == 0) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1) {
            printf("-1");
            continue;
        }
        
        
        // 标记代理服务器，初始化
        int *mark = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            mark[i] = 0;
        }
        int ans = 0; 
        int count = 0;
        int take = -1;
        
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (strcmp(str2[i], str1[j]) == 0 && mark[j] == 0) {
                    mark[j] = 1;
                    count ++;
                }
                // 归零
                if (count == n) {
                    for (int k = 0; k < n; k++) {
                        mark[k] = 0;
                    }
                    mark[j] = 1;
                    take = j;
                    ans ++;
                    count = 1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}