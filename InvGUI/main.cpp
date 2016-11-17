#include "mainwindow.h"
#include <QApplication>

#include <mysql_connection.h>

#include <cppconn\driver.h>
#include <cppconn\exception.h>
#include <cppconn\resultset.h>
#include <cppconn\statement.h>

#include <iostream>

// Put these in a header prob.
sql::Driver		*driver;
sql::Connection *con;
sql::Statement	*stmt;
sql::ResultSet	*result;

int main(int argc, char *argv[])
{
	try
	{
		driver = get_driver_instance();
		con = driver->connect("ims.cj2zvsooupan.us-west-2.rds.amazonaws.com", "imsmaster", "S0ftwareEngineeringDog!");
	}
	catch (sql::SQLException &e)
	{

	}

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
