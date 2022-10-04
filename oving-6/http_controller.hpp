#pragma once
#include "http_server.hpp"

// This class is where we configure our actual endpoins for the server
// It should contain a constructor that passes in the HttpServer class,
// and implement function corresponding to each path to listen for
class HttpServerController {
public:
    HttpServerController(HttpServer &server);
};
