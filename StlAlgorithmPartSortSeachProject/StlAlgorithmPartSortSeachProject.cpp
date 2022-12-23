#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class User
{
    string name;
    int age;
public:
    User(string name, int age) : name{ name }, age{ age } {}
    string& Name() { return name; }
    int& Age() { return age; }
    friend ostream& operator<<(ostream& out, const User& u)
    {
        cout << "name: " << u.name << ", age: " << u.age;
        return out;
    }
    friend bool operator<(const User& u1, const User& u2)
    {
        return u1.name < u2.name;
    }
};

template <class Iterator>
void quickSort(Iterator begin, Iterator end)
{
    if (begin == end)
        return;
    int pivot = *(begin + distance(begin, end) / 2);
    auto it1 = partition(begin, end, [pivot](auto item) { return item < pivot; });
    auto it2 = partition(it1, end, [pivot](auto item) { return item <= pivot; });
    quickSort(begin, it1);
    quickSort(it2, end);
}

struct UserNameComparer
{
    bool operator()(User& u1, User& u2)
    {
        return u1.Name() < u2.Name();
    }
};

struct UserAgeComparer
{
    bool operator()(User& u1, User& u2)
    {
        return u1.Age() < u2.Age();
    }
};


int main()
{
    /*vector<int> v1{ 1, 4, 7, 2, 3, 6, 5 };
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    auto it = stable_partition(v1.begin(), v1.end(),
        [](auto item) { return item % 2; });
    copy(v1.begin(), it, ostream_iterator<int>(cout, " "));
    cout << "\n";
    copy(it, v1.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";*/

    /*srand(time(nullptr));
    vector<int> v2(10);
    generate(v2.begin(), v2.end(), []() { return rand() % 100; });
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";*/

    /*
    quickSort(v2.begin(), v2.end());
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";*/

    //vector<int> sortpart;
    //copy(v2.begin(), v2.end(), back_inserter(sortpart));
    //partial_sort(sortpart.begin(), sortpart.begin() + 5, sortpart.end());
    //copy(sortpart.begin(), sortpart.end(), ostream_iterator<int>(cout, " "));
    //cout << "\n";

    //sort(v2.begin(), v2.begin() + 5);
    //copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    //cout << "\n";

    //vector<User> users;
    //users.push_back(User("Tim", 36));
    //users.push_back(User("Joe", 21));
    //users.push_back(User("Sam", 19));
    //users.push_back(User("Leo", 48));
    //users.push_back(User("Bob", 32));
    //users.push_back(User("Tom", 26));
    //users.push_back(User("Jim", 20));

    //for (User user : users)
    //    cout << user << "\n";
    //cout << "\n";

    //sort(users.begin(), users.begin(), UserAgeComparer());

    ///*sort(users.begin(), users.end(),
    //    [](User u1, User u2)
    //    {
    //        return u1.Age() < u2.Age();
    //    });*/

    //for (User user : users)
    //    cout << user << "\n";
    //cout << "\n";

    vector<int> v1{ 1, 2 ,3, 4, 5, 6, 7 };
    vector<int> v2{ 5, 6, 7, 8, 9, 10, 11 };
    vector<int> v3{ 3, 4, 5, 9 };

    vector<int> v4;

    cout << boolalpha << includes(v1.begin(), v1.end(), v3.begin(), v3.end()) << "\n";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    cout << "set_difference:\n";
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v4));
    copy(v4.begin(), v4.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    v4.clear();
    cout << "set_intersection:\n";
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v4));
    copy(v4.begin(), v4.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    v4.clear();
    cout << "set_symmetric_difference:\n";
    set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v4));
    copy(v4.begin(), v4.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    v4.clear();
    cout << "set_union:\n";
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v4));
    copy(v4.begin(), v4.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

}
