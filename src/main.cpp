#include <Alarmer.hpp>

#include <stdexcept>
#include <iostream>

void setArgs(int count, char **argv, AlarmerArgs& args) {
    if (count != 5)
        throw std::runtime_error("Args error: ip port login pass");

    args.ip = std::string(argv[1]);
    args.port = std::stoi(argv[2]);
    args.login = std::string(argv[3]);
    args.pass = std::string(argv[4]);
}

int main(int count, char **argv) {
    AlarmerArgs args;
    setArgs(count, argv, args);
    Alarmer a(args);

    using TMD = AlarmProtocol::TMotion;

    a.run([](const TMD& md, const size_t& size) {
        std::cout << "md on channels: ";

        for (size_t i = 0 ; i < size ; i++) {
            std::cout << (int)md[i] << ", ";
        }

        std::cout << std::endl;
    });

    return 0;
}
