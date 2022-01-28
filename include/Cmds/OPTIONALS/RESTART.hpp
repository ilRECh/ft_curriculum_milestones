#pragma once
#include "ACommand.hpp"

class RESTART : public ACommand {
private:
    RESTART();
    RESTART(RESTART const &that);
    RESTART& operator=(RESTART const &that);
public:
    RESTART(Server &Server) : ACommand("RESTART", Server) {}
    virtual ~RESTART() {}
    virtual int run(){
        if (_Arguments.empty()) {
            return _Initiator->updateReplyMessage(ERR_NEEDMOREPARAMS(_Name));
            
        }
        //code
    }
};/*
        Parameters: None

        The restart message can only be used by an operator to force a server
        restart itself.  This message is optional since it may be viewed as a
        risk to allow arbitrary people to connect to a server as an operator
        and execute this command, causing (at least) a disruption to service.

        The RESTART command must always be fully processed by the server to
        which the sending client is connected and not be passed onto other
        connected servers.

        Numeric Replies:

        ERR_NOPRIVILEGES

        Examples:

        RESTART                         ; no parameters required.
*/