#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    int power;
    int cost;

public:
    //конструктор без параметров
    Car() {
        brand = " ";
        power = 0;
        cost = 0;
    }

    //конструктор с 3 параметрами
    Car(string _brand, int _power, int _cost) {
        brand = " ";
        brand = _brand;
        power = _power;
        cost = _cost;
    }

    //конструктор с 1 параметром
    Car(string _brand) {
        brand = " ";
        brand = _brand;
        power = 0;
        cost = 0;
    }

    void read() { //Ввод данных
        cout << "Enter a brand: ";   cin >> brand;
        cout << "Enter a power: ";   cin >> power;
        cout << "Enter a cost: ";    cin >> cost;
    }

    void display() {
        try {
            if (brand == " ") throw 228;
            cout << brand << " - " << power << "л.с. - " << cost << "р" << endl;
            cout << endl;
        }
        catch (int e) {
            cout << "Ошибка: " << e << "\nНе указана марка!" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    cout << "Oдномерный статический массив" << endl;
    Car cars[3]{
        Car("car0", 400, 3000000),
        Car("car1", 401, 3020000),
        Car("car2", 421, 3024000)
    };

    for (int i = 0; i < 3; i++) 
        cars[i].display();

    cout << "\nДвумерный статический массив" << endl;
    Car cars1[2][2] {
        {
        Car("car00", 400, 3200000),
        Car("car01", 401, 302000)
        },
        {
        Car("car10", 430, 3002000),
        Car("car11", 101, 3020000)
        }
    };

    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 2; j++)
            cars1[i][j].display();
    
    system("pause");
    system("cls");

    cout << "Oдномерный динамический массив" << endl;
    Car* cars2 = new Car[2];

    for (int i = 0; i < 2; i++) 
        cars2[i] = Car("car" + to_string(i), 210, 1332130);

    for (int i = 0; i < 2; i++)
        cars2[i].display();

    cout << "Двумерный динамический массив" << endl;
    Car** cars3 = new Car*[2];

    for (int i = 0; i < 2; i++) 
        cars3[i] = new Car[2];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cars3[i][j] = Car("car" + to_string(i) + to_string(j), 21*(i+j+1), 133*(i+j+1));

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cars3[i][j].display();

    return 0;
}
