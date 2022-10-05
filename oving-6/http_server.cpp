#include <boost/asio.hpp>
#include <iostream> 
#include "http_server.hpp" 
#include "utils.hpp" 

HttpServer::HttpServer(int port) :
    url(boost::asio::ip::tcp::v4(), port),
    acceptor(io_service, url){}

// Starts the actual server
void HttpServer::start() {
    accept();
    io_service.run();
}

void HttpServer::add_endpoint(const std::string &path, std::function<std::string()> create_response) {
    std::cout << "path: " << path << std::endl;
    Endpoint endpoint(path);
    endpoint.create_response = create_response;
    std::cout << "calling: " << endpoint.create_response() << std::endl;
    endpoints.emplace_back(endpoint);
}


// Waits for client trying to connect and begins the request handling. Immidietly
// starts waiting for another request after accepting
void HttpServer::accept() {
    auto connection = std::make_shared<Connection>(io_service);

    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &error) {
        accept();
        if(!error) {
            handle_request(connection);
        } else {
            handle_error(error);
        }
    });
}
void HttpServer::handle_error(const boost::system::error_code &error) {
    std::cerr<< "There was an error: " << error.message();
}

std::string HttpServer::parse_request(std::shared_ptr<Connection> connection) {
    auto read_buffer = std::make_shared<boost::asio::streambuf>();
    std::string request = "/en_side";

    std::cout << "hello " << request << std::endl;
    // Read from client until newline ("\r\n")
    boost::asio::async_read_until(connection->socket, *read_buffer, "\r\n",
                     [connection, read_buffer, &request](const boost::system::error_code &error, std::size_t length) {
        
        std::cout << "hello from read" << std::endl;
        if (error) {
            std::cout << "error" << std::endl;
            throw error;
        }
        // Retrieve message from client as string:
        std::istream read_stream(read_buffer.get());
        std::getline(read_stream, request);
        // TODO: Consider moving the new line removal outside this function
        request.pop_back(); // Remove "\r" at the end of message

        std::cout << "Request: " << request << std::endl;
        request = extract_endpoint(request);
    });

    std::cout << "hello " << request << std::endl;
    return request;
}

std::string HttpServer::handle_endpoint(std::string path) {
    std::cout << "handle endpoint: " << path << std::endl;
    for (auto &endpoint : endpoints) {
        std::cout << "current: " << endpoint.path << std::endl;
        if (endpoint.path == path) {
            if (endpoint.create_response) {
                return create_http_response(endpoint.create_response());
            } else {
                std::cout << "No function implemente for endpoint " << path << std::endl;
            }
        }
    }
    std::cout << "end endpoint" << std::endl;
    throw "Unhandled endpoint: " + path;
}

void HttpServer::write_response(std::shared_ptr<Connection> connection, std::string response) {
    auto write_buffer = std::make_shared<boost::asio::streambuf>();
    std::ostream write_stream(write_buffer.get());
    write_stream << response << "\r\n";
    // Add message to be written to client:
    // Write to client
    async_write(connection->socket, *write_buffer,
                  [this, connection, write_buffer](const boost::system::error_code &error, size_t) {

        if (error) {
            throw error;
        }
        handle_request(connection);
    });
}

void HttpServer::handle_request(std::shared_ptr<Connection> connection) {
    try {
        // Parse request
        std::string endpoint = parse_request(connection);
        std::cout << "Parsed endpoint: " << endpoint << std::endl;
        // Create response 
        std::string response = handle_endpoint(endpoint);
        std::cout << "Created response: " << response  << std::endl;
        // Respond
        write_response(connection, response);
    } catch(const boost::system::error_code err) {
        handle_error(err);
    } catch(std::string *err) {
        std::cerr << err << std::endl;
    }
}


