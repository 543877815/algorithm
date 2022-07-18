// ʱ�临�Ӷȣ�O(1)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    using Coor = vector<double>;

    vector<double> intersection(vector<int> &start1, vector<int> &end1, vector<int> &start2, vector<int> &end2) {
        int ax = start1[0], ay = start1[1], bx = end1[0], by = end1[1];
        int cx = start2[0], cy = start2[1], dx = end2[0], dy = end2[1];
        int acx = cx - ax, acy = cy - ay, abx = bx - ax, aby = by - ay, adx = dx - ax, ady = dy - ay;
        int cax = ax - cx, cay = ay - cy, cbx = bx - cx, cby = by - cy, cdx = dx - cx, cdy = dy - cy;
        // �������
        auto cross = [](int ux, int uy, int vx, int vy) {
            return ux * vy - vx * uy;
        };
        // �ж��߶� (ux, uy) - (vx, vy) �Ƿ���� (mx, my);
        auto bothSide = [&](int mx, int my, int ux, int uy, int vx, int vy) {
            return (ux - mx) * (vx - mx) <= 0 && (uy - my) * (vy - my) <= 0;
        };
        // �� x Ϊ��һ�ؼ��֣�y Ϊ�ڶ��ؼ��ֱȽ�������Ĵ�С
        auto cmp = [](const Coor &u, const Coor &v) {
            if (u.size() == 0 || v.size() == 0) return v.size() == 0;
            return (u[0] != v[0]) ? (u[0] < v[0]) : (u[1] < v[1]);
        };

        // ���ߴ����T�δ���
        if (cross(cax, cay, cbx, cby) == 0 || cross(adx, ady, abx, aby) == 0) {
            bool aInCd = bothSide(ax, ay, cx, cy, dx, dy);
            bool bInCd = bothSide(bx, by, cx, cy, dx, dy);
            bool cInAb = bothSide(cx, cy, ax, ay, bx, by);
            bool dInAb = bothSide(dx, dy, ax, ay, bx, by);
            Coor ans;
            if (aInCd) ans = min(ans, Coor({(double) ax, (double) ay}), cmp);
            if (bInCd) ans = min(ans, Coor({(double) bx, (double) by}), cmp);
            if (cInAb) ans = min(ans, Coor({(double) cx, (double) cy}), cmp);
            if (dInAb) ans = min(ans, Coor({(double) dx, (double) dy}), cmp);
            return ans;
        }

        // �ж������߶��Ƿ��й�����
        auto intersect = [&]() {
            return cross(acx, acy, abx, aby) * cross(adx, ady, abx, aby) <= 0 && cross(cax, cay, cdx, cdy) * cross(cbx, cby, cdx, cdy) <= 0;
        };

        if (!intersect()) return Coor();

        // ���������� PQM �����
        auto getArea = [&](int px, int py, int qx, int qy, int mx, int my) -> double {
            int mpx = px - mx, mpy = py - my, mqx = qx - mx, mqy = qy - my;
            return fabs(double(0.5) * cross(mpx, mpy, mqx, mqy));
        };

        // ���ȷֵ�
        double ck = getArea(ax, ay, bx, by, cx, cy), dk = getArea(ax, ay, bx, by, dx, dy);
        double k = ck / dk;
        double rx = (cx + k * dx) / (1 + k), ry = (cy + k * dy) / (1 + k);
        return Coor({rx, ry});
    }
};