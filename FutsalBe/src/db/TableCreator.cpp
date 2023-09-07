#include "TableCreator.hpp"

void Futsal::DB::TableCreator::createTablesIfNotExists(pqxx::connection& connection)
{
	pqxx::work transaction(connection);

	transaction.exec("CREATE TABLE IF NOT EXISTS PLAYER ("
		"   id      UUID PRIMARY KEY DEFAULT gen_random_uuid(),"
		"   name    VARCHAR(255) NOT NULL,"
		"   surname VARCHAR(255) NOT NULL,"
		"   avatar  VARCHAR(255) NOT NULL"
		");");

	transaction.commit();
}