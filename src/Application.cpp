#include "Application.h"

#include <AlarmClient.hpp>
#include <Config/ServerConfig.hpp>
#include <Config/ChannelConfig.hpp>
#include <Misc/Debug.hpp>

Application::Application(int argc, char* argv[])
    : HikAlarmApplication(argc, argv) {
}

Application::~Application() {
}

void Application::onNewClient(AlarmClient* client) {
    using TMD = AlarmClient::TMotion;

    client->onMotion.connect([client](const TMD& md, const size_t& size) {
        const std::string server = client->config()->getComment().empty() ?
                    client->config()->getIp() : client->config()->getComment();
        AAP_LOG(fmt("MD on %1%, channels: ") % server);

        for (size_t i = 0 ; i < size ; i++) {
            const std::string channel = md[i]->getComment().empty() ?
                        std::to_string(md[i]->getId()) : md[i]->getComment();

            AAP_LOG(fmt("%1%, ") % channel);
        }
    });
}
