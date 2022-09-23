#include <iostream>
#include <string>
using namespace std;

int COUNTER = 0;

int getNumber()
{
    int number = 0;
    for (;;)
    {
        if ((cin >> number).good() && number > 0)
            return number;
        cin.clear();
        cin.ignore();
        cout << "Wrong number" << endl;
    }
}

class Student
{   
public: 
      Student()   //конструктор по умолчанию
      {
          name = "No name";
          rate = 0;
          id = COUNTER++;   
      }
      Student(string n)  //конструктор инициализации
      {
          id = COUNTER++; 
          name = n;
          rate = 0;
      }
      ~Student()
      {
          cout << endl << "--------------------------";
          cout << "Destructor Number " << id << " worked" << endl;
      }
      friend class Decan;
      void friend show(Student& student);
private: int id;
         string name; 
         int rate;
};

class Decan
{
public:
    void setRate(Student& student)
    {
        cout << "Student's Num. " << student.id << " rate is " << endl;
        student.rate = getNumber();
    }
};

void show(Student& student)
{
    cout << "Name: " << student.name << endl;
    cout << "Id: " << student.id << endl;
    cout << "Rate: " << student.rate << endl;
}

int main()
{
    Student s1;
    show(s1);
    cout << endl;
    Student s2("Tom");
    show(s2);
    cout << "---------------------------------------" << endl;
    Decan decan;
    decan.setRate(s1);
    cout << endl;
    show(s1);
    cout << endl;
    decan.setRate(s2);
    cout << endl;
    show(s2);
    cout << "---------------------------------------" << endl;
    Student* Univer = new Student[2];  
    for (int i = 0; i < 2; i++)
    {
        cout << endl;
        show(Univer[i]);
        cout << endl;
        decan.setRate(Univer[i]);
        cout << endl;
        show(Univer[i]);
    }
    delete[] Univer; //вызов деструктора для каждого объекта массива
    Univer = nullptr;
    return 0;
}

