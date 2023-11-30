#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to generate a random application name
std::string generateRandomAppName() {
    const std::string appNames[] = {"CoolApp", "AwesomeApp", "SuperApp", "MegaApp", "FantasticApp"};
    const int numAppNames = sizeof(appNames) / sizeof(appNames[0]);
    int randomIndex = rand() % numAppNames;
    return appNames[randomIndex];
}

// Function to generate a random version number
std::string generateRandomVersion() {
    int major = rand() % 10;
    int minor = rand() % 10;
    int patch = rand() % 10;
    return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}

int main() {
    // Seed for the random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // Generate random application name and version
    std::string appName = generateRandomAppName();
    std::string appVersion = generateRandomVersion();

    // Print deployment message
    std::cout << "Deploying " << appName << " v" << appVersion << "...\n";
    std::cout << "Deployment successful!\n";

    return 0;
}
