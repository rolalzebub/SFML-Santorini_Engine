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
	m_publicAddress = sf::IpAddress::getPublicAddress();
}

void NetworkManager::Stop()
{
}

void NetworkManager::StartAsServer()
{
	m_mode = NetworkMode::Server;

	std::thread tcpListenerThread([&]() {
	sf::TcpListener listener;

	listener.listen(m_port);
	
		sf::TcpSocket* newClient = new sf::TcpSocket();
		sf::Packet packet;
		sf::Socket::Status status = listener.accept(*newClient);

		while (status == newClient->Disconnected ||
			status == newClient -> Error) { 
			status = listener.accept(*newClient);
		}

		std::cout << " New client: " << newClient->getRemoteAddress() << std::endl;

		NetworkingManager.AcceptClient(newClient);

		packet << "Connected to server";
		newClient->send(packet);
	});
	tcpListenerThread.detach();
}

void NetworkManager::StartAsClient()
{
	m_mode = NetworkMode::Client;
	
}

void NetworkManager::StartAcceptingConnections()
{
	if (m_mode != NetworkMode::Server) {
		m_mode = NetworkMode::Server;
	}

	sf::TcpListener m_listener;

	std::vector<sf::TcpSocket*> new_clients;

	bool* keepThreadRunning = new bool(true);

	runListenerThread = keepThreadRunning;


	m_listener.listen(m_port);


}

void NetworkManager::StopAcceptingConnections()
{
	*runListenerThread = false;

	current_thread->join();
}

void NetworkManager::SendConnectionRequest(const std::string& ipAddress)
{
	sf::IpAddress ip(ipAddress);
	sf::TcpSocket socket;
	sf::Packet packet;
	
	unsigned short remote_port = m_port; 
	//std::thread TcpConnectThread([&socket, &ip, &remote_port] {
		
		sf::IpAddress address;

		packet.clear();

		sf::Socket::Status status = connectionHostSocket.connect(ip, remote_port);

		if (status == sf::Socket::Done) {

			connectionHostSocket.receive(packet);
			std::cout << packet;
		}
		else {
			std::cout << "Receive status: " << status << std::endl;
		}
	//});
	//TcpConnectThread.detach();
}


void NetworkManager::StopAllConnections()
{
	for (auto& obj : clientSockets) {
		obj->disconnect();
	}
	
	connectionHostSocket.disconnect();
}

//void NetworkManager::AcceptClient()
//{
//
//	sf::TcpListener listener;
//	sf::TcpSocket tsocket;
//
//
//	if (listener.listen(m_port) != sf::Socket::Done) {
//		std::cout << "Binding error TCP \n";
//		return;
//	}
//	std::cout << "TCP bound to port " << listener.getLocalPort() << std::endl;
//
//	if (listener.accept(tsocket) != sf::Socket::Done) {
//		std::cout << "Accepting error TCP";
//		return;
//	}
//	sf::Packet packet;
//	
//	sf::TcpSocket* new_client_socket = new sf::TcpSocket();
//
//	listener.accept(*new_client_socket);
//	
//	StartAsServer();
//}

void NetworkManager::AcceptClient(sf::TcpSocket* newClient)
{
	clientSockets.push_back(newClient);
}


sf::IpAddress NetworkManager::GetPublicIPAddress()
{
	if (m_publicAddress == sf::IpAddress::Any) {
		m_publicAddress = sf::IpAddress::getPublicAddress();
	}
	return m_publicAddress;
}

sf::IpAddress NetworkManager::GetLocalIPAddress()
{
	return sf::IpAddress::getLocalAddress();
}

int NetworkManager::GetClientCount()
{
	return clientSockets.size();
}


