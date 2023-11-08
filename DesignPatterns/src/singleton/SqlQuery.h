#include <string>
class SqlQuery
{

public:
    SqlQuery(const std::string conn, const std::string username, const std::string password);
    int query(std::string conn, std::string username, std::string password);

private:
    std::string m_conn;
    std::string m_username;
    std::string m_password;
};