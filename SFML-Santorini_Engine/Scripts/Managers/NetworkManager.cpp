#include "NetworkManager.h"
NetworkManager* NetworkManager::instance{ nullptr };

NetworkManager& NetworkManager::Instance()
{
	if (instance == nullptr)
		instance = new NetworkManager;

	return *instance;
}

void NetworkManager::Start()
{
	m_publicAddress = sf::IpAddress::getPublicAddress(sf::Time::Time(sf::seconds(addressLookupTimeout)));
}

void NetworkManager::Stop()
{
}

void NetworkManager::StartAsServer()
{
	m_mode = NetworkMode::Server;
}

void NetworkManager::StartAsClient()
{
	m_mode = NetworkMode::Client;
}

void NetworkManager::StartAcceptingConnections()
{
}

void NetworkManager::StopAcceptingConnections()
{
}

bool NetworkManager::SendConnectionRequest(const std::string& ipAddress)
{
	return false;
}

bool NetworkManager::SendConnectionRequest(sf::IpAddress ipAddress)
{
	return false;
}

sf::IpAddress NetworkManager::GetPublicIPAddress()
{
	if (m_publicAddress == sf::IpAddress::None) {
		return sf::IpAddress::getPublicAddress(sf::Time::Time(sf::seconds(addressLookupTimeout)));
	}
	else return m_publicAddress;
}

sf::IpAddress NetworkManager::GetLocalIPAddress()
{
	return sf::IpAddress::getLocalAddress();
}


