#ifndef FUTSAL_BE_SERVER_HPP
#define FUTSAL_BE_SERVER_HPP

#include <cpprest/http_listener.h>
#include <cpprest/json.h>

class FutsalServer
{
public:
	FutsalServer(const utility::string_t& url);

	pplx::task<void> open();
	pplx::task<void> close();

private:
	using http_listener = web::http::experimental::listener::http_listener;
	using http_request = web::http::http_request;

	void handle_get(web::http::http_request request);
	void handle_put(web::http::http_request request);
	void handle_post(web::http::http_request request);
	void handle_delete(web::http::http_request request);

	http_listener listener;
};

#endif // FUTSAL_BE_SERVER_HPP

