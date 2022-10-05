#include <boost/asio.hpp>
#include <iostream>
#include <vector>
#include "http_server.hpp"
#include "http_controller.hpp"

int main() {
    int port = 8080;
    HttpServer http_server(port);
    HttpServerController controller(http_server);

    std::cout << "Starting http server on port " << port << std::endl;
    http_server.start();

    return 0;
}
