#ifndef IMS_H
#define IMS_H
#include "mysql_connection.h"

#include <QtWidgets>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cstring>

using namespace std;

class Ims {
private:
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
	sql::PreparedStatement *pstmt;
	std::string sql;

public:
	Ims();
	~Ims();
	void connect();
	void print_info();
	void test_fuction();
	bool add_user(const string user_id_name, const string user_fname, const string user_lname, const string user_email, const string user_password, const int user_priv_level);


	bool login(const string NAME, const string PASSWORD);
	bool add_item(const string NAME, const string MAKE, const string DESC, const double PRICE, const int COUNT, const int STATUS);
	bool delete_item(const int ID);
	bool delete_user(const int ID);
	void print_all_items();
	void print_all_users();
	void print_item_by_name(const string NAME);
	void print_item_by_id(const string ID);
	bool modify_item(const string ATTRIBUTE_TO_MODIFY, const int ID, const string NEW_VAL);
	bool modify_item(const int ID, const string NAME, const string MAKE, const double PRICE, const int QUANTITY, const string DESCRIPTION);
	bool modify_user(const int ID, const string USERNAME, const string FIRSTNAME, const string LASTNAME, const string EMAIL, const string PASSWORD, const int PRIV_LEVEL);
	void print_result_set(QTextBrowser *text);
	void print_items_to_table(QTableWidget* table);
	void print_users_to_table(QTableWidget* table);
	void white_space_format(sql::SQLString str, QString &str_to_append_to, int desired_length);
	void get_map_of_unique_makes(map<string, string>& makes);
	

private:
	void log_error(sql::SQLException &e);

};

extern Ims db;
extern int userPriv;

#endif // !IMS_H