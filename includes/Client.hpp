#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <sys/socket.h>
# include <netinet/in.h>

# include "Utils.hpp"
# include "Request.hpp"
# include "Socket.hpp"
# include "Response.hpp"

//# define CLIENT_READ_BUFFER_SIZE 10 // 4096
# define CLIENT_READ_BUFFER_SIZE 4096

class Request;
class Response;


class Client
{
	private:
		int						_fd;
		Socket*					_socket;
		Request*				_request;
		Response*				_response;

	public:
		Client(void);
		Client(int fd, Socket* socket);
		~Client(void);

		/* HANDLE */
		int	handleRequest( int epollFD );
		void handleResponse(int epollFD);
		
		void clearRequest(void);

		/* GETTERS */
		int getFd(void) const { return _fd; }
		Request* getRequest(void) const { return _request; }
		Socket* getSocket(void) const { return _socket; }
		Response* getResponse(void) const { return _response; }
};

#endif // CLIENT_HPP
