#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    int n;

    // Timer fixed at 3 seconds
    const int TIMEOUT = 3;

    cout << "Stop and Wait ARQ\n\n";

    // User decides number of frames
    cout << "Enter the number of frames to be sent: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of frames.\n";
        return 0;
    }

    srand(time(0));

    // Randomly select one frame to be lost
    int lostFrame = rand() % n + 1;

    for (int i = 1; i <= n; i++)
    {
        cout << "Sending Frame " << i << "...\n";

        // Simulate frame loss
        if (i == lostFrame)
        {
            cout << "Frame " << i << " lost!\n";

            cout << "Timer started for "
                 << TIMEOUT << " seconds...\n";

            // Wait for 3 seconds
            this_thread::sleep_for(
                chrono::seconds(TIMEOUT)
            );

            cout << "Timeout occurred.\n";
            cout << "Retransmitting Frame " << i << "...\n";

            cout << "Frame " << i
                 << " received successfully.\n";

            cout << "ACK " << i << " received.\n\n";
        }
        else
        {
            cout << "Frame " << i
                 << " received successfully.\n";

            cout << "ACK " << i << " received.\n\n";
        }
    }

    cout << "Transmission completed successfully.\n";

    return 0;
}