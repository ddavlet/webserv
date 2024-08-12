#ifndef SESSION_HPP
# define SESSION_HPP

# include <iostream>
# include "../utilities/Utils.hpp"

class Session
{
	private:
		char		_sessionId[256];
		std::string	_first_socket;
	public:
		Session(int socket_id);
		const char*	getSessionId();
		static std::vector<Session>::const_iterator findSession(std::vector<Session>& sessions, std::string& id);
};


#endif
