#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string>
#include <map>
#include <algorithm>
#include "../requests/Request.hpp"
#include "../configuration/Config.hpp"

class Response {
private:
    std::string _httpVersion;
    int _statusCode;
    std::string _statusMessage;
    std::map<std::string, std::string> _headers;
    std::string _body;
    std::string _responseString;
	const ServerConfig& _config;
    std::map<int, std::string> _httpErrors;

    std::string readFile(const std::string& filename);
    std::string getMimeType(const std::string& filename);
    std::string toString(size_t num) const;

    void handleGetRequest(const Request& req);
    void handlePostRequest(const Request& req);
    void handleDeleteRequest(const Request& req);
	void _setError(int code);
    bool isMethodAllowed(const std::string& method, const std::string& uri) const;

public:
    Response(const Request& req, const ServerConfig& config);

    void initializeHttpErrors();
    void setStatus(int code);
    void addHeader(const std::string& key, const std::string& value);
    void setBody(const std::string& body);
    std::string toString() const;
	const char* toCString();
};

#endif
