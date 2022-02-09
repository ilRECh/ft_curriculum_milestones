#include "ft.hpp"
#include "Channel.hpp"
#include "Replies.hpp"
#include "Client.hpp"
#include "Server.hpp"

Channel::Channel(
	string const & nameChannel,
	Client * userAdmin,
	Server *Server,
	uint maxUserLimit)
	:	Modes(this),
		_maxUserLimit(maxUserLimit),
		_ChannelName(nameChannel),
		_Server(Server){
	_Clients.insert(userAdmin);
	setMode(userAdmin, 'o');
}

std::string const &Channel::getTopic() const{
	return _Topic;
}

bool Channel::isOnChannel(Client *whom) const {
	return _Clients.find(whom) != _Clients.end();
}

std::set<Client *>::size_type Channel::getCountClients(){
	return _Clients.size();
}

void Channel::removeClient(Client *whom) {
	std::set<Client *>::iterator first = _Clients.begin();
	int countUserO = 0;

	static bool ToRemove = false;
	if (ToRemove) {
		return ;
	}
	std::set<Client *>::iterator i = find(_Clients.begin(), _Clients.end(), whom);
	if (i != _Clients.end()) {
		eraseClientFromModes(*i);
		_Clients.erase(i);
	}
	if (_Clients.empty()) {
		ToRemove = true;
		_Server->pushBackErase(this);
	}
	else
	{	
		if (countUserO == 0)
			for(;first != _Clients.end(); ++first)
				if (getModeIsExist(*first, 'o'))
					++countUserO;
		if (countUserO == 0 and ++countUserO)
			setMode(*_Clients.begin(), 'o');
	}
	replyToAllMembers("leaved", whom);
}

void Channel::replyToAllMembers(std::string msg, Client * sender) {
	std::string Reply = msg;//_ChannelName +  " :" + msg;
	Client * _Initiator = sender;
	if (sender != NULL) {
		if (this->getModeIsExist(this, 'm') && !this->getModeIsExist(sender, 'v'))
		{
			sender->updateReplyMessage(ERR_CANNOTSENDTOCHAN(_ChannelName));
			return ;
		}
		for (std::set<Client *>::iterator i = _Clients.begin(); i != _Clients.end(); ++i) {
			if (*i != sender) {
				(*i)->updateReplyMessage(Reply, "");
			}
		}
	} else {
		for (std::set<Client *>::iterator i = _Clients.begin(); i != _Clients.end(); ++i) {
			(*i)->updateReplyMessage(Reply, "");
		}
	}
}

void Channel::addToBan(std::string const &BanMask)
{
	_BanList.insert(BanMask);
}
void Channel::removeFromBan(std::string const &BanMask)
{
SearchAgain:
	std::set<std::string>::iterator EachBanMaskInBanList = _BanList.begin();
	while (EachBanMaskInBanList != _BanList.end()) {
		if (ft::wildcard(*EachBanMaskInBanList, BanMask)) {
			_BanList.erase(EachBanMaskInBanList);
			goto SearchAgain;
		}
		++EachBanMaskInBanList;
	}
}
bool Channel::isBanned(std::string const &NickName)
{
	for (std::set<std::string>::iterator EachBanMask = _BanList.begin();
		EachBanMask != _BanList.end();
		++EachBanMask) {
		if (ft::wildcard(*EachBanMask, NickName)) {
			return true;
		}
	}
	return false;
}

Client * Channel::getClient(std::string nickName){
	std::set<Client *>::iterator beginClient = _Clients.begin();
	std::set<Client *>::iterator endClient = _Clients.end();

	nickName = ft::tolowerString(nickName);
	while(beginClient != endClient)
	{
		if (nickName == ft::tolowerString((*beginClient)->_NickName))
			return *beginClient;
		++beginClient;
	}
	return NULL;
}
