#include <AlarmManager.hpp>

#include <iostream>

int main(int argc, char **argv) {
    std::unique_ptr<AlarmManager> am(new AlarmManager(argc, argv));
    using TMD = AlarmManager::TMotion;

    am->setMotionCallback([] (AlarmClient* client, const TMD& md, const size_t& size) {
        const std::string server = client->config()->getComment().empty() ?
                    client->config()->getIp() : client->config()->getComment();
        std::cout << "MD on " << server << ", channels: ";

        for (size_t i = 0 ; i < size ; i++) {
            const std::string channel = md[i]->getComment().empty() ?
                        std::to_string(md[i]->getId()) : md[i]->getComment();

            std::cout << channel << ", ";
        }

        std::cout << std::endl;
    });

    return am->run();
}
