#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Queuesize 100000

typedef struct node { // 队列元素类型 
	char str[15];
	int count;
} Node;

typedef struct queue { // 队列结构 
	int head; // 头
	int tail; // 尾
	int len; // 长度
	Node data[Queuesize]; // 队列内容 
}queues;

void initqueue(queues *q) { // 队列初始化 
	q -> head = 0;
	q -> tail = 0;
	q -> len = 0;
}

void push(queues *q, Node n) {
	q -> len ++;
	q -> data[q -> tail] = n;
	q -> tail = (q -> tail + 1) % Queuesize;
}

void pop(queues *q) {
	q -> len --;
	q -> head = (q -> head + 1) % Queuesize;
}

Node front(queue *q) {
	return q->data[q->head];
}

int isEmpty(queue *q) {
	if (q -> head == q -> tail) return 1;
	else return 0;
}

int is(char *s) {
    if(strstr(s,"2012") != NULL) // 判断子串 
        return 1;
    else
        return 0;
}

void swap(char *s, int i) {
    char c = s[i];
    s[i] = s[i+1];
    s[i+1] = c;
}

void BFS(queues *q, int n) {
	while(isEmpty(q)==0) {
		Node now = front(q);
		pop(q);
		if(is(now.str)) {
			printf("%d\n",now.count); 
			return;
		} else {
			for (int i = 0; i < n - 1; i++) {
				Node temp = now;
				swap(temp.str, i);
				temp.count = now.count + 1;
				if (is(temp.str)) {
					printf("%d\n", temp.count);
					return; 
				} else if(temp.count > 13) {
					printf("-1\n");
					return;
				} else {
					push(q, temp);
				}
			}
		}
	}
} 

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		char *str = (char *)malloc(sizeof(char) * (n + 1));
		scanf("%s", str);
		if (n < 4) {
			printf("-1\n");
			continue;
		}
		// 第一个节点初始化 
		Node first;
        strcpy(first.str,str);
        first.count = 0;
        // 队列初始化 
		queues q;
        initqueue(&q);
        // 将第一个节点放入队列中 
		push(&q,first);
		// 广度优先搜索 
		BFS(&q,n);
	}
	return 0;
}