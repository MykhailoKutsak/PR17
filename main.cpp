#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

struct Point // Зберігання координат точки
{
double x;
double y;
};

double area(Point* points, int size) // Обчислення площі прямокутника
{
double side1 = sqrt(pow(points[1].x - points[0].x, 2) + pow(points[1].y - points[0].y, 2));

double side2 = sqrt(pow(points[2].x - points[1].x, 2) + pow(points[2].y - points[1].y, 2));

return side1 * side2; // Сама площа
}

int main()
{
srand(time(0)); // Генеруємо випадкові числа, якщоо користувач захоче

int choice;

Point* rectangle = new Point[4]; // Масив з чотирма вершинами прямокутника

cout << "1 - Manual input" << endl;
cout << "2 - Random generation" << endl;
cin >> choice;

if (choice == 1) // Для введення даних користувачем
{
for (int i = 0; i < 4; i++)
{
cout << "Point " << i + 1 << endl;
cout << "x = ";
cin >> rectangle[i].x;
cout << "y = ";
cin >> rectangle[i].y;
}
}
else if (choice == 2) // Генерація координат випадковим чином
{
rectangle[0].x = 0;
rectangle[0].y = 0;

rectangle[1].x = rand() % 10 + 1;
rectangle[1].y = 0;

rectangle[2].x = rectangle[1].x;
rectangle[2].y = rand() % 10 + 1;

rectangle[3].x = 0;
rectangle[3].y = rectangle[2].y;

cout << "Generated points:" << endl;

for (int i = 0; i < 4; i++)
{
cout << "(" << rectangle[i].x
<< "; " << rectangle[i].y
<< ")" << endl;
}
}
else
{
cout << "Wrong chose" << endl;
delete[] rectangle;
return 0;
}

cout << "Area = " // обчислення плоші прямокутн
<< area(rectangle, 4)
<< endl;

delete[] rectangle; //звільнення пам'яті

return 0;
}
