#include "Connector.hpp"

namespace Futsal::DB
{

	Connector& Connector::setHost(const std::string& host)
	{
		connectionString += "host=" + host + " ";
		return *this;
	}

	Connector& Connector::setPort(int port)
	{
		connectionString += "port=" + std::to_string(port) + " ";
		return *this;
	}

	Connector& Connector::setDbName(const std::string& dbName)
	{
		connectionString += "dbname=" + dbName + " ";
		return *this;
	}

	Connector& Connector::setUsername(const std::string& username)
	{
		connectionString += "user=" + username + " ";
		return *this;
	}

	Connector& Connector::setPassword(const std::string& password)
	{
		connectionString += "password=" + password + " ";
		return *this;
	}

	pqxx::connection Connector::connect() const
	{
		return pqxx::connection(connectionString);
	}

} // namespace Futsal::DB
