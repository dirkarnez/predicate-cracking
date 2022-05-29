#include <iostream>
#include <string>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio/ts/internet.hpp>

using namespace std;

void api()
{
    using boost::asio::ip::tcp;
    try
    {
        // if (argc != 3)
        // {
        //   std::cout << "Usage: http_client <server> <path>\n";
        //   std::cout << "Example:\n";
        //   std::cout << "  http_client www.boost.org /LICENSE_1_0.txt\n";
        //   return 1;
        // }
        string host = "jsonplaceholder.typicode.com"; // argv[1]
        string path = "/todos/1";                     // argv[2]

        boost::asio::ip::tcp::iostream s;

        // The entire sequence of I/O operations must complete within 60 seconds.
        // If an expiry occurs, the socket is automatically closed and the stream
        // becomes bad.
        s.expires_after(std::chrono::seconds(60));

        // Establish a connection to the server.
        s.connect(host, "http");
        if (!s)
        {
            std::cout << "Unable to connect: " << s.error().message() << "\n";
            return;
        }

        // Send the request. We specify the "Connection: close" header so that the
        // server will close the socket after transmitting the response. This will
        // allow us to treat all data up until the EOF as the content.
        s << "GET " << path << " HTTP/1.0\r\n";
        s << "Host: " << host << "\r\n";
        s << "Accept: */*\r\n";
        s << "Connection: close\r\n\r\n";

        // By default, the stream is tied with itself. This means that the stream
        // automatically flush the buffered output before attempting a read. It is
        // not necessary not explicitly flush the stream at this point.

        // Check that response is OK.
        std::string http_version;
        s >> http_version;
        unsigned int status_code;
        s >> status_code;
        std::string status_message;
        std::getline(s, status_message);
        if (!s || http_version.substr(0, 5) != "HTTP/")
        {
            std::cout << "Invalid response\n";
            return;
        }
        if (status_code != 200)
        {
            std::cout << "Response returned with status code " << status_code << "\n";
            return;
        }
        
        // Process the response headers, which are terminated by a blank line.
        std::string header;
        while (std::getline(s, header) && header != "\r")
            std::cout << header << "\n";
        std::cout << "\n";

        // Write the remaining data to output.
        std::cout << s.rdbuf();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << "\n";
        return;
    }
}

bool validate(string userInput)
{
    return userInput == "icecream";
}

int main()
{
    cout << "input secret" << endl;
    string userInput;
    getline(std::cin, userInput);
    if (validate(userInput))
    {
        cout << "welcome" << endl;
    }
    else
    {
        cout << "sorry" << endl;
    }
    cin.get();
    api();
    cin.get();
    return 0;
}