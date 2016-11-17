#define _CRT_SECURE_NO_WARNINGS
#include "ims.h"
#include <cstring>
#include <qdebug.h>

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

bool Ims::add_user(const string user_id_name, const string user_fname, const string user_lname,
	const string user_email, const string user_password, const int user_priv_level) {

	bool addedUser = false;

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
		addedUser = this->pstmt->executeUpdate();
		delete this->pstmt;

	}
	catch (sql::SQLException &e) {
		this->log_error(e);
	}

	return addedUser;
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

void Ims::print_all_items()
{
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT item_id, item_name, price, stock_count FROM item WHERE status != 7");

}

void Ims::print_item_by_name(const string NAME)
{
	pstmt = con->prepareStatement("SELECT item_id, item_name, price, stock_count FROM item WHERE item_name = ? AND status != 7");
	pstmt->setString(1, NAME);
	res = pstmt->executeQuery();
}

void Ims::print_item_by_id(const string ID)
{
	pstmt = con->prepareStatement("SELECT item_id, item_name, price, stock_count FROM item WHERE item_id = ? AND status != 7");
	pstmt->setString(1, ID);
	res = pstmt->executeQuery();
}

bool Ims::modify_item(const string ATTRIBUTE_TO_MODIFY, const int ID, const string NEW_VAL)
{
	bool itemModified;

	if (ATTRIBUTE_TO_MODIFY == "Product Name")
	{
		pstmt = con->prepareStatement("UPDATE item SET item_name = ? WHERE item_id = ?");
		pstmt->setString(1, NEW_VAL);
		pstmt->setInt(2, ID);
		itemModified = pstmt->executeUpdate();
	}
	else if (ATTRIBUTE_TO_MODIFY == "Price")
	{
		pstmt = con->prepareStatement("UPDATE item SET price = ? WHERE item_id = ?");
		pstmt->setString(1, NEW_VAL);
		pstmt->setInt(2, ID);
		itemModified = pstmt->executeUpdate();
	}
	else if (ATTRIBUTE_TO_MODIFY == "Stock_count")
	{
		pstmt = con->prepareStatement("UPDATE item SET stock_count = ? WHERE item_id = ?");
		pstmt->setString(1, NEW_VAL);
		pstmt->setInt(2, ID);
		itemModified = pstmt->executeUpdate();
	}
	else if (ATTRIBUTE_TO_MODIFY == "Status")
	{
		pstmt = con->prepareStatement("UPDATE item SET status = ? WHERE item_id = ?");
		pstmt->setString(1, NEW_VAL);
		pstmt->setInt(2, ID);
		itemModified = pstmt->executeUpdate();
	}
	else if (ATTRIBUTE_TO_MODIFY == "Description")
	{
		pstmt = con->prepareStatement("UPDATE item SET item_description = ? WHERE item_id = ?");
		pstmt->setString(1, NEW_VAL);
		pstmt->setInt(2, ID);
		itemModified = pstmt->executeUpdate();
	}
	else
	{
		// ERROR CASE
		itemModified = false;
	}

	return itemModified;
}

void Ims::print_result_set(QTextBrowser *text)
{
	QString print;
	
	print.append("Id  ");
	print.append("Item Name      ");
	print.append("Price    ");
	print.append("Count  ");
	print.append("\n");
	print.append("____________________________________");
	print.append("\n");

	while (res->next())
	{
		qDebug() << "1";
		print.append(QString::fromStdString(res->getString("item_id").asStdString()));
		white_space_format(res->getString("item_id"), print, 4);
		qDebug() << "2";
		print.append(QString::fromStdString(res->getString("item_name").asStdString()));
		white_space_format(res->getString("item_name"), print, 15);
		qDebug() << "3";
		print.append(QString::fromStdString(res->getString("price").asStdString()));
		white_space_format(res->getString("price"), print, 9);
		qDebug() << "4";
		print.append(QString::fromStdString(res->getString("stock_count").asStdString()));
		white_space_format(res->getString("stock_count"), print, 8);
		qDebug() << "5";
		// The sql does not recognize "item_description" as a valid column for some reason.
		//print.append(QString::fromStdString(res->getString("item_description").asStdString()));
		print.append("\n");
	}

	text->setText(print);
}

void Ims::white_space_format(sql::SQLString str, QString &str_to_append_to, int desired_length)
{
	if (desired_length > str.length())
	{
		for (int x = 0; x < desired_length - str.length(); x++)
		{
			str_to_append_to.append(" ");
		}
	}
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

