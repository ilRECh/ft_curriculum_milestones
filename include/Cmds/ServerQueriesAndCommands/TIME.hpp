#include "Commands.hpp"

class TIME : public ACommand {
private:
    TIME();
    TIME(TIME const &that);
    TIME& operator=(TIME const &that);
public:
    TIME(Server const *Server):   ACommand("TIME", Server) {}
    virtual ~TIME() {}
    virtual int run(){
        if (_Argument.empty()) {
            std::string arr[] = { _Name };
            return reply(ERR_NEEDMOREPARAMS, _User->_Fd, _User->getName(), L(arr));
        }
        //code
    }
};/*
   Parameters: [<server>]

   The time message is used to query local time from the specified
   server. If the server parameter is not given, the server handling the
   command must reply to the query.

   Numeric Replies:

           ERR_NOSUCHSERVER                RPL_TIME

   Examples:

   TIME tolsun.oulu.fi             ; check the time on the server
                                   "tolson.oulu.fi"

   Angel TIME *.au                 ; user angel checking the time on a
                                   server matching "*.au"

*/