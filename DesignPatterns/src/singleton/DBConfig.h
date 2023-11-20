#include <string>

class DBConfig
{
public:
    static DBConfig *config;
    static DBConfig *getInstance();


    // 禁止通过copy构造对象
    DBConfig(const DBConfig& config) = delete;
    // 禁止通过赋值copy对象
    DBConfig& operator = (const DBConfig & config) = delete;

    std::string getConn();
    std::string getUsername();
    std::string getPassword();

private:
    std::string m_conn;
    std::string m_username;
    std::string m_password;

    // 禁止外部通过构造创建对象
    DBConfig();
};