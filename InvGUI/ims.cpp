#define _CRT_SECURE_NO_WARNINGS
#include "ims.h"
#include <cstring>

using namespace std;


Ims::Ims() {
	this->connect();
}

void Ims::print_info() {
	string sql;
	sql = "select * from user;";
	this->pstmt = con->prepareStatement(sql);
	this->res = this->pstmt->executeQuery();
	cout << this->res->rowsCount() << endl;
	while (this->res->next()) {
		cout << "... MySQL replies: " << endl;;
		/* Access column data by alias or column name */
		cout << "\tUser ID: ";
		cout << this->res->getString("user_id_name") << endl;
		cout << "\tUser Name: ";
		cout << this->res->getString("user_fname") << " ";
		cout << this->res->getString("user_fname") << endl;
		cout << "\tUser Email: ";
		cout << this->res->getString("user_email") << endl;
		cout << "... testing this: " << endl;
		/* Access column data by numeric offset, 1 is the first column */
		cout << this->res->getString(1) << endl;
	}

}

void Ims::add_user(const string user_id_name, const string user_fname, const string user_lname,
	const string user_email, const string user_password, const int user_priv_level) {
	try {
		if (this->con->isClosed())
			this->connect();
		this->sql = ""
			"INSERT INTO	user"
			"("
			"user_id_name"
			", user_fname"
			", user_lname"
			", user_email"
			", user_password"
			", status"
			", user_privilege_level"
			", user_create_ts"
			", user_last_login_ts"
			", update_ts"
			") VALUES "
			"("
			"?"
			",?"
			",?"
			",?"
			",?"
			",1"
			",?"
			",CURRENT_TIMESTAMP"
			",CURRENT_TIMESTAMP"
			",CURRENT_TIMESTAMP"
			")";

		this->pstmt = this->con->prepareStatement(this->sql);
		this->pstmt->setString(1, user_id_name);
		this->pstmt->setString(2, user_fname);
		this->pstmt->setString(3, user_lname);
		this->pstmt->setString(4, user_email);
		this->pstmt->setString(5, user_password);
		this->pstmt->setInt(6, 10);
		this->pstmt->executeUpdate();
		delete this->pstmt;

	}
	catch (sql::SQLException &e) {
		this->log_error(e);
	}
}

void Ims::connect() {
	try {
		if (this->con == nullptr)
		{
			/* Create a connection */
			this->driver = get_driver_instance();
			this->con = this->driver->connect("tcp://ims.cj2zvsooupan.us-west-2.rds.amazonaws.com:3306", "imsmaster", "S0ftwareEngineeringDog!");
			/* Connect to the MySQL test database */
			this->con->setSchema("ims");
			this->stmt = this->con->createStatement();
		}
	}
	catch (sql::SQLException &e) {
		this->log_error(e);
	}

}
void Ims::test_fuction() {
	try {
		if (this->con->isClosed())
			this->connect();

		this->stmt->execute("DROP TABLE IF EXISTS test");
		this->stmt->execute("CREATE TABLE test(id INT)");

		/* '?' is the supported placeholder syntax */
		this->pstmt = this->con->prepareStatement("INSERT INTO test(id) VALUES (?)");
		for (int i = 1; i <= 10; i++) {
			this->pstmt->setInt(1, i);
			this->pstmt->executeUpdate();
		}
		delete this->pstmt;

		/* Select in ascending order */
		this->pstmt = this->con->prepareStatement("SELECT id FROM test ORDER BY id ASC");
		this->res = this->pstmt->executeQuery();

		/* Fetch in reverse = descending order! */
		this->res->afterLast();
		while (this->res->previous())
			cout << "\t... MySQL counts: " << res->getInt("id") << endl;
		delete this->res;
		delete this->pstmt;

		this->stmt = this->con->createStatement();
		this->res = this->stmt->executeQuery("SELECT * FROM item");
		while (this->res->next()) {
			cout << "\t... MySQL replies: ";
			/* Access column data by alias or column name */
			cout << this->res->getString("_message") << endl;
			cout << "\t... MySQL says it again: ";
			/* Access column data by numeric offset, 1 is the first column */
			cout << this->res->getString(1) << endl;
		}
	}
	catch (sql::SQLException &e) {
		this->log_error(e);
	}
}
Ims::~Ims() {
	this->con->close();
	//delete this->driver;
	delete this->stmt;
	delete this->res;
	delete this->pstmt;
}

