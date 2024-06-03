#pragma once
#include "ACommand.hpp"

class ADMIN : public ACommand {
private:
    ADMIN();
    ADMIN(ADMIN const &that);
    ADMIN& operator=(ADMIN const &that);
public:
    ADMIN(Server &Server) : ACommand("ADMIN", Server) {}
    virtual ~ADMIN() {}
    virtual int run(){
        if (not _Argument.empty()) {
            return _Initiator->updateReplyMessage(ERR_NOSUCHSERVER(_Argument));
        }
        _Initiator->updateReplyMessage(RPL_ADMINME);
        _Initiator->updateReplyMessage(RPL_ADMINLOC1("Russia, Kazan"));
        _Initiator->updateReplyMessage(RPL_ADMINLOC2("School 21"));
        _Initiator->updateReplyMessage(RPL_ADMINEMAIL("vcobbler@student.21-school.ru, "
                                                    "csamuro@student.21-school.ru, "
                                                    "caugusta@student.21-school.ru"));
        return 0;
    }
};/*
   Parameters: [<server>]

   The admin message is used to find the name of the administrator of
   the given server, or current server if <server> parameter is omitted.
   Each server must have the ability to forward ADMIN messages to other
   servers.

   Numeric Replies:

           ERR_NOSUCHSERVER
           RPL_ADMINME                     RPL_ADMINLOC1
           RPL_ADMINLOC2                   RPL_ADMINEMAIL

   Examples:

   ADMIN tolsun.oulu.fi            ; request an ADMIN reply from
                                   tolsun.oulu.fi

   :WiZ ADMIN *.edu                ; ADMIN request from WiZ for first
                                   server found to match *.edu.

*/
