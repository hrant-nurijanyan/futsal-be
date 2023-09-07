#include "PlayerRepository.hpp"

namespace Futsal
{

	PlayerRepository::PlayerRepository(pqxx::connection& dbConnection)
		: dbConnection(dbConnection)
	{
		dbConnection.prepare(GET_PLAYERS, "SELECT * FROM player");
		dbConnection.prepare(INSERT_PLAYER, "INSERT INTO player(name, surname, avatar) VALUES($1,$2,$3) RETURNING *");
		dbConnection.prepare(GET_PLAYER_BY_ID, "SELECT * FROM player where id=$1");
	}

	std::vector<Player> PlayerRepository::selectPlayers() const
	{
		pqxx::work transaction(dbConnection);
		pqxx::result result = transaction.exec_prepared(GET_PLAYERS);

		std::vector<Player> selectedPlayers(result.size());
		for (std::size_t i = 0; i < result.size(); ++i)
		{
			selectedPlayers[i] = getPlayerByRow(result[i]);
		}
		return selectedPlayers;
	}

	Player PlayerRepository::insertPlayer(const std::string& name, const std::string& surname, const std::string& avatar) const
	{
		pqxx::work transaction(dbConnection);
		pqxx::result result = transaction.exec_prepared(INSERT_PLAYER, name, surname, avatar);
		transaction.commit();

		if (result.empty())
		{
			return {};
		}

		return getPlayerByRow(result[0]);
	}

	Player PlayerRepository::selectPlayerById(const std::string& id)
	{
		pqxx::work transaction(dbConnection);
		pqxx::result result = transaction.exec_prepared(GET_PLAYER_BY_ID, id);

		if (result.empty())
		{
			return {};
		}

		return getPlayerByRow(result[0]);
	}

	Player PlayerRepository::getPlayerByRow(const pqxx::row& row)
	{
		if (row.size() != 4)
		{
			return {};
		}

		return {
			row[0].as< std::string >(),
			row[1].as< std::string >(),
			row[2].as< std::string >(),
			row[3].as< std::string >()
		};
	}

} // namespace Futsal
