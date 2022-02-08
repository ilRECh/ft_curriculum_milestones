#pragma once

#include "ft.hpp"
#include "Modes.hpp"

class Client;
class Server;

class Channel : public Modes {
private:
	uint _maxUserLimit;
	std::string _ChannelName;
	std::string _Key;
	std::string _Topic;
	std::set<Client *> _Clients;
	std::set<std::string> _BanList;
	Server *_Server;
public:
	Channel(
		std::string const & nameChannel,
		Client *userAdmin,
		Server *Server,
		uint maxUserLimit = 1024);
	~Channel() {}
	
	std::string const &getTopic() const;
	void setTopic(std::string const & Topic);
	std::string const &getChannelName() const { return _ChannelName; }
	void	removeClient(Client *whom);
	bool	isOnChannel(Client *whom) const;
	std::set<Client *>::size_type getCountClients();
	void	setChannelName(
		Client *who,
		std::string const & newNameChannel);
	void replyToAllMembers(std::string msg, Client * sender = NULL);
	//* Ban!!
	void addToBan(std::string const &BanMask);
	void removeFromBan(std::string const &BanMask);
	bool isBanned(std::string const &NickName);
	Client * getClient(std::string nickName);
private:
	friend class NAMES;
	friend class JOIN;
	friend class WHO;
	friend class INVITE;
	friend class MODE;
	friend class TOPIC;
};
