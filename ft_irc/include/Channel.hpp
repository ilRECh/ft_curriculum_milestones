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
    std::set<Client *> _InviteClients;
	std::set<std::string> _BanList;
	Server *_Server;
	bool _ToRemove;
public:
	Channel(
		std::string const & nameChannel,
		std::string const & key,
		Client *userAdmin,
		Server *Server,
		uint maxUserLimit = std::numeric_limits<unsigned int>::max());
	~Channel() {}
	
	std::string const &getTopic() const;
	std::string const &getChannelName() const { return _ChannelName; }
	void	removeClient(Client *whom);
	bool	isOnChannel(Client *whom) const;
	std::set<Client *>::size_type getCountClients();
	void replyToAllMembers(std::string msg, Client * sender = NULL);
	//* Ban!!
	void addToBan(std::string BanMask);
	void removeFromBan(std::string const &BanMask);
	bool isBanned(std::string const &NickName);
	Client * getClient(std::string nickName);
    bool isInvited(Client *client);
private:
	friend class NAMES;
	friend class JOIN;
	friend class WHO;
	friend class INVITE;
	friend class PART;
	friend class MODE;
	friend class TOPIC;
};
