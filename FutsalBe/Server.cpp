#include "Server.hpp"

FutsalServer::FutsalServer(const utility::string_t& url) : listener(url)
{
	using web::http::methods;

	listener.support(methods::GET, [this](auto&& PH1) { handle_get(std::forward<decltype(PH1)>(PH1)); });
	listener.support(methods::POST, [this](auto&& PH1) { handle_post(std::forward<decltype(PH1)>(PH1)); });
	listener.support(methods::PUT, [this](auto&& PH1) { handle_put(std::forward<decltype(PH1)>(PH1)); });
	listener.support(methods::DEL, [this](auto&& PH1) { handle_delete(std::forward<decltype(PH1)>(PH1)); });
}

pplx::task<void> FutsalServer::open()
{
	return listener.open();
}

pplx::task<void> FutsalServer::close()
{
	return listener.close();
}

void FutsalServer::handle_get(web::http::http_request request)
{
}

void FutsalServer::handle_put(web::http::http_request request)
{
}

void FutsalServer::handle_post(web::http::http_request request)
{
}

void FutsalServer::handle_delete(web::http::http_request request)
{
}
