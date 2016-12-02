// QT Headers
#include "mainwindow.h"
#include <QApplication>

// MySQL Connector Headers
#include <mysql_connection.h>
#include <cppconn\driver.h>
#include <cppconn\exception.h>
#include <cppconn\resultset.h>
#include <cppconn\statement.h>

// Standard Headers
#include <iostream>

// User Defined Headers
#include "ims.h"

// Making global to make everyone's life easier
Ims db;

int userPriv;


int main(int argc, char *argv[])
{
	try
	{
		db.connect();
	}
	catch (sql::SQLException &e)
	{
		// Error TODO
	}

    QApplication a(argc, argv);
    MainWindow w;

	w.setFixedSize(300, 300);
    w.show();

    return a.exec();
}
