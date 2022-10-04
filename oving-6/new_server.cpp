#include <boost/asio.hpp>
#include <iostream>
#include <vector>
#include "http_server.hpp"
#include "http_controller.hpp"

using namespace boost::asio::ip;

int main() {
    HttpServer http_server(8080);
    HttpServerController controller(http_server);

    std::cout << "Starting http server" << std::endl;
    http_server.start();

    return 0;
}
