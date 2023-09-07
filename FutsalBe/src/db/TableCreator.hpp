#ifndef FUTSAL_BE_SRC_DB_TABLE_CREATOR_HPP
#define FUTSAL_BE_SRC_DB_TABLE_CREATOR_HPP

#include <pqxx/pqxx>

namespace Futsal::DB
{

	struct TableCreator
	{
		static void createTablesIfNotExists(pqxx::connection& connection);
	};

} // namespace Futsal::DB

#endif // FUTSAL_BE_SRC_DB_TABLE_CREATOR_HPP