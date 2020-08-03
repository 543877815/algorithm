// 普通约瑟环
// 时间复杂度：O(nm)
// 时间复杂度：O(n)
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n < 1 || m < 1) return -1;
        list<int> numbers;
        for (unsigned int i = 0; i < n; i++) numbers.push_back(i);
        list<int>::iterator current = numbers.begin();
        while (numbers.size() > 1) {
            for (int i = 1; i < m; i++) {
                current++;
                if (current == numbers.end()) current = numbers.begin();
            }
            list<int>::iterator next = ++current;
            if (next == numbers.end()) next = numbers.begin();
            --current;
            numbers.erase(current);
            current = next;
        }

        return *(current);
    }
};


// 递推关系，递归实现
/*
 *  最初序列f(n,m) = 删除数字k后剩下的序列重排f'(n-1,m)
 *  定义映射p(x)=(x-k-1)%n
 *  则逆映射p-1(x)=(x+k+1)%n
 *  f'(n-1,m)=p-1[f(n-1,m)]=[f(n-1,m)+k+1]%n
 *  把k=(m-1)%n代入得到f(n,m)=f'(n-1,m) = [f(n-1,m)+(m-1)%n+1]%n = [f(n-1,m)+m]%n
 *
 */
// f(n,m) = 0                       , n = 1
//        = [f(n - 1 ,m) + m] % n   , n > 1
// 空间复杂度：O(n)
// 时间复杂度：O(1)
class Solution {
private:
    int f(int n, int m) {
        if (n == 1) return 0;
        return (f(n - 1, m) + m) % n;
    }

public:
    int lastRemaining(int n, int m) {
        return f(n, m);
    }
};


// 非递归
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n < 1 || m < 1) return -1;
        int last = 0;
        for (int i = 2; i <= n; i++) {
            last = (last + m) % i;
        }
        return last;
    }
};