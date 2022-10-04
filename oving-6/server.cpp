#include <boost/asio.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace boost::asio::ip;

class EchoServer {
private:
  class Connection {
  public:
    boost::asio::ip::tcp::socket socket;
    Connection(boost::asio::io_service &io_service) : socket(io_service) {}
  };

  boost::asio::io_service io_service;

  tcp::endpoint endpoint;
  tcp::acceptor acceptor;
  /* std::vector<std::string> HTTP_ENDPOINTS = { */
  /*   "GET / HTTP/1.1", */
  /*   "GET /en_side HTTP/1.1", */
  /* }; */

  /* bool is_http_request(std::string request) { */
  /*     return request.find(GET_REQUEST_STRING) != std::string::npos; */
  /* } */

  void write_response(shared_ptr<Connection> connection, string message) {
    auto write_buffer = make_shared<boost::asio::streambuf>();
    ostream write_stream(write_buffer.get());

      write_stream << message << "\r\n";

      // Add message to be written to client:
      // Write to client
      async_write(connection->socket, *write_buffer,
                  [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
        // If not error:
      if (!ec)
        handle_request(connection);
      });
  }

  void handle_request(shared_ptr<Connection> connection) {
    auto read_buffer = make_shared<boost::asio::streambuf>();
    // Read from client until newline ("\r\n")
    async_read_until(connection->socket, *read_buffer, "\r\n",
                     [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
      // If not error:
      if (!ec) {
        // Retrieve message from client as string:
        istream read_stream(read_buffer.get());
        std::string message;
        getline(read_stream, message);
        message.pop_back(); // Remove "\r" at the end of message

        // Close connection when "exit" is retrieved from client
        if (message == "exit") return;

        cout << "Message from a connected client: " << message << endl;

        // Beklager stygg kode

        if (message.find("GET / HTTP/1.1") != std::string::npos) {
          message = 
            "HTTP/1.1 200 OK\r\n"
            "Content-Length: 69\r\n"
            "Content-Type: text/html; charset=utf-8\r\n\r\n"
            "<!DOCTYPE html>" 
            "<html>"  
            "<body>"  
            "<h1>Dette er hovedsiden</h1>" 
            "</body>"
            "</html>";
        }
        
        else if (message.find("GET /en_side HTTP/1.1") != std::string::npos) {
          message = 
            "HTTP/1.1 200 OK\r\n"
            "Content-Length: 65\r\n"
            "Content-Type: text/html; charset=utf-8\r\n\r\n"
            "<!DOCTYPE html>" 
            "<html>"  
            "<body>"  
            "<h1>Dette er en side</h1>" 
            "</body>"
            "</html>";
        }

        // If the request is an HTTP request, but none of the supported ones,
        // we return 404 Not Found
        else if (message.find("HTTP/1.1") != std::string::npos) {
          message = 
            "HTTP/1.1 404\r\n"
            "Content-Length: 62\r\n"
            "Content-Type: text/html; charset=utf-8\r\n\r\n"
            "<!DOCTYPE html>" 
            "<html>"  
            "<body>"  
            "<h1>404 Not Found</h1>" 
            "</body>"
            "</html>";
        }

        cout << message << endl;
        write_response(connection, message);
      }
    });
  }

  void accept() {
    // The (client) connection is added to the lambda parameter and handle_request
    // in order to keep the object alive for as long as it is needed.
    auto connection = make_shared<Connection>(io_service);
    
    // Accepts a new (client) connection. On connection, immediately start accepting a new connection 
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept();
      // If not error:
      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
  EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

  void start() {
    accept();

    io_service.run();
  }
};

int main() {
  EchoServer echo_server;

  cout << "Starting echo server" << endl
       << "Connect in a terminal with: telnet localhost 8080. Type 'exit' to end connection." << endl;

  echo_server.start();
}
