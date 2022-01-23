class Solution {
public:
    double distance(vector<vector<int>> &positions, double center_x, double center_y) {
        int n = positions.size();
        double res = 0;
        for (int i = 0; i < n; i++) {
            res += sqrt(pow((positions[i][0] - center_x), 2.0) + pow((positions[i][1] - center_y), 2.0));
        }
        return res;
    }

    double dp[4][2] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1}
    };

    double getMinDistSum(vector<vector<int>> &positions) {
        int n = positions.size();
        if (n == 0) return 0;
        double lr = 1.0;
        vector<double> point = {(double) positions[0][0], (double) positions[0][1]};
        double last_f_x = distance(positions, point[0], point[1]);
        double res = last_f_x;
        while (true) {
            double new_dx = 0;
            for (int i = 0; i < 4; i++) {
                double new_x = (dp[i][0] * lr + point[0]);
                double new_y = (dp[i][1] * lr + point[1]);
                double new_f_x = distance(positions, new_x, new_y);
                double dx = ((new_f_x - last_f_x) / abs(new_y - point[1] + new_x - point[0]));

                if (dx < new_dx) {
                    new_dx = dx;
                    point[0] = new_x;
                    point[1] = new_y;
                    res = min(res, new_f_x);
                    last_f_x = new_f_x;
                    // cout << "x: " << point[0] << " , y: " << point[1] << ", lr: " << lr << ", res: " << res << endl;
                }
            }

            if (lr < 10e-6) break;
            if (new_dx == 0) lr /= 10;
        }

        return res;
    }
};