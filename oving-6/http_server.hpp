#pragma once

#include <boost/asio.hpp>
#include <memory>
#include <vector>
#include "endpoint.hpp"

class HttpServer {
private:
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::endpoint url;
    boost::asio::ip::tcp::acceptor acceptor;

    // List of all endpoints to listen for
    std::vector<Endpoint> endpoints;
    // TODO: Add fallback function?

    class Connection {
    public:
        boost::asio::ip::tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {};
    };

    void accept();
    void handle_request(std::shared_ptr<Connection> connection);
    void write_response(std::shared_ptr<Connection> connection, std::string);
    void handle_error(const boost::system::error_code &error);
    std::string parse_request(std::shared_ptr<Connection> connection);
    std::string handle_endpoint(std::string endpoint);

public:
    void add_endpoint(const std::string &path, std::function<std::string()> create_response);

    HttpServer(int port);
    void start();
};
