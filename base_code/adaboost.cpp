#include <bits/stdc++.h>
using namespace std;

class G {
private:
    float _boundary;
    bool _is_l_pos;
    float _weight;
    float _error;
public:
    static float calcWeight(double error) {
        return 0.5 * log((1 - error) / error);
    }

    float getWeight() { return _weight; };

    G(float error = 0, float boundary = 0, bool is_l_pos = false) : _error(error), _boundary(boundary), _is_l_pos(is_l_pos) {
        _weight = calcWeight(_error);
    };

    ~G() = default;

    double forward(float x) {
        return x < _boundary ? (_is_l_pos ? 1 : -1) : (_is_l_pos ? -1 : 1);
    }
};

float optimizer(vector<int> &x, vector<int> &y, vector<float> &weight, G *func) {
    int n = x.size();
    int _min = *min_element(x.begin(), x.end());
    int _max = *max_element(x.begin(), x.end());
    float _dis = 0.5;

    float error = 1;
    float boundary = _min;
    bool is_l_pos = false;

    // 简单搜索分裂边界，基本分类器
    float _boundary = _min;
    for (int i = 0; _boundary <= _max; i++, _boundary = i * _dis + _min) {
        float l_pos = 0;
        float l_neg = 0;
        for (int j = 0; j < n; j++) {
            if (j < _boundary) {
                l_pos += (y[j] != 1) * weight[j];
                l_neg += (y[j] != -1) * weight[j];
            } else {
                l_pos += (y[j] != -1) * weight[j];
                l_neg += (y[j] != 1) * weight[j];
            }
        }
        float l_err = l_pos;
        float r_err = l_neg;
        if (l_err < error) {
            error = l_err;
            boundary = _boundary;
            is_l_pos = true;
        }
        if (r_err < error) {
            error = r_err;
            boundary = _boundary;
            is_l_pos = false;
        }
    }

    // 构造模型
    *func = G(error, boundary, is_l_pos);

    // 计算规范化因子
    float Zn = 0;
    for (int i = 0; i < n; i++) {
        Zn += weight[i] * exp(-func->getWeight() * y[i] * func->forward(x[i]));
    }

    // 更新权重
    for (int i = 0; i < n; i++) {
        weight[i] = (weight[i] / Zn) * exp(-func->getWeight() * y[i] * func->forward(x[i]));
    }

    return error;
}

float getEnsemblePred(vector<G* >&Gs, float x) {
    float res = 0;
    int m = Gs.size();
    for (int j = 0; j < m; j++) {
        res += Gs[j]->forward(x) * Gs[j]->getWeight();
    }
    return res;
}

int getEnsembleError(vector<int> &x, vector<int> &y, vector<G *> &Gs) {
    int n = x.size();
    int m = Gs.size();
    int error = 0;
    auto sign = [=](float x) -> int { return x > 0 ? 1 : -1; };
    for (int i = 0; i < n; i++) {
        float score = getEnsemblePred(Gs, x[i]);
        error += sign(score) != y[i];
    }
    return error;
}

vector<G *> adaboost(vector<int> &x, vector<int> &y) {
    int n = x.size();
    assert(x.size() == y.size());
    vector<float> weight(n, static_cast<float>(1) / n);
    vector<G *> Gs;
    while (!Gs.size() || getEnsembleError(x, y, Gs)) {
        G *model = new G();
        optimizer(x, y, weight, model);
        Gs.push_back(model);
    }
    return Gs;
}


int main() {
    // 李航：统计学习方法，P159
    vector<int> x = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> y = {1, 1, 1, -1, -1, -1, 1, 1, 1, -1};
    vector<G *> Gs = adaboost(x, y);
    for (int i = 0; i < x.size(); i++) {
        cout << getEnsemblePred(Gs, x[i]) << " ";
    }
}
