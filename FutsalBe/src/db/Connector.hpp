#ifndef FUTSAL_BE_SRC_DB_CONNECTOR_HPP
#define FUTSAL_BE_SRC_DB_CONNECTOR_HPP

#include <pqxx/pqxx>

namespace Futsal::DB
{

	class Connector final
	{
	public:
		Connector() = default;
		~Connector() = default;

		Connector(const Connector&) = delete;
		Connector(Connector&&) = delete;

		Connector& operator=(const Connector&) = delete;
		Connector& operator=(Connector&&) = delete;

		Connector& setHost(const std::string& host);
		Connector& setPort(int port);
		Connector& setDbName(const std::string& dbName);
		Connector& setUsername(const std::string& username);
		Connector& setPassword(const std::string& password);

		pqxx::connection connect() const;

	private:
		std::string connectionString;
	};

} // namespace Futsal::DB

#endif // FUTSAL_BE_SRC_DB_CONNECTOR_HPP
