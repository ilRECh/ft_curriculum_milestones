#pragma once
#include "ACommand.hpp"

class OPER : public ACommand {
private:
    OPER();
    OPER(OPER const &that);
    OPER& operator=(OPER const &that);
public:
    OPER(Server &Server) : ACommand("OPER", Server) {}
    virtual ~OPER() {}
    virtual int run(){
        if (_Arguments.empty()) {
            return _Initiator->updateReplyMessage(ERR_NEEDMOREPARAMS(_Name));
        }
        //code
    }
};/*
   Parameters: <user> <password>

   OPER message is used by a normal user to obtain operator privileges.
   The combination of <user> and <password> are required to gain
   Operator privileges.

   If the client sending the OPER command supplies the correct password
   for the given user, the server then informs the rest of the network
   of the new operator by issuing a "MODE +o" for the clients nickname.

   The OPER message is client-server only.

   Numeric Replies:

           ERR_NEEDMOREPARAMS              RPL_YOUREOPER
           ERR_NOOPERHOST                  ERR_PASSWDMISMATCH

   Example:

   OPER foo bar                    ; Attempt to register as an operator
                                   using a username of "foo" and "bar" as
                                   the password.

*/