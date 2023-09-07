#ifndef FUTSAL_BE_SRC_PLAYER_PLAYER_API_HPP
#define FUTSAL_BE_SRC_PLAYER_PLAYER_API_HPP

#include <optional>
#include <pqxx/pqxx>

#include "Player.hpp"

namespace Futsal
{

	class PlayerRepository final
	{
	public:
		PlayerRepository() = delete;
		PlayerRepository(const PlayerRepository&) = delete;
		PlayerRepository(PlayerRepository&&) = delete;
		PlayerRepository& operator=(const PlayerRepository&) = delete;
		PlayerRepository& operator=(PlayerRepository&&) = delete;

		PlayerRepository(pqxx::connection& dbConnection);

		std::vector<Player> selectPlayers() const;
		Player insertPlayer(const std::string& name, const std::string& surname, const std::string& avatar) const;
		Player selectPlayerById(const std::string& id);

	private:
		static constexpr const char* GET_PLAYERS = "get_players";
		static constexpr const char* INSERT_PLAYER = "insert_player";
		static constexpr const char* GET_PLAYER_BY_ID = "get_player_by_id";

		static inline Player getPlayerByRow(const pqxx::row& result);

		pqxx::connection& dbConnection;
	};

} // namespace Futsal

#endif // FUTSAL_BE_SRC_PLAYER_PLAYER_API_HPP