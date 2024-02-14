#include <iostream>
#include <unordered_map>
#include <cmath>
#include <vector>

using namespace std;

// Class for cab which has cab id location and available indicators.
class Cab
{
private:
    int cabId;
    pair<double, double> location; // Location represented as (x, y) coordinates
    bool available;

public:
    // constructor and other methods for cab allocation
    Cab(int id, double x, double y) : cabId(id), location(make_pair(x, y)), available(true) {}

    int getId() const { return cabId; }

    pair<double, double> getLocation() const { return location; }

    bool isAvailable() const { return available; }

    void setLocation(double x, double y) { location = make_pair(x, y); }

    void setAvailability(bool avail) { available = avail; }
};

// admin class which has private member username and password and cabs to maintain in the system
class Admin
{
private:
    string username = "admin";
    string password = "admin123";
    vector<Cab> cabs;

public:
    // method to check if the admin is authenticated or not
    bool getAdminAuthorized(string enteredName, string enteredPassword)
    {
        return enteredName == username && enteredPassword == password;
    }
    // method to add a cab into the system
    void addCab(const Cab &cab)
    {
        cabs.push_back(cab);
    }
    // method to get list of cabs available in the system
    vector<Cab> getAllCabsDetails()
    {
        return cabs;
    }
};

// user class which has user details and some incomplete functionality.
class User
{
    string name;
    string password;

public:
    User(string userName, string password)
    {
        name = userName;
        password = password;
    }
    string getUsername()
    {
        return name;
    }
    void login(string userName, string password)
    {
        name = userName;
        password = password;
    }
};

// user manager class which will manage all the user it has private users hashmap to store hashed password for better security
class UserManager
{
private:
    unordered_map<string, size_t> users; // Store username and hashed password

public:
    void registerUser(const string &username, const string &password)
    {
        // Hash the password before storing it
        size_t hashedPassword = hashPassword(password);
        users[username] = hashedPassword;
        cout << "\nUser registered successfully!" << endl;
    }

    bool authenticate(const string &username, const string &password)
    {
        // Check if the username exists
        auto it = users.find(username);
        if (it != users.end())
        {
            // Verify the hashed password
            size_t hashedPassword = hashPassword(password);
            return it->second == hashedPassword;
        }
        return false;
    }

private:
    size_t hashPassword(const string &password)
    {
        // Use std::hash for simple hashing
        return hash<string>{}(password);
    }
};

// authentication class to start the setup of choice between admin or normal user login.
class Auth
{
    UserManager manager;
    bool isAdminLogged = 0;

public:
    Admin admin;
    User user1 = User("", "");

    // the first method which will be called for.
    void home()
    {
        string mainoption;
        cout << "Welcome to smart cab allocation system\nPlease read the documentation for how this system works.\n\n";
        cout << "Enter one from below\n\t1.Admin login\n\t-1.exit from the system\n\tany other key for normal user login \t\n:";
        cin >> mainoption;
        if (mainoption == "1")
        {
            adminRoute();
            return;
        }
        else if (mainoption == "-1")
        {
            return;
        }
        else
        {
            userRoute();
            return;
        }
    }

    // User login utility method
    void loginUtil()
    {
        string username, password;
        cout << "\nEnter your username :\t";
        cin >> username;
        cout << "\nEnter your password :\t";
        cin >> password;
        if (!manager.authenticate(username, password))
        {
            cout << "\nAuthentication failed please register first\nReturning to the login setup...\n\n\n";
        }
        else
        {
            cout << "\nAuthentication successful!\n\tCreating your instance for accessing the cab features\n\n"
                 << endl;
            user1.login(username, password);
        }
    }

    // Register utility method
    void registerUtil()
    {
        string username, password;
        cout << "\nEnter your username :\t";
        cin >> username;
        cout << "\nEnter your password :\t";
        cin >> password;
        manager.registerUser(username, password);
        cout << "Now login to access our features.\nReturning to the login setup...\n\n\n";
    }

    // Admin route
    void adminRoute()
    {

        cout << "Admin please authenticate yourself first\n";
        string username, password;
        cout << "\nEnter your username :\t";
        cin >> username;
        cout << "\nEnter your password :\t";
        cin >> password;
        if (admin.getAdminAuthorized(username, password))
        {
            cout << "\nWelcome Admin choose from below options for system maintainance\n";
            isAdminLogged = 1;
            return;
        }
        else
            cout << "\nAdmin login failed please retry\n";
    }

