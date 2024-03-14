#include <iostream>
#include <list>

using namespace std;

class User {
public:
    virtual void getPermissions() {
        cout << "Users can see limited info" << endl;
    }
};

class Superuser:public User {
    void getPermission() {
        cout << "Superusers can see all the info" << endl;
    }
};

int main(void)
{
    User u;
    Superuser s;

    list<User*>users;
    users.push_back(&u);
    users.push_back(&s);

    for(User* usrPtr : users)
        usrPtr ->getPermissions();// this desicion made at runtime
    cin.get();
}