// Scott's Stuff
bool Ims::login(const string NAME, const string PASSWORD)
{
	pstmt = con->prepareStatement("SELECT * FROM user WHERE user_id_name = ? AND user_password = ?");
	pstmt->setString(1, NAME);
	pstmt->setString(2, PASSWORD);

	res = pstmt->executeQuery();

	return res->rowsCount() >= 1;
}

bool Ims::add_item(const string NAME, const string DESC, const double PRICE, const int COUNT, const int STATUS)
{
	pstmt = con->prepareStatement("INSERT INTO item (item_name, item_description, price, stock_count, status) VALUES (?, ?, ?, ?, ?)");

	pstmt->setString(1, NAME);
	pstmt->setString(2, DESC);
	pstmt->setDouble(3, PRICE);
	pstmt->setInt(4, COUNT);
	pstmt->setInt(5, STATUS);

	return pstmt->executeUpdate();
}

bool Ims::delete_item(const int ID)
{
	pstmt = con->prepareStatement("UPDATE item SET status = 7 WHERE item_id = ?");
	pstmt->setInt(1, ID);

	return pstmt->executeUpdate();
}

sql::ResultSet *Ims::print_all_items()
{
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT * FROM item");

	// May change to string or vector of strings
	return res;
}

sql::ResultSet *Ims::print_item_by_name(const string NAME)
{
	pstmt = con->prepareStatement("SELECT * FROM item WHERE item_name = ?)");
	pstmt->setString(1, NAME);
	res = pstmt->executeQuery();

	return res;
}

sql::ResultSet *Ims::print_item_by_id(const int ID)
{
	pstmt = con->prepareStatement("SELECT * FROM item WHERE item_id = ?)");
	pstmt->setInt(1, ID);
	res = pstmt->executeQuery();

	return res;
}

bool Ims::modify_item(const string ATTRIBUTE_TO_MODIFY, const int ID, const string NEW_VAL)
{
	bool itemModified;

	pstmt = con->prepareStatement("UPDATE item SET ? = ? WHERE item_id = ?");
	pstmt->setString(1, ATTRIBUTE_TO_MODIFY);

	if (ATTRIBUTE_TO_MODIFY == "Product Name")
	{
		pstmt->setString(2, "item_name");
		pstmt->setString(3, NEW_VAL);
		itemModified = res->rowUpdated();
	}
	else if (ATTRIBUTE_TO_MODIFY == "Price")
	{
		pstmt->setString(2, "price");
		pstmt->setString(3, NEW_VAL);
		itemModified = res->rowUpdated();
	}
	else if (ATTRIBUTE_TO_MODIFY == "Stock_count")
	{
		pstmt->setString(2, "stock_count");
		pstmt->setString(3, NEW_VAL);
		itemModified = res->rowUpdated();
	}
	else if (ATTRIBUTE_TO_MODIFY == "Status")
	{
		pstmt->setString(2, "status");
		pstmt->setString(3, NEW_VAL);
		itemModified = res->rowUpdated();
	}
	else if (ATTRIBUTE_TO_MODIFY == "Description")
	{
		pstmt->setString(2, "item_description");
		pstmt->setString(3, NEW_VAL);
		itemModified = res->rowUpdated();
	}
	else
	{
		// ERROR CASE
		itemModified = false;
	}

	return itemModified;
}
// End Scott's Stuff

void Ims::log_error(sql::SQLException &e) {
	cout << " IN LOG_ERROR!!" << endl;
	freopen("C:\\Users\\robert\\Desktop\\ims_error_log.txt", "w", stderr);
	cerr << "# ERR: SQLException in " << __FILE__;
	cerr << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
	cerr << "# ERR: " << e.what();
	cerr << " (MySQL error code: " << e.getErrorCode();
	cerr << ", SQLState: " << e.getSQLState() << " )" << endl;
	fclose(stderr);
}

