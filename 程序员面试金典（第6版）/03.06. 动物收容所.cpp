class AnimalShelf {
private:
    queue<int> dogs;
    queue<int> cats;
public:
    AnimalShelf() {

    }

    void enqueue(vector<int> animal) {
        if (animal[1] == 0) cats.push(animal[0]);
        else if (animal[1] == 1) dogs.push(animal[0]);
    }

    vector<int> dequeueAny() {
        if (dogs.size() == 0 && cats.size() == 0) return {-1, -1};
        if (dogs.size() == 0) {
            int id = cats.front();
            cats.pop();
            return {id, 0};
        }
        if (cats.size() == 0) {
            int id = dogs.front();
            dogs.pop();
            return {id, 1};
        }
        int catId = cats.front();
        int dogId = dogs.front();
        if (catId < dogId) {
            cats.pop();
            return {catId, 0};
        } else {
            dogs.pop();
            return {dogId, 1};
        }
    }

    vector<int> dequeueDog() {
        if (dogs.size() == 0) return {-1, -1};
        int id = dogs.front();
        dogs.pop();
        return {id, 1};
    }

    vector<int> dequeueCat() {
        if (cats.size() == 0) return {-1, -1};
        int id = cats.front();
        cats.pop();
        return {id, 0};
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */
