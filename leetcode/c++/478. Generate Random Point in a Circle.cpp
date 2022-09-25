// 拒绝采样
// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    double radius;
    double x_center;
    double y_center;
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};

    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }

    vector<double> randPoint() {
        double x0 = x_center - radius;
        double y0 = y_center - radius;

        while(true) {
            double xg = x0 + uni(rng) * 2 * radius;
            double yg = y0 + uni(rng) * 2 * radius;
            if (sqrt(pow((xg-x_center), 2) + pow((yg-y_center), 2)) <= radius) return {xg, yg};
        }
    }
};

// 极坐标
// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    double radius;
    double x_center;
    double y_center;
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};

    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }

    vector<double> randPoint() {
        double d = radius * sqrt(uni(rng));
        double theta = uni(rng) * (2 * M_PI);
        return {d * cos(theta) + x_center, d * sin(theta) + y_center};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */