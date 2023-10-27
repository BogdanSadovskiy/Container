using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include<Windows.h>


template<class T>
class Container
{
private:
    vector <T> date;
    bool sorted;
public:
    Container() {
        sorted = false;
    };
    void addDate(T date) {
        this->date.push_back(date);
        sorted = false;
    }
    void printDate() {
        for (T n : date) {
            cout << n << " ";
        }
    };
    int getLength() {
        int i = 0;
        for (T d : date) {
            i++;
        }
        return i;
    }
    void Sort() {
        sort(date.begin(), date.end());
        this->sorted = true;
    }
    bool search(T date) {
        for (int i = 0; i < date.size(); i++) {
            if (date[i] == date) {
                return true;
            }
        }
    }
    bool searchByI(int i) {
        if (i > date.size() - 1) {
            return false;
        }
        return true;
    }
    bool delDate(int i) {
        if (!searchByI(i)) {
            return false;
        }

        int tmp = date[i - 1];
        date.erase(date.begin() + i - 1);
        return true;
    }
};




int main()
{

    string menu;
    Container<int>* container = new Container <int>();
    do {
        system("cls");
        cout << "Add -------- 1\n";
        cout << "Delete ----- 2\n";
        cout << "Sort date -- 3\n";
        cout << "Exit ------- E\n";
        container->printDate(); cout << endl;
        cin >> menu;
        if (menu == "E" || menu == "e") {
            break;
        }
        else if (menu == "1") {
            int date;
            cout << "Input some date\n";
            cin >> date;
            container->addDate(date);

        }
        else if (menu == "2") {
            if (container->getLength() == 0) {
                cout << "Nothing to delete\n";
                Sleep(1000);
                continue;
             }
             cout << "What element do you want to delete?\n";
             cout << "1 - " << container->getLength() << endl;
             int i;
             cin >> i;
             int date = container->delDate(i);
             cout << "Deleted " << date;

 
        }
        else if (menu == "3") {
            container->Sort();
        }
    } while (true);



}