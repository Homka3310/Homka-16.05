#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
struct Motya
{
    int id;
    char text[255];
    int lenght;
    int Homka;
    void Show() {
        cout << "Age: " << Homka << endl;
    }
};

struct Charlie
{
    char name[20];
    void Show() {
        cout << "Name: " << name << endl;
        cout << "Charlie look like tomato" <<endl;
    }
};

struct Ness {
    double salary;
    void Show() {
        cout << "Salary Ness : " << salary << endl;
    }
};

struct Slava {
    int age;
    void Show() {
        cout << "Age Slava : " << age << endl;
    }
};

template<typename T>

void SaveToFile(T obj, string filename)
{
    fstream file(filename, ios::out | ios::binary);
    if (file.is_open())
    {
        file.write((char*)&obj, sizeof(T));
        cout << "Saved!" << endl;
    }
    else
    {
        cout << "Error!" << endl;
    }
}
template<typename T>
void LoadFormFile(T& obj, string filename)
{
    fstream file(filename, ios::in | ios::binary);
    if (file.is_open())
    {
        file.read((char*)&obj, sizeof(T));
        cout << "Load!" << endl;
    }
    else
    {
        cout << "Error!" << endl;
    }
}
int main()
{
    char switch_on;
    Motya motya;
    Charlie charlie;
    Ness ness;
    Slava slava;
    do {
        system("cls");
        cout << "1 - Input info" << endl;
        cout << "2 - Show info" << endl;
        cout << "3 - Save info" << endl;
        cout << "4 - Load info" << endl;
        cout << "Enter->" << endl;
        switch (switch_on)
        {
        case 1:
        {
            motya.id = 0;
            gets_s(motya.text, 255);
            motya.lenght = strlen(motya.text);
        }break;
        case 2:
        {
            slava.Show();
            ness.Show();
            motya.Show();
            charlie.Show();
        }break;
        case 3:
        {
            SaveToFile<Slava>(slava, "slava.bin");
            SaveToFile<Ness>(ness, "ness.bin");
            SaveToFile<Motya>(motya, "motya.bin");
            SaveToFile<Charlie>(charlie, "charlie.bin");
        }break;
        case 4:
        {
            LoadFormFile<Slava>(slava, "slava.bin");
            LoadFormFile<Motya>(motya, "motya.bin");
            LoadFormFile<Charlie>(charlie, "charlie.bin");
            LoadFormFile<Ness>(ness, "ness.bin");
        }break;
        default:
            cout << "Choose error";
            break;
        }
        system("pause");
    } while (true);
    return 0;

    Motya motya;
    Charlie charlie;
    Ness ness;
    Slava slava;

    slava.Show();
    ness.Show();
    motya.Show();
    charlie.Show();

    LoadFormFile<Slava>(slava, "slava.bin");
    LoadFormFile<Motya>(motya, "motya.bin");
    LoadFormFile<Charlie>(charlie, "charlie.bin");
    LoadFormFile<Ness>(ness, "ness.bin");

    slava.Show();
    ness.Show();
    motya.Show();
    charlie.Show();

    /*SaveToFile<Slava>(slava, "slava.bin");*/
    /*SaveToFile<Ness>(ness, "ness.bin");*/
    //SaveToFile<Motya>(motya, "motya.bin");
    //SaveToFile<Charlie>(charlie, "charlie.bin");
    return 0;
}