    bool checkIfAdmin()
    {
        return isAdminLogged;
    }

    void setAdminLogout()
    {
        isAdminLogged = 0;
    }

    // User route
    void userRoute()
    {

        int option;
        while (true)
        {
            cout << "\nPlease authenticate or register if new user. Choose an option from below \n\n \t\t1.Register \n \t\t2.Login\n \t\t-1.Close \n\n\n";
            cout << "Enter option to get started :";
            cin >> option;
            if (option == 1)
            {
                registerUtil();
            }
            else if (option == 2)
            {
                loginUtil();
            }
            else if (option == -1)
            {
                cout << "\nThankyou for using our services\nExiting...\n\n";
                home();
            }
            else
            {
                cout << "Bad option system shuting down\n\n";
            }
        }
    }
};

// System class which will has parent class as authentication.
class SmartCabAllocSystem : Auth
{

public:
    // admin functionalities after the admin is logged in
    void adminFunctionality()
    {
        cout << "Please maintain the concurrency of the system\n";
        cout << "\nSelect from the below option.\n";
        int options = 0;
        while (options != -1)
        {
            cout << "Choose from below job\n\t-1.Exit\n\t1.Add cab\n\t2.Get all cabs details\n\t3.Check cab location\n";
            cin >> options;

            if (options == 1)
            {
                int id;
                double x, y;
                cout << "Enter the cab id :\t";
                cin >> id;
                cout << "Enter the cab location (x y space in between):\t";
                cin >> x >> y;
                Cab cab = Cab(id, x, y);
                admin.addCab(cab);
                cout << "Cab added to the system successfully\n\n";
            }

            if (options == 2)
            {
                vector<Cab> cabs = admin.getAllCabsDetails();
                if (cabs.size() == 0)
                {
                    cout << "Sorry the system doesn't have any cabs till now please add and try again\n\n";
                }
                else
                {
                    cout << "Here is the list of all cabs associated with our system with their live locations\n\n";
                    for (auto cab : cabs)
                    {
                        int id = cab.getId();
                        pair<double, double> location = cab.getLocation();
                        cout << "The cab with id " << id << " is currently located at " << location.first << " " << location.second << endl;
                    }
                    cout << endl;
                }
            }
            if (options == 3)
            {
                int checkId;
                bool cabPresent = 0;
                cout << "Enter the cab id which you want to check location for:\t";
                cin >> checkId;
                vector<Cab> cabs = admin.getAllCabsDetails();
                for (auto cab : cabs)
                {
                    int id = cab.getId();
                    if (id == checkId)
                    {
                        pair<double, double> location = cab.getLocation();
                        cabPresent = 1;
                        cout << "The cab with id " << id << " is currently located at " << location.first << " " << location.second << endl
                             << endl;
                        break;
                    }
                }
                if (cabPresent == 0)
                {
                    cout << "Sorry! But the cab id which is entered is not present in the system\n\n";
                }
            }

            if (options == -1)
            {
                cout << "Thankyou for maintaining the system\n Exiting...\n\n";
                setAdminLogout();
                getStarted();
            }
        }
    }

    // user functionalities after user is logged in (incomplete)
    void userFunctionality()
    {
        cout << "Welcome " + user1.getUsername() + " you are logged in successfully \n Hope you like our services \n";

        cout << "\nSelect from the below option.\n";
        int options = 0;
        while (options != -1)
        {
            cout << "Choose from below job\n\t-1.Exit\n\t1.Start a trip\n\t2.Get nearest cab from a location\n\t\n";
            cin >> options;

            if (options == 1)
            {
                // Yet to complete
            }

            if (options == -1)
            {
                cout << "Thankyou for using the system\n Exiting...\n\n";
                getStarted();
            }
        }
    }

    void getStarted()
    {
        home();

        if (checkIfAdmin())
        {
            adminFunctionality();
        }

        // if normal user logged in then normal user functions will be executed
        else if (user1.getUsername() != "")
        {
            userFunctionality();
        }

        // If any error or authentication failed
        else
        {
            cout << "Sorry the authentication was failed.\nExiting to main page please retry again..\n\n\n";
            getStarted();
        }
    }
};

int main()
{

    SmartCabAllocSystem system;
    system.getStarted();

    return 0;
}