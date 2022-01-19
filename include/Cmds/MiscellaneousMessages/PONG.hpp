#include "Commands.hpp"

class PONG : public ACommand {
private:
    PONG();
    PONG(PONG const &that);
    PONG& operator=(PONG const &that);
public:
    PONG(Server const *Server):   ACommand("PONG", Server) {}
    virtual ~PONG() {}
    virtual int run(){
        if (_Argument.empty()) {
            std::string arr[] = { _Name };
            return reply(ERR_NEEDMOREPARAMS, _User->_Fd, _User->getName(), L(arr));
        }
        //code
    }
};/*
        Parameters: <daemon> [<daemon2>]

        PONG message is a reply to ping message.  If parameter <daemon2> is
        given this message must be forwarded to given daemon.  The <daemon>
        parameter is the name of the daemon who has responded to PING message
        and generated this message.

        Numeric Replies:

        ERR_NOORIGIN                    ERR_NOSUCHSERVER

        Examples:

        PONG csd.bu.edu tolsun.oulu.fi  ; PONG message from csd.bu.edu to
                                        tolsun.oulu.fi
*/