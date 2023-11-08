#include <string>

class DBConfig
{
public:
    static DBConfig *config;
    static DBConfig *getInstance();

    DBConfig();
    std::string getConn();
    std::string getUsername();
    std::string getPassword();

private:
    std::string m_conn;
    std::string m_username;
    std::string m_password;
};