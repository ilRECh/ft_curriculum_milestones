#pragma once

#include "ft.hpp"

#ifndef GODMODE
#define MAY_BE_UNREGISTERED_seconds 40
#define MAY_BE_INACTIVE_seconds 100
#else
#define MAY_BE_UNREGISTERED_seconds 100000
#define MAY_BE_INACTIVE_seconds 100000
#endif

using std::string;
using std::vector;

class Channel;
class TimeStamp;

class Client {
private:
	TimeStamp _time;
	Client(Client& that);
	Client& operator=(Client& that);
	Channel *	_lastJoin;
	std::set<Channel const *> _Channels;
	std::string _Password;
	std::string _UserName;
	std::string _NickName;
	std::string _RealName;
    std::string _Away;
	std::string _HostName;
	std::string _ServerName;
	struct registration_s {
		registration_s()
			:	IsRegistered(false) {}
		bool IsRegistered;
		TimeStamp Time;
	} _Registration;
	struct activity_s {
		activity_s()
			:	WaitingForPONG(false) {} 
		bool WaitingForPONG;
		TimeStamp LastResponse;
		TimeStamp LastPING;
	} _Activity;
    std::string _ReplyMessage;
	std::string _IncomingBuffer;
public:
	Client(int const Fd);
	~Client() {}
	
	bool operator!=(const Client& that) const;
	bool operator==(const Client& that) const;

	std::string const &getUserName() const { return _UserName; };
	int const _Fd;
	void setPassword(std::string & Password) { _Password = Password; }

	// Names get|set
	string const & getNickName() const;
	string const & getAwayMessage() const { return _Away; }
	
	// * get time
	TimeStamp const & getTime() const;
	TimeStamp const & getLastActivity() const;

	//	* get|set  invite Channels
	void inviteToChannel(Channel * channel, Client * Iniciator = NULL);
	void leaveFromChannel(Channel * channel);
	std::set<Channel const *> const &getChannels() const;
	bool isOnChannel(const Channel * channel);

	//	* get Registered
	bool isRegistered() const;
	// void setRegistered(bool const Condition);
	bool unregisteredShouldDie() const;

	// get IP address
	std::string getAddresIP() const;

	// Last Activity
	bool inactiveShouldDie() const;
	bool ServerNeedToPING() const;
	bool isWaitingForPONG() const;
	void updateActivity();
	void PINGisSent();

	// ReplyMessage
	bool updateReplyMessage(std::string const & Msg);
	std::string const getReplyMessage();

	// Incoming buffer
	std::string& getIncomingBuffer();
private:
	friend class ACommand;
	friend class INVITE;
	friend class JOIN;
	friend class KICK;
	friend class LIST;
	friend class MODE;
	friend class NAMES;
	friend class PART;
	friend class TOPIC;
	friend class NICK;
	friend class OPER;
	friend class PASS;
	friend class QUIT;
	friend class SERVER;
	friend class Server;
	friend class SQUIT;
	friend class USER;
	friend class ERROR;
	friend class KILL;
	friend class PING;
	friend class PONG;
	friend class AWAY;
	friend class ISON;
	friend class REHASH;
	friend class RESTART;
	friend class SUMMON;
	friend class USERHOST;
	friend class USERS;
	friend class WALLOPS;
	friend class NOTICE;
	friend class PRIVMSG;
	friend class ADMIN;
	friend class CONNECT;
	friend class INFO;
	friend class LINKS;
	friend class STATS;
	friend class TIME;
	friend class TRACE;
	friend class VERSIONS;
	friend class WHO;
	friend class WHOIS;
	friend class WHOWAS;
	friend class Channel;
};
