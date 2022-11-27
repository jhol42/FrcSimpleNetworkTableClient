#include <iostream>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <thread>
#include <chrono>

// For chorno user defined literals like 's' as in 1s as in 1 second.
using namespace std::chrono_literals;

bool waitConnect = true;

void connectionListener(const nt::ConnectionNotification& event)
{
    std::cout << "connectionListener called.\n";
    std::cout << "Connected to: " << event.conn.remote_id << " on " << event.conn.remote_ip << ":" << event.conn.remote_port << "\n";
    waitConnect = false;
}

void logmsg(const nt::LogMessage& msg)
{
    std::cout << msg.message << "\n";
}

int main()
{
    auto ntInstance = nt::NetworkTableInstance::Create();
    ntInstance.AddConnectionListener(connectionListener, false);
    //dflt.AddLogger(logmsg, 0, 100);
    ntInstance.SetServer("localhost", 1735);
    ntInstance.SetNetworkIdentity("MyTestClient");
    ntInstance.SetUpdateRate(.1);
    ntInstance.StartClient();
    
    while (waitConnect)
    {
        std::this_thread::sleep_for(1s);
    }

    auto table = ntInstance.GetTable("LiveWindow/Ungrouped/DifferentialDrive[1]");
    auto connections = ntInstance.GetConnections();

    auto keys = table->GetKeys();

    while (ntInstance.IsConnected()) {
        auto lms = table->GetEntry("Left Motor Speed");
        auto info = lms.GetInfo();
        double value = lms.GetDouble(-1000.0);
        std::cout << value << std::endl;
        std::this_thread::sleep_for(50ms);
    }
}
 
