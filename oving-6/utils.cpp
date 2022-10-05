#include <stdexcept>
#include "utils.hpp"

// Extracts the endpoint from a http get request. Example:
//   GET /helloworld HTTP/1.1
//   Returns '/helloworld'
//
// Throws exception if the request is not a valid HTTP GET request
std::string extract_endpoint(std::string request) {
    if (request.find("HTTP/1.") == std::string::npos) {
        throw "The server only supports http requests";
    }

    if (request.find("GET") == std::string::npos) {
        throw "The server only supports GET requests";
    }

    size_t start = request.find("/");
    size_t end = request.substr(start).find(" ");
    return request.substr(start, end);
}

std::string create_http_response(std::string html) {
    return  "HTTP/1.1 200 OK\r\n"
            "Content-Length: " + std::to_string(html.length()) + "\r\n"
            "Content-Type: text/html; charset=utf-8\r\n\r\n"
            + html;
}

