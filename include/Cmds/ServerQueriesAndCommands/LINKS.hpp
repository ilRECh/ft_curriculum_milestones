#pragma once
#include "ACommand.hpp"

class LINKS : public ACommand {
private:
    LINKS();
    LINKS(LINKS const &that);
    LINKS& operator=(LINKS const &that);
public:
    LINKS(Server &Server) : ACommand("LINKS", Server) {}
    virtual ~LINKS() {}
    virtual int run(){
        if (_Arguments.empty()) {
            return _Initiator->updateReplyMessage(ERR_NEEDMOREPARAMS(_Name));
            
        }
        //code
    }
};/*
   Parameters: [[<remote server>] <server mask>]

   With LINKS, a user can list all servers which are known by the server
   answering the query.  The returned list of servers must match the
   mask, or if no mask is given, the full list is returned.

   If <remote server> is given in addition to <server mask>, the LINKS
   command is forwarded to the first server found that matches that name
   (if any), and that server is then required to answer the query.

   Numeric Replies:

           ERR_NOSUCHSERVER
           RPL_LINKS                       RPL_ENDOFLINKS

   Examples:

   LINKS *.au                      ; list all servers which have a name
                                     that matches *.au;

   :WiZ LINKS *.bu.edu *.edu       ; LINKS message from WiZ to the first
                                     server matching *.edu for a list of
                                     servers matching *.bu.edu.

*/