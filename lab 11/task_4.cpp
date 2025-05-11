#include <iostream>
using namespace std;

class DatabaseException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Database error occurred";
    }
};

class connectionFailedException : public DatabaseException
{};

class querytimeoutException : public DatabaseException
{};

template<class T>
class DatabaseConnector
{
public:
    void connect(string dbname)
    {
        cout << "Attempting to connect to database: " << dbname << endl;

        if(dbname == "invalid_db")
        {
            throw connectionFailedException();
        }
        else if(dbname == "slow_db")
        {
            throw querytimeoutException();
        }
        else
        {
            cout << "Connected to database: " << dbname << endl;
        }
    }
};



int main()
{
    DatabaseConnector<int> db;
    try
    {
        db.connect("invalid_db");
    }
    catch (const connectionFailedException &e)
    {
        cout << "Caught connectionFailedException - " << e.what() << endl;
    }
    catch (const querytimeoutException &e)
    {
        cout << "Caught a general databaseException - " << e.what() << endl;
    }
    catch (const DatabaseException &e)
    {
        cout << "Caught DatabaseException - " << e.what() << endl;
    }
    return 0;
}