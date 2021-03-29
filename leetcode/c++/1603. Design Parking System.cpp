// 时间复杂度：O(1)
// 空间复杂度：O(1)
class ParkingSystem {
public:
    int big_count = 0;
    int medium_count = 0;
    int small_count = 0;
    int max_big, max_medium, max_small;

    ParkingSystem(int big, int medium, int small) {
        max_big = big;
        max_medium = medium;
        max_small = small;
    }

    bool addCar(int carType) {
        if (carType == 1) {
            if (big_count == max_big) return false;
            else {
                big_count++;
                return true;
            }
        } else if (carType == 2) {
            if (medium_count == max_medium) return false;
            else {
                medium_count++;
                return true;
            }
        } else {
            if (small_count == max_small) return false;
            else {
                small_count++;
                return true;
            }
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */