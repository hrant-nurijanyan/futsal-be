# CMakeList.txt : CMake project for FutsalBe, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (FutsalBe "main.cpp" "Server.cpp" "src/player/Player.cpp" "src/player/PlayerRepository.cpp" "src/db/Connector.cpp" "src/db/TableCreator.cpp")

# TODO: Add tests and install targets if needed.
find_package(cpprestsdk REQUIRED)
target_link_libraries(FutsalBe PRIVATE cpprestsdk::cpprest)

find_package(libpqxx REQUIRED)
target_link_libraries(FutsalBe PRIVATE libpqxx::pqxx)