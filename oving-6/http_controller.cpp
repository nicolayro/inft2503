#include "http_controller.hpp"
#include "http_server.hpp"


HttpServerController::HttpServerController(HttpServer &server) {

    server.add_endpoint("/", []{
            return  "<!DOCTYPE html>"
                "<html>"
                "<body>"
                "<h1>Hei fra hovedsiden</h1>"
                "</body>"
                "</html>";
    });

    server.add_endpoint("/en_side", []{
            return  "<!DOCTYPE html>"
                "<html>"
                "<body>"
                "<h1>Hei fra en side</h1>"
                "</body>"
                "</html>";
    });
}

