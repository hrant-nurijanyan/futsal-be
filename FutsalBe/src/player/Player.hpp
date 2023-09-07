#ifndef FUTSAL_BE_SRC_PLAYER_PLAYER_HPP
#define FUTSAL_BE_SRC_PLAYER_PLAYER_HPP

#include <string>

namespace Futsal
{

	class Player
	{
	public:
		Player(const std::string& id, const std::string& name, const std::string& surname, const std::string& avatarUrl);

		Player() = default;
		Player(const Player&) = default;
		Player(Player&&) = default;
		Player& operator=(const Player&) = default;
		Player& operator=(Player&&) = default;

		const std::string& getId() const;

		const std::string& getName() const;
		const std::string& getSurname() const;
		const std::string& getAvatarUrl() const;

	private:
		std::string id;

		std::string name;
		std::string surname;
		std::string avatarUrl;
	};

} // namespace Futsal

#endif // FUTSAL_BE_SRC_PLAYER_PLAYER_HPP
