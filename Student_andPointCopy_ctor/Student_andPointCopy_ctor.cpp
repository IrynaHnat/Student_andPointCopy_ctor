

#include <iostream>
#include<string>
#include<fstream>
using namespace std;

//1
struct Date
{
    size_t day, month, year;
    string getDate()const
    {
        return (day < 10 ? "0" : "") + to_string(day) + "." + (month < 10 ? "0" : "") + to_string(month) + "." + to_string(year);
    }
};


class Student {
private:
    char* fullName;
    Date birthDate{};
    string phone;
    string city;
    string country;
    string institution;
    string institutionCity;
    string institutionCountry;
    string groupNumber;

    static int instanceCount;

public:
    Student() : Student("NoName", { 0, 0, 0 }, "NoPhone", "NoCity", "NoCountry", "NoInstitution", "NoCity", "NoCountry", "NoGroup") {}


    Student(const char* fullName, const Date& birthDate, const string& phone,
        const string& city, const string& country, const string& institution,
        const string& institutionCity, const string& institutionCountry, const string& groupNumber)
        : birthDate(birthDate), phone(phone), city(city), country(country),
        institution(institution), institutionCity(institutionCity),
        institutionCountry(institutionCountry), groupNumber(groupNumber) {

        setFullName(fullName);
        ++instanceCount;
    }

    Student(const Student& other) {
        setFullName(other.fullName);
        birthDate = other.birthDate;
        phone = other.phone;
        city = other.city;
        country = other.country;
        institution = other.institution;
        institutionCity = other.institutionCity;
        institutionCountry = other.institutionCountry;
        groupNumber = other.groupNumber;
        ++instanceCount;
    }

    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] fullName;

            setFullName(other.fullName);
            birthDate = other.birthDate;
            phone = other.phone;
            city = other.city;
            country = other.country;
            institution = other.institution;
            institutionCity = other.institutionCity;
            institutionCountry = other.institutionCountry;
            groupNumber = other.groupNumber;
        }
        return *this;
    }


    ~Student() {
        delete[] fullName;
        --instanceCount;
    }

    static int getInstanceCount() {
        return instanceCount;
    }

    inline const char* getFullName() const { return fullName; }
    inline Date getBirthDate() const { return birthDate; }
    inline string getPhone() const { return phone; }
    inline string getCity() const { return city; }
    inline string getCountry() const { return country; }
    inline string getInstitution() const { return institution; }
    inline string getInstitutionCity() const { return institutionCity; }
    inline string getInstitutionCountry() const { return institutionCountry; }
    inline string getGroupNumber() const { return groupNumber; }

    inline void setFullName(const char* fullName) {
        if (this->fullName) {
            delete[] this->fullName;
        }
        size_t length = strlen(fullName) + 1;
        this->fullName = new char[length];
        strcpy(this->fullName, fullName);

    }

    void setPhone(const string& phone) { this->phone = phone; }
    void setCity(const string& city) { this->city = city; }
    void setCountry(const string& country) { this->country = country; }
    void setInstitution(const string& institution) { this->institution = institution; }
    void setInstitutionCity(const string& institutionCity) { this->institutionCity = institutionCity; }
    void setInstitutionCountry(const string& institutionCountry) { this->institutionCountry = institutionCountry; }
    void setGroupNumber(const string& groupNumber) { this->groupNumber = groupNumber; }

    void print()const {
        cout << "====================== " << fullName << " =======================" << endl;
        cout << "\t Date of Birth         :: " << birthDate.getDate() << endl;
        cout << "\t Contact Phone         :: " << phone << endl;
        cout << "\t City                  :: " << city << endl;
        cout << "\t Country               :: " << country << endl;
        cout << "\t Institution Name      :: " << institution << endl;
        cout << "\t Institution City      :: " << institutionCity << endl;
        cout << "\t Institution Country   :: " << institutionCountry << endl;
        cout << "\t Group Number          :: " << groupNumber << endl;
    }

    void input() {
        string tempFullName;
        cout << "\t Full Name             :: "; getline(cin, tempFullName);
        setFullName(tempFullName.c_str());
        cout << "\t Date of Birth (day month year):: "; cin >> birthDate.day >> birthDate.month >> birthDate.year;
        cin.ignore();
        cout << "\t Contact Phone         :: "; getline(cin, phone);
        cout << "\t City                  :: "; getline(cin, city);
        cout << "\t Country               :: "; getline(cin, country);
        cout << "\t Institution Name      :: "; getline(cin, institution);
        cout << "\t Institution City      :: "; getline(cin, institutionCity);
        cout << "\t Institution Country   :: "; getline(cin, institutionCountry);
        cout << "\t Group Number          :: "; getline(cin, groupNumber);
    }

};

int Student::instanceCount = 0;

//2

class Point {
private:
    double x;
    double y;
    double z;

    static int Count;

public:
    Point() : Point(0, 0, 0) {}

    Point(double x, double y, double z) : x(x), y(y), z(z)
    {
        ++Count;
    }

    Point(const Point& other) : x(other.x), y(other.y), z(other.z) {
        ++Count;  
    }

    
    ~Point() {
        --Count;  
    }

    
    static int getCount() {
        return Count;
    }


    inline double getX() const { return x; }
    inline double getY() const { return y; }
    inline double getZ() const { return z; }

    inline void setX(double x) { this->x = x; }
    inline void setY(double y) { this->y = y; }
    inline void setZ(double z) { this->z = z; }

    void input() {
        cout << "Enter x: "; cin >> x;
        cout << "Enter y: "; cin >> y;
        cout << "Enter z: "; cin >> z;
    }

    void print() const {
        cout << "Coordinates of points: (" << x << ", " << y << ", " << z << ")" << endl;
    }


    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error!" << endl;
            return;
        }
        file << x << endl;
        file << y << endl;
        file << z << endl;
        file.close();
    }


    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error" << endl;
            return;
        }
        file >> x >> y >> z;
        file.close();
    }
};
int Point::Count = 0;

int main()
{
    //1

    Date birthDate = { 14, 8, 1995 };
    Student student1;
    Student student2("Iryna Hnativ", { 7, 3, 1999 }, "123-456-7890", "Lviv", "Ukraine",
        "Lviv National University im.Ivana Franka", "Lviv", "Ukraine", "AB-101");

    student2.print();
    student1.input();
    student1.print();

    cout << "Number of Student instances: " << Student::getInstanceCount() << endl;


    //2
    Point p1;
    Point p2(1.0, 2.0, 3.0);

    p1.input();
    p1.print();
    p2.print();

    p1.saveToFile("point.txt");
    p2.loadFromFile("point.txt");
    p2.print();

    cout << "Number of Point instances: " << Point::getCount() << endl;







}

