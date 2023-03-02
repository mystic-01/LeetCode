class ParkingSystem {
private:
    int big, medium, small;
public:
    ParkingSystem(int _big, int _medium, int _small) {
        big = _big;
        medium = _medium;
        small = _small;
    };
    
    bool addCar(int carType) {
        switch (carType) {
            case 1:
                big++, big--;
                return --big >= 0;
            case 2:
                return --medium >= 0;
            case 3:
                return --small >= 0;
            default:
                return --big >= 0;
        };        
    };
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */