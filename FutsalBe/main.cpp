#include <iostream>
#include "src/player/PlayerRepository.hpp"
#include "src/db/Connector.hpp"
#include "src/db/TableCreator.hpp"

int main()
{

	try
	{
		auto connection = Futsal::DB::Connector()
			.setHost("localhost")
			.setPort(5432)
			.setDbName("futsal_db")
			.setUsername("postgres")
			.setPassword("postgres")
			.connect();

		if (!connection.is_open())
		{
			std::cerr << "Connection could not be opened" << std::endl;
			return -1;
		}

		Futsal::DB::TableCreator::createTablesIfNotExists(connection);

		Futsal::PlayerRepository playerRepo(connection);

		auto players = playerRepo.selectPlayers();
		auto player = playerRepo.selectPlayerById(players[0].getId());
		std::cout << player.getName() << " " << player.getSurname() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// utility::string_t url = U("http://localhost::8080");
	// FutsalServer server(url);

	// server.open().then([](pplx::task<void> t) {
	//	try {
	//		t.get();
	//	}
	//	catch (const std::exception& e) {
	//		// Handle exceptions
	//	}
	//	}).wait();

	//	// Keep the server running until a termination signal is received
	//	std::cout << "Server is listening..." << std::endl;
	//	std::string line;
	//	std::getline(std::cin, line);

	//	server.close().wait();

	//	return 0;
}
