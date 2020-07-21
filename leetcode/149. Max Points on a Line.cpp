// 直接遍历
// 时间复杂度: O(n^3)
// 空间复杂度：O(1)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //两点确定一条直线
        if(points.size()<3)return points.size();

        int Max=0;
        for(int i=0;i<points.size();++i)//i表示数组中的第i+1个点
        {
            //same用来表示和i一样的点
            int same=1;
            for(int j=i+1;j<points.size();++j)//j表示数组中的第j+1个点
            {
                int count=0;
                // i、j在数组中是重复点，计数
                if(points[i][0]==points[j][0]&&points[i][1]==points[j][1])same++;
                else{//i和j不是重复点，则计算和直线ij在一条直线上的点
                    count++;
                    long long xDiff = (long long)(points[i][0] - points[j][0]);//Δx1
                    long long yDiff = (long long)(points[i][1] - points[j][1]);//Δy1

                    for (int k = j + 1; k < points.size(); k ++)//Δy1/Δx1=Δy2/Δx2 => Δx1*Δy2=Δy1*Δx2，计算和直线ji在一条直线上的点
                        if (xDiff * (points[i][1] - points[k][1]) == yDiff * (points[i][0] - points[k][0]))
                            count++;
                }
                Max=max(Max,same+count);
            }
            if(Max>points.size()/2)return Max;//若某次最大个数超过所有点的一半，则不可能存在其他直线通过更多的点
        }
        return Max;
    }
};

class Solution {
private:
    double calc_k(vector<int> &pa, vector<int> &pb) {
        return ((double)pa[1]-(double)pb[1]) / ((double)pa[0]-(double)pb[0]);
    }

    double calc_b(vector<int> &pa, double k) {
        return (double)pa[1] - (double)pa[0] * k;
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {

            }
        }
    }
};




// 使用哈希表
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
private:
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    pair<int, int> slope(vector<int> &pa, vector<int> &pb) {
        int dx = pa[0] - pb[0];
        int dy = pa[1] - pb[1];
        int _gcb = gcd(abs(dx), abs(dy));
        dx /= _gcb;
        dy /= _gcb;
        if (dx < 0) {
            dx = -dx;
            dy = -dy;
        }
        return make_pair(dx, dy);
    }

    string pair2string(pair<int, int> a) {
        return to_string(a.first) + "/" + to_string(a.second);
    }

public:
    int maxPoints(vector<vector<int>> &points) {
        if (points.size() < 2) return points.size();
        int res = 1;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<string, int> record;
            int samepoint = 0;
            for (int j = 0; j < points.size(); j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    samepoint++;
                    continue;
                } else {
                    record[pair2string(slope(points[i], points[j]))]++;
                }
            }
            res = max(res, samepoint);
            for (auto &m : record) {
                res = max(res, m.second + samepoint);
            }
        }
        return res;
    }
